# Elastik 1 — portage ARM64 en cours, ELA024

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA024 raccorde les quatre modes de filtre à la lecture directe et reprend les changements de réglages pendant la lecture. **77 séquences et 790 blocs** concordent bit à bit avec l’i386, notamment sur ARM64 sous QEMU. [Notes et reproduction ELA024](analysis/ELA024-notes.md) · [Preuves](evidence/ELA024)

Le pitch, l’étirement temporel, le catalogue hôte et l’intégration Cocoa/AU restent à établir. Ce jalon est un checkpoint de développement. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA024](Elastik-ELA024-complet-checkpoint.zip) réunit sources, preuves et analyse. L’installateur de référence est conservé à part. [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
