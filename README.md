# Sophistry — checkpoint CP-022

**CP021 charge les sons dans les anciens projets Logic et les sons sauvegardés dans Live.** Le rapport Mac confirme aussi auval, l’oracle Core Audio et les douze WAV de référence. Voir [la preuve vérifiée](evidence/mac-cp021-installed-audio.json).

**CP022 corrige la gestion de la mémoire des samples et la conservation du nom du preset.** Le diagnostic reçu montre `std::bad_alloc` près de la limite mémoire CP021 ; les fichiers sont trouvés et convertis. Le nouvel allocateur regroupe et découpe les blocs libérés, et l’arène de production passe de 256 Mio à 1 Gio avec initialisation à zéro sans remplissage explicite de toute la réserve. Le nom est enregistré dans l’état AU et rétabli dans une instance neuve, même si l’hôte fournit « Default ». Voir [CP022](docs/CP022.md) et [le diagnostic filtré](evidence/mac-cp021-memory-load-error.json).

Les 96 chargements sur douze formats, les tests de mémoire et les régressions passent en Linux et ARM64/Linux/QEMU. Les binaires Mac se compilent en ARM64. **L’exécution CP022 sur macOS reste à vérifier**, notamment le gros preset concerné et le nom dans Live. La finalisation graphique reste inscrite dans [la suite](docs/SUITE.md).

Le lanceur CP022 sera épinglé à l’archive vérifiée lors de sa publication. Fermer Logic/Live et lancer `bash "$HOME/Downloads/Demarrer-Sophistry-CP022.command"`. Licence et banque valides sont réutilisées. Attendre **« Installation CP022 confirmée »**, tester une copie du projet, les changements successifs de son et une nouvelle sauvegarde Live, puis transmettre le ZIP CP022. Un ancien état dont le nom a déjà été perdu nécessite le rechargement du FXP d’origine pour retrouver ce nom.

## Historique des checkpoints précédents

**Le premier candidat Audio Unit ARM64 a maintenant été compilé, signé et exécuté sur le Mac utilisateur.** Le rapport CP-013 confirme le chargement de la factory, les 522 métadonnées et deux rendus AU musicaux byte-exact contre les instructions originales. Cette étape historique précédait auval, réussi depuis dans CP-016 ; l’interface fidèle et le rappel sonore des projets restent à terminer.

Le binaire fourni est Sophistry 3.0.8 **i386 32 bits + PowerPC**, sans tranche x86-64. L’identité à conserver pour les anciens projets AU est `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`.

**CP-016 : correctifs du rapport Mac CP-015.** La licence a bien été enregistrée et relue ; CP-015 l’a ensuite annulée en restaurant les préférences après l’échec d’auval. CP-016 conserve les réglages dès leur validation dans un nouveau processus. Il corrige aussi la propriété valeur/texte de 99 paramètres et la limite interrompant l’initialisation à 192 kHz. Les 596 cas de texte correspondent aux routines originales. Voir [CP-016](docs/CP016.md) et [le rapport Mac CP-015 anonymisé](evidence/mac-cp015-installation.json). Ces correctifs ont passé auval sur le Mac dans le rapport CP-016. Les projets Logic s’ouvrent mais restent silencieux ; le rappel Live n’est pas vérifié.

[Télécharger le lanceur CP-016](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/3b81d8b39548536d1f8511e473fae3f8ee7dc141/Demarrer-Sophistry-CP016.command), puis lancer `bash "$HOME/Downloads/Demarrer-Sophistry-CP016.command"`, sans sudo. Le lanceur vérifie l’archive épinglée ; les droits sont demandés au remplacement du composant.

**CP-014 : rapport Mac CP-013 vérifié.** Les WAV du candidat, du moteur AU direct et de la référence i386 sont identiques pour chaque configuration 2/6 canaux : 264600 et 793800 échantillons float32, tous finis. La licence est acceptée localement. Trois secondes de son sont calculées en environ 0,60 s ; ce test hors temps réel ne certifie pas une charge de projet. Voir [la preuve anonymisée](evidence/mac-cp013-au-factory.json). Aucun composant n’a encore été installé par le script CP-013.

