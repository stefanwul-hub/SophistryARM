# ELA019 — lecture du programme et des affectations depuis ClassInfo

28 novembre 2026. Analyse avec Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

`decode_class_info` reçoit les champs numériques du CFDictionary hôte et les octets de `data`. Il vérifie la version 0 et les codes `aumu`, `ELSK` et `UBER`. `decode_program_state` reçoit directement le flux GNArchiver v1 émis par l’original. Le lecteur décode et valide le graphe avant de remettre le programme et son graphe à l’appelant. Il rapporte l’objet ou l’offset à l’origine d’un rejet, lorsqu’ils sont connus. [API C++](../src/OriginalProgramState.h)

| Partie | Valeurs projetées |
| --- | --- |
| `ETProgram` | `formattedTempo`, `autoselect`, `automapMode`, `algorithm`, `syncUserTempoToFileTempo` |
| `keyMappings` | Ordre, alias, note MIDI, drapeau de touche utilisateur, références aux chaînes du chemin et de la banque, lien au programme |
| `automationParameters` | Ordre des enregistrements et emplacements par défaut jusqu’à huit. Les paramètres excédentaires et leurs propriétés restent accessibles dans le graphe |

Le tempo emploie le scanner numérique réutilisé depuis le lecteur de propriétés d’ELA015. Dans la branche GNString sans formateur hôte, l’original arrondit la valeur en float32 avant de l’enregistrer en double. Le tempo initial est 120. Le constructeur initialise 68 touches, notes 36 à 103. Une liste archivée vide reste vide. Si la liste est omise, le lecteur recrée les notes initiales et reproduit la remise à zéro du drapeau de touche utilisateur sur les affectations vides. Le graphe préserve les autres champs archivés, dont les paramètres sonores et les cibles d’automation.

Le lecteur remet le graphe et les localisateurs sauvegardés au moteur appelant. Si une banque manque au catalogue, le binaire d’origine peut remettre l’affectation à zéro pendant la finalisation. Cette décision dépend des banques accessibles et relève du futur raccordement au catalogue. La projection conserve donc le chemin et l’identifiant archivés jusqu’à cette étape. [Relevé des points d’entrée et de l’attache du programme](ELA019-program-entry-progress.md)

## Vérification

Le premier banc exécute le receveur ClassInfo i386 `0x5b64` avec des liaisons CoreFoundation. Il vérifie l’identité et la version, puis capture les octets transmis au moteur. Le second banc exécute la lecture GNArchiver et GNKeyValue, l’initialisation d’`ETProgram` (`0x160584`), la distribution des champs (`0x315e4`), sa finalisation (`0x160ba8`), l’analyse numérique du tempo (`0x34496`, `0x18b560`) et son attache au moteur (`0x1b2bc`). Les setters de propriétés, les collections, les objets et le catalogue sont liés à des données synthétiques. Le banc observe les demandes au lecteur d’échantillons.

Les **40 archives synthétiques** correspondent sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Les deux points d’entrée natifs sont comparés pour chaque archive. Les résultats couvrent **522 affectations**, **334 emplacements d’automation**, 84 appels au lecteur d’échantillons dans le banc i386 et 15 904 octets de comparaison par point d’entrée. Seize validations traitent les métadonnées et structures incorrectes, dont quatre rejets exécutés dans le ClassInfo i386. Deux cas natifs vérifient la préservation des chemins et identifiants en attente de résolution.

Les suites ELA015 et ELA018 repassent sur x86‑64. L’objet Mach‑O ARM64 du lecteur a été compilé et son en-tête vérifié. L’analyse Ghidra couvre 77 fonctions, dont 36 nouvelles, pour un total de 550. [Rapports et objet ARM64](../evidence/ELA019) · [Décompilation et désassemblage](ELA019-original-program-state-decompiled.zip)

## Reproduction

Depuis la racine du dossier Elastik, avec le binaire i386 extrait de l’installateur d’origine et les dépendances de `requirements-probe.txt` installées.

```sh
python3 scripts/build_planar_sum_probe.py --kind program-state --output work/ProgramStateProbe
python3 scripts/compare_original_program_state.py reference/Elastik.i386 work/ProgramStateProbe \
  --platform local --output work/program-state.json
```

Le prochain jalon porte sur la résolution des banques par identifiant et l’ouverture des membres à partir des chemins archivés. L’application des réglages au moteur natif, l’exécution sur macOS et la validation sur un ancien état utilisateur restent à réaliser. ELA019 est un checkpoint de développement sans Audio Unit installable.
