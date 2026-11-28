# Elastik 1 — portage ARM64 en cours, ELA019

Le portage vise à rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`.

ELA019 lit le programme actif dans ClassInfo. Il restitue le tempo, l’ordre des affectations de touches, les notes MIDI, les chemins et identifiants de banque ainsi que les emplacements d’automation. [Notes et reproduction ELA019](analysis/ELA019-notes.md)

Les **40 archives synthétiques et 522 affectations** concordent avec l’i386 sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. ELA018 fournit la lecture des enregistrements à clés. ELA016 raccorde le chargeur de banque au lecteur GNFA. [Preuves ELA019](evidence/ELA019) · [Checkpoint ELA018](Elastik-ELA018-complet-checkpoint.zip)

Le raccordement au catalogue de banques, le rappel dans le moteur, l’exécution sur macOS et l’intégration Cocoa/AU restent à établir. **Ce jalon est un checkpoint de développement.** Un état Elastik 1 d’époque et ses banques serviront à valider la restauration. [Document de reprise](ELASTIK_REPRISE.md) · [État du portage](elastik-status.json)

Le [checkpoint complet ELA019](Elastik-ELA019-complet-checkpoint.zip) réunit sources, preuves et archives d’analyse. L’installateur et le payload d’origine sont conservés à part pour reproduire les comparaisons. L’accord de publication couvre le portage Elastik et exclut les banques personnelles, numéros de série, données d’activation, préférences et projets. [Référence de l’installateur](reference-input.json) · [Périmètre de publication](PUBLICATION_AUTHORIZATION.json)
