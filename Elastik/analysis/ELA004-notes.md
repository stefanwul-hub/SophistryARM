# ELA004 — lecture des octets PCM et conversion des samples

Trois routines supplémentaires sont traduites depuis les instructions i386 d’Elastik 1.5.2.3. Elles prolongent les traitements de bloc ELA003 vers les données encodées des samples.

| Routine originale | Taille | Traduction native |
| --- | ---: | --- |
| `0x161584` | 128 octets | Taille en octets d’un sample selon son code de format |
| `0x1619b0` | 2 922 octets | Conversion de canal et format, strides, ordre des octets |
| `0x219820` | 556 octets | Lecture par buffers, déplacement dans le fichier et conversion vers des canaux float32 |

Les sources sont `src/OriginalSampleFormat.cpp/.h` et `src/OriginalBufferedPcm.cpp/.h`. Les pointeurs, interfaces d’entrée/sortie et diagnostics sont adaptés au C++ 64 bits. Le lecteur exige des métadonnées et buffers valides ; le mécanisme d’exceptions du framework GN n’est pas réimplémenté. Le convertisseur reproduit les effets sur les données, sans chercher à reproduire les registres de statut d’exception flottante Intel.

Les codes testés comprennent les entiers signés 8/16/24/32 bits, les entiers non signés 8 bits et float32, avec les ordres big-endian, little-endian ou natif prévus par le code. Le format float64 possède une taille de huit octets dans la routine de taille, mais le convertisseur d’origine le refuse ; le port le refuse également. Le format n’est pas déduit uniquement de sa largeur.

Certains détails sont essentiels pour la concordance. L’original échange les octets des entrées big-endian 16/32 bits et float32 directement dans le buffer source. Il laisse cette mutation en place. Il conserve aussi des règles de conversion asymétriques pour les entiers 8 bits. Les instructions Intel de conversion flottant vers int32 renvoient `0x80000000` en cas de NaN ou de dépassement ; ARM64 sature différemment, donc ce comportement Intel est écrit explicitement dans la traduction. Les copies avec chevauchement suivent les chargements et écritures d’origine.

Le lecteur `0x219820` découpe la demande selon la capacité du buffer, effectue un seek absolu, lit les octets puis convertit chaque canal demandé. Un canal de sortie nul est ignoré. La capacité doit contenir au moins une frame ; les métadonnées ne doivent pas provoquer de dépassement arithmétique. En cas de lecture partielle ou échouée, l’original convertit néanmoins le bloc prévu avec le contenu restant du buffer. Le port conserve cette règle et les arguments du diagnostic, sans ajouter de remplissage silencieux.

## Comparaisons réalisées

