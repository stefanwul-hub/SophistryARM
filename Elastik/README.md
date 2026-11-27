# Elastik 1 — portage ARM64 en cours, ELA010

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA010 raccorde le lecteur WAVE au fichier, au cache et aux blocs de voix en suivant cinq routines supplémentaires de l’original : choix du lecteur, ouverture, association mono/stéréo, transfert des métadonnées et création du cache. Les 1 555 scénarios concordent bit à bit avec les instructions i386 d’origine sur x86-64, ARM64 sous QEMU, UBSan et AddressSanitizer.

Le test continu ouvre un vrai WAVE, crée le cache, constate la première lecture à vide, remplit le cache puis compare la lecture par blocs de voix avec la lecture directe. Il couvre PCM, float32 et les deux ADPCM déjà portés. Les métadonnées et les samples du cache proviennent du fichier. Les 176 399 frames stéréo du WAV intégré correspondent aussi à une référence indépendante PCM16/32768. Un nouvel objet macOS ARM64 est compilé et son architecture vérifiée.

Le projet compte maintenant 49 routines traduites dans leur domaine de validité et 284 fonctions sélectionnées décompilées. Les objets GN, les liaisons macOS et la concurrence, les conteneurs de banques et formats encore nécessaires, la voix complète et le pitch/time stretching restent à réaliser. La recherche du fichier mono partenaire reste une liaison explicite ; le choix gauche/droite et les conditions d’association sont portés et testés.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA010](analysis/ELA010-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA010) · [Ouverture et métadonnées](src/OriginalFileOpen.cpp)

Le [checkpoint complet ELA010](Elastik-ELA010-complet-checkpoint.zip) réunit sources, scripts, schémas, rapports et décompilations. L’[archive détaillée ELA010](analysis/ELA010-original-file-open-decompiled.zip) est aussi disponible séparément. L’installateur, les banques et le WAV original restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA009](Elastik-ELA009-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
