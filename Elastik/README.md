# Elastik 1 — portage ARM64 en cours, ELA017

Objectif. Rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA017 lit les corps GNArchiver des dictionnaires, listes, chaînes, nombres et données sans compression. Le décodeur restitue les références jusqu’aux enregistrements d’un état synthétique de structure `objects` / `@id` / `@isa`. [Notes et reproduction ELA017](analysis/ELA017-notes.md)

Les **392 archives synthétiques et 1 503 objets** concordent avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Le chargeur de banque d’ELA016 et les fichiers GNFA constituent les briques de lecture des banques. [Preuves ELA017](evidence/ELA017) · [Checkpoint ELA016](Elastik-ELA016-complet-checkpoint.zip)

L’interprétation des champs des modèles, le runtime macOS, la voix complète et l’intégration Cocoa/AU restent à établir. **Ce jalon est un checkpoint de développement.** La restauration réclamera un état d’époque et ses banques de référence. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA017](Elastik-ELA017-complet-checkpoint.zip) réunit sources, preuves et archives d’analyse. L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre le portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
