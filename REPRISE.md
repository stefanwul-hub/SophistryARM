# Reprendre à CP027 — interface récupérée ; validation Mac en attente

## Instructions persistantes

Utilisateur propriétaire de la licence et des banques, publication explicitement autorisée. Ne pas demander à nouveau la clé, les presets ou les banques. Ne publier ni préférences, ni rapports Mac bruts, ni chemins privés. Branche autorisée : `codex/sophistry-native-checkpoints` ; ne pas modifier `main`. Pas de sous-agents sans demande explicite. Voir README et docs/CP027.md.

## État technique

CP027 implémente les sept pages, 12 types/six emplacements FX, modulation/enveloppes ADSFR, zones/repères/zoom Loop, séquenceur, clavier et carte des sorties. Relevé original : 86 panneaux,19 sélecteurs,1067 définitions. Les champs Main/navigateur et dialogues utilisent l’adaptation Cocoa existante. Panneaux Enhanced réservés vides et bitmap250 absent documentés. Numéro de série non exposé ; statut seulement.

Getters et setters originaux ; saisie numérique convertie par 109c8/getter normalisé puis1cc86, car1cf16 ignore les nombres. ModuleManager b5a12/Nav2bf9e exécutés avec adaptateurs de plateforme ; Arp647 explicitement transmis au gestionnaire d’origine lorsque ses notifications sont désactivées. Écritures limitées au chemin choisi. Copie/collage d’origine ; aucun presse-papiers DSP inventé. Confirmation native pour les actions concernées. Clavier62 états/72blits et hit942d0 ; quatre routines de gestes originales, tracés XY/Loop CP026 conservés.

Ghidra a récupéré b5b71 MOV ECX,[EBP+8]. Listing191379,366 unités. Base gzip inchangée +fragment analysis/lifter-full/editor-additions-cp027.jsonl ; commande de génération dans sa provenance. Seuls Unit0335/Dispatch et manifeste changent. Runtime/allocateur/PCM inchangés. Identité aumu/Sop3/LinP, bundle,522ID,AU3.0.8,chunks préservés ; build27001, marqueurCP-027.

## Vérifications

NativeCompleteEditorProbe/compare_complete_editor :104configurations,852metadata/choix normalisés exacts,12dialogues,6fichiers de modules,3copies/collages,3240positions clavier,676positions de quatre gestes,4repères Loop numériques et6actions samples. États/fichiers exacts à l’original. Module incompatible rejeté. Mêmes sorties ARM64/QEMU. Régressions59champs/8XY/formeLoop/136edits/cinq états ;522paramètres/huit cycles ;704DSP et11635instructions ;30Python. Sept binaires Mac liés strictement. Voir preuves publiques ; ne pas confondre ces contrôles avec exécution AppKit/auval/audio CP027 sur Mac.

Les scripts d’installation gardent audio original/licence locale/auval/rollback. Nouveau parcours Cocoa7pages,72cas FX,9choix modulation,auxiliaires et quatre saisies Loop. Cache de compilation inclut tous les nouveaux en-têtes. Dernier Mac reçu et confirmé :CP025,preuve evidence/mac-cp025-installed-controls.json. CP026/CP027 Mac en attente ; l’utilisateur a demandé de continuer sans nouveau rapport.

## Reproduction et fichiers de travail

`python3 scripts/recover_original_editor.py --output work/editor-recovery --check` recrée les tables depuis le composant public, sans licence/préférences. `work/cp027` contient recherches/builds/logs/comparaisons ; `work/cross-cp027` les liens Mac ; `work/cp027/arm64` le replay QEMU. Outils/SDK dans `/workspace/work/tools`. Ne pas relancer toute la recompilation des366unités : les objets existent. Le nettoyage ciblé d’anciens exécutables/du tar SDK extrait est consigné dans work/cp027/rebuildable-cleanup.json ; sources, objets, rapports et historique conservés.

Publication source effectuée : `2756543de3f18ae4e1e7f6ed55d28a4228ed068c`. Archive téléchargée : 44354376 octets, SHA256 `3bbcd5ca9a91ec3f00e663426cf4610054c841f1e74a9ab07f3e841f2e2f1606`, 4157 blobs vérifiés. Source et arbre identiques à la préparation. Le lanceur CP027 est publié et téléchargé à l’identique : `e157133359f8da45524f27b1f7ddec5119f720c1`, 2448 octets, SHA256 `ce8989f7a295480cfcf060bc4fc24a3431570689401f062cb54ba46a5db7dd22`. URL immuable : https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/e157133359f8da45524f27b1f7ddec5119f720c1/Demarrer-Sophistry-CP027.command. Les métadonnées de vérification sont dans checkpoints/CP027-launcher-verification.json. Régénérer checkpoints/Sophistry-history.bundle après le dernier commit et vérifier l’arbre propre. Publication et téléchargements CP027 vérifiés ; prochain retour attendu : rapport Mac CP027.
