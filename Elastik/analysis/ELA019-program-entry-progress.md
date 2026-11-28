# ELA019 — reprise de l’état AU au niveau du programme

28 novembre 2026. Relevé d’avancement après le checkpoint complet ELA018.

Le ClassInfo d’Elastik passe par `ETInstrument::save` et `ETInstrument::load`. L’archiveur à clés reçoit comme racine le programme actif `ETProgram`. Le getter `0x1b34c` lit le membre de programme de l’instrument et la sauvegarde `0x1b416` choisit le format 2. Au retour de la désérialisation, `0x1b4aa` appelle le setter `0x1b2bc` avec la racine. Un argument de données nul laisse le programme en place.

L’exécution de ces routines avec des objets synthétiques montre que le setter détache et libère l’ancien programme, attache le nouveau, recopie son tempo et demande la résolution de l’échantillon pour chaque affectation concernée. Le banc lie les appels à l’archiveur, au désarchiveur et au lecteur d’échantillons. Il vérifie le passage du programme entre ces étapes et le moteur d’origine. [Trace d’exécution i386](../evidence/ELA019/program-state-entry.json)

```sh
python3 scripts/probe_original_program_state_entry.py reference/Elastik.i386 \
  --output work/program-state-entry.json
```

Le raccordement natif devra appliquer les valeurs d’`ETProgram` avant l’attache, puis résoudre chaque `ETKeyMapping` avec sa banque. Il reste à exercer ce chemin avec un état Elastik 1 d’époque. Le checkpoint complet de référence reste ELA018.