Le comparateur charge uniquement l’image Mach-O i386 dont le SHA-256 est `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. Il exécute les instructions originales dans Unicorn, MXCSR `0x1f80`. Le convertisseur original, sa routine de taille et le lecteur original ne sont pas substitués par du Python. Seules la frontière seek/read du flux d’octets et l’impression des diagnostics sont liées à la fixture. Tout autre appel d’hôte provoque un échec.

| Corpus, par plateforme | Cas | Vérification |
| --- | ---: | --- |
| Formats | 1 350 | Matrice des 16 codes, limites entières, NaN/Inf/subnormaux/zéros signés, strides, chevauchements, mutation des entrées et gardes : 477 515 octets de stockage |
| Lecture PCM | 673 | Canaux 1/2/4, sorties nulles, buffers non alignés sur une frame, offsets, lectures partielles/échouées, diagnostics, gardes et buffers : 601 081 octets, 5 332 appels de lecture |

Les deux corpus concordent intégralement bit à bit avec le C++ Linux x86-64 et le C++ AArch64 exécuté sous QEMU 7.2.0. Les mêmes sources compilent en deux objets Mach-O ARM64, type CPU `0x0100000c`, `MH_OBJECT`. Ces objets sont inclus dans l’archive détaillée. Ils ne constituent pas un composant Audio Unit.

Neuf cas du lecteur utilisent les véritables octets du WAV intégré `01drm120elastik_2.WAV`, au début, au milieu et à la fin de ses 176 399 frames stéréo PCM16. Son SHA-256 est `3a34c829da83d0b79773927fd2d026479a8038f4f7666c29a745aff2968b342f`. Le comparateur repère le chunk RIFF `data` pour fournir les métadonnées de la fixture ; il **n’exécute pas encore le parseur d’en-tête WAVE original**. Ni ce WAV ni une banque utilisateur ne sont ajoutés au checkpoint public.

Deux processus QEMU des premiers essais se sont arrêtés par SIGSEGV sur des cas différents, sans fournir de résultat. Le second cas exact a ensuite réussi 24 fois. La cause reste inconnue. Le protocole des sondes permet désormais de passer tout le corpus dans un seul processus, avec des buffers réinitialisés à chaque cas. Les deux corpus complets ARM64 ont passé ainsi, sans reprise automatique de cas et sans changement du code DSP. L’observation est conservée dans `evidence/ELA004/qemu-process-observation.json` ; ces essais sous Linux ne remplacent pas une exécution macOS.

## Lecture du cache et du conteneur

Le chemin analysé est `0x1f0c92` → `0x1afb00` → `0x1af4e2`. Ce dernier appelle soit le cache `0x21900c`, soit un lecteur de fichier via sa vtable. Pour WAVE, ce lecteur est `0x24cc60` ; il sélectionne le chemin PCM/float `0x219820` ou les décodeurs ADPCM. Le parseur WAVE `0x24ce76` est décompilé (11 316 octets) et sauvegardé, mais n’est pas traduit dans ce checkpoint. Les formats compressés, AIFF et les autres lecteurs restent à examiner.

**Correction d’interprétation d’ELA003 :** les deux arguments double égaux à 100 ne sont pas des pourcentages de gain. `0x1aecf0` les utilise pour agrandir une plage de frames préparée dans le cache, en les multipliant par le champ `GNSoundFile + 0x18`. L’unité de ce champ n’est pas encore établie. Les commentaires et notes sont corrigés ; aucun calcul DSP ELA003 n’est modifié. Les anciens rapports et archives restent des preuves historiques de leur version.

Le cache `0x21900c` assemble les portions de chunks planaires et signale un manque de données. Le wrapper de fichier remet alors la zone demandée à zéro. `0x218102` recherche le slot d’un chunk et vérifie la correspondance de son identifiant. `0x218cf6` enregistre les indices de début/fin demandés par un client, avec la borne inclusive particulière de l’original ; `0x218d48` invalide cette plage. Ces méthodes et leurs décompilations sont sauvegardées pour la suite ; le cache asynchrone n’est pas encore porté.

Les quatre phases Ghidra comprennent 53 fonctions distinctes, dont 30 nouvelles, soit 218 fonctions sélectionnées décompilées au total. Le projet contient maintenant six routines originales traduites, représentant 6 049 octets d’origine. Ce décompte mesure des routines bornées, pas la proportion du moteur audio intégral. La récupération de 10 436 plages d’unwind ne constitue pas un port de toutes ces fonctions.

## Reproduction locale

La préparation de l’installateur et du Python est celle d’ELA002. Sur Mac avec Xcode :

```sh
python3 -m venv work/venv
work/venv/bin/python -m pip install -r requirements-probe.txt
python3 scripts/inspect_elastik.py /chemin/ElastikAU.pkg.zip --output work/inspection --extract work/reference/original-payload
python3 scripts/extract_builtin_demo.py work/reference/original-payload/Library/Audio/Plug-Ins/Components/Elastik.component/Contents/Resources/Elastik.elastik --output work/builtin-demo --report work/builtin-demo-report.json
python3 scripts/build_planar_sum_probe.py --kind sample-format --output work/sample-format-probe
python3 scripts/build_planar_sum_probe.py --kind buffered-pcm --output work/buffered-pcm-probe
work/venv/bin/python scripts/compare_original_sample_formats.py work/reference/Elastik.i386 work/sample-format-probe --persistent-runner --platform macos-local --output work/sample-formats-local.json
work/venv/bin/python scripts/compare_original_buffered_pcm.py work/reference/Elastik.i386 work/buffered-pcm-probe --persistent-runner --wave work/builtin-demo/01drm120elastik_2.WAV --platform macos-local --output work/buffered-pcm-local.json
```

Pour les preuves de compilation et les commandes ARM64 de cet environnement, voir `evidence/ELA004/native-pcm-build.json`. Les rapports complets se trouvent dans `evidence/ELA004/`. L’option `--persistent-runner` n’effectue aucun nouvel essai automatique après un échec.

Les racines Ghidra sont `analysis/ELA004-{file-reader,cache,wave,pcm}-roots.txt`. Le thunk ECX `0x2e5020`, octets `8b0c24c3`, est maintenant reconnu en plus du thunk EBX déjà traité ; aucune instruction originale n’est patchée. Exemple :

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA004-pcm analysis/ELA004-pcm-roots.txt 1 ELA004
```

L’archive `analysis/ELA004-original-file-pcm-decompiled.zip` contient ces quatre phases, le relevé des classes sélectionnées et les deux objets macOS ARM64. La publication relève de l’accord permanent enregistré dans `PUBLICATION_AUTHORIZATION.json`.

La suite reste le wrapper/cache de samples, les conteneurs et codecs nécessaires, le traitement complet d’une voix avec pitch/time stretching et la lecture des corps d’état. Aucun moteur intégral ni AU ARM64 installable n’est disponible, aucun `auval`, rappel de projet ou résultat CPU dans Logic/Live n’est établi. Sophistry CP038 et CronoX CRX013 restent figés.
