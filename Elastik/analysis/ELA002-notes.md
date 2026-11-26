# ELA002 — chemin audio, format d’état et première routine ARM64

Le checkpoint poursuit l’objectif de restauration des projets Elastik 1. Le moteur complet n’est pas disponible. Aucune banque utilisateur ni sauvegarde originale n’a été reçue depuis ELA001. Le code de Sophistry CP038 et de CronoX CRX013 reste figé.

Les métadonnées GNU C++ d’origine permettent maintenant d’identifier 520 enregistrements RTTI et les tables virtuelles de 12 classes utiles. Le relevé est dans `selected-original-classes.json`, à l’intérieur de l’archive locale des décompilations. Le script public `scripts/index_original_classes.py` permet de le reproduire avec le binaire fourni. Il relie des adresses de code à `ETInstrument`, `ETProgram`, `ETInstrumentVoice`, `ETKeyMapping`, au cache de rendu, au pitch shifter, au rééchantillonneur et aux archiveurs.

Le chemin audio relevé dans l’original est :

| Étape | Adresse i386 / appel |
| --- | --- |
| Entrée AU, sélecteur Render 14 | `0x6bce` → `0x5490` |
| Adaptation des buffers et événements | `0x5490` → `0x2f6c` |
| Mise à jour des paramètres avant bloc | vtable instrument `+0x354` → `0x1cafe` |
| Traitement du bloc instrument | vtable `+0x27c` → `0x1b7f8` → `0x156134` |
| Traitement d’une voix active | vtable voix `+0x27c` → `0x1532f8` |
| Lecture des données de cette voix | `0x1532f8` → `0x152664`, encore à porter |
| Sommation des voix dans la sortie | `0x156134` → `0x161700` |

La routine complète `0x161700..0x161774`, soit 117 octets, est traduite dans `src/OriginalPlanarSum.cpp`. Les instructions d’origine font une addition IEEE binary32 par sample, canal après canal. Le troisième argument est inutilisé ; le cinquième décrit les canaux et son bit 8 sélectionne le compte dans l’octet de poids faible. La traduction garde l’ordre destination + source et permet le chevauchement des buffers. Elle n’ajoute ni gain, ni limite de voix, ni raccourci sur le silence.

Le programme de comparaison exécute ces 117 octets originaux sous Unicorn, sans moteur et sans appels d’hôte. Il compare tous les octets des buffers au C++ compilé. Les 73 cas couvrent 0/1/2/4/16 canaux, les tailles 0/1/7/32/257/1024, le bit de format, les zéros signés, les valeurs subnormales, les chevauchements et une sommation de la boucle WAV incluse. Ils représentent 140 512 mots de stockage float32, avec les zones de garde. Tous concordent sur l’exécutable Linux x86-64 et sur l’exécutable AArch64 exécuté sous QEMU. Ce dernier test n’est pas une exécution macOS. Les NaN, les infinis en entrée et les autres modes flottants ne sont pas validés.

Le même source est compilé en objet Mach-O ARM64, CPU `0x0100000c`, sous-type 0, avec Zig 0.14.1 et son Clang. L’objet est conservé dans l’archive d’analyse locale. Ce fichier `.o` n’est pas un plugin. Aucun `auval`, chargement dans Logic/Live ni rendu complet du moteur n’est établi.

Le contrôle automatique a refusé l’envoi public de l’archive détaillée de décompilation en l’absence d’une autorisation explicite pour ce contenu dérivé du binaire privé. L’archive est conservée pour la reprise et exclue du ZIP public ELA002. Le source C++ que nous avons écrit et les rapports de vérification peuvent être publiés. Les scripts d’analyse permettent de régénérer les décompilations localement à partir de l’original.

Pour l’état, `ETInstrument::save` à `0x1b416` utilise `GNKeyValueArchiver` avec l’option 2. `0x155546` forme un graphe sous la clé `objects` ; les entrées portent `@id` et `@isa` (`0x155396`). L’option 2 fait sérialiser ce graphe par `GNArchiver`, à partir de `0x1b5932`. La version 0 du dictionnaire AU ClassInfo et la version 1 de ce flux binaire sont deux niveaux distincts.

Le flux binaire commence par un entier typé de version 1, puis la table des classes (numéro, version, nom), puis le nombre d’objets et leurs numéros de classe. Un entier est le tag ASCII `i` suivi d’un int32 big-endian. Une chaîne est le tag `*`, un entier typé de longueur, puis ses octets. Les routines `0x1640f2`, `0x163006` et `0x164748` ont été exécutées sur des enregistrements mémoire initialisés de `GNTypedStream`, `GNData` et `GNString` : 265 allers-retours d’entiers et cinq écritures de chaînes concordent avec ce format. Seul le `memcpy` de libc est fourni pour les chaînes. Aucun moteur ni chemin de licence n’est appelé.

`scripts/inspect_state_archive.py` lit la table des classes et celle des types d’objets d’un payload binaire ou du champ `data` d’un `.aupreset`. Il ne lit pas encore les corps d’objets. La fixture `synthetic-header-only.bin` est écrite par les primitives d’origine ; elle n’est pas un preset complet ni un état utilisateur. Les assertions de ce test incluent le rejet des en-têtes tronqués.

Pour reproduire la comparaison avec Xcode sur Mac (outillage de développement, aucune installation AU) :

```sh
python3 -m venv work/venv
work/venv/bin/python -m pip install -r requirements-probe.txt
python3 scripts/inspect_elastik.py /chemin/ElastikAU.pkg.zip --output work/inspection --extract work/reference/original-payload
python3 scripts/build_planar_sum_probe.py --output work/planar-sum-probe
work/venv/bin/python scripts/compare_original_planar_sum.py work/reference/Elastik.i386 work/planar-sum-probe --platform macos-local --output work/planar-sum-comparison.json
work/venv/bin/python scripts/probe_original_typed_stream.py work/reference/Elastik.i386 --output work/state-probe
```

Le test avec la boucle intégrée utilise en plus `scripts/extract_builtin_demo.py` puis l’option `--demo` du comparateur. Les rapports publiés comprennent ce cas ; la recette minimale ci-dessus utilise les 72 cas indépendants de la boucle.

Les six fichiers `ELA002-*-roots.txt` reproduisent la sélection Ghidra. Syntaxe : adresse, éventuellement taille vérifiée pour une fonction sans FDE, puis commentaire. Exemple d’appel après import de l’i386 dans un projet Ghidra :

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA002-decompiled analysis/ELA002-state-render-roots.txt 1
```

Utiliser Ghidra 11.3.2 et un JDK 21. Le script ne change pas les instructions et reconnaît le thunk PIC d’origine. Les tailles ajoutées sans FDE sont vérifiées par désassemblage, pas déduites du simple espacement des symboles. Les métadonnées d’unwind ne donnent pas toutes les limites de fonctions. Les décompilations C comportent des types inconnus et des casts int/float qui ne doivent pas être recopiés littéralement.

Suite du travail : décoder les corps de l’archive et les modèles `ETProgram`/`ETKeyMapping`, suivre et traduire `0x152664`, puis le traitement complet des voix, des boucles, du cache et du changement de hauteur. Le rappel de projet et la fidélité du moteur entier demandent encore des essais sur un état original et sur macOS.
