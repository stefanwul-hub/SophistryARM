# Elastik 1 — portage ARM64 en cours, ELA025

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA025 restaure les réglages de hauteur et de tempo et calcule les paramètres que le moteur d’origine envoie au processeur hors ligne. **65 cas** concordent bit à bit avec l’i386, dont deux utilisant la boucle fournie et des essais sur ARM64 sous QEMU. [Notes et reproduction ELA025](analysis/ELA025-notes.md) · [Preuves](evidence/ELA025)

Le traitement PCM de ces transformations, la synchronisation hôte, le catalogue et l’intégration Cocoa/AU restent à établir. Ce jalon est un checkpoint de développement. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA025](Elastik-ELA025-complet-checkpoint.zip) réunit sources, preuves et analyse. L’installateur de référence est conservé à part. [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
