# ELA021 — limites de boucle, sens et premiers blocs d’une voix

28 novembre 2026. Référence Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le lecteur d’état extrait `startDegree`, `stopDegree`, `direction` et `loopMode` d’`ETKeyMapping`. Le réglage absent reprend la valeur de construction d’origine. Ces champs alimentent `configure_program_voice`, qui utilise le nombre de trames du fichier ouvert et initialise l’état transmis au lecteur de blocs existant. [API C++](../src/OriginalProgramVoice.h)

| Routine i386 | Règle vérifiée |
|---|---|
| `0x1ab7c0`, `0x14af3e` | Le décompte du fichier est utilisé s’il est connu. Sinon le lecteur fournit le nombre de trames. Une borne se calcule par multiplication et division en double, puis troncature. Les angles 0 et 360 indiquent la première trame pour le début et la dernière pour la fin. |
| `0x14af3e`, `0x14d374` | Si les bornes calculées coïncident, la fin recule d’une trame. Lorsque le début vaut zéro, la fin prend la dernière trame. La durée est inclusive et le passage par la fin du fichier est conservé. Le fichier d’une seule trame garde une longueur de 1. |
| `0x152472` | Le curseur démarre sur la première borne en sens normal et sur la dernière en sens inverse. Les fondus sont initialisés sur les deux premiers canaux actifs au plus. Le fondu d’entrée de 100 trames est armé lorsque le début est différent de zéro. L’état de relâchement est conservé. |
| `0x152664`, `0x15197c` | Le lecteur réutilisé prépare la plage, inverse au besoin le bloc, applique les fondus et calcule la position suivante. |

Les angles hors de l’intervalle 0–360°, les valeurs non finies et l’absence de trames sont signalés avant de modifier la voix. Le lecteur de l’état signale aussi un type d’archive incohérent. Les champs valides conservent leur précision de stockage.

## Vérification

Le banc exécute l’écriture et la lecture de l’état puis la distribution des champs sur l’i386 avec les liaisons GN. Il appelle les routines originales de calcul des bornes, d’initialisation et de lecture d’un bloc. Le banc natif utilise le programme décodé, le lecteur de fichiers de l’échantillon et la routine de bloc traduite. Les deux bancs lisent les mêmes trames PCM. En plus des signaux de test, quatre cas utilisent la boucle WAV fournie par l’installateur, y compris le passage de la fin du fichier en marche avant et inverse.

Les **132 cas et 13 603 trames** concordent bit à bit sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Six cas supplémentaires vérifient le rejet et la conservation de l’état. Les rapports ELA005 et ELA020 sont reproduits à l’identique, soit 839 cas supplémentaires sur x86‑64. L’objet Mach‑O ARM64 du module a été compilé et son en-tête vérifié. L’analyse Ghidra couvre 31 fonctions, dont 19 nouvelles, pour un total de 573. [Rapports et objet ARM64](../evidence/ELA021) · [Décompilation et désassemblage](ELA021-original-voice-loop-decompiled.zip)

Les appels de préparation du cache sont relevés dans le test i386. Leur raccordement au chargement d’une voix native et l’initialisation des filtres sont des étapes distinctes. Les comparaisons portent sur la lecture de blocs avant le mixage, le pitch et l’étirement temporel.

## Reproduction

Depuis le dossier Elastik, avec le binaire i386 et la banque fournie dans l’installateur d’origine.

```sh
python3 scripts/extract_builtin_demo.py /chemin/vers/Elastik.elastik \
  --output work/builtin --report work/builtin.json
python3 scripts/build_planar_sum_probe.py --kind program-voice --output work/ProgramVoiceProbe
python3 scripts/compare_original_program_voice.py reference/Elastik.i386 work/ProgramVoiceProbe \
  --wave work/builtin/01drm120elastik_2.WAV --platform local --output work/program-voice.json
```

ELA021 est un checkpoint de développement. Il reste à intégrer la voix dans le moteur, à raccorder le catalogue hôte et à vérifier le rappel d’un état d’époque dans un Audio Unit ARM64 sur macOS.
