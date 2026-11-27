# Elastik 1 — portage ARM64 en cours, ELA011

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA011 ajoute huit routines du conteneur de banques GNFA : lecture de l’en-tête et du répertoire, identification des fichiers, lecture des données, déplacement et partage du flux. Les 600 cas de contrôle et 64 cas GNFA → WAVE concordent bit à bit avec les instructions i386 d’origine sur x86-64, ARM64 sous QEMU, UBSan et AddressSanitizer.

Le décodeur WAVE peut maintenant lire le sample directement dans la banque d’exemple originale, sans extraction préalable. Ses 176 399 frames stéréo correspondent aussi à une référence indépendante PCM16/32768, avec un flux partagé comme avec un lecteur dédié. Les archives synthétiques couvrent les deux dispositions du répertoire et PCM, float32, MS/DVI ADPCM. Un nouvel objet macOS ARM64 est compilé et son architecture vérifiée. Le raccordement WAVE/cache/blocs de voix validé dans ELA010 reste inchangé.

Le projet compte maintenant 57 routines traduites dans leur domaine de validité et 322 fonctions sélectionnées décompilées. La recherche des chemins et les fabriques GNFA, le catalogue et le délégué des banques, les objets GN, les liaisons macOS et la concurrence, la voix complète et le pitch/time stretching restent à réaliser. La compatibilité avec vos banques personnelles n’est pas encore vérifiée.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA011](analysis/ELA011-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA011) · [Lecteur GNFA](src/OriginalFileArchive.cpp)

Le [checkpoint complet ELA011](Elastik-ELA011-complet-checkpoint.zip) réunit sources, scripts, schémas, rapports et décompilations. L’[archive détaillée ELA011](analysis/ELA011-original-gnfa-decompiled.zip) est aussi disponible séparément. L’installateur, les banques et le WAV original restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA010](Elastik-ELA010-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
