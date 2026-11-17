# Sophistry — checkpoint CP029

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8. Le composant original i386/PPC est traduit statiquement en C++ ; la couverture de tous les chemins DSP reste à démontrer.

**CP029 retire le panneau « Commandes du son » et ses sliders en double.** L’éditeur revient à 762 points de large, avec les sept pages originales et les utilitaires nécessaires. Les noms de samples sont affichés sans leurs anciens chemins Windows. Les quatre commandes Full Loop rejoignent les menus Time Sampler. [Fonctions et limites restantes](docs/CP029.md).

L’utilisateur confirme que CP028 compile et que les commandes essayées fonctionnent. **CP029 reste à valider dans Cocoa et auval sur Mac.** Le moteur, les anciens états et les paramètres AU sont conservés. Les essais de charge ont été annulés à la demande de l’utilisateur.

## Télécharger et installer

[Télécharger le lanceur CP029](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP029.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP029.command"
```

Le lanceur télécharge [l’archive immuable CP029](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/19b3bdea246534ba0b902d3435b48f5deb6bc9d0), vérifie son SHA-256, la décompacte puis exécute la compilation ARM64, les tests, auval et le remplacement sauvegardé dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. En cas d’échec, il restaure le composant précédent. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP029 confirmée**, puis vérifier **SophistryARM CP-029** dans l’éditeur. Parcourir les sept pages et **Clavier / MIDI…**, essayer les repères Loop et les menus de modules, puis sauvegarder/réouvrir des copies de projets Logic et Live. Le ZIP CP029 est créé automatiquement, y compris en cas d’échec.

Pour changer de banque : ajouter `--choose-bank`. Les options `--diagnose-only` et `--recenter-windows` restent disponibles.

## Compatibilité et reprise

Identité `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`, 522 paramètres, version AU 3.0.8 et chunks conservés ; build `29001`. La sauvegarde générale reste `.aupreset`, les modules utilisent leur format original `.MOD`.

[Comparaisons originales précédentes](evidence/complete-editor-cp028.json) · [Vérifications CP029](evidence/cp029-development-checks.json) · [Reprise](REPRISE.md). Les sources et checkpoints sont publiés sur `codex/sophistry-native-checkpoints`. Préférences, licence et rapports Mac bruts restent privés.
