# Elastik 1 — portage ARM64 en cours, ELA012

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA012 ajoute huit routines pour rechercher un sample par son chemin, créer son lecteur et lire ses données en mémoire ou via les liaisons de fichier. Le chemin complet **nom → répertoire GNFA → fabrique → WAVE → audio** est maintenant comparé aux instructions i386 d’origine. Les 644 cas concordent bit à bit sur x86-64, ARM64 sous QEMU, UBSan et AddressSanitizer.

Le sample intégré de 176 399 frames stéréo reste identique à une référence indépendante PCM16/32768, avec un lecteur partagé ou dédié. Les tests couvrent aussi la disposition de banque qui copie le fichier en mémoire avant décodage. Deux nouveaux objets macOS ARM64 sont compilés et leur architecture vérifiée. Les 27 anciens fichiers natifs restent inchangés.

Le projet compte 65 routines traduites dans leur domaine de validité et 341 fonctions sélectionnées décompilées. Le catalogue et le vrai délégué des banques, les objets GN et leurs durées de vie, les flux macOS, la concurrence, la voix complète et le pitch/time stretching restent à réaliser. Les primitives GNString sont encore des liaisons ; l’encodage historique des noms est documenté et vérifié dans les tests.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Les banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA012](analysis/ELA012-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA012) · [Recherche et fabrique](src/OriginalArchiveLookup.cpp) · [Lecteur mémoire](src/OriginalByteFile.cpp)

Le [checkpoint complet ELA012](Elastik-ELA012-complet-checkpoint.zip) réunit sources, scripts, schémas, rapports et décompilations. L’[archive détaillée ELA012](analysis/ELA012-original-named-files-decompiled.zip) est aussi disponible séparément. L’installateur, les banques et le WAV original restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA011](Elastik-ELA011-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

L’[accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré, y compris pour la création des blobs GitHub. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