**CP-013 : premier candidat AU.** Le constructeur et le contrat AU originaux sont récupérés (un bus 2/6 canaux, 522 paramètres). Les chemins MIDI, rendu, reset et réinitialisation sont intégrés. Les tests du pont passent sous Linux natif et ARM64/Linux/QEMU ; le candidat Mach-O ARM64 et sa factory sont liés. Le [test Mac CP-013](docs/CP013.md) compile localement le `.component`, teste sa factory sans installation et compare ses WAV au moteur direct et aux instructions AU originales, avec la licence saisie uniquement sur le Mac. Le [lanceur CP-013](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/480349830f8c5ab65e4d169bde6a05780ff67caa/Demarrer-Sophistry-CP013.command) télécharge l’archive épinglée dont les 4007 fichiers ont été vérifiés.

**CP-012 : premier rendu du preset complet vérifié sur le Mac utilisateur.** Le code C++ statiquement traduit compile et s’exécute en ARM64 sur macOS 15.7.2 avec la licence saisie localement. Le FXP Lightgarden fourni produit un WAV de trois secondes identique aux instructions i386 originales exécutées dans l’hôte de référence : 793800 valeurs float32, aucun octet différent. Les 704 cas DSP, 11635 cas d’instructions/gardes et les deux sérialisations passent aussi. Ce résultat valide ce scénario ; l’Audio Unit installable et le rappel des anciens projets restent à terminer.

Lire [le rapport CP-011](docs/CP011.md) pour le test Mac avec saisie locale de la licence, les preuves et les limites. [CP-010](docs/CP010.md) et [CP-009](docs/CP009.md) sont conservés comme historique. Le nouvel hôte C++ est maintenant compilé et exécuté sur le Mac ; voir [la preuve CP-012](evidence/mac-cp011-licensed-render.json). Les autres résultats historiques restent datés.

Le [lanceur CP-011](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP011.command) télécharge une archive épinglée, contrôle son SHA-256, la décompacte et appelle `Verifier-Moteur-Mac.command`. Il conserve les sources et builds dans `~/Documents/SophistryARM-CP011`. La licence se saisit localement dans le Terminal ; ne pas l’envoyer dans le chat ou sur GitHub. Le candidat CP-013 se teste maintenant avec `Verifier-AU-Mac.command` ; l’installation système reste bloquée.

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

`auval` a renvoyé 2 avec « didn't find the component » pour `aumu/Sop3/LinP`. Ce résultat historique CP-008 précède les essais du candidat. Le rapport CP-015 contient le premier auval du nouveau composant enregistré : il échoue sur la propriété 33 et l’initialisation à 192 kHz ; voir CP-016.

Le PCM du WAV est décodé selon la convention PCM16 standard pour les tests. Le loader original utilise AudioConverter ; cet appel Apple n’a pas été exécuté ici. L’adaptateur `free` des tests ne libère rien, car les buffers sont possédés par l’hôte de test. Ce n’est pas encore l’allocateur d’un moteur complet.

## Exécuter les vérifications sur votre Mac

**Correctif 1 du vérificateur Mac** : les quatre appels `lipo` sont corrigés, avec le fichier avant `-verify_arch arm64`. Le second journal reçu confirme la compilation et les replays sur Mac ARM64. Le lanceur actualisé télécharge les sources corrigées s’il se trouve dans une ancienne copie CP-008. Ce correctif ne change aucun calcul DSP.

Avec Xcode installé :

```sh
bash "/chemin/vers/Sophistry-CP008/Verifier-Mac.command"
```

Le script compile les probes **en ARM64**, vérifie les en-têtes d’architecture, rejoue les références, compare séparément les maths natives et compile l’hôte de diagnostic AU. Il lance aussi `auval -v aumu Sop3 LinP` sur l’instrument déjà enregistré. Un échec est attendu si seul l’ancien composant i386/PPC est présent. Les résultats sont conservés dans `work/mac-<date>/`.

Les anciens vérificateurs n’installent aucun composant. Pour le candidat CP-013, utiliser `Verifier-AU-Mac.command`. `Installer-ARM64.command` réalise maintenant une installation expérimentale avec sauvegarde et restauration automatique sur échec, après les prévalidations. Le rappel des projets reste à tester sur des copies.

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
