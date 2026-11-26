# Elastik 1 — étude du portage ARM64, ELA001

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’archive fournie contient Elastik 1.5.2.3, en Intel 32 bits et PowerPC 32 bits. Son identité est `aumu/ELSK/UBER`. Ce travail est enregistré dans le dossier `Elastik/` du dépôt SophistryARM. Sophistry CP038 et CronoX CRX013 restent des références figées.

Ce checkpoint contient l’extraction de l’ancien paquet sans exécuter son installateur, l’inventaire Mach-O et des ressources, la récupération de 10 436 plages de fonctions, 32 décompilations ciblées des fonctions Audio Unit et d’état, et le relevé du contrat de sauvegarde. Une boucle stéréo de quatre secondes intégrée au composant a également été retrouvée et extraite sans changer ses octets.

**Il n’y a pas encore de plugin Elastik ARM64 à installer.** Le moteur n’a pas été recompilé ni exécuté ; le rappel de projets et la fidélité audio restent à établir. Les fichiers C issus de Ghidra sont des documents d’analyse, pas du source C++ compilable.

L’utilisateur dispose de « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » et recherche ses anciens projets. Aucun de ces fichiers ni de preset `.aupreset` n’est encore reçu ; leur compatibilité reste à vérifier. Un état original permettra de confronter la reconstruction aux données effectivement sauvegardées.

Le paquet d’origine, les banques et les données privées restent hors de Git. Le checksum de l’installateur est dans [reference-input.json](reference-input.json). Pour reproduire l’extraction avec Python 3 :

```sh
python3 scripts/inspect_elastik.py /chemin/ElastikAU.pkg.zip --output work/inspection --extract reference/original-payload
```

La récupération des plages de fonctions requiert `pyelftools==0.32` (`requirements-analysis.txt`). La sonde facultative de l’entrée i386 utilise Unicorn ; elle vérifie seulement les erreurs renvoyées sans instance, sans ouvrir le moteur. Le script Ghidra est destiné à l’analyse de développement. Aucun script n’installe ou ne remplace de composant dans `/Library`.

Reprise détaillée : [ELASTIK_REPRISE.md](ELASTIK_REPRISE.md). État : [elastik-status.json](elastik-status.json). Preuves : [evidence/ELA001](evidence/ELA001). Décompilations : [analysis/ELA001-original-au-decompiled.zip](analysis/ELA001-original-au-decompiled.zip).

La prise en charge ARM actuelle d’Elastik 3 ne suffit pas à établir sa compatibilité avec les projets Elastik 1.
