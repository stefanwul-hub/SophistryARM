# ELA003 — lecture des blocs de samples et définition des modèles

Deux routines supplémentaires sont traduites depuis l’i386 Elastik 1.5.2.3 : `0x152664` (2 064 octets, lecture d’un bloc de voix, bornes de boucle, inversion et fondus) et `0x15197c` (262 octets, position suivante). Le source est dans `src/OriginalVoiceChunk.cpp` et son interface dans `src/OriginalVoiceChunk.h`. L’addition des voix d’ELA002 reste inchangée.

L’interface native utilise des champs typés et un fournisseur de samples décodés. Elle adapte les pointeurs et objets GN 32 bits à un appel natif 64 bits. Dans le banc de comparaison, seule l’API de fourniture des samples (`0x1f0c92`) est liée à des fixtures float32. Les décisions de boucle, le traitement des fondus, l’inversion et le calcul de position sont exécutés comme instructions i386 originales. Les accesseurs originaux lisent des enregistrements mémoire initialisés de voix, key mapping et fichier audio. Aucun moteur complet ni chemin d’activation n’est exécuté.

Le fournisseur reçoit les deux arguments de pourcentage exactement égaux à 100, comme l’original. Ce banc ne valide pas le décodeur de fichiers, le chargement d’une banque, le cache de pitch ou le time stretching. Le code natif ne fournit pas encore ces parties. Les appels de diagnostic ne font pas partie de cette interface DSP ; les contrats testés utilisent des samples chargés, des bornes valides, les canaux 0/1 et le mode de diagnostic désactivé.

Les 1 760 cas comprennent des données générées et les 4 096 premières frames stéréo de la boucle WAV intégrée. Ils couvrent les boucles ordinaires et celles qui passent par la fin du sample, les deux sens, le mode bouclé ou non, les deux canaux, les tailles nulles/paires/impaires, les fondus positifs/négatifs avec saturation sur la cible, le drapeau de relâchement et le pointeur de position suivante optionnel. Les buffers entiers, leurs gardes, les deux états de fondus par canal, la plage lue, la position suivante et la direction mémorisée sont comparés bit à bit.

Les 1 760 cas passent sur l’exécutable Linux x86-64 et sur l’exécutable AArch64 sous QEMU 7.2.0. Ils totalisent 77 776 samples de canal traités par plateforme. Le source est aussi compilé en objet Mach-O ARM64. Ces vérifications ne constituent pas une validation macOS, `auval` ou Logic/Live.

Une première tentative ARM64 a connu l’arrêt d’un processus QEMU par SIGSEGV. Le cas exact a ensuite réussi 24 relectures (CPU par défaut et cortex-a53), puis l’ensemble des 1 760 cas est passé, sans modifier le source DSP. La cause de cet arrêt isolé n’est pas établie ; ce fait est conservé dans `evidence/ELA003/native-voice-chunk-build.json`. Il n’a produit aucune divergence de données reproductible. La validation sur Mac reste nécessaire avant tout AU installable.

Un détail inhabituel de l’original est conservé : le test de fin de l’inversion (`0x152865/0x152868`) laisse effectuer un échange central supplémentaire sur les blocs de taille paire. La traduction reproduit exactement ces instructions plutôt que de substituer une inversion standard. De même, la fin d’un fondu et le traitement des samples restants suivent les branches d’origine.

La lecture du véritable décodeur s’enchaîne ainsi : `0x152664` → `0x1f0c92` → `0x1afb00` → `0x1af4e2`, avec un traitement complémentaire à `0x1aecf0`. C’est la prochaine partie du chemin audio à porter, avec le cache et le pitch. Le traitement complet d’une voix (`0x1532f8`) reste lui aussi à terminer : ce checkpoint porte sa routine de lecture de bloc, pas l’ensemble de ses filtres, gains et contrôles.

Pour les états, les déclarations originales de `ETProgram` et `ETKeyMapping` révèlent 36 champs enregistrés : sept pour le programme et 29 pour les affectations. Ils comprennent notamment `_soundFilePath`, `_soundBankIdentifier`, les réglages d’enveloppe et de filtre, le sens, le mode de boucle, les bornes en degrés, le pitch, le tempo, la note MIDI et les relations d’automation. Les orthographes originales, dont `_automatationTargets`, sont conservées. Ce sont des déclarations de modèle ; cela n’établit pas que tous ces champs sont toujours sérialisés ni que les corps d’archive sont déjà décodés.

`evidence/ELA003/state-model-fields.json` garde les noms, types et offsets i386 ainsi que les empreintes des deux décompilations utilisées. Ces offsets ne sont pas à recopier dans un objet ARM64. Le schéma est extrait par `scripts/recover_state_models.py` depuis les inscriptions de classe de l’original. Les offsets de `_direction` et `_loopMode` concordent également avec les accesseurs machine exécutés dans la comparaison audio. Aucun preset ou projet utilisateur n’est reçu à ce stade.

Pour reproduire les essais avec le compilateur local :

```sh
python3 scripts/build_planar_sum_probe.py --kind voice-chunk --output work/voice-chunk-probe
work/venv/bin/python scripts/compare_original_voice_chunk.py work/reference/Elastik.i386 work/voice-chunk-probe --platform macos-local --output work/voice-chunk-comparison.json
```

La préparation de l’original et de l’environnement Python est décrite dans les notes ELA002. L’option `--demo` ajoute la fixture extraite de l’original ; sans elle la recette utilise 880 cas générés. Les rapports publiés utilisent les deux sources et donc les 1 760 cas. Pour ARM64 sous Linux, compiler avec Zig 0.14.1 (`-target aarch64-linux-musl -static -nostdlib++`) puis passer `--runner-prefix /chemin/qemu-aarch64-static`. Pour l’objet macOS, utiliser `-target aarch64-macos -c src/OriginalVoiceChunk.cpp`. Les autres options sont enregistrées dans la preuve de compilation.

Les fichiers de racines Ghidra sont `ELA003-sample-roots.txt` et `ELA003-state-roots.txt`. Exemple :

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA003-sample analysis/ELA003-sample-roots.txt 1 ELA003
python3 scripts/recover_state_models.py work/ELA003-state --output work/state-model-fields.json
```

Les [décompilations détaillées ELA003](ELA003-original-sample-state-decompiled.zip), les schémas et les rapports sont publiés après l’accord élargi de l’utilisateur : « Je donne un accord élargi pour toutes les futures publications. » Cet accord permanent est enregistré dans `PUBLICATION_AUTHORIZATION.json`. Il couvre les prochaines analyses et publications du même portage, sans nouvelle demande pour ce périmètre. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le checkpoint complet ELA003 inclut les archives d’analyse ; les exports Git par défaut continuent de les traiter comme des téléchargements séparés.

Le moteur complet, l’AU ARM64, la reprise des projets et la fidélité globale restent à établir. Sophistry CP038 et CronoX CRX013 restent figés.
