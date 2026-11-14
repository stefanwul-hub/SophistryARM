# Sophistry — checkpoint CP-011

**Le plugin Audio Unit ARM64 complet n’est pas encore obtenu. Ce paquet contient le travail de portage et ses preuves ; il ne doit pas remplacer l’ancien `.component`.**

Le binaire fourni est Sophistry 3.0.8 **i386 32 bits + PowerPC**, sans tranche x86-64. L’identité à conserver pour les anciens projets AU est `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`.

**Nouveau à CP-011 :** l’hôte d’exécution est porté en C++ autonome. Avec les 191378 instructions statiquement traduites, il charge et resauvegarde les deux états fournis, avec des régions mémoire identiques à la référence i386 sous Linux natif et ARM64/Linux/QEMU. Les méthodes de l’ancien AU exposent 522 paramètres et 56 alias de validation, sauvegardés pour l’intégration. Le rendu sans enregistrement reste sous −100 dBFS et demeure en échec. **Aucun preset sonore complet ni AU installable n’est validé.**

Lire [le rapport CP-011](docs/CP011.md) pour le test Mac avec saisie locale de la licence, les preuves et les limites. [CP-010](docs/CP010.md) et [CP-009](docs/CP009.md) sont conservés comme historique. Le nouvel hôte C++ n’a pas encore été compilé/exécuté sous macOS ; les résultats reçus du Mac concernent CP-008.

## Travail effectué

- Archive originale épinglée, 106 images d’interface conservées, projet Ghidra enregistré et 3 249 fonctions détectées exportées en pseudo-code. Le pseudo-code comporte des avertissements et ne se compile pas directement.
- Paire réelle `.fxp` / `.aupreset` analysée, schémas de 51 classes de paramètres récupérés, lecteur structurel C++ des chunks avec réécriture sans changement des octets. Le chargement sémantique complet dans un synthétiseur reste à développer.
- Sample `BT_cronox18.wav` conservé : PCM16 stéréo, 44,1 kHz, 334 664 frames.
- **Lifter statique expérimental** : 3 242 instructions originales de 19 fonctions sont traduites à partir du p-code brut Ghidra en opérations et branchements C++ fixes. Le runtime ne décode pas les octets x86. Il maintient explicitement les registres et adresses 32 bits de ces fonctions.
- Périmètre traduit/testé : saturation, dispatch et huit chemins de filtre `FilterMoogSI`, mélange mono du sample, normalisation, construction des 64 tables Schrader et lecteur de ces tables. Les fonctions non sélectionnées ne sont pas portées par ce résultat.
- **704 cas différentiels** : 5 420 672 octets de sorties et d’état interne comparés au code i386 exécuté sous Unicorn, sans différence. Les fonctions hôtes mathématiques sont partagées pour isoler les instructions DSP.
- La même référence passe en code **ARM64/Linux sous QEMU**, puis **nativement sur le Mac ARM64 de l’utilisateur sous macOS 15.7.2** : le journal reçu confirme les 704 cas et 5 420 672 octets sans différence avec les réponses mathématiques enregistrées. Les 161 cas du saturateur et les deux tests structurels des états passent également. Preuve structurée : `evidence/mac-cp008-native-replay.json`.
- Les conversions de stockage x87 80 bits / IEEE 32 et 64 bits ont passé 20 000 cas canoniques finis contre le type étendu natif Intel, en arrondi au plus proche pair. L’arithmétique x87 générale reste hors du périmètre du lifter.

## Sondes audio

`evidence/audio/schrader-root60-original-instructions.wav` et `schrader-root60-lifted-cpp.wav` sont deux rendus mono de trois secondes à 44,1 kHz du **générateur Schrader isolé**, à partir du sample fourni. Leurs valeurs sont identiques et leur erreur maximale/RMSE sont nulles. Les contrôles sont explicitement fixés dans le test ; aucun rendu complet du preset Lightgarden n’est revendiqué.

Les fichiers `satur-*.wav` testent uniquement la saturation.

## Limites mathématiques constatées

Le replay principal réinjecte les réponses `log10` et `pow` enregistrées avec la référence pour tester la traduction des instructions. Le replay avec les bibliothèques mathématiques natives passe sous Linux x86_64. Avec le `libm` ARM64/Linux musl sous QEMU, **sept octets d’état interne diffèrent**, sans différence des buffers de sortie observés sur ces cas. Ce mode est donc signalé en échec strict. Le `libm` Apple d’origine et celui du Mac utilisateur restent à comparer ; ne pas déduire une fidélité globale de ces seuls tests.

Les rapports détaillés reçus confirment aussi **sept octets d’état interne différents et zéro octet différent dans les buffers audio comparés** sur le Mac ARM64, avec le même détail d’adresses et de valeurs que sous Linux/musl. Ils concernent les cas de filtre stéréo 117 et 123. Le replay avec les réponses mathématiques enregistrées passe ; la variation apparaît dans le mode séparé utilisant les fonctions mathématiques de la plateforme. La comparaison stricte reste en échec, car les états différents peuvent influer sur la suite. L’ancien libm Apple i386 n’est pas exécuté : les fixtures mathématiques Linux ne sont pas présentées comme une preuve de ses résultats. Voir `evidence/mac-cp008-native-math-details.json`.

`auval` a renvoyé 2 avec « didn't find the component » pour `aumu/Sop3/LinP`. Aucun nouveau composant n’a été construit ou validé.

Le PCM du WAV est décodé selon la convention PCM16 standard pour les tests. Le loader original utilise AudioConverter ; cet appel Apple n’a pas été exécuté ici. L’adaptateur `free` des tests ne libère rien, car les buffers sont possédés par l’hôte de test. Ce n’est pas encore l’allocateur d’un moteur complet.

