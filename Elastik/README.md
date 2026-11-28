# Elastik 1 — portage ARM64 en cours, ELA021

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA021 relie les réglages de boucle enregistrés à la lecture des blocs d’une voix. Il calcule les bornes en trames, initialise le curseur et restitue les blocs dans les deux sens, y compris au passage de la fin du fichier. [Notes et reproduction ELA021](analysis/ELA021-notes.md)

Les **132 cas et 13 603 trames** concordent avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Les essais incluent la boucle fournie avec Elastik. ELA020 raccorde les affectations au lecteur d’échantillons. [Preuves ELA021](evidence/ELA021) · [Checkpoint ELA020](Elastik-ELA020-complet-checkpoint.zip)

Le catalogue hôte, le rendu complet de la voix et l’intégration Cocoa/AU restent à établir. **Ce jalon est un checkpoint de développement.** Un état d’époque et ses banques serviront à vérifier le rappel dans Logic et Live. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA021](Elastik-ELA021-complet-checkpoint.zip) réunit sources, preuves et analyse. L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre le portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
