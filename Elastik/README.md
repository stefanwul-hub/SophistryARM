# Elastik 1 — portage ARM64 en cours, ELA013

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA013 ajoute quatorze routines : métadonnées de banques, références et invalidation du cache, recherche du fichier source, ouverture GNFA en lecture seule et création des chemins internes. Les **2 831 cas de contrôle par configuration** concordent bit à bit avec les corps i386 d’origine sur x86-64, ARM64 sous QEMU, UBSan et AddressSanitizer.

L’ouverture réelle du conteneur est reliée au parseur, au lookup et à la lecture des membres ; les 707 036 octets du WAV intégré sont comparés entièrement. Le contrôle des métadonnées de banque utilise encore des liaisons explicites pour le parseur de plist, les objets GN et les services système. Deux nouveaux objets macOS ARM64 sont compilés et leur architecture vérifiée. Les 31 anciens fichiers natifs restent inchangés.

Le projet compte 79 routines traduites dans leur domaine de validité et 390 fonctions sélectionnées décompilées. Il reste à relier le parseur de plist, le runtime GN et le chargeur, puis le catalogue global et le vrai délégué des banques. La voix complète avec boucles/pitch/time stretching, les états, l’interface et l’AU restent à réaliser. Les routines d’autorisation d’origine ne sont pas remplacées.

Pour préparer les anciens états, 41 champs sont identifiés : les 36 champs `ETProgram`/`ETKeyMapping` déjà récupérés et cinq champs `ETSoundbank`, dont l’identifiant de banque et son chemin source. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Les banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA013](analysis/ELA013-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA013) · [Métadonnées de banque](src/OriginalSoundbank.cpp) · [Ouverture du conteneur](src/OriginalArchiveOpen.cpp)

Le [checkpoint complet ELA013](Elastik-ELA013-complet-checkpoint.zip) réunit sources, scripts, schémas, rapports et décompilations. L’[archive détaillée ELA013](analysis/ELA013-original-soundbank-decompiled.zip) est aussi disponible séparément. L’installateur, les banques et le WAV original restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA012](Elastik-ELA012-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

L’[accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré, y compris pour la création des blobs GitHub. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
