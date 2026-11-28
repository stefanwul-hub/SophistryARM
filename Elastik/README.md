# Elastik 1 — portage ARM64 en cours, ELA018

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA018 reconstitue les références entre les enregistrements d’un état. Il décode les listes d’affectations de touches et vérifie les noms de champs d’`ETProgram` et d’`ETKeyMapping` en exécutant les routines i386 d’origine. [Notes et reproduction ELA018](analysis/ELA018-notes.md)

Les **40 états synthétiques et 427 enregistrements** concordent avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. ELA017 fournit la lecture des corps GNArchiver. ELA016 raccorde le chargeur de banque au lecteur GNFA. [Preuves ELA018](evidence/ELA018) · [Checkpoint ELA017](Elastik-ELA017-complet-checkpoint.zip)

Le rappel dans le moteur, l’exécution sur macOS et l’intégration Cocoa/AU restent à établir. **Ce jalon est un checkpoint de développement.** Un état Elastik 1 d’époque et ses banques serviront à valider la restauration. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA018](Elastik-ELA018-complet-checkpoint.zip) réunit sources, preuves et archives d’analyse. L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre le portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
