# Elastik 1 — portage ARM64 en cours, ELA016

Objectif. Rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

Le chargeur `ETSoundbank` utilise désormais le lecteur de banques GNFA et le parseur XML/OpenStep pour charger `/Info.plist`. ELA016 reproduit le chargement paresseux, les replis et les transitions du cache observés dans l’original. [Notes et reproduction ELA016](analysis/ELA016-notes.md)

Les **200 cas** concordent bit à bit avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Les 4 183 résultats des corpus ELA013 et ELA015 gardent leurs empreintes sur x86‑64. Deux objets Mach‑O ARM64 sont compilés. [Rapports de vérification](evidence/ELA016)

Le runtime d’objets et les services de fichier macOS restent à raccorder. Le catalogue, le vrai délégué de banque, la voix complète, le rappel d’état et l’intégration Cocoa/AU restent à établir. **Ce jalon est un checkpoint de développement.** La restauration d’un projet et la compatibilité des banques utilisateur restent à valider. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA016](Elastik-ELA016-complet-checkpoint.zip) réunit sources, rapports et archives d’analyse. [Checkpoint ELA015](Elastik-ELA015-complet-checkpoint.zip)

L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre les checkpoints du portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
