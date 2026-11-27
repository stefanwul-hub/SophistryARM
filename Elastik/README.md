# Elastik 1 — portage ARM64 en cours, ELA006

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA006 porte le remplissage du cache depuis les octets PCM, la croissance des buffers et la lecture multicanal. Les 301 cas multicanaux et 577 scénarios de remplissage concordent bit à bit avec les instructions i386 d’origine, sur x86-64 et ARM64 sous QEMU. Les 1 057 cas d’ELA005 restent identiques. Les sources compilent aussi en objets macOS ARM64.

Le test peut partir d’un cache vide, lire les octets du sample, remplir les blocs et alimenter les voix sans substituer leur fournisseur original. Les métadonnées et allocations restent des interfaces du banc ; le cycle de vie et le timer Carbon, les conteneurs/codecs, le pitch et les voix complètes restent à porter. Les notes détaillent ces limites. Le projet réunit maintenant 18 routines traduites et 238 fonctions sélectionnées décompilées.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA006](analysis/ELA006-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA006) · [Source du remplissage](src/OriginalCacheRefill.cpp)

Le [checkpoint complet ELA006](Elastik-ELA006-complet-checkpoint.zip) réunit les sources, les scripts, les schémas de modèle, les rapports et les décompilations. L’[archive détaillée ELA006](analysis/ELA006-original-refill-lifecycle-decompiled.zip) est aussi disponible séparément. L’installateur original et les banques restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA005](Elastik-ELA005-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
