# ELA022 — rendu d’une voix sur des blocs consécutifs

28 novembre 2026. Référence Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le lecteur d’état récupère le volume, le panorama, la sortie et le drapeau de filtre d’ETKeyMapping. Le port relie le mode de lecture directe de `0x1532f8` aux bornes d’ELA021 et au lecteur de blocs existant. Il garde le curseur et les rampes entre les appels. [API C++](../src/OriginalProgramVoice.h)

Le rendu respecte l’offset de départ fourni par l’appelant, les sorties mono ou stéréo, le panorama et la progression du gain. À la fin d’une boucle, une modification des bornes est appliquée selon le chemin de réinitialisation d’origine. Une lecture sans répétition signale la fin de la note selon l’état de relâchement et sa rampe. Le banc compare aussi la partie du tampon préservée après la fin d’une note.

## Vérification

Les 52 séquences et 260 blocs concordent bit à bit avec l’i386 sur Linux x86‑64, ARM64 sous QEMU et x86‑64 avec ASan+UBSan. Les comparaisons couvrent 458 096 octets de tampons audio, leur état entre les blocs et 26 fins de voix. Deux cas vérifient l’application de bornes modifiées en cours de lecture. Le banc exécute `0x1532f8`, `0x152664` et la routine i386 de calcul des bornes. Le PCM synthétique, l’horloge, l’amorce hors synchronisation et la notification de fin de note sont fournis par la sonde. Les 132 cas ELA021 repassent à l’identique. [Rapports ELA022](../evidence/ELA022)

Le périmètre est la lecture directe sans filtre. Le raccrochement du filtre, le pitch, l’étirement temporel, la synchronisation hôte et le mixage complet restent à intégrer. L’objet Mach‑O ARM64 a été compilé et son en-tête vérifié. Le composant Audio Unit installable et la restauration sur macOS restent à valider.

```sh
python3 scripts/build_planar_sum_probe.py --kind program-voice-render --output work/ProgramVoiceRenderProbe
python3 scripts/compare_original_program_voice_render.py reference/Elastik.i386 work/ProgramVoiceRenderProbe \
  --platform local --output work/program-voice-render.json
```
