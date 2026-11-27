# ELA008 — lecture du conteneur WAVE et des métadonnées

Le banc peut maintenant partir du WAVE complet, calculer son format, ses canaux, sa fréquence, sa durée et son offset de données avec le parseur original, puis lire le PCM. Il ne remplace plus ces métadonnées par celles d’une fixture. Le code natif reproduit le répartiteur d’origine et les règles de lecture associées ; les objets GN, entrées/sorties et exceptions restent des interfaces explicites.

| Adresse originale | Octets | Traduction |
| --- | ---: | --- |
| `0x24ce76` | 11 316 | En-tête RIFF/WAVE et répartiteur de chunks |
| `0x24bfce` | 522 | Reconnaissance et récupération d’un octet d’alignement |
| `0x249976` | 129 | Getter du format encodé |
| `0x2499f8` | 44 | Getter du format de canaux |
| `0x249a3c` | 11 | Getter du nombre de frames |
| `0x2498bc` | 175 | Texte Broadcast de taille fixe, intégré à `Parser::fixed_text` |

Ces six routines représentent 12 197 octets d’origine, soit 38 routines / 25 226 octets au total. Les primitives scalaires de lecture `0x17fb68`, `0x17fc6e`, `0x17ff80` et `0x180086` sont reproduites dans les helpers internes du parseur et ne sont pas comptées séparément. Le décompte ne mesure pas la proportion du moteur instrumental complet.

## Règles originales conservées

Le lecteur vérifie les signatures RIFF et WAVE et fixe l’ordre des entiers du flux à little-endian. `0x17f560(stream, 0)` est ce réglage d’ordre des octets : ce n’est pas un déplacement dans le fichier. Le flux renvoyé par l’ouverture fournit sa position initiale ; le port n’ajoute pas de seek à zéro.

La recherche de chunks lit huit octets et compare les identifiants avec la table originale de 21 lignes. La dernière ligne est une suite non textuelle du binaire ; elle est conservée. Pour un identifiant inconnu, le code peut récupérer un décalage d’un octet, suivant l’identifiant décalé, la taille et la fin RIFF. Il ne remplace pas cette logique par un alignement systématique sur deux octets. La fin de boucle principale reste `position < taille_RIFF - 1`.

Le chunk `data` peut annoncer une taille plus grande que la fin disponible. Le parseur la borne à la plus petite fin entre fichier et RIFF, émet le diagnostic original, puis calcule les frames avec les divisions dans l’ordre d’origine. PCM et float partagent le calcul de largeur ; le getter n’accepte ensuite que les profondeurs reconnues par l’original. Les en-têtes Microsoft ADPCM et DVI/IMA ADPCM conservent leurs paramètres, tables de coefficients, calculs de frames et allocation de scratch. **Leurs samples compressés ne sont pas encore décodés.**

Le graphe de métadonnées conserve les champs originaux : `chunks.cuePoints`, `chunks.dataList`, `chunks.sample` et ses boucles, `chunks.regionList`, et `chunks.Broadcast Audio Extension`. Les clés, entiers 32/64 bits, chaînes, listes et octets privés sont comparés. Les listes `labl`, `note` et `ltxt` conservent leurs règles de terminaison et de padding, y compris les quatre octets supplémentaires du compteur interne sur les textes `labl`/`note` non vides. Les régions conservent les UMID, cinq champs 64 bits et noms. Le texte Broadcast s’arrête au premier NUL ; son historique est découpé en lignes et champs avec la règle CR/LF d’origine.

Les chunks inconnus sont conservés dans `privateChunks`, en alternant identifiant et données. Cela comprend les 1 388 octets `LGWV` du WAV intégré. Le lecteur n’invente pas un décodeur de ces données privées. `plst`, `wavl`, `PAD ` et le libellé original `JNUK` gardent leur traitement de saut ou de diagnostic.

Les chunks `inst` et `acid` appellent leurs sous-décodeurs via une interface native. Le banc remplace ces deux sous-décodeurs par des objets opaques de test, ou par un résultat nul. Il vérifie l’appel, la conservation de son résultat et le déplacement final, mais **ne décode pas leurs valeurs musicales**. Les lecteurs réels de ces charges utiles, notamment `0x28900e` et `0x288744`, restent à porter.

## Comparaisons

| Corpus, par plateforme | Cas | Résultat |
| --- | ---: | --- |
| WAVE, scanner, getters, métadonnées et erreurs | 1 078 | 4 267 966 octets de résultats et 22 290 événements de frontière comparés |
| Chemin en-tête → lecture PCM, inclus ci-dessus | 126 | Formats PCM8/16/24/32 et float32, canaux, gardes et buffers |
| WAV intégré, inclus ci-dessus | 4 | Début, milieu, fin et fichier complet de 176 399 frames stéréo |

