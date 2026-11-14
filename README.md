# Sophistry — checkpoint CP-004

**Ce paquet ne contient pas de Sophistry Audio Unit ARM64 installable. Le portage complet demandé reste à réaliser.**

Il conserve le travail réellement effectué : audit du composant fourni, décompilation Ghidra des fonctions détectées, images originales, traduction C++ d’un seul noyau de saturation, tests différentiels et outils pour poursuivre sur Mac. Aucun synthétiseur de substitution n’est présenté comme l’original.

## Ajout CP-004 : paire de presets réelle

La paire fournie depuis `Presets/` est conservée avec ses empreintes. L’utilisateur confirme le format partagé entre Sophistry et CronoX 3. Le `.aupreset` porte l’identité CronoX `CrX3`, qui reste distincte de l’identité cible Sophistry `Sop3`.

Le lecteur de conteneur C++ reconstruit les deux chunks sans changer un octet (22 192 et 20 640 octets), en conservant les données inconnues. La récupération des descriptions de paramètres à partir du flux de contrôle i386 produit 51 schémas de classes et 3 437 entrées de champs (avec répétitions entre classes apparentées ; **ce ne sont pas des IDs AU**). Les schémas consomment intégralement 117 des 121 blocs AU et 116 des 118 blocs FXP. Les champs supplémentaires restent conservés et non interprétés.

La comparaison rapproche 115 blocs, 3 829 valeurs égales et 31 différentes. Certaines différences concernent les libellés de modulation, les états d’édition et le chemin de `BT_cronox18.wav`. La restauration sonore n’est pas prouvée par ce décodage. Voir `docs/PRESETS-CP004.md`.

## Résultats vérifiés

- Original : Sophistry 3.0.8, **PowerPC et Intel i386 32 bits**. Aucune tranche x86-64 ou ARM64.
- Identité AU : `aumu / Sop3 / LinP`, bundle `com.linplug.au.Sophistry`.
- Ghidra 11.3.2 : 3 249 fonctions détectées exportées en pseudo-code ; 161 tables de classes candidates. **207 avertissements de tables de sauts non reconstruites** subsistent. Ce pseudo-code ne se compile pas directement.
- 106 PNG de l’interface et 554 appels de construction de paramètres catalogués dans 47 classes. Les identifiants de paramètres AU et les actions de l’interface restent à reconstruire.
- Noyau isolé `Satur_c`, adresse i386 `0x73fb0` : 160 cas, 133 500 valeurs comparées aux instructions originales exécutées dans Unicorn, sans différence binaire. Un cas désactivé supplémentaire porte les fixtures natives à 161 cas et 133 502 valeurs.
- Deux WAV de régression du **seul noyau de saturation**, 48 kHz stéréo, une seconde : écart nul. Ils ne représentent pas un preset ni le son du synthétiseur complet.
- Ce noyau compile en objet Mach-O ARM64 ; l’objet n’est ni un exécutable ni un `.component`. L’exécution ARM64, la compilation des outils avec Xcode, `auval`, Logic et Live n’ont pas été testés ici (environnement Linux).

## Sur votre Mac

Lancez depuis Terminal :

```sh
bash "/chemin/vers/Sophistry-CP004/Verifier-Mac.command"
```

Ce script compile aussi le lecteur structurel d’états et vérifie les deux chunks réels. Ce script exige Xcode ou ses outils en ligne de commande. Il compile **les outils de test** en ARM64, exécute les fixtures du noyau, compile l’hôte de diagnostic AU et lance `auval -v aumu Sop3 LinP` sur le composant déjà enregistré. Il enregistre les résultats dans `work/mac-<date>/`. Il ne copie, ne remplace et ne supprime aucun composant. L’échec de `auval` est attendu si seul l’ancien i386/PPC est présent.

