# Elastik 1 — portage ARM64 en cours, ELA023

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA023 relie les affectations MIDI sauvegardées au déclenchement, au relâchement et à la fin d’une voix en lecture directe. Les deux ordres de touches et **240 blocs sur 48 séquences** concordent avec l’i386, notamment sur ARM64 sous QEMU. [Notes et reproduction ELA023](analysis/ELA023-notes.md) · [Preuves](evidence/ELA023)

Le filtre, le pitch, l’étirement temporel, le catalogue hôte et l’intégration Cocoa/AU restent à établir. Ce jalon est un checkpoint de développement. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA023](Elastik-ELA023-complet-checkpoint.zip) réunit sources, preuves et analyse. L’installateur de référence est conservé à part. [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
