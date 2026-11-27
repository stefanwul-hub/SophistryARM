# Elastik 1 — portage ARM64 en cours, ELA014

Objectif. Rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA014 porte la lecture des listes de propriétés OpenStep et la relie aux membres d’archives de banques GNFA. La banque intégrée fournit bien son document de 96 octets à `/Info.plist`. Le parseur restitue sa couleur, son identifiant et son titre. [Notes et reproduction ELA014](analysis/ELA014-notes.md)

Les **1 725 cas** concordent bit à bit avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Les 2 831 cas d’ELA013 repassent aussi sur x86‑64. Deux objets Mach‑O ARM64 sont compilés. [Rapports de vérification](evidence/ELA014)

La branche XML et le raccordement des objets GN au chargeur de banque restent à porter. Le décodage des corps d’état, la voix complète et l’intégration Cocoa/AU restent à établir. **Aucun composant Elastik ARM64 installable ni projet restauré n’est disponible à ce stade.** Les fichiers des banques de l’utilisateur et un état ou projet original restent attendus pour leurs vérifications. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA014](Elastik-ELA014-complet-checkpoint.zip) réunit sources, rapports et archives d’analyse. [Checkpoint ELA013](Elastik-ELA013-complet-checkpoint.zip) · [Décompilation ELA014](analysis/ELA014-original-plist-decompiled.zip)

L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre les checkpoints du portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
