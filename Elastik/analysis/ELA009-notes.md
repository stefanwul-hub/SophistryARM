# ELA009 — métadonnées instrument/ACID et audio ADPCM

Le lecteur WAVE peut maintenant transmettre les valeurs réellement décodées des chunks instrument et ACID, puis lire les samples PCM, float32, Microsoft ADPCM ou DVI/IMA ADPCM par le répartiteur original traduit. Les fabriques et objets GN restent des interfaces de plateforme ; le banc compare leurs valeurs typées.

| Adresse originale | Octets | Traduction |
| --- | ---: | --- |
| `0x28900e` | 347 | Lecture des sept octets du chunk instrument WAVE |
| `0x288744` | 433 | Lecture du chunk ACID WAVE de 24 octets |
| `0x28916a` | 150 | Écriture du chunk instrument, sept ou huit octets |
| `0x24c638` | 1 575 | Décodage d’un bloc Microsoft ADPCM |
| `0x249b18` | 1 000 | Décodage d’un bloc DVI/IMA ADPCM |
| `0x24cc60` | 533 | Répartition PCM/ADPCM et lecture des blocs nécessaires |

Ces six routines représentent 4 038 octets d’origine. Le total atteint 44 routines / 29 264 octets dans leurs contrats de validité. Les sources sont `OriginalWaveChunks.cpp/.h` et `OriginalWaveAdpcm.cpp/.h`. Les lecteurs de charges utiles AIFF ne sont pas inclus dans cette phase.

## Métadonnées musicales

Le chunk instrument accepte au moins sept octets et lit note de référence, accordage fin, gain, limites de notes et limites de vélocité. **Chaque octet est signé dans le code i386.** La traduction fait cette extension de signe explicitement, car le type `char` peut être non signé par défaut sur ARM. Les 256 valeurs possibles sont comparées dans chacun des sept champs. L’écriture conserve les huit bits bas des valeurs ; le bit zéro du paramètre choisit sept octets ou huit avec un zéro final.

Le chunk ACID exige exactement 24 octets. Il lit les indicateurs, la note de référence, le nombre de temps et les deux champs de signature rythmique. Le mode de racine vaut 3 si le bit 1 est actif et que la note signée est non nulle ; son décalage vaut alors `note - 48`. Le bit 0 remet le nombre de temps à zéro sans réécrire le précédent octet de boucle. S’il est absent, le code met cet octet à 1. Les tests couvrent aussi des objets réutilisés avec des états antérieurs non nuls et leur padding.

Les deux champs float aux offsets 8 et 20 sont lus mais non conservés par cette routine originale, y compris le tempo nominal ACID. Le port ne déduit pas un nouveau tempo à leur place. Les valeurs NaN et autres représentations présentes dans ces champs ignorés ne modifient pas les états retenus.

Le banc WAVE ne renvoie plus les anciens objets opaques contenant le payload brut. Il appelle le lecteur natif réel et compare un objet typé canonique avec les champs issus des instructions originales. Le banc de référence utilise une seconde instance i386 pendant l’appel à la fabrique GN pour exécuter le vrai lecteur, sans écraser la pile du parseur WAVE suspendu. La construction, rétention et libération de la véritable classe GN restent à réaliser dans le runtime natif.

## Calculs ADPCM conservés

La normalisation est asymétrique dans les deux décodeurs : un entier positif est divisé en float32 par 32767 ; un entier nul ou négatif est multiplié par `2^-15`. Cette règle diffère de la conversion PCM16 déjà portée, et reste distincte.

Microsoft ADPCM conserve le prédicteur et l’ordre des deux samples initiaux, l’alias des historiques gauche/droite en mono, l’ordre des deux nibbles et les saturations. La somme de prédiction suit les débordements int32 puis une division par 256 tronquée vers zéro. Le delta adapté conserve ses seize bits bas. Les cas de bord comparent coefficients extrêmes, deltas 1/16/32768/65535, tous les nibbles, plages tronquées, sorties nulles et frames impaires. Une plage directe dépassant le dernier sample annoncé peut observer le dernier nibble traité par l’original ; le port n’ajoute pas de borne absente de cette routine.

DVI/IMA conserve le dégroupement par paquets de quatre octets de chaque canal, le scratch intermédiaire, le plafonnement des indices à 88 et le diagnostic de synchronisation. Les additions de delta passent par des entiers signés sur 16 bits, avec leur wrap d’origine ; une bibliothèque de codec moderne ne garantirait pas cette concordance. Pour plusieurs canaux, la mise à jour des indices utilise la parité comme l’original. Les tests incluent les buffers de quatre et huit canaux dans le domaine mémoire valide. Le répartiteur conserve la division du champ DVI par le nombre de canaux pour établir les frames par bloc.

Les deux décodeurs parcourent le bloc même si seules certaines sorties ou une portion des frames sont demandées. Le répartiteur alloue son buffer, se déplace au bloc de départ et exige un bloc complet, même si la lecture d’octets renvoie true avec moins d’octets. Pour le chemin compressé, une demande de zéro frame lit encore un bloc. En cas d’exception de lecture, la libération du chemin normal n’est pas appelée ; le statut natif représente cette exception, et la gestion de durée de vie extérieure reste une liaison GN à fournir. Le banc conserve les allocations physiques jusqu’à la fin de la fixture pour les observer puis les libère.

## Comparaisons

