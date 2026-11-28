# ELA017 — lecture des corps d’objets GNArchiver

28 novembre 2026. Reprise après ELA016. L’image de référence est Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le décodeur C++ lit le flux binaire GNArchiver version 1 depuis son répertoire jusqu’à la fin des corps d’objets pris en charge. Il restitue un graphe de références numériques. Les doublons, références en avant, cycles et références nulles sont conservés. La première entrée d’objet est la racine et l’indice zéro indique une référence nulle. Le décodeur rend une erreur avec l’offset et le numéro d’objet en cas d’échec. Son API permet de chercher une clé de dictionnaire tout en distinguant une clé absente d’une clé dont la valeur est nulle.

| Classe d’archive | Corps pris en charge | Routines i386 |
| --- | --- | --- |
| `GNDictionary` | Deux références vers les listes parallèles des clés et valeurs | `0x63374` écrit, `0x6325c` lit |
| `GNList` | Compte, références et drapeaux selon les versions 0 à 3 | `0x29f66`, `0x2c7ec` |
| `GNString` | Encodage historique 0 et UTF‑16 avec marque d’ordre des octets. Drapeau de mutabilité | `0x35a8a`, `0x34c02` |
| `GNNumber` | Int32, booléen, float32 et float64. Types et bits préservés dans le domaine testé | `0x851d4`, `0x84ff2` |
| `GNData` | Taille et octets des blocs sans compression | `0x28680`, `0x284f4` |

Pour `GNNumber` version 2, le type int64 `l` est suivi immédiatement de l’objet suivant. Le slot i386 `0x1e8ed8` signale que l’écriture int64 est indisponible et n’écrit aucune valeur. Le slot de lecture `0x1e9440` retourne zéro sans avancer dans le flux. Le modèle natif distingue ce cas d’une valeur zéro présente. Les anciens corps numériques bruts et les données compressées restent à traiter.

L’exemple synthétique suit la structure `objects` décrite par `0x155546`. Ses deux enregistrements portent `@id` et `@isa` et servent à vérifier le parcours des références jusqu’aux champs. Les contenus de test sont synthétiques. Les identifiants `@id` appartiennent au graphe de modèles et les indices binaires sont ceux du graphe GNArchiver. [Exemple synthétique](../evidence/ELA017/synthetic-key-value-envelope.bin)

## Vérifications

Les écrivains i386 `0x1b71e2` et `0x1b73d8` produisent les octets du répertoire et des corps courants. Le lecteur i386 `0x1b92b4` instancie les enregistrements en deux passages via les liaisons de classe. Il appelle les vrais lecteurs de corps et résout les références. Les allocations, opérations de liste et métadonnées du registre de classes sont fournies par la sonde. Onze variantes historiques ou d’ordre des octets sont dérivées de sorties d’origine et lues par l’i386. La sonde observe 156 diagnostics int64 à l’écriture et 156 à la lecture.

Les **392 archives synthétiques**, **1 503 objets** et **58 078 octets** de résultats concordent sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. **603 cas** de troncature ou d’entrée invalide sont également rejetés par le nouveau décodeur. Le rapport des 265 entiers et cinq chaînes d’ELA002 reste identique. Un objet Mach‑O ARM64 a été compilé et son en-tête vérifié. [Rapports et objet ARM64](../evidence/ELA017)

L’analyse Ghidra en lecture seule couvre 90 fonctions distinctes, dont 43 nouvelles. Le total sélectionné atteint 489. Les deux passes de sélection utilisent les listes de racines incluses. [Décompilation et désassemblage](ELA017-original-state-bodies-decompiled.zip)

## Reproduction

```sh
mkdir -p work reference
python3 -m pip install -r requirements-probe.txt
python3 scripts/inspect_elastik.py reference/ElastikAU.pkg.zip \
  --output work/installer.json --extract reference/original-payload
python3 scripts/build_planar_sum_probe.py --kind state-archive --output work/StateArchiveProbe
python3 scripts/compare_original_state_archive.py reference/Elastik.i386 work/StateArchiveProbe \
  --platform local --output work/state-archive.json
```

Il reste à interpréter les champs des modèles Elastik et à reconstruire leur configuration de banque, programme et clavier. Un état ou projet d’époque servira à vérifier les classes présentes et le raccordement à ClassInfo. L’AU installable et la restauration de projets restent à réaliser.
