# Sophistry — checkpoint CP-003

**Ce paquet ne contient pas de Sophistry Audio Unit ARM64 installable. Le portage complet demandé reste à réaliser.**

Il conserve le travail réellement effectué : audit du composant fourni, décompilation Ghidra des fonctions détectées, images originales, traduction C++ d’un seul noyau de saturation, tests différentiels et outils pour poursuivre sur Mac. Aucun synthétiseur de substitution n’est présenté comme l’original.

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
bash "/chemin/vers/Sophistry-CP003/Verifier-Mac.command"
```

Ce script exige Xcode ou ses outils en ligne de commande. Il compile **les outils de test** en ARM64, exécute les fixtures du noyau, compile l’hôte de diagnostic AU et lance `auval -v aumu Sop3 LinP` sur le composant déjà enregistré. Il enregistre les résultats dans `work/mac-<date>/`. Il ne copie, ne remplace et ne supprime aucun composant. L’échec de `auval` est attendu si seul l’ancien i386/PPC est présent.

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
python3 -m unittest discover -s tests -p test_tools.py -v
```

Pour analyser vos presets sans les modifier :

```sh
python3 scripts/inspect_presets.py "/chemin/preset.aupreset" --output work/presets
python3 scripts/inspect_presets.py "/chemin/preset.fxp" --output work/presets
```

L’outil extrait le conteneur et les octets opaques. **Il ne sait pas encore charger un état Sophistry dans un moteur ARM64.** Il ne traite pas les projets `.logicx`/`.als`.

Le composant d’origine ne contient ni la banque de sons ni les presets externes. Vous avez confirmé les posséder et avoir utilisé le format AU. Un vrai `.aupreset` et quelques `.fxp`, avec les échantillons référencés, restent nécessaires pour tester le décodage des états et le rappel sonore.
