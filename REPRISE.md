# Reprendre à CP028 — correction de la prévalidation CP027

## Autorisation et confidentialité

Utilisateur propriétaire de la licence et des banques ; publication explicitement autorisée. Ne pas demander à nouveau la clé, les presets ou les banques. Publier uniquement sur `codex/sophistry-native-checkpoints`, sans modifier `main`. Aucune préférence, licence, chemin privé ou archive brute de rapport Mac ne doit être publié. Pas de sous-agents sans demande explicite.

## Rapport Mac reçu

CP027 compilé et exécuté sur Mac ARM64. Prévalidation audio à deux/six canaux, Main/Filter, huit croix X/Y, Loop et navigation des presets passent. Cinq WAV sont exacts à la référence, 16 fichiers de données de l’interface également. 522 paramètres/huit cycles, 704 cas DSP, 11 635 instructions et PCM passent. Arrêt avant installation au premier sélecteur du générateur 1 : le test demandait 766 et le panneau Schrader affichait 770. Le composant précédent a été conservé ; licence et banque restent validées localement. Auval et hôte séparé CP027 non exécutés. Preuve filtrée : evidence/mac-cp027-prevalidation.json. Dernière installation confirmée : CP025.

## Correction CP028

Correspondance des 14 identifiants de type vérifiée par la fonction originale 1cb52 : indices internes 90/91/102/103. Le modèle retrouve le menu du panneau visible, Cocoa utilise ce nœud, les cinq commandes de modules sont ajoutées dans tous les modes et les paramètres AU sont synchronisés après changement. Les noms de types déjà présents dans les images ne sont plus surimprimés. Les autres commandes restent recherchées exactement.

Les captures montrent aussi MIX/AM/FM incorrects. Dix-sept PNG originaux ont une résolution différente de 72 DPI ; bmp00380 est à 300 DPI. Le chargeur partagé fixe la taille logique aux pixels originaux ; les images ne changent pas. Le test Cocoa vérifie les dimensions des fonds et sprites, la construction réelle des menus et 50 transitions entre modes.

Le moteur LegacyEngine, le runtime, les 366 unités statiques, l’identité aumu/Sop3/LinP, com.linplug.au.Sophistry, la version AU3.0.8, les 522 identifiants et les chunks restent identiques. Marqueur CP-028, build28001. CP027 avait récupéré une instruction b5b71 ; son fragment et sa provenance restent conservés.

## Vérifications et reprise technique

Comparaison complète : 104 configurations/852 commandes/0 ULP, 50 transitions successives, 17 fichiers binaires exacts à l’exécution i386 originale et au replay ARM64/Linux-QEMU. 12 dialogues, six fichiers de modules, trois copies/collages, 3 240 positions clavier, 676 gestes, quatre repères Loop et six actions samples. Les sept binaires Mac sont liés strictement en ARM64 ; 30 tests Python passent. Voir evidence/complete-editor-cp028.json et evidence/cp028-development-checks.json. Les derniers contrôles DSP/PCM/contrat reçus sur Mac viennent de CP027 ; aucun changement DSP CP028.

Le comparateur Python exécute la nouvelle séquence de menus dans un hôte original frais après les 16 contrôles précédents : l’hôte d’enregistrement ne recycle pas les allocations libérées. Aucun élargissement mémoire ni changement de l’allocateur du plugin. La séquence native et Cocoa reste successive.

L’environnement Linux ne permet pas d’exécuter AppKit, auval ou le rendu AU macOS CP028. Le script garde les prévalidations avant remplacement, puis auval, comparaisons audio et hôte séparé avant confirmation ; sauvegarde/restauration inchangée. Ne pas annoncer l’installation CP028 comme validée avant son rapport Mac.

Recherches, journaux, preuves et scripts de construction : work/cp028. Exécutables réutilisés dans work/cp027 et work/cross-cp027 pour économiser l’espace ; nouvelles sorties ARM dans work/cp028/arm64. Objets moteur conservés dans work/native-core-cp011 et work/fxp-complete-build. Outils et SDK dans /workspace/work/tools. Ne pas reconstruire inutilement les 366 unités. L’ancienne archive source CP027 déjà publiée et vérifiée a été supprimée du cache, consignée dans work/cp028/rebuildable-cleanup.json ; sources, objets, rapports et historique préservés.

Publication CP028 : en cours. Après publication, inscrire les commits et empreintes immuables, vérifier les téléchargements puis régénérer checkpoints/Sophistry-history.bundle avec le dernier commit. Le prochain contrôle utilisateur est le rapport de l’installateur CP028.
