# Sophistry — checkpoint CP028

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8. Le composant original i386/PPC fourni est traduit statiquement en C++ ; aucun décodeur x86 ne tourne dans le plugin. La couverture de tous les chemins DSP reste à démontrer.

**CP028 corrige l’échec de prévalidation CP027** : sélection des générateurs selon le mode affiché, menus de modules et dimensions des images Cocoa. Les sept pages récupérées depuis les constructeurs originaux sont conservées. [Détails et limites](docs/CP028.md).

Les 50 transitions entre modes et leurs états sont comparés aux instructions originales et en ARM64/QEMU. Sept binaires Mac sont liés strictement en ARM64. **L’exécution Cocoa, auval et audio CP028 reste à effectuer sur votre Mac.** Le rapport CP027 confirme des rendus audio exacts, puis un arrêt avant remplacement ; le composant précédent a été conservé. [Rapport filtré](evidence/mac-cp027-prevalidation.json).

## Télécharger et installer

[Télécharger le lanceur CP028](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP028.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP028.command"
```

Le lanceur télécharge [l’archive immuable CP028](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/8f5a7b879edc436173c0304f29f37849ef0f427d), vérifie son SHA-256, la décompacte puis exécute la compilation ARM64, les tests, auval et le remplacement sauvegardé dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. En cas d’échec, il restaure le composant précédent. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP028 confirmée**, puis vérifier **SophistryARM CP-028** dans l’éditeur. Parcourir les sept pages et **Clavier / MIDI…**, essayer les repères Loop et les menus de modules, puis sauvegarder/réouvrir des copies de projets Logic et Live. Le ZIP CP028 est créé automatiquement, y compris en cas d’échec.

Pour changer de banque : ajouter `--choose-bank`. Les options `--diagnose-only` et `--recenter-windows` restent disponibles.

## Compatibilité et reprise

Identité `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`, 522 paramètres, version AU 3.0.8 et chunks conservés ; build `28001`. La sauvegarde générale reste `.aupreset`, les modules utilisent leur format original `.MOD`.

[Comparaisons originales](evidence/complete-editor-cp028.json) · [Vérifications](evidence/cp028-development-checks.json) · [Reprise](REPRISE.md). Les sources et checkpoints sont publiés sur `codex/sophistry-native-checkpoints`. Préférences, licence et rapports Mac bruts restent privés.
