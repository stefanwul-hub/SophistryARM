# ELA025 — préparer les changements de hauteur et de tempo

28 novembre 2026. Référence Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le lecteur restaure les quatre champs `pitchShiftSemitones`, `pitchShiftCent`, `pitchShifterMode` et `userTempoFactor`. Le résolveur peut maintenant ouvrir l’échantillon et produire le plan que le moteur d’origine transmet à son traitement hors ligne. Le plan distingue la lecture directe d’une demande de transformation. Il contient la fréquence source, les rapports de tempo, de durée et de hauteur, le sélecteur du processeur et la longueur attendue du résultat. [API du résolveur](../src/OriginalProgramSamples.h) · [Plan de transformation](../src/OriginalProgramSampleTransform.h)

## Règles d’origine

Le binaire cherche le tempo dans le nom de fichier, après un préfixe de trois caractères lorsque le nom contient au moins trois caractères. Sur `01drm120elastik_2.WAV`, il lit 120. Le port utilise le tempo du programme lorsqu’aucun nombre exploitable ne figure dans le nom. Dans ce chemin, le banc initialise à zéro une variable locale que l’i386 peut lire sans l’avoir écrite.

Le moteur arrondit le produit du tempo du programme et du facteur de la touche en float32. Il le divise par le tempo de l’échantillon et arrondit de nouveau en float32. La lecture directe est choisie lorsque ce rapport vaut 1 et que les deux champs de hauteur sont nuls. Le processeur reçoit l’inverse du rapport de tempo et le rapport de hauteur `2^(semitones/12 + pitchShiftCent/100)`. Les deux divisions de l’exposant et leur somme sont en float32. Le calcul de longueur multiplie le nombre de trames source par le rapport de durée en float32, puis tronque le résultat. Le port signale les rapports invalides et les longueurs hors plage.

| Algorithme du programme | Mode archivé 1 | Mode archivé 2 | Mode archivé 3 | Autre mode archivé |
| --- | --- | --- | --- | --- |
| 0 | 2 | 3 | 3 | 3 |
| Autre valeur | 1 | 4 | 5 | 0 |

## Vérification

La sonde exécute le scanner i386, la décision de préparer une version transformée, la construction d’ETPitchShifterJob et l’appel à la fabrique du processeur. Elle compare aussi les trois instructions du calcul de longueur du processeur. Elle utilise des liaisons pour les objets GN, le fichier source, `pow` et la capture des paramètres de la fabrique. Le côté natif ouvre les membres GNFA et lit leurs métadonnées WAVE par le résolveur utilisé depuis ELA020.

Les **65 cas** concordent bit à bit sur Linux x86‑64, ARM64 sous QEMU et x86‑64 avec ASan+UBSan. Ils couvrent 57 demandes de transformation, 8 lectures directes, les six sélecteurs du processeur et deux cas avec la boucle fournie de 176 399 trames. Les rapports ELA019 et ELA020 repassent à l’identique. Deux objets Mach‑O ARM64 ont été compilés et leurs en-têtes vérifiés. Ghidra sélectionne 63 fonctions, dont 31 nouvelles, pour un total de 621. [Rapports ELA025](../evidence/ELA025) · [Analyse Ghidra](ELA025-original-sample-transform-decompiled.zip)

Le traitement PCM élastique, la mise en cache de ses résultats et leur remplacement dans la voix restent à intégrer. Le composant Audio Unit installable et le rappel de projets dans Logic et Live restent à valider sur macOS.

```sh
python3 scripts/build_planar_sum_probe.py --kind program-samples --output work/ProgramSamplesProbe
python3 scripts/compare_original_program_sample_transform.py reference/Elastik.i386 work/ProgramSamplesProbe \
  --builtin reference/payload/Library/Audio/Plug-Ins/Components/Elastik.component/Contents/Resources/Elastik.elastik \
  --platform local --output work/program-sample-transform.json
```
