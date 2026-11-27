# Elastik 1 — portage ARM64 en cours, ELA008

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA008 traduit le répartiteur des en-têtes et des chunks WAVE, ses getters et le texte de métadonnées Broadcast. Les 1 078 scénarios concordent avec les instructions i386 d’origine sur x86-64 et ARM64 sous QEMU ; les mêmes cas passent avec UBSan et AddressSanitizer. Le chemin part désormais du fichier WAVE complet pour calculer les métadonnées et lire le PCM, sans fournir ces métadonnées depuis la fixture.

Les 176 399 frames stéréo du WAV intégré sont comparées intégralement, avec une seconde référence PCM16 indépendante. Les marqueurs, boucles, régions, listes et métadonnées Broadcast testés sont conservés. Les sous-décodeurs des chunks `inst` et `acid` restent des interfaces opaques ; les en-têtes ADPCM sont traités mais leur audio reste à décoder. Un objet macOS ARM64 supplémentaire est compilé. Les notes précisent les frontières GN et les limites des essais.

Le projet compte maintenant 38 routines traduites dans leur domaine de validité et 271 fonctions sélectionnées décompilées. Le cache et ses timers sont portés avec des interfaces de plateforme explicites. Leurs liaisons macOS, les objets GN, les conteneurs de banques, les codecs, la voix complète et le pitch/time stretching restent à réaliser.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA008](analysis/ELA008-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA008) · [Lecteur WAVE](src/OriginalWave.cpp)

Le [checkpoint complet ELA008](Elastik-ELA008-complet-checkpoint.zip) réunit sources, scripts, schémas, rapports et décompilations. L’[archive détaillée ELA008](analysis/ELA008-original-wave-decompiled.zip) est aussi disponible séparément. L’installateur, les banques et le WAV original restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA007](Elastik-ELA007-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