`Installer-ARM64.command` s’arrête avec le code 78 : le moteur complet et le décodeur d’états sont absents. Un installateur qui remplacerait déjà l’ancien composant ne répondrait pas au besoin de rappel des projets. **Il n’existe pas encore de commande honnête qui compile et installe le Sophistry complet depuis ce paquet.**

Les scripts peuvent être lancés avec `bash` même si le Finder n’autorise pas leur ouverture directe. Aucun changement global de sécurité macOS n’est nécessaire.

## Où trouver le travail

| Fichier ou dossier | Contenu |
|---|---|
| `docs/RAPPORT.md` | Audit, preuves, limites, contrat de compatibilité et étapes restantes |
| `REPRISE.md` | Instructions pour reprendre une prochaine session sans recommencer l’analyse |
| `port-status.json` | État explicite et lisible par machine des fonctionnalités absentes |
| `analysis/ghidra/functions/` | Un fichier de pseudo-code par fonction détectée |
| `analysis/ghidra/all-functions.c` | Export regroupé ; **pas des sources C compilables** |
| `analysis/ghidra/calls.tsv` | Appels directs reconnus ; appels virtuels non résolus exclus |
| `checkpoints/ghidra-project/` | Projet Ghidra enregistré, à ouvrir avec Ghidra 11.3.2 |
| `checkpoints/Sophistry-history.bundle` | Historique Git local autonome des trois checkpoints |
| `reference/` | Archive originale épinglée, tranche i386 et ressources extraites |
| `src/SaturKernel.cpp` | Traduction C++ du noyau isolé réellement comparé |
| `src/AUStateProbe.cpp` | Hôte Mac de diagnostic et rendu ; à compiler et vérifier sur Mac |
| `evidence/` | Rapports, fixtures, WAV du noyau et objet ARM64 |
| `docs/Interface.html` | Visionneuse locale des fonds graphiques originaux |

Le dossier `work/` est réservé aux nouveaux résultats et n’est pas inclus dans le checkpoint distribué.

## Reproduire les vérifications sous Linux

Depuis la racine du paquet, avec Python 3, un compilateur C++17 et un accès réseau pour les deux dépendances d’analyse :

```sh
python3 -m venv work/venv
work/venv/bin/pip install -r requirements-analysis.txt
mkdir -p work/build
c++ -std=c++17 -O2 -ffp-contract=off -fno-fast-math -fPIC -shared src/SaturKernel.cpp -o work/build/libsatur.so
work/venv/bin/python tests/compare_satur_original.py reference/Sophistry.i386 work/build/libsatur.so --report work/kernel-report.json --fixtures work/fixtures.bin
python3 -m unittest discover -s tests -p 'test_*.py' -v
```

Pour analyser vos presets sans les modifier :

```sh
python3 scripts/inspect_presets.py "/chemin/preset.aupreset" --output work/presets
python3 scripts/inspect_presets.py "/chemin/preset.fxp" --output work/presets
```

L’outil extrait le conteneur et les octets opaques. **Il ne sait pas encore charger un état Sophistry dans un moteur ARM64.** Il ne traite pas les projets `.logicx`/`.als`.

Le composant d’origine ne contient ni la banque de sons ni les presets externes. Vous avez confirmé les posséder et avoir utilisé le format AU. La paire réelle fournie est maintenant dans `reference/Presets/`. Le sample référencé et des variantes ciblées resteront nécessaires pour tester le rappel sonore et généraliser les migrations de format.

Pour reproduire l’analyse des états :

```sh
work/venv/bin/python scripts/recover_parameter_schemas.py
python3 scripts/decode_legacy_state.py "reference/Presets/Lightgarden 02 BT.aupreset" "reference/Presets/lightgarden 02 BT.FXP" --output work/preset-analysis
```

La récupération des schémas exécute uniquement le flux de contrôle d’initialisation des descriptions, en remplaçant les constructeurs de paramètres par des collecteurs. Elle ne fait pas fonctionner le synthétiseur original. Le décodeur structurel est indépendant d’Unicorn une fois les schémas obtenus.