Les mêmes noms et hashes de cas concordent sur x86-64, AArch64 Linux sous QEMU 7.2.0, x86-64 avec UBSan et x86-64 avec AddressSanitizer + UBSan. Les erreurs couvrent notamment signatures, en-têtes obligatoires tronqués, tailles RIFF/data, formats refusés, lectures échouées et allocation DVI nulle. Les erreurs GN sont représentées par des statuts en conservant les écritures déjà effectuées. Il n’y a aucun retry automatique. Les routines DSP précédentes ne sont pas modifiées ; leurs anciens corpus ne sont pas relancés dans ce checkpoint.

La référence exécute les instructions i386 inchangées du parseur, du scanner, des lectures scalaires, des getters et du chemin WAVE PCM → convertisseur. Son SHA-256 imposé reste `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. L’import de division entière non signée 64 bits est lié en respectant le retour i386 EDX:EAX. Les frontières sont le fichier d’octets, les primitives GN de métadonnées et de données brutes, les exceptions, l’allocateur DVI et les deux sous-décodeurs opaques.

Les objets de test comparent un graphe logique, sans reproduire la disposition mémoire, les compteurs de références ou les conversions internationales de chaînes GN. Les chaînes de métadonnées sont des octets de l’encodage original 4 à l’interface ; les tests ne valident pas sa conversion en chaînes macOS. Les allocations doivent réussir, les compteurs doivent rester bornés et les dénominateurs atteints doivent être non nuls. Les lectures scalaires réussies doivent fournir tous les octets demandés. Les octets de pile indéfinis de l’i386 après certains échecs de récupération d’alignement ne constituent pas un contrat du port. Le parseur ne représente pas encore une couche de lecture de banque prête à utiliser dans l’hôte.

Un objet Mach-O ARM64 est compilé et contrôlé (`0x0100000c`, `MH_OBJECT`) ; son empreinte est enregistrée et il est inclus dans l’archive détaillée. Il n’est pas exécuté sous macOS et ne constitue pas un Audio Unit. Ghidra conserve 49 fonctions dans cette phase, dont neuf nouvelles, soit 271 fonctions distinctes au total. Les petits getters sans plage d’unwind sont bornés au RET vérifié, avant le NOP ; le getter de frames mesure 11 octets. Le projet Ghidra est ouvert avec `-readOnly`.

## Vérification audio du WAV complet

Les 176 399 frames / deux canaux / 44 100 Hz, soit environ quatre secondes, passent intégralement par le conteneur puis la conversion native. Chaque sample est identique à celui des instructions i386. Une deuxième vérification lit le PCM16 source avec le lecteur WAVE standard de Python et calcule `int16 / 32768` : chaque bit float32 est encore identique, sur x86-64 et ARM64 sous QEMU.

Le pic vaut 0,999969482421875 sur les deux canaux. Les RMS sont environ 0,3317181349 et 0,3218807572. Le SHA-256 des float32 stéréo entrelacés est `555760159fb2f5e4331d3df06df12c1e659b27585601687f8ab364cd3e3d4ef3`. Le rapport `embedded-wave-audio-comparison.json` contient les empreintes par canal. Le WAV d’origine et le rendu restent privés ; seuls les chiffres et empreintes sont publiés. Cette vérification concerne la lecture PCM, sans voix instrumentale, pitch, time stretching ou effets.

## Reproduction

Après extraction privée de l’original et du WAV selon ELA004, avec Unicorn et Capstone dans le venv :

```sh
python3 scripts/build_planar_sum_probe.py --kind wave --output work/wave-probe
work/venv/bin/python scripts/compare_original_wave.py work/reference/Elastik.i386 work/wave-probe --wave work/builtin-demo/01drm120elastik_2.WAV --platform macos-local --output work/wave-local.json
work/venv/bin/python scripts/verify_original_wave_audio.py work/reference/Elastik.i386 work/builtin-demo/01drm120elastik_2.WAV work/wave-probe --platform macos-local --output work/wave-audio-local.json
```

Le dernier script peut produire un rendu privé avec `--audio-output work/wave-native.wav`. Pour ajouter une sonde Linux ARM64 dans ce même script : `--arm64-runner chemin/wave-aarch64 --qemu chemin/qemu-aarch64-static`. Notre environnement conserve l’original sous `reference/Elastik.i386` ; la recette utilisateur ci-dessus utilise le dossier `work/reference` proposé par l’extraction. Ces commandes ne compilent ni n’installent d’AU.

Les versions, flags, empreintes et rapports se trouvent dans `evidence/ELA008/`. Les racines Ghidra sont `analysis/ELA008-wave-roots.txt` :

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -readOnly -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA008-wave analysis/ELA008-wave-roots.txt 1 ELA008
```

Le checkpoint public contient sources, scripts, rapports et archives détaillées, avec l’accord permanent `PUBLICATION_AUTHORIZATION.json`. Installateur, banques et audio restent exclus. La suite concerne les sous-décodeurs instrument/ACID et codecs nécessaires, les liaisons au cache/voix, puis les voix complètes et les corps d’état. Le framework natif, l’AU, l’interface Cocoa, `auval` et le rappel d’un vrai projet restent à réaliser. Sophistry CP038 et CronoX CRX013 restent figés.
