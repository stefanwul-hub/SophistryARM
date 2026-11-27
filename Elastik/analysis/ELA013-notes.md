# ELA013 — métadonnées de banques et ouverture GNFA en lecture seule

27 novembre 2026. Original Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. [Autorisation permanente](../PUBLICATION_AUTHORIZATION.json). Sophistry CP038 et CronoX CRX013 restent figés.

## Routines traduites

| Adresse | Octets | Rôle |
| --- | ---: | --- |
| `0x1a9b78` | 86 | Identifiant de banque, copie immuable si nécessaire |
| `0x1a9bda` | 77 | Source de banque et invalidation de l’archive |
| `0x1a9cb4` | 55 | Chemin racine |
| `0x1a9cf8` | 55 | Titre |
| `0x1a9d3c` | 55 | Couleur |
| `0x1a9d80` | 55 | Champ de numéro de série |
| `0x1a9dc4` | 55 | Champ de réponse |
| `0x1a99d2` | 199 | Libération des références de banque |
| `0x1a9c28` | 127 | Résolution de la source système ou ressource |
| `0x1aa964` | 98 | Changement de fichier de banque |
| `0x1aa9c6` | 1 143 | Chargement paresseux de l’archive et de ses métadonnées |
| `0xe13de` | 217 | Ouverture GNFA en lecture seule, puis parseur |
| `0xe168c` | 433 | Création d’un chemin absolu interne |
| `0xe1a68` | 18 | Accès au chemin depuis le conteneur, saut terminal |

Quatorze routines / 2 673 octets supplémentaires ; total 79 routines / 40 510 octets dans leur domaine valide. Les 31 anciens fichiers `src` sont inchangés. Le wrapper `0xe1a68`, sans FDE, est borné aux 18 octets vérifiés par instructions. Les exports C de Ghidra peuvent développer le parseur appelé par un saut terminal : les tailles comptées restent celles des corps délimités, sans recompter ce parseur.

Les sept setters sont réunis dans une interface native typée. Ils conservent leurs décisions distinctes. Les noms internes de champs `serial` et `response` décrivent le modèle ; aucun numéro de série ou code de réponse utilisateur n’a été reçu ou publié. Le contrôle de validité de licence n’est pas remplacé par ces méthodes d’affectation.

## Comportements conservés

La modification de la source libère et invalide toujours l’archive, même lorsque le nouvel objet de source est identique à l’ancien. Les autres setters ne remplacent les références que si les objets diffèrent. L’identifiant mutable passe d’abord par la copie immuable originale. Le changement de fichier récupère son chemin POSIX avant d’invalider l’archive. La routine de nettoyage respecte l’ordre couleur, réponse, série, identifiant, source, racine, archive, titre ; elle ne réinitialise pas les deux champs numériques.

La résolution demande le chemin système lorsque la chaîne de source est non vide. Le slot `+0x1d0` est le prédicat « fichier », et non un simple test d’existence d’un répertoire : la vtable GNFA le relie à `0xe05a2`. Si le chemin construit n’est pas un fichier, l’original recherche une ressource avec son dernier composant. Une construction de chemin renvoyant nul ne tente pas cette ressource. Le chargeur résout encore la source lorsqu’une archive est déjà en cache ; cette résolution n’implique pas une nouvelle ouverture.

À la première ouverture, l’ancien identifiant est libéré, puis une archive GN est construite. L’exception d’ouverture est interceptée : l’archive est libérée et remise à nul, les mutations précédentes étant conservées. Les autres appels de métadonnées ne sont pas placés dans ce bloc de capture. Le chargeur recherche exactement `/Info.plist`. S’il peut être lu, il récupère `identifier`, `title`, `serial`, `color`, puis `gracePeriode`, avec cette orthographe d’origine. La valeur de grâce est lue en float32 puis élargie en double ; si la clé manque, l’ancienne valeur reste présente. À défaut d’identifiant et de titre, les méthodes originales du chemin fournissent les valeurs de repli. Les autres anciennes métadonnées peuvent subsister après une plist absente ou invalide.

L’ouverture `0xe13de` exige un lecteur précédent nul. Elle positionne le drapeau de lecture seule avant de demander le fichier, conserve le lecteur, étend la taille signée 32 bits vers 64 bits et saute vers le parseur d’ELA011. Elle ne restaure pas l’ancien état après une erreur. Ce chemin impose aussi la lecture seule à la disposition GNFA 0 ; la fabrique de fichier choisit alors le flux membre. Ce n’est pas l’ouverture en lecture/écriture/création `0xe1164` ni l’écriture/ajout `0xe2c14`.

L’erreur `GNFileArchiveCannotOpenArchiveException` est distincte de `GNFileArchiveCannotReadArchiveException`. Le nouveau wrapper expose le statut 5 pour la première, sans modifier l’enum ni les fonctions natives précédentes. Le chargeur de banque intercepte l’échec d’ouverture, quel que soit son type. Les assertions, erreurs de format et lectures illisibles gardent leurs statuts existants.

La fabrique de chemin construit l’objet avant de vérifier que la chaîne n’est pas vide et commence par `/`. Les allocations et champs partiels avant une assertion sont observés. Après succès, elle conserve la chaîne, verrouille le core, résout le chemin si le flux est présent, déverrouille et conserve le propriétaire. L’objet retourné peut représenter un chemin non résolu : aucune règle nouvelle de réussite n’est ajoutée.

