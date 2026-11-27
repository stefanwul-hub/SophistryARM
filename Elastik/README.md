# Elastik 1 — portage ARM64 en cours, ELA009

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA009 ajoute les vrais lecteurs des métadonnées instrument et ACID, l’écriture du chunk instrument, les décodeurs Microsoft ADPCM et DVI/IMA ADPCM et leur répartiteur de lecture. Les 6 900 scénarios concordent avec les instructions i386 d’origine sur x86-64 et ARM64 sous QEMU ; ils passent aussi avec UBSan et AddressSanitizer.

Le chemin WAVE utilise maintenant les champs musicaux réellement décodés et peut lire PCM, float32, MS ADPCM et DVI/IMA ADPCM. Les blocs compressés, leurs découpes, buffers et erreurs sont comparés ; 162 cas intègrent le décodage depuis le WAVE complet. Les 176 399 frames stéréo du WAV intégré gardent exactement le résultat PCM d’ELA008. Deux nouveaux objets macOS ARM64 sont compilés.

Le projet compte maintenant 44 routines traduites dans leur domaine de validité et 281 fonctions sélectionnées décompilées. Le raccordement du lecteur au cache et aux voix, les liaisons macOS, les objets GN, les conteneurs de banques et formats encore nécessaires, la voix complète et le pitch/time stretching restent à réaliser.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA009](analysis/ELA009-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA009) · [Métadonnées musicales](src/OriginalWaveChunks.cpp) · [Décodeurs ADPCM](src/OriginalWaveAdpcm.cpp)

Le [checkpoint complet ELA009](Elastik-ELA009-complet-checkpoint.zip) réunit sources, scripts, schémas, rapports et décompilations. L’[archive détaillée ELA009](analysis/ELA009-original-chunks-codecs-decompiled.zip) est aussi disponible séparément. L’installateur, les banques et le WAV original restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints précédents, dont [ELA008](Elastik-ELA008-complet-checkpoint.zip), sont conservés. Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
