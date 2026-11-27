# Elastik 1 — portage ARM64 en cours, ELA005

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA005 raccorde le consommateur du cache et le gestionnaire de fichier au lecteur PCM ELA004 et aux blocs de voix ELA003. Les 244 cas de cache (22 373 opérations) et 813 cas de lecture concordent bit à bit avec les instructions i386 d’origine, sur x86-64 et ARM64 sous QEMU. Les nouveaux sources compilent aussi en objets macOS ARM64.

Le fournisseur original de samples est désormais exécuté dans le comparateur. Les essais comprennent 198 intégrations avec les blocs de voix et 24 cas avec les véritables octets du WAV intégré. Les métadonnées et le contenu initial du cache sont fournis par les fixtures ; son remplissage asynchrone, les conteneurs/codecs, le pitch et la voix complète restent à porter. Les notes détaillent les adaptations de plateforme et les limites. Le projet réunit maintenant 15 routines traduites et 227 fonctions sélectionnées décompilées.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA005](analysis/ELA005-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA005) · [Source du gestionnaire de fichier](src/OriginalSampleFile.cpp)

Le [checkpoint complet ELA005](Elastik-ELA005-complet-checkpoint.zip) réunit les sources, les scripts, les schémas de modèle, les rapports et les décompilations. L’[archive détaillée ELA005](analysis/ELA005-original-cache-file-decompiled.zip) est aussi disponible séparément. L’installateur original et les banques restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA004](Elastik-ELA004-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
