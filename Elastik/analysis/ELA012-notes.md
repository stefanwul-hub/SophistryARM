# ELA012 — recherche des samples par nom et ouverture GNFA

27 novembre 2026. Original Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. [Autorisation permanente](../PUBLICATION_AUTHORIZATION.json). Sophistry CP038 et CronoX CRX013 restent figés.

## Routines traduites

| Adresse | Octets | Rôle |
| --- | ---: | --- |
| `0xdf8d2` | 321 | Résolution d’un chemin dans le répertoire GNFA |
| `0xe3ff4` | 381 | Fabrique de fichier en lecture, flux ou données mémoire |
| `0x17f8a0` | 119 | Association des données GNFile et retour au début |
| `0x17f918` | 591 | Lecture GNFile mémoire ou fork système |
| `0x180a68` | 236 | Position GNFile |
| `0x180c72` | 329 | Déplacement GNFile |
| `0x180b54` | 285 | Fin GNFile |
| `0xdfab4` | 24 | Position du membre d’archive ou appel de la base GNFile |

Huit routines / 2 286 octets supplémentaires ; total 65 routines / 37 837 octets dans leur domaine valide. Les 27 anciens fichiers `src` restent identiques. `0xdfab4`, sans FDE, est bornée à 24 octets vérifiés par instructions, saut terminal compris. Le C++ adapte les dispositions d’objets et appels de plateforme ; il conserve les décisions et effets observés des corps i386.

**Correction de l’interprétation ELA011 :** `0xe2c14` est une ouverture en écriture/ajout. Elle positionne le drapeau d’écriture et utilise `0x17f7ce`, qui place la position à la fin des données. Ce n’est pas une seconde fabrique de lecture. `0xe3ff4` contient déjà les deux chemins de lecture : membre du flux pour une archive en lecture seule, ou matérialisation puis `0x17f8a0` pour l’autre disposition. L’écriture reste hors du portage actuel.

## Comportements conservés

Le résolveur ne remplace l’indice et ne libère le chemin qu’après réussite complète. Un échec conserve le chemin non résolu et l’ancien indice, même non nul. Les entrées sont parcourues dans l’ordre du répertoire ; le premier nom correspondant au parent est choisi, sauf longueur zéro. Le code n’ajoute pas de test imposant un répertoire comme parent : une entrée fichier peut donc être un parent dans une archive synthétique. Un chemin de moins de deux unités donne l’indice zéro ; des séparateurs seuls produisant zéro segment donnent l’indice 1.

La fabrique conserve cette distinction : elle ne refait pas un contrôle supplémentaire du chemin non résolu après le lookup. Un ancien indice peut encore conduire à ouvrir l’ancien fichier ; un autre chemin peut ensuite déclencher une assertion. Ces effets, les références d’objets, les buffers et les profondeurs de verrou sont comparés. Une exception arrive avant le déverrouillage du chemin normal. Le C++ renvoie un statut ; l’intégration future des exceptions et du déroulement GN reste nécessaire.

Les opérations de chaîne et de tableaux restent des liaisons natives explicites. La référence i386 exécute réellement le découpage `0x39a08`/`0x395f6`, la comparaison et le hash GNString, ainsi que la conversion `0x340ba`/`0x189b58`. Les constructeurs de stockage et primitives de tableaux sont adaptés. L’encodage par défaut 0 n’est pas UTF‑8 : ASCII imprimable et table historique de 159 correspondances, caractère de remplacement `0x1a` pour une unité non représentable. Les segments issus du découpage sont des chaînes d’octets ; leurs comparaisons sensibles à la casse et leurs éventuelles collisions après conversion sont conservées. La table de test est extraite du binaire et accompagnée de sa preuve. Cela ne constitue pas le portage de tout GNString, de ses caches ou de ses classes.

GNFile mémoire peut copier un préfixe positif et renvoyer vrai, contrairement à la lecture d’archive directe qui renvoie faux pour une lecture courte. À zéro ou en fin de mémoire, il renvoie faux avec compte zéro. La nouvelle association des mêmes données réinitialise aussi la position et recalcule la longueur. La référence de données change seulement si l’objet diffère. Une association de données nulles atteint l’assertion lors du verrouillage, après les mutations précédentes.

Les imports `FSReadFork`, `FSGetForkPosition` et `FSSetForkPosition` sont des liaisons de test, pas des appels Carbon exécutés sur macOS. Le chemin fork réussi conserve le compte fourni par l’appelant, même si l’import indique une lecture plus courte dans sa variable locale. Un échec peut avoir copié des octets mais ramène le compte appelant à zéro. Un fichier fermé sans données ni fork renvoie faux sans modifier ce compte. Les erreurs de position/fin et le mot inférieur 32 bits suivent l’original. Les buffers accessibles et callbacks non levants font partie du contrat des fonctions portées.

## Vérifications

