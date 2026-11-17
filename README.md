# Sophistry — checkpoint CP027

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8. Le composant original i386/PPC fourni est traduit statiquement en C++ ; aucun décodeur x86 ne tourne dans le plugin. La couverture de tous les chemins DSP reste à démontrer.

**CP027 implémente les pages restantes à partir des constructeurs originaux** : effets, modulation, enveloppes ADSFR, détails Loop, séquenceur, clavier, sorties et menus de modules. Le relevé contient 86 panneaux et 1 067 définitions visuelles. Les fonctions de conversion, de commande et de sérialisation sont celles du moteur original. [Détails et limites](docs/CP027.md).

Les comparaisons originales et ARM64/QEMU passent, ainsi que les liens stricts de sept binaires Mac. **L’exécution Cocoa, auval et audio CP027 reste à effectuer sur votre Mac.** Les dernières validations Mac reçues sont celles de CP025 ; les chargements successifs et noms sauvegardés dans Logic/Live avaient déjà été confirmés.

## Télécharger et installer

[Télécharger le lanceur CP027](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP027.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP027.command"
```

Le lanceur télécharge une archive immuable, vérifie son SHA-256, la décompacte puis exécute la compilation ARM64, les tests, auval et le remplacement sauvegardé dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. En cas d’échec, il restaure le composant précédent. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP027 confirmée**, puis vérifier **SophistryARM CP-027** dans l’éditeur. Parcourir les sept pages et **Clavier / MIDI…**, essayer les repères Loop et les menus de modules, puis sauvegarder/réouvrir des copies de projets Logic et Live. Le ZIP CP027 est créé automatiquement, y compris en cas d’échec.

Pour changer de banque : ajouter `--choose-bank`. Les options `--diagnose-only` et `--recenter-windows` restent disponibles.

## Compatibilité et reprise

Identité `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`, 522 paramètres, version AU 3.0.8 et chunks conservés ; build `27001`. La sauvegarde générale reste `.aupreset`, les modules utilisent leur format original `.MOD`.

[Comparaisons originales](evidence/complete-editor-cp027.json) · [Vérifications](evidence/cp027-development-checks.json) · [Reprise](REPRISE.md). Les sources et checkpoints sont publiés sur `codex/sophistry-native-checkpoints`. Préférences, licence et rapports Mac bruts restent privés.
