# Elastik 1 — portage ARM64 en cours, ELA022

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA022 enchaîne les blocs d’une voix à partir de ses réglages sauvegardés. Le curseur, les boucles, le panorama, les rampes et les fins de notes sont comparés sur **52 séquences et 260 blocs**, notamment sur ARM64 sous QEMU. [Notes et reproduction ELA022](analysis/ELA022-notes.md) · [Preuves](evidence/ELA022)

Le filtre, le pitch, l’étirement temporel, le catalogue hôte et l’intégration Cocoa/AU restent à établir. Ce jalon est un checkpoint de développement. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA022](Elastik-ELA022-complet-checkpoint.zip) réunit sources, preuves et analyse. L’installateur de référence est conservé à part. [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