| Corpus, par plateforme | Cas | Octets comparés |
| --- | ---: | ---: |
| Lecteurs instrument/ACID et sérialisation | 2 556 | 133 664 |
| Blocs ADPCM et répartiteur de lecture | 3 020 | 7 446 828 |
| WAVE complet, métadonnées et audio | 1 324 | 5 129 726 |
| Total | 6 900 | 12 710 218 |

Les mêmes noms et hashes de cas concordent sur x86-64, AArch64 Linux sous QEMU 7.2.0, x86-64/UBSan et x86-64/AddressSanitizer + UBSan. Les états de métadonnées, octets d’entrée, gardes, float32 de sortie, scratch DVI et traces d’allocation/lecture sont comparés. Les données encodées et champs du lecteur restent inchangés. Il n’y a aucun retry automatique.

Les 1 324 cas WAVE incluent 126 lectures PCM et 162 exécutions de lecture compressée ; 372 scénarios visent un chemin audio, certains s’arrêtant à une erreur d’ouverture avant cette lecture. La référence exécute le parseur original, les lecteurs musicaux, les décodeurs de blocs et le répartiteur, avec des frontières d’objets et d’entrées/sorties explicites. L’image imposée conserve le SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Parmi les 1 078 cas ELA008, 1 070 gardent exactement leur hash. Les huit autres sont les cas `inst`/`acid` avant/après les données, de taille 6 ou 24 : ils passent maintenant par les vrais lecteurs. Les payloads trop courts sont rejetés et les payloads valides fournissent leurs champs, au lieu des anciens objets bruts du banc. Les 246 nouveaux cas couvrent des métadonnées valides combinées et le WAVE ADPCM complet, avec lectures défaillantes. Le résumé de régression précise ces changements attendus.

Les 176 399 frames stéréo du WAV intégré gardent leur résultat bit à bit, y compris la référence indépendante PCM16/32768. Le SHA-256 float32 stéréo entrelacé reste `555760159fb2f5e4331d3df06df12c1e659b27585601687f8ab364cd3e3d4ef3`. WAV original et rendu restent privés. Les blocs ADPCM des essais sont générés ; aucune banque utilisateur n’a été utilisée ni publiée.

Deux objets Mach-O ARM64 sont compilés et leurs en-têtes sont contrôlés (`0x0100000c`, `MH_OBJECT`). Ils ne sont pas exécutés sous macOS et ne sont pas des Audio Units. Les contrats exigent des blocs, tables, sorties et scratch valides, avec tailles et diviseurs adéquats. Les vrais objets GN, leurs références, exceptions et entrées/sorties macOS ne sont pas validés. Ce checkpoint ne démontre pas encore les voix complètes, le pitch, le time stretching ou le rappel d’un projet.

Ghidra sauvegarde 25 fonctions, dont dix nouvelles, soit 281 distinctes au total. Le décodeur MS sans plage d’unwind est borné à 1 575 octets, jusqu’au JMP final avant le NOP `0x24cc5f`. Les getters de nom de classe sont analysés mais non ajoutés au décompte des six routines traduites. Le projet est ouvert avec `-readOnly`.

## Reproduction

Après la préparation privée de l’original, du WAV intégré et du venv selon ELA004 :

```sh
python3 scripts/build_planar_sum_probe.py --kind wave-chunks --output work/wave-chunks-probe
python3 scripts/build_planar_sum_probe.py --kind wave-adpcm --output work/wave-adpcm-probe
python3 scripts/build_planar_sum_probe.py --kind wave --output work/wave-probe
work/venv/bin/python scripts/compare_original_wave_chunks.py work/reference/Elastik.i386 work/wave-chunks-probe --platform macos-local --output work/chunks-local.json
work/venv/bin/python scripts/compare_original_wave_adpcm.py work/reference/Elastik.i386 work/wave-adpcm-probe --platform macos-local --output work/adpcm-local.json
work/venv/bin/python scripts/compare_original_wave.py work/reference/Elastik.i386 work/wave-probe --wave work/builtin-demo/01drm120elastik_2.WAV --platform macos-local --output work/wave-local.json
work/venv/bin/python scripts/verify_original_wave_audio.py work/reference/Elastik.i386 work/builtin-demo/01drm120elastik_2.WAV work/wave-probe --platform macos-local --output work/wave-audio-local.json
```

Notre environnement utilise `reference/Elastik.i386` ; la recette d’extraction utilisateur utilise `work/reference`. Ces commandes ne compilent ni n’installent de composant AU. Les flags, empreintes et douze rapports de comparaison sont dans `evidence/ELA009/`.

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -readOnly -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA009-chunk-codec analysis/ELA009-chunk-codec-roots.txt 1 ELA009
```

Le checkpoint public conserve code, rapports, objets ARM64 et décompilations. L’accord permanent pour GitHub reste applicable sans nouvelle demande. Installateur, banques, données d’activation et audio original restent exclus. Seuls douze fichiers de cache compilateur C++ inutilisés ont été supprimés pour libérer 21 181 916 octets ; originaux, sources, produits figés et anciens checkpoints sont conservés.

La suite concerne les fabriques et l’ouverture du fichier (`0x219202`, `0x1adbb6`), leur liaison au cache et aux voix, puis les conteneurs de banques et le reste du moteur instrumental. La méthode `0x219704` est un lecteur abstrait qui lève NotImplemented, pas un initialiseur à porter comme tel. Runtime GN/timers, interface Cocoa, Audio Unit, `auval` et restauration d’un vrai projet restent à réaliser. Sophistry CP038 et CronoX CRX013 restent figés.
