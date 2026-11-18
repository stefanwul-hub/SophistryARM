# Sophistry — checkpoint CP033

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8 à partir du code machine i386 fourni.

**CP033 réduit le coût du stockage intermédiaire du moteur traduit.** Le prototype passe les références DSP sélectionnées avec environ 45 % de temps en moins sous Linux, sans écart de sortie ou d’état. Le gain dans Live et Logic reste à mesurer sur votre Mac. Les 191379 instructions originales identifiées sont conservées. [Détails CP033](docs/CP033.md).

## Télécharger et installer sur votre Mac

[Télécharger le lanceur CP033](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP033.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP033.command"
```

Le lanceur télécharge l’archive immuable CP033 (lien après publication), vérifie son SHA-256, la décompacte, compile en ARM64 puis exécute les tests audio et auval sur votre Mac. Il remplace `/Library/Audio/Plug-Ins/Components/Sophistry.component` après les prévalidations et restaure l’ancien composant si une validation échoue. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP033 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-033)** en bas à gauche. Le ZIP de rapports CP033 est créé automatiquement. Les options `--choose-bank`, `--diagnose-only` et `--recenter-windows` restent disponibles.

## Mesure CPU et portée des tests

Si CP032 est installé, le script compare avant remplacement les deux composants dans des processus séparés : cinq passages chacun, même son public et même note, 44100 Hz/256 samples. Il vérifie un audio identique et écrit `cpu-comparison.json` dans le rapport. La mesure porte sur le thread de rendu ; elle ne constitue pas une comparaison avec CronoX.

Les huit tests de preuve des temporaires et les six cas de conservation d’état lors d’arrêts/erreurs passent localement. Le prototype DSP a passé les références originales sélectionnées. **La compilation ARM64 complète, auval et le rendu musical CP033 seront validés sur votre Mac, comme aux checkpoints précédents.** Aucun runner GitHub n’est requis.

CP032 est confirmé fonctionnel sur le Mac de l’utilisateur. Identité AU `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`, 522 paramètres, chunks et version AU 3.0.8 sont conservés ; build 33001. L’identité sonore de tous les presets et la parité CPU avec CronoX restent à vérifier.

[Couverture du code original](evidence/cp032-original-code-coverage.json) · [Mesure du prototype CP033](evidence/cp033-cpu-prototype.json) · [Rapport Mac CP032 filtré](evidence/mac-cp032-installed.json) · [Reprise](REPRISE.md).