## Exécuter les vérifications sur votre Mac

**Correctif 1 du vérificateur Mac** : les quatre appels `lipo` sont corrigés, avec le fichier avant `-verify_arch arm64`. Le second journal reçu confirme la compilation et les replays sur Mac ARM64. Le lanceur actualisé télécharge les sources corrigées s’il se trouve dans une ancienne copie CP-008. Ce correctif ne change aucun calcul DSP.

Avec Xcode installé :

```sh
bash "/chemin/vers/Sophistry-CP008/Verifier-Mac.command"
```

Le script compile les probes **en ARM64**, vérifie les en-têtes d’architecture, rejoue les références, compare séparément les maths natives et compile l’hôte de diagnostic AU. Il lance aussi `auval -v aumu Sop3 LinP` sur l’instrument déjà enregistré. Un échec est attendu si seul l’ancien composant i386/PPC est présent. Les résultats sont conservés dans `work/mac-<date>/`.

Il n’installe aucun composant. `Installer-ARM64.command` refuse explicitement le remplacement : le moteur complet, la restauration sémantique des projets et l’AU natif sont absents. Aucun test dans Logic ou Live n’a été effectué.

Pour transmettre les détails d’un test déjà terminé, télécharger `Recuperer-Rapports-Mac.command` puis le lancer avec `bash`. Il sélectionne le dernier journal Sophistry sous son dossier ou `~/Downloads`, rassemble uniquement les neuf noms de rapports prévus dans une archive ZIP et affiche l’archive dans Finder. Il ne télécharge, ne recompile et n’installe rien. Un chemin vers le dossier de rapports ou vers son `diagnostic.log` peut être fourni en premier argument.

Le probe natif n’exige ni Ghidra, ni Python, ni Unicorn pour rejouer les références. La tranche originale i386 est lue comme **données de référence et constantes**, pas exécutée par un émulateur sur le Mac. La génération et les nouvelles comparaisons contre i386 utilisent les outils d’analyse décrits ci-dessous.

## Reproduire les tests sous Linux

```sh
python3 -m venv work/venv
work/venv/bin/pip install -r requirements-analysis.txt
bash scripts/build-lifter.sh
work/venv/bin/python tests/compare_lifted_dsp.py work/lifter/liblift.so --output work/static-lift-comparison.json
work/lifter/LiftedProbe reference/Sophistry.i386 evidence/static-lift-comparison.fixtures
python3 -m unittest discover -s tests -p 'test_*.py' -v
```

Le probe autonome utilise le format de fixtures `SLFT0003`. `--native-math` teste le libm de l’hôte au lieu des réponses enregistrées et peut mettre en évidence les différences décrites ci-dessus.

## Reprendre le travail

| Chemin | Contenu |
|---|---|
| `REPRISE.md` | Dernière étape, faits vérifiés, suites et limites |
| `port-status.json` | État des fonctionnalités, dont celles non réalisées |
| `checkpoints/Sophistry-history.bundle` (archives locales) | Historique autonome ; sur GitHub, utiliser l’historique de la branche |
| `checkpoints/ghidra-project/` | Projet Ghidra 11.3.2 complet avec son `.rep` |
| `analysis/ghidra/` | Décompilation initiale et graphe d’appels reconnus |
| `analysis/lifter-all/` | P-code brut sélectionné et provenance |
| `src/lifter/` | Générateur de code déjà exécuté : C++ émis et runtime |
| `scripts/lift_pcode_cpp.py` | Émetteur C++ à partir du p-code brut |
| `tests/compare_lifted_dsp.py` | Oracle i386 et comparaison différentielle |
| `tests/LiftedProbeMain.cpp` | Replay autonome pour Linux/Mac/ARM64 |
| `reference/` | Original, presets réels et sample conservés |
| `evidence/` | Rapports, fixtures, objets ARM64 et sondes audio |
| `docs/STATIC-LIFT.md` | Périmètre et limites de la traduction statique |
| `docs/PRESETS-CP004.md` | Structure commune des états CronoX/Sophistry |
| `docs/Interface.html` | Visionneuse des images originales ; aucune commande audio |

Le dossier `work/` contient les nouvelles compilations et sorties de test et n’est pas distribué. Les archives de checkpoints précédentes restent conservées dans l’environnement de travail. Les sources et les huit checkpoints sont maintenant publiés sur la branche `codex/sophistry-native-checkpoints` du dépôt utilisateur. L’archive GitHub a été téléchargée et chaque fichier vérifié contre son objet Git. `main` reste inchangée. Le transfert Git classique fonctionne ; ne pas utiliser l’envoi monolithique base64 qui avait bloqué l’outil. Les archives GitHub n’incluent pas le `.bundle` ignoré : pour récupérer l’historique, cloner la branche.

## Copie distante et historique

```sh
git clone --branch codex/sophistry-native-checkpoints https://github.com/stefanwul-hub/SophistryARM.git Sophistry-reprise
```

L’archive ZIP contient le projet Ghidra enregistré et tous les fichiers suivis du checkpoint ; le clone Git récupère aussi les versions précédentes.

## Téléchargement automatique du checkpoint

`Demarrer-Sophistry-CP008.command`, téléchargé seul, récupère l’archive de code CP-008 figée au commit vérifié, contrôle son SHA-256, la décompacte puis lance la compilation et les tests sur Mac. Dans un dossier de sources déjà extrait, il lance directement `Verifier-Mac.command`. Il ne prétend pas compiler le synthétiseur complet et n’installe aucun composant.

Le fichier `checkpoints/CP008-correctif1-publication.json` consigne l’URL de l’archive corrigée réellement téléchargée et vérifiée, sa taille, son empreinte et le commit source. `CP008-publication.json` conserve la provenance de la distribution précédente.