## Vérifications et limites des liaisons

| Corpus | Cas par configuration | Octets comparés |
| --- | ---: | ---: |
| Banque : références, source, cache et métadonnées | 2 062 | 1 602 008 |
| Ouverture GNFA → parseur → chemin → lecture de membre | 769 | 3 924 524 |
| Total | 2 831 | 5 526 532 |

Les deux corpus passent bit à bit sur x86‑64, ARM64 Linux sous QEMU, x86‑64/UBSan et x86‑64/ASan+UBSan, avec les mêmes noms et SHA-256 de cas. Détection des fuites activée pour ASan, aucune nouvelle tentative automatique. Les tests stricts passent avec `-Wall -Wextra -Werror`. Deux objets Mach-O ARM64 sont compilés et leur en-tête `MH_OBJECT`/CPU vérifié ; aucun composant AU n’en résulte.

Le premier corpus exécute les vrais corps i386 de banque, mais adapte explicitement les primitives GN, copies immuables, dictionnaires/plist, archives et chemins système. Le contexte d’exception/setjmp est une liaison, comme dans ELA010. Le retour numérique utilise le même ABI x87 float que la primitive GN. **Ce corpus ne fait pas tourner le vrai parseur de plist ni l’ouverture d’une banque utilisateur.**

Le second corpus exécute réellement les wrappers d’ouverture et de chemin, le parseur GNFA, le lookup, la fabrique et les lectures de membre, dans le même processus natif et la même VM de référence respective. Aucun descripteur du répertoire ni octet de membre n’est injecté. La construction/rétention GN, la chaîne/les tableaux, les exceptions, les mutex et l’I/O brute restent des liaisons. Le contexte de départ possède un répertoire vide synthétique ; les octets de l’archive à tester ne servent qu’à la vraie ouverture. Les lectures du WAV intégré comparent ses 707 036 octets complets, en modes partagé et dédié. Il ne s’agit pas d’un nouveau rendu audio du moteur.

La banque de ressource intégrée place sa plist à `/elastik/Info.plist`, pas à `/Info.plist`. Ces deux chemins sont testés séparément ; ne pas annoncer que le chargeur de banque a lu ses métadonnées racines. Cette plist est au format OpenStep, et non XML, avec couleur, identifiant et titre. Le parseur d’origine `0x6739a` gère plusieurs branches de format ; il est décompilé, encore non porté.

Les constructeurs de banque sont également analysés : ils mettent les références et la grâce à zéro, mais n’écrivent pas le double `mounted_at`. Ne pas inventer sa remise à zéro en portant le runtime. Les routines d’autorisation et de grâce restent des dépendances analysées, non remplacées ni validées. Le catalogue global, le vrai délégué et la compatibilité des banques protégées restent à établir.

Cinq champs déclarés de `ETSoundbank` sont relevés depuis son enregistrement de classe : `_identifier`, `_sourceFilePosixPath`, `_rootFilePath`, `_serialNumber`, `_responseCode`. Avec les 36 champs déjà récupérés de `ETProgram`/`ETKeyMapping`, cela fait 41 champs identifiés ; cela ne décode pas les corps d’un état enregistré et ne démontre pas un ancien projet restauré.

## Reproduction

Après extraction privée du paquet original et installation de `requirements-probe.txt` :

```sh
python3 scripts/build_planar_sum_probe.py --kind soundbank --output work/SoundbankProbe
python3 scripts/build_planar_sum_probe.py --kind archive-open --output work/ArchiveOpenProbe
python3 scripts/compare_original_soundbank.py reference/Elastik.i386 work/SoundbankProbe --platform local --output work/soundbank.json
python3 scripts/compare_original_archive_open.py reference/Elastik.i386 work/ArchiveOpenProbe --platform local --output work/archive-open.json
```

Xcode est choisi sur Mac. Les chemins par défaut et SHA de la banque intégrée restent ceux des checkpoints précédents ; `--builtin` indique le même fichier ailleurs. Les commandes des variantes ARM64/sanitizers et les rapports sont dans [evidence/ELA013](../evidence/ELA013).

Ghidra 11.3.2 en lecture seule, profondeur 1, trois jeux de racines : soundbank, bank-loading, bank-defaults. 95 exports, 84 fonctions distinctes dont 49 nouvelles ; total 390 fonctions sélectionnées décompilées. L’[archive détaillée](ELA013-original-soundbank-decompiled.zip) conserve les C/ASM originaux, racines et manifestes. Les seules étiquettes de portée/checkpoint des manifestes sont normalisées.

## Suite et sauvegarde

Intégrer le parseur de plist et les objets/durées de vie GN pour relier le chargeur de banque aux vrais services natifs, puis le catalogue et le délégué d’origine. Les formats nécessaires, voix complète/boucles/pitch/time stretching, corps d’états, Cocoa/AU, `auval`, anciens projets et CPU du moteur restent à établir. Aucun composant installable n’est proposé à ce stade.

Les anciens checkpoints et originaux sont conservés. Seuls deux bundles Git isolés, vérifiés identiques aux copies dans leurs ZIP privés, et 32 exécutables de sondes recompilables ELA008–ELA011 ont été retirés pour libérer le disque. Le relevé privé donne chaque empreinte, archive de récupération ou commande de compilation ; il accompagne la sauvegarde finale. Aucun original ni ZIP de checkpoint n’a été supprimé.
