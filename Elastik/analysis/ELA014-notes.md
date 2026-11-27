# ELA014 — listes de propriétés OpenStep dans les banques GNFA

27 novembre 2026. Reprise depuis ELA013 avec l’installateur Elastik 1.5.2.3 joint. L’empreinte de l’installateur correspond à `reference-input.json`. L’extraction a fourni le binaire i386 attendu, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

## Lecture et décodage

Le nouveau parseur natif reprend la sélection de format de `0x6739a` et sa branche OpenStep. Il produit des valeurs typées pour les dictionnaires, listes, chaînes UTF‑16, entiers 32 bits, flottants 32 bits et données hexadécimales.

| Adresse d’origine | Lecture portée dans cette étape |
| --- | --- |
| `0x1a4cb0`, `0x1a4e18` | Reconnaissance OpenStep sur le flux du chemin, puis sur les données |
| `0x1a4ffc`, `0x1a515a`, `0x1a54f4`, `0x1a55b8`, `0x1a56c6` | Espaces, commentaires, échappements, chaînes et clés |
| `0x1a5776`, `0x1a59d8`, `0x1a5bce`, `0x1a5d8a` | Données hexadécimales, sélection du type, dictionnaires et listes |
| `0x189376`, `0x38aa0`, `0x18b3ce`, `0x18b560` | Sous-ensembles de décodage et de conversion utilisés par le parseur OpenStep |

Le chemin ouvert emploie le décodage UTF‑8 d’origine, le repli sur les données emploie l’encodage historique 0 et une marque UTF‑16 initiale est traitée dans les deux branches. L’entrée est limitée à 128 niveaux du côté natif. Les tests reproduisent le dernier remplacement d’une clé répétée, les nombres nus, le flottant d’origine et le traitement des listes en fin de groupe. L’échappement octal aboutit à une erreur GN dans l’original. Le parseur natif signale un document invalide dans ce cas. Il signale séparément la route XML encore à porter.

`OriginalArchivePropertyList.cpp` relie un chemin déjà résolu par GNFA à la fabrique de lecteur et à la lecture intégrale du membre. Le format est choisi à partir des octets lus. La sonde ARM64 enchaîne ouverture, recherche du chemin, lecture et décodage dans un même processus.

## Correction du chemin de la banque intégrée

Le répertoire GNFA donne `Info.plist` à l’entrée 3, avec le parent racine 0. La recherche originale i386 et le port ARM64 résolvent **`/Info.plist`**. Le chemin **`/elastik/Info.plist`** reste non résolu. Les 96 octets du membre racine ont pour SHA-256 `56c88669d0b5358acab74a337f3e5a7d184f16525c21748d5729c812d5020fca`. La plist OpenStep livre les trois clés `color`, `identifier` et `title`. Cette correction s’appuie sur la lecture intégrale dans quatre configurations de partage et de duplication du flux.

## Vérifications

| Corpus par configuration | Cas |
| --- | ---: |
| Sélection de format et documents OpenStep | 1 680 |
| Ouverture GNFA, recherche, lecture et décodage | 45 |
| Total | 1 725 |

Les 17 692 octets de résultats par configuration concordent bit à bit sur Linux x86‑64, Linux ARM64 sous QEMU, x86‑64 avec UBSan et x86‑64 avec ASan+UBSan. Les rapports conservent les empreintes de chaque résultat. Le test ASan active la détection des fuites. Les 2 831 cas d’ELA013 repassent séparément sur x86‑64, avec les mêmes résultats. Deux objets Mach‑O ARM64 sont compilés et leurs en-têtes vérifiés.

La référence exécute les corps i386 de reconnaissance et de grammaire, les conversions de nombres et le décodeur de chaînes. Les opérations de stockage GN, d’allocation, de collection, les exceptions et les entrées/sorties brutes restent des liaisons. Pour les cas GNFA, une première VM exécute l’ouverture, la recherche et la lecture d’origine. Elle transmet les octets du membre à une seconde VM qui exécute le parseur. Les deux corpus ne valident ni la durée de vie des objets GN sur Mac ni le raccordement à `ETSoundbank::archive`.

L’archive Ghidra contient 63 fonctions sélectionnées, dont 35 nouvelles. Le total sélectionné passe à 425. Les exports couvrent aussi le début du chemin XML pour la reprise. [Décompilation et désassemblage](ELA014-original-plist-decompiled.zip)

## Reproduction

```sh
python3 -m pip install -r requirements-probe.txt
python3 scripts/inspect_elastik.py reference/ElastikAU.pkg.zip \
  --output work/installer.json --extract reference/original-payload
python3 scripts/build_planar_sum_probe.py --kind property-list --output work/PropertyListProbe
python3 scripts/compare_original_property_list.py reference/Elastik.i386 work/PropertyListProbe \
  --platform local --output work/property-list.json
```

Le script de compilation choisit Xcode sur macOS. Les résultats et les paramètres des autres compilations sont dans [evidence/ELA014](../evidence/ELA014).

## Suite

Porter la branche XML de `0x670cc`, puis relier le résultat à la durée de vie des objets GN et au chargeur `ETSoundbank`. Le catalogue et le délégué d’origine, les états enregistrés, la voix complète et l’intégration Cocoa/AU restent à établir. Aucun composant AU installable ni rappel d’un ancien projet n’a été produit sur ce checkpoint. Aucun essai Logic, Live ou `auval` n’a été exécuté.