| Corpus | Cas par configuration | Octets comparés |
| --- | ---: | ---: |
| GNFile mémoire / fork / erreurs / références | 192 | 86 224 |
| Chemin → lookup → fabrique → lectures | 384 | 19 227 432 |
| Chemin → fabrique → GNFA → WAVE / PCM / MS / DVI | 68 | 4 221 398 |
| Total | 644 | 23 535 054 |

Les quatre configurations sont x86‑64, ARM64 Linux sous QEMU, x86‑64/UBSan et x86‑64/ASan+UBSan. Les noms et SHA-256 des cas sont identiques entre configurations. Aucune nouvelle tentative automatique. Les vérificateurs ont initialement détecté un marqueur `-1` stocké dans un enum du banc de test ; un booléen séparé corrige ce problème de test sans changer les routines portées ni les résultats attendus. Les vérifications finales passent, détection des fuites activée pour ASan.

Le test natif d’intégration est un seul exécutable C++. Il passe par la recherche par nom et la vraie fabrique portée, y compris en disposition GNFA 0 qui choisit les données mémoire. La référence utilise deux VM i386 épinglées ; l’I/O WAVE appelle les méthodes originales de l’archive et de GNFile dans la seconde VM. Aucune extraction WAVE préalable, métadonnée d’en-tête ou donnée audio décodée n’est fournie à la chaîne native. Les tests comprennent aussi nom absent, répertoire et plist rejetés comme audio, chemins Unicode/casse, doublons, ancien indice, erreur de matérialisation et flux partagé/cloné.

Les 176 399 frames stéréo à 44 100 Hz du sample intégré d’origine concordent avec un calcul indépendant `int16/32768`, en lecture partagée et dédiée, sur host et ARM64/QEMU. SHA-256 float32 entrelacé : `555760159fb2f5e4331d3df06df12c1e659b27585601687f8ab364cd3e3d4ef3`. Le programme reçoit seulement la banque et le chemin ; le WAV privé sert uniquement de référence indépendante. Banque, WAV et audio ne sont pas publiés.

Deux objets Mach-O ARM64 `MH_OBJECT` sont compilés et vérifiés depuis les nouveaux modules. Ce ne sont pas des Audio Units. Les 12 rapports, deux contrôles audio indépendants, commandes de compilation, empreintes et preuves sont dans [evidence/ELA012](../evidence/ELA012).

## Reproduction

Après extraction privée du paquet original et préparation de l’environnement Python de recherche :

```sh
python3 scripts/build_planar_sum_probe.py --kind byte-file --output work/ByteFileProbe
python3 scripts/build_planar_sum_probe.py --kind archive-names --output work/ArchiveNameProbe
python3 scripts/build_planar_sum_probe.py --kind named-archive-wave --output work/NamedArchiveWaveProbe
python3 scripts/compare_original_byte_file.py reference/Elastik.i386 work/ByteFileProbe --platform local --output work/byte-file.json
python3 scripts/compare_original_archive_names.py reference/Elastik.i386 work/ArchiveNameProbe --platform local --output work/archive-names.json
python3 scripts/compare_original_named_archive_wave.py reference/Elastik.i386 work/NamedArchiveWaveProbe --wave work/builtin-demo/01drm120elastik_2.WAV --platform local --output work/named-wave.json
python3 scripts/verify_named_archive_wave_audio.py work/NamedArchiveWaveProbe --wave work/builtin-demo/01drm120elastik_2.WAV --platform local --output work/named-audio.json
```

Le script de compilation choisit Xcode sur Mac. `--builtin` permet d’indiquer la même banque intégrée ailleurs, SHA original exigé. Les corpus synthétiques sont générés localement. La preuve des compilations ARM64 et des variantes avec vérificateurs est dans `build-commands.json`.

Ghidra 11.3.2, lecture seule, profondeur 1, quatre jeux de racines : path, string, extra et store. 68 exports, 46 fonctions distinctes dont 19 nouvelles ; total 341 décompilations sélectionnées distinctes. L’[archive détaillée](ELA012-original-named-files-decompiled.zip) conserve les C/ASM, manifestes et racines ; les seuls libellés de checkpoint/portée des manifestes sont normalisés.

## Suite et sauvegarde

Le catalogue `ETSoundbank`, son vrai délégué et l’autorisation des banques, les objets/durées de vie GN, les flux macOS et l’ordonnancement restent à intégrer. Puis : formats nécessaires, voix complète avec boucles/pitch/time stretching, corps d’états, Cocoa/AU et validation sur Mac. Les banques personnelles et un état réel ne sont pas encore reçus ; aucune compatibilité d’anciens projets ni fidélité du moteur complet n’est annoncée. Aucun installateur de composant n’est proposé à ce stade.

Les checkpoints précédents et l’original sont conservés. Pour libérer le disque, seule l’archive d’installation de Zig a été retirée après vérification que son compilateur est strictement identique au compilateur installé. URL et SHA de récupération figurent dans le relevé privé `work/ELA012-storage-maintenance.json`, inclus dans la sauvegarde privée finale.
