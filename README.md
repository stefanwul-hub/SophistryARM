# Sophistry — checkpoint CP030

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8. Le composant original i386/PPC est traduit statiquement en C++ ; la couverture de tous les chemins DSP reste à démontrer.

**CP030 corrige le sens des tirettes, améliore le partage du moteur entre l’interface et l’audio et rend le nom du preset et Prev / Load / Next / Save blancs.** Le pied de page affiche **Sophistry ARM64 port OA 2026 (CP-030)**. La forme d’onde Loop est préparée au chargement du preset ; les widgets inchangés ne sont plus redessinés à chaque rafraîchissement. Deux conversions numériques courantes sont accélérées sans écart dans les fixtures vérifiées. [Détails, mesures et limites](docs/CP030.md).

Le rapport reçu confirme l’installation, auval et les comparaisons audio de CP029. **CP030 est compilé et lié en ARM64 ici ; son exécution Cocoa, audio et auval reste à faire sur Mac.** La disparition des craquements dans Live et la réduction réelle du CPU restent à confirmer. La parité CPU avec CronoX 3 n’est pas annoncée.

## Télécharger et installer

[Télécharger le lanceur CP030](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP030.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP030.command"
```

Le lanceur télécharge [l’archive immuable CP030](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/8d20e5950eb1dac53b1b606d11d0d1fa962b49e1), vérifie son SHA-256, la décompacte puis exécute la compilation ARM64, les tests, auval et le remplacement sauvegardé dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. En cas d’échec, il restaure le composant précédent. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP030 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-030)** en bas à gauche. Écouter le même preset avec Main puis Gen1+2 et vérifier les enveloppes et les textes blancs. Un bref essai automatique compare également l’audio Main/Gen1+2. Le test extrême DX Bass annulé précédemment reste exclu. Le ZIP de rapports CP030 est créé automatiquement, y compris en cas d’échec.

Pour changer de banque : ajouter `--choose-bank`. Les options `--diagnose-only` et `--recenter-windows` restent disponibles.

## Compatibilité et reprise

Identité `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`, 522 paramètres, version AU 3.0.8 et chunks conservés ; build `30001`. Les valeurs des enveloppes enregistrées dans les projets ne sont pas inversées. Le navigateur de sliders en double retiré à CP029 reste absent ; les sept pages originales restent disponibles. La sauvegarde générale reste `.aupreset`, les modules utilisent leur format original `.MOD`.

[Comparaisons originales CP030](evidence/complete-editor-cp030.json) · [Vérifications CP030](evidence/cp030-development-checks.json) · [Rapport Mac CP029 filtré](evidence/mac-cp029-installed.json) · [Reprise](REPRISE.md). Les sources et checkpoints sont publiés sur `codex/sophistry-native-checkpoints`. Préférences, licence et rapports Mac bruts restent privés.
