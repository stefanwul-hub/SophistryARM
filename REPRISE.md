# Reprendre à CP026 — tests de développement passés, publication en préparation

## Demande et dernier Mac confirmé

L’utilisateur confirme CP025 : Edit Filter, Prev/Next et corrections graphiques fonctionnent. Demande : formes d’onde, carrés Generators/Filters vides, valeurs Voices/Precision/Auto Bend et Cutoff/Resonance Filter inactifs ; récupérer les routines originales.

Le ZIP CP025 reçu a été inspecté indépendamment. SHA256 c2fabc1c8986e9f846fe1f1c56d2f4cbd49d99c355b3eeec9a8fde269deff098. Installation/build25001/CP-025/auval/actions/nom-rappel confirmés ; douze WAV finis non silencieux, huit comparaisons exactes. Preuve publique filtrée : evidence/mac-cp025-installed-controls.json. Le rapport brut est privé, conservé dans les attachments de cette session. Ne pas le redemander.

## CP026 réalisé

Nouveaux EditorControls.h et OriginalEditorView.h ; propriétés SpEp/SpEe/SpEd sans nouveaux ID AU. Métadonnées originales1ce0e/1d640/1d532/1d28c, getter normalisé vtable2b4, setter1cc86. Carrés Main/Filter = croix X/Y : original729d2, dix segments/couleurs, facteur de geste0.006666. Main15 molettes avec courbes originales +958Voices/614Precision/482Bend +481Glide/483Const. Filter114..117 et commandes périphériques/types780/781 selon567e6. Enveloppes141..152 encore dans la colonne générique.

Loop : original81258/8231e/819e2/818cc exécuté statiquement, quatre imports CGContext convertis en segments Cocoa avec CGFloat32. Données du sample intégré ; cache révision+valeurs ; lecture sans modifier le preset. Fixture publique tests/fixtures/loop-preview.fxp créée par original766type3 puis setter string1cf16 tag804 BT_cronox18.wav. Provenance jointe ;334664frames/44100Hz. Pas de licence privée. Les sources des instructions, runtime, allocateur, PCM et image restent inchangées. Identité aumu/Sop3/LinP, bundle,522ID et chunks conservés ; build26001, marqueurCP-026.

## Tests et reprise locale

work/cp026 : builds/logs/recherches ; work/cross-cp026 : six MachOarm64 liés strictement. tests/compare_editor_controls.py passe59metadata/getters float32exacts, huit croix et un tracéLoop474segments byte-exacts,136edits/cinq programmes exacts. NativeEditorProbe :23allers-retours de valeurs,quatre entrées invalides rejetées,aperçu ne change pas programme. Même14fichiers exacts sous ARM64/QEMU. Bridge522paramètres/huit cycles passe.30testsPython,bashsyntax/diffcheck passent. Preuves : evidence/editor-controls-cp026.json et evidence/cp026-development-checks.json. AppKit/auval/audio avec licence CP026 NON exécutés dans Linux.

Installer ajoute NativeEditorProbe/comparaisonUnicorn puis sept actions de champs/Filter et huitXY par coordonnées, capturesFilter/Loop. Tests précédents audio/auval et rollback restent obligatoires. Licence/banque privées sont réutilisées, ne pas les demander. LanceurCP026 doit épingler l’archive de sources et SHA256. Publication déjà autorisée sur codex/sophistry-native-checkpoints seulement ; main intacte. Aucun agent.

Disque serré ; suppressions d’exécutables reconstruisibles consignées work/cp026/rebuildable-cleanup.json. Sources, objets, snapshots, rapports et historique conservés. Bundle complet ignoré checkpoints/Sophistry-history.bundle à régénérer après le dernier commit. Ne pas supprimer les snapshots de référence.

## À terminer

Publier source→télécharger/vérifier chaque blob de l’archive→lanceur pinned→vérifier téléchargement brut→métadonnées et bundle. Ensuite livrer lien et commande Mac ; examiner prochain ZIP CP026. Interface complète encore inachevée : browser/trim/zones/zoomLoop/enveloppes graphiques/effets/modulation. Étendre ensuite comparaisons musicales, automation et charge temps réel. Ne pas présenter les tracés/états exacts comme certification sonore complète.
