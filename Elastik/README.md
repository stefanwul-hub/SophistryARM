# Elastik 1 — portage ARM64 en cours, ELA007

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA007 ajoute la traduction du cycle de vie du cache et du contrôle des timers : allocation, configuration depuis le fichier, réutilisation des clients, démarrage, annulation, rappel et nettoyage. Les 195 scénarios du cache et 280 scénarios du timer concordent avec les instructions i386 d’origine sur x86-64 et ARM64 sous QEMU ; ils passent aussi avec UBSan. Les 1 390 scénarios de lecture/remplissage précédents gardent les mêmes résultats. Deux nouveaux objets macOS ARM64 sont compilés.

Le projet compte maintenant 32 routines traduites dans leur domaine de validité, avec des interfaces de plateforme explicites, et 262 fonctions sélectionnées décompilées. Le chemin déjà comparé va des octets PCM au remplissage d’un cache vide, puis au fournisseur et aux blocs de voix. Le parseur WAVE original, les codecs nécessaires, la voix complète et le pitch/time stretching restent à porter. Le timer s’attache à la boucle d’événements courante ; son vrai raccordement macOS, les objets GN et les garanties de concurrence restent à réaliser. Les essais délivrent les événements directement, sans ordonnanceur macOS.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA007](analysis/ELA007-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA007) · [Source du cache](src/OriginalCacheLifecycle.cpp) · [Source du timer](src/OriginalTimer.cpp)

Le [checkpoint complet ELA007](Elastik-ELA007-complet-checkpoint.zip) réunit les sources, les scripts, les schémas, les rapports et les décompilations. L’[archive détaillée ELA007](analysis/ELA007-original-cache-timer-decompiled.zip) est aussi disponible séparément. L’installateur original et les banques restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA006](Elastik-ELA006-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
