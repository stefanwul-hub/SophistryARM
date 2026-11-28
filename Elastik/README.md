# Elastik 1 — portage ARM64 en cours, ELA020

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA020 relie les affectations d’un état enregistré au lecteur d’échantillons. La sonde retrouve la boucle fournie par l’installateur et décode ses **176 399 trames** stéréo à 44,1 kHz. [Notes et reproduction ELA020](analysis/ELA020-notes.md)

Les **26 cas et 80 affectations** concordent sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. ELA019 décode le programme actif, son tempo et ses emplacements d’automation depuis ClassInfo. [Preuves ELA020](evidence/ELA020) · [Checkpoint ELA019](Elastik-ELA019-complet-checkpoint.zip)

Le catalogue hôte, la voix complète et l’intégration Cocoa/AU restent à établir. **Ce jalon est un checkpoint de développement.** Un état d’époque et ses banques serviront à vérifier la restauration dans Logic et Live. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA020](Elastik-ELA020-complet-checkpoint.zip) réunit sources, preuves et analyse. L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre le portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
