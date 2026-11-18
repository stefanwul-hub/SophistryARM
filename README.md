# Sophistry — CP033 en validation

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8 à partir du code machine i386 fourni.

**CP033 optimise le stockage intermédiaire de la traduction complète.** Les instructions originales restent dans le C++ de référence ; un passage vérifié prépare des variables locales avant compilation. Le prototype améliore les routines DSP sélectionnées sans écart de sortie ou d’état. La validation native ARM64 est en cours. [Détails et limites CP033](docs/CP033.md).

CP032 est confirmé fonctionnel sur le Mac de l’utilisateur ; son coût CPU reste élevé. Le téléchargement ci-dessous reste celui de CP032 pendant la préparation du paquet CP033.

## Télécharger et installer

[Télécharger le lanceur CP032](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/bbac4a3781b090fb20b76fcb00eae999ea06c378/Demarrer-Sophistry-CP032.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP032.command"
```

Le lanceur télécharge [l’archive immuable CP032](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/6859eaa4b3513b384ecab6bc6e5501174977dfb8), vérifie son SHA-256, la décompacte, compile en ARM64, exécute les tests et auval puis remplace `/Library/Audio/Plug-Ins/Components/Sophistry.component`. L’ancien composant est restauré si une validation échoue. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP032 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-032)** en bas à gauche. Le ZIP de rapports CP032 est créé automatiquement, y compris en cas d’échec. Les options `--choose-bank`, `--diagnose-only` et `--recenter-windows` restent disponibles.

## Vérifications et limites

Les1351nouveaux cas de code original, les références d’instructions et DSP précédentes, l’intégration AU et l’éditeur passent localement et sous ARM64/QEMU selon leur périmètre. Les binaires Mac sont liés strictement en ARM64. **CP032 est confirmé sur le Mac de l’utilisateur ; CP033 reste en validation.** La couverture du code identifié ne constitue pas une validation de tous les presets et comportements possibles.

Identité `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`,522 paramètres, chunks et version AU 3.0.8 conservés ; build 32001. Les fonctions d’interface déjà disponibles et la sauvegarde `.aupreset`/modules`.MOD` restent en place.

[Couverture du code original](evidence/cp032-original-code-coverage.json) · [Vérifications CP032](evidence/cp032-development-checks.json) · [Rapport Mac CP031 filtré](evidence/mac-cp031-installed.json) · [Reprise](REPRISE.md). Publication sur `codex/sophistry-native-checkpoints` ; préférences, licence, chemins privés et rapports bruts restent hors Git.
