# ELA023 — déclenchement et relâchement d’une voix

28 novembre 2026. Référence Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le port retrouve l’affectation d’une note MIDI dans le programme sauvegardé selon les deux ordres reconnus par `0x15f296`. Pour les notes 36 à 103, l’ordre courant commence sur la note 36. Dans l’autre ordre, les notes 72 à 103 commencent au premier emplacement et les notes 36 à 71 occupent les emplacements 36 à 71.

Le déclenchement initialise le curseur, le gain, le panorama et les rampes de la voix. Le relâchement tient compte de la longueur de la boucle et du réglage d’enveloppe archivé. La lecture directe applique le fondu par canal du chemin court d’origine et termine la note en libérant son état. La voix conserve la vélocité et l’offset transmis à chaque événement. L’hôte doit encore distribuer les événements MIDI à la voix. [API C++](../src/OriginalProgramVoice.h)

## Vérification

Deux programmes synthétiques comparent chacun les réponses pour les 128 notes MIDI. Le banc exécute aussi les routines originales de sélection, de calcul des bornes, de déclenchement, de relâchement et de rendu. Les 48 séquences couvrent la lecture dans les deux sens, les boucles qui franchissent la fin du fichier, plusieurs durées d’enveloppe et 48 fins de voix. Le PCM synthétique, le stockage d’objets GN et les notifications de fin sont fournis par la sonde.

Les 240 blocs et leur état concordent bit à bit sur Linux x86‑64, ARM64 sous QEMU et x86‑64 avec ASan+UBSan. Le rapport ELA022 repasse à l’identique sur x86‑64. Un objet Mach‑O ARM64 a été compilé et son en-tête vérifié. L’analyse Ghidra sélectionne 14 fonctions, dont 7 nouvelles, pour un total de 580. [Rapports ELA023](../evidence/ELA023) · [Analyse Ghidra](ELA023-original-voice-lifecycle-decompiled.zip)

Le filtre, le pitch, l’étirement temporel et la synchronisation au tempo de l’hôte restent à raccorder au moteur. La compilation du composant Audio Unit et la restauration d’un projet d’époque restent à vérifier sur macOS.

```sh
python3 scripts/build_planar_sum_probe.py --kind program-voice-lifecycle --output work/ProgramVoiceLifecycleProbe
python3 scripts/compare_original_program_voice_lifecycle.py reference/Elastik.i386 work/ProgramVoiceLifecycleProbe \
  --platform local --output work/program-voice-lifecycle.json
```
