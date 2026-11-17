# Sophistry — checkpoint CP026

Portage expérimental de Sophistry 3.0.8 vers Audio Unit ARM64. L’original contient du code i386 32 bits et PowerPC ; les instructions récupérées sont traduites statiquement en C++. La couverture de tous les chemins et de toutes les banques reste à démontrer.

**CP025 est installé et validé sur Mac** : auval, boutons Edit et Prev/Next, quatorze cas de générateurs, six clics de routage, rappel du nom/type et douze WAV vérifiés. L’utilisateur confirme les corrections graphiques et les commandes. Le rappel sonore des anciens projets Logic et des sons sauvegardés dans Live est confirmé depuis les étapes précédentes. [Preuve CP025](evidence/mac-cp025-installed-controls.json).

**CP026 ajoute les croix X/Y Main/Filter, la forme d’onde du Loop Sampler, les valeurs Voices/Precision/Auto Bend et les commandes Filter dont Cutoff/Resonance.** Les calculs de tracé et les getters/setters originaux sont exécutés dans le moteur statiquement traduit. La comparaison avec les instructions i386 et l’exécution ARM64/QEMU passent ; six binaires Mac sont liés strictement en ARM64. **Cocoa, auval et les rendus audio CP026 restent à exécuter sur le Mac.** Voir [CP026](docs/CP026.md), [comparaisons originales](evidence/editor-controls-cp026.json) et [vérifications de développement](evidence/cp026-development-checks.json).

Les carrés sont des commandes X/Y. Le tracé de sample apparaît pour le Loop Sampler avec sample chargé. Le navigateur/trim, les zones et boucles détaillées Loop, les enveloppes graphiques, les effets et la modulation restent à compléter. [Suite](docs/SUITE.md).

## Installer et tester

[Télécharger le lanceur CP026](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/9475b87d6a76e66176df221e6809084e81d57465/Demarrer-Sophistry-CP026.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP026.command"
```

Le lanceur télécharge [l’archive immuable](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/259682fd602ee76ae4455a7468892ec002aa84df), vérifie son SHA-256 et la décompacte. Le script compile, teste, valide auval, sauvegarde l’ancien composant et le remplace dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`, avec restauration en cas d’échec. Licence et banque valides sont réutilisées. Les droits administrateur servent au remplacement système.

Attendre **« Installation CP026 confirmée »** et vérifier **SophistryARM CP-026** en bas de l’éditeur. Sur une copie de projet, vérifier les trois champs Main, déplacer les carrés X/Y, tourner Cutoff/Resonance dans Filter et ouvrir un preset Loop avec sample chargé. Écouter, sauvegarder et réouvrir dans Logic/Live. Le ZIP CP026 automatique contient les nouveaux tests et les captures Filter/Loop, en plus des contrôles audio précédents ; transmettre ce rapport.

Pour changer de banque : `bash "$HOME/Downloads/Demarrer-Sophistry-CP026.command" --choose-bank`. `--diagnose-only` et `--recenter-windows` restent disponibles sans installation.

## Compatibilité et reprise

L’identité `aumu / Sop3 / LinP`, le bundle `com.linplug.au.Sophistry`, les 522 paramètres, la version AU 3.0.8 et les formats de chunks sont conservés. Le build est `26001`. Les essais reçus et les états exacts ne certifient pas tous les projets ou toute la fidélité sonore.

Sources/tests/preuves : branche `codex/sophistry-native-checkpoints`. [REPRISE.md](REPRISE.md) conserve l’état et les suites ; les archives et lanceurs vérifiés sont décrits dans `checkpoints/`. Préférences privées, licence et rapports Mac bruts restent exclus de Git.
