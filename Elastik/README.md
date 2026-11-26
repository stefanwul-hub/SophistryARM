# Elastik 1 — portage ARM64 en cours, ELA003

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA003 porte deux routines supplémentaires : la lecture d’un bloc de samples avec ses limites de boucle, son inversion et ses fondus, puis le calcul de la position suivante. Leurs 1 760 comparaisons avec les instructions i386 d’origine concordent bit à bit sur x86-64 et sur ARM64 sous QEMU. Le même source compile en objet macOS ARM64.

Le banc fournit les samples déjà décodés à l’API de lecture d’origine. Il valide ces routines de traitement de bloc, leurs buffers et leurs états ; le véritable décodeur de fichiers, le cache/pitch et le traitement complet d’une voix restent à porter. Les limites de ces essais, dont un arrêt QEMU isolé non reproduit ensuite, figurent dans les notes et les preuves.

Pour préparer les états, 36 champs de définition des modèles `ETProgram` et `ETKeyMapping` sont récupérés : fichiers et identifiants de banques, boucles, enveloppes, filtres, pitch, tempo et automation. Les noms originaux sont conservés. Le décodage des corps d’archive et le rappel d’un état utilisateur ne sont pas encore établis.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées ; leurs fichiers et un état ou projet original restent attendus pour les vérifications correspondantes.

[Notes et reproduction ELA003](analysis/ELA003-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA003) · [Source du lecteur de blocs](src/OriginalVoiceChunk.cpp)

Le [checkpoint complet ELA003](Elastik-ELA003-complet-checkpoint.zip) réunit les sources, les scripts, les schémas de modèle, les rapports et les décompilations. L’[archive détaillée ELA003](analysis/ELA003-original-sample-state-decompiled.zip) est aussi disponible séparément. L’installateur original et les banques restent hors de Git ; le paquet d’origine reste nécessaire pour reproduire les essais contre le binaire.

Les checkpoints ELA001 et ELA002 sont conservés, y compris l’[archive ELA002 publiée après votre accord explicite](analysis/ELA002-original-state-render-decompiled.zip). Les références du binaire sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

Votre [accord élargi pour toutes les futures publications du portage](PUBLICATION_AUTHORIZATION.json) est enregistré. Il couvre les notes, schémas, décompilations, sources, rapports et objets compilés issus du même original Elastik, sans redemander à chaque checkpoint. Les banques, numéros de série, données d’activation et préférences personnelles restent exclus. Le petit ZIP de code seul ELA003 est conservé comme premier instantané ; le checkpoint complet ci-dessus contient les éléments ajoutés après cet accord.
