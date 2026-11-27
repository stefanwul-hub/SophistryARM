# Elastik 1 — portage ARM64 en cours, ELA004

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA004 porte la conversion des formats de samples et la lecture de leurs octets PCM vers des canaux float32. Les 1 350 cas de conversion et 673 cas de lecture concordent bit à bit avec les instructions i386 d’origine, sur x86-64 et ARM64 sous QEMU. Les sources compilent aussi en objets macOS ARM64.

Le lecteur est testé avec des données générées et les véritables octets du WAV intégré. Les métadonnées du fichier sont fournies par la fixture : le parseur WAVE original, les codecs compressés, le cache/pitch et la voix complète restent à porter. Les notes précisent les limites des essais, dont des arrêts QEMU avant le passage complet des corpus dans des processus continus. Le port réunit maintenant six routines originales traduites et 218 fonctions sélectionnées décompilées.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA004](analysis/ELA004-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA004) · [Source du lecteur PCM](src/OriginalBufferedPcm.cpp)

Le [checkpoint complet ELA004](Elastik-ELA004-complet-checkpoint.zip) réunit les sources, les scripts, les schémas de modèle, les rapports et les décompilations. L’[archive détaillée ELA004](analysis/ELA004-original-file-pcm-decompiled.zip) est aussi disponible séparément. L’installateur original et les banques restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints ELA001, ELA002 et [ELA003](Elastik-ELA003-complet-checkpoint.zip) sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
