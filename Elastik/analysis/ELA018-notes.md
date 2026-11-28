# ELA018 — graphe des modèles et affectations de touches

28 novembre 2026. Reprise d’ELA017 sur Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le décodeur C++ indexe les enregistrements de `objects` après la lecture de GNArchiver v1. Les identifiants `@id` sont des entiers de modèle distincts des références du flux binaire. L’index conserve l’ordre de restauration et utilise le premier enregistrement comme racine. La classe est conservée via `@isa`. Les liens en avant, les cycles et les identifiants non contigus sont résolus sans instancier les classes. [Source](../src/OriginalKeyedState.h)

| Routine d’origine | Comportement vérifié |
| --- | --- |
| `0x155396`, `0x155546` | Écriture des identifiants, noms de classes et liste d’enregistrements |
| `0x1211b0` | Construction des objets et indexation des identifiants, puis passage de restauration sur la même liste. Le premier objet est retourné |
| `0x1218f2`, `0x1219d4` | Un nom exact retourne une valeur du dictionnaire et un nom précédé de `@` résout un identifiant de modèle. Le premier nom correspondant dans l’ordre des clés l’emporte. Le test de présence ôte d’abord un `@` |
| `0x29f66`, `0x2c7ec` | En mode à clés, `GNList` utilise `count` puis des clés décimales de `0` à `count-1`. Chaque entrée peut être intégrée ou référencer un modèle |
| `0x1489c0`, `0x15ecac`, `0x3b05e`, `0x21866`, `0x315e4` | Les classes déclarent leurs propriétés en retirant le tiret bas initial du nom du membre. Le parcours consulte les propriétés présentes et transmet leurs valeurs au setter |

L’exécution de l’enregistrement i386 confirme les 7 clés d’`ETProgram` et les 29 d’`ETKeyMapping`. Les noms comprennent `keyMappings`, `soundFilePath`, `soundBankIdentifier`, `midiNote` et l’orthographe originale `automatationTargets`. L’index restitue des valeurs d’archive et des références. Un lien dont l’identifiant manque reste distinguable d’un champ absent. Un identifiant de modèle dupliqué, une structure d’enveloppe incohérente et une liste incomplète sont signalés côté natif. [Clés dans l’ordre de restauration et rapports](../evidence/ELA018)

## Vérification

Quarante graphes synthétiques ont été sérialisés et relus par les routines de corps GNArchiver i386 d’ELA017, puis traités par le chargeur à clés i386. Les comparaisons couvrent 427 enregistrements, 385 éléments de listes, 10 010 recherches de champs et 69 177 octets de résultat par configuration. Le parcours réflectif d’origine transmet 8 768 valeurs aux liaisons de test des setters. La sonde fournit le registre des classes, l’allocation, les collections et les opérations C utilisées. Les fixtures incluent des champs omis, des liens pendants, des références cycliques, des affectations au-delà de la clé `12` et des chemins Unicode synthétiques. Les 23 validations négatives ciblent l’enveloppe, les métadonnées et les listes incomplètes.

Les suites concordent sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. L’objet Mach‑O ARM64 a été compilé et son en-tête a été vérifié. Les 392 comparaisons et 603 rejets GNArchiver d’ELA017 repassent sur x86‑64. L’analyse Ghidra couvre 86 fonctions, dont 25 nouvelles, pour un total de 514. [Preuves](../evidence/ELA018) · [Décompilation et désassemblage](ELA018-original-keyed-state-decompiled.zip)

## Reproduction

Depuis la racine du dossier Elastik, avec le binaire i386 extrait de l’installateur d’origine et les dépendances de `requirements-probe.txt` installées.

```sh
python3 scripts/build_planar_sum_probe.py --kind keyed-state --output work/KeyedStateProbe
python3 scripts/compare_original_keyed_state.py reference/Elastik.i386 work/KeyedStateProbe \
  --platform local --output work/keyed-state.json
```

La suite porte sur le décodage de la racine réelle d’un état AU et la mise en application des valeurs dans le moteur, jusqu’au chargement de banque et au rendu. Le test substitue la construction des objets et capture les appels aux setters. Il reste à vérifier le chemin ClassInfo complet sur un état Elastik 1 d’époque, puis le rappel dans Logic et Live sur macOS. ELA018 est un checkpoint de développement sans Audio Unit installable.
