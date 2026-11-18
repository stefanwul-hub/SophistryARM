# Sophistry — checkpoint CP031

Audio Unit ARM64 expérimental pour rouvrir les projets Sophistry 3.0.8. Le composant i386/PPC fourni est traduit statiquement en C++ ; une reproduction intégrale et la couverture de tous les chemins DSP ne sont pas certifiées.

CP030 a supprimé les craquements de Gen1+2 selon le retour de l’utilisateur. **CP031 reproduit un réglage flottant du rendu original qui manquait sur le processeur natif**, et ajoute des vérifications du Master. Le facteur quatre de CPU et l’écart de niveau signalés face à CronoX 3 restent à expliquer complètement. Aucun gain de compensation n’est ajouté. [Enquête, correction et limites](docs/CP031.md).

## Télécharger et installer

[Télécharger le lanceur CP031](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/e3a0c5c8921b1c3304c3f0b6721f177140c1163e/Demarrer-Sophistry-CP031.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP031.command"
```

Le lanceur télécharge [l’archive immuable CP031](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/eeca148326f7d96d1059d37d0a264d50b194344e), vérifie son SHA-256, la décompacte, compile en ARM64, exécute les tests et auval puis remplace `/Library/Audio/Plug-Ins/Components/Sophistry.component`. L’ancien composant est restauré si une validation échoue. Licence et banque valides restent enregistrées localement.

Attendre **Installation CP031 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-031)** en bas à gauche. Le ZIP de rapports CP031 est créé automatiquement. Pour l’enquête CPU/niveau, copier le diagnostic après lecture du preset concerné : il contient le Master réel et indique si l’hôte utilisait déjà le mode flottant corrigé. Le scénario DX Bass avec release extrême reste exclu.

Les options `--choose-bank`, `--diagnose-only` et `--recenter-windows` restent disponibles. Les sept pages originales, tirettes corrigées et textes blancs de CP030 sont conservés ; le navigateur de sliders en double reste supprimé.

## État des vérifications

Les nouveaux tests passent sur Linux et ARM64/QEMU ; les binaires Mac modifiés sont liés strictement en ARM64. **CP031 reste à exécuter dans macOS, auval, Logic et Live.** Les comparaisons existantes portent sur l’original Sophistry fourni ; le binaire CronoX de l’utilisateur n’a pas été comparé ici.

Identité `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`, 522 paramètres, chunks et version AU3.0.8 conservés ; build31001. Sauvegarde générale `.aupreset`, modules `.MOD`, import FXP disponibles.

[Vérifications CP031](evidence/cp031-development-checks.json) · [Audit de reproduction](evidence/cp031-reproduction-audit.json) · [Mesures expérimentales et limites](evidence/cp031-cpu-investigation.json) · [Reprise](REPRISE.md). Publication sur `codex/sophistry-native-checkpoints` ; préférences, licence, chemins privés et rapports Mac bruts restent hors Git.
