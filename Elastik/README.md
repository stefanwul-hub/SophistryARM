# Elastik 1 — portage ARM64 en cours, ELA015

Objectif. Rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

Le lecteur de métadonnées GNFA décode désormais les listes de propriétés XML et OpenStep. ELA015 porte les types XML et leurs conversions d’origine. ELA014 avait confirmé le document OpenStep de 96 octets à `/Info.plist` dans la banque intégrée. [Notes et reproduction ELA015](analysis/ELA015-notes.md)

Les **2 121 cas**, dont 396 nouveaux cas XML, concordent bit à bit avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Trois objets Mach‑O ARM64 sont compilés. [Rapports de vérification](evidence/ELA015)

Le raccordement des objets GN au chargeur de banque reste à porter. Le décodage des corps d’état, la voix complète et l’intégration Cocoa/AU restent à établir. **Aucun composant Elastik ARM64 installable ni projet restauré n’est disponible à ce stade.** Les fichiers des banques de l’utilisateur et un état ou projet original restent attendus pour leurs vérifications. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA015](Elastik-ELA015-complet-checkpoint.zip) réunit sources, rapports et archives d’analyse. [Checkpoint ELA014](Elastik-ELA014-complet-checkpoint.zip) · [Décompilation ELA015](analysis/ELA015-original-xml-plist-decompiled.zip)

L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre les checkpoints du portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
