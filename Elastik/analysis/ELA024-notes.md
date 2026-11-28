# ELA024 — filtre d’une voix en lecture directe

28 novembre 2026. Référence Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le lecteur restaure les huit champs de filtre d’ETKeyMapping. Le moteur applique le filtre après la lecture et le gain, puis multiplie le résultat par les enveloppes d’attaque et de relâchement. Les quatre réponses du filtre ont chacune leur historique stéréo et peuvent utiliser jusqu’à trois passes. Le type, l’ordre et le redéclenchement d’une note effacent les historiques concernés suivant le chemin i386. [API C++](../src/OriginalProgramVoice.h)

La fréquence de coupure est calculée par `20 × 2^(10 × filterCutOff)`. Le port utilise la fréquence du moteur pour calculer les coefficients. Un changement de la fréquence de coupure pendant une transition peut être différé jusqu’au bloc qui suit la fin de la transition. Le seuil du limiteur de rétroaction est appliqué dès le bloc courant. La modulation d’origine utilise une suite pseudo-aléatoire partagée. Le futur moteur doit fournir la fréquence de rendu et conserver cette suite entre les voix dans leur ordre d’exécution. [Filtre natif](../src/OriginalProgramVoiceFilter.cpp)

## Vérification

La sonde exécute les corps i386 de construction et de traitement du filtre, de déclenchement, de relâchement et de rendu. Elle compare le PCM stéréo, l’activation du filtre et l’état de la suite pseudo-aléatoire. Le jeu d’essai couvre les quatre réponses, les six ordres, les fréquences 44,1, 48 et 96 kHz, les changements de réglages pendant la lecture, le contournement, le redéclenchement, le relâchement et les transitions longues de coefficients. Les sons, les objets GN, la fonction système `pow` et les notifications de note proviennent des liaisons de la sonde.

Les 77 séquences et 790 blocs concordent bit à bit sur Linux x86‑64, ARM64 sous QEMU et x86‑64 avec ASan+UBSan. Les 500 blocs des jalons ELA022 et ELA023 repassent à l’identique sur x86‑64. L’objet Mach‑O ARM64 a été compilé et son en-tête vérifié. L’analyse sélectionne 20 fonctions, dont 10 nouvelles, pour un total de 590. [Rapports ELA024](../evidence/ELA024) · [Analyse Ghidra](ELA024-original-voice-filter-decompiled.zip)

Le chemin filtré vérifié couvre une voix en lecture directe. Le pitch, l’étirement temporel, la synchronisation hôte, le mixage des voix et la restauration d’un projet dans un hôte Audio Unit restent à valider.

```sh
python3 scripts/build_planar_sum_probe.py --kind program-voice-filter --output work/ProgramVoiceFilterProbe
python3 scripts/compare_original_program_voice_filter.py reference/Elastik.i386 work/ProgramVoiceFilterProbe \
  --platform local --output work/program-voice-filter.json
```
