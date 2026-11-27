# ELA005 — cache de samples et raccordement aux blocs de voix

Ce checkpoint traduit neuf routines originales supplémentaires et raccorde le lecteur PCM ELA004 aux traitements de blocs ELA003. Le fournisseur de samples `0x1f0c92` est désormais réellement exécuté dans la référence i386. Le banc ne le remplace plus par une copie de samples déjà décodés.

| Adresse d’origine | Octets | Fonction portée |
| --- | ---: | --- |
| `0x218102` | 130 | Recherche d’un bloc dans le cache, avec récupération d’une entrée incohérente |
| `0x2181d6` | 168 | Recherche d’un emplacement vide ou réutilisable hors des plages demandées par les clients actifs |
| `0x21900c` | 337 | Copie d’un canal depuis plusieurs blocs planaires du cache |
| `0x218cf6` | 82 | Enregistrement d’une plage de blocs à préparer pour un client |
| `0x218d48` | 22 | Invalidation d’une demande, en conservant son drapeau d’activité |
| `0x1af4e2` | 794 | Lecture d’un canal de fichier : bornes, cache ou lecteur direct, accès sérialisé |
| `0x1aecf0` | 324 | Extension et bornage de la plage à préparer dans le cache |
| `0x1afb00` | 159 | Lecture puis préparation, selon le mode direct d’origine |
| `0x1f0c92` | 79 | Fournisseur de samples associé au handle de fichier d’une voix |

Les 2 095 octets d’origine concernés portent le total à 15 routines traduites / 8 144 octets d’origine. Ces tailles ne mesurent pas la proportion du moteur complet : certaines fonctions sont des contrôles de lecture, et les interfaces du framework GN restent à adapter. Les sources natives sont `src/OriginalSampleCache.cpp/.h` et `src/OriginalSampleFile.cpp/.h`.

## Comportements conservés

Un indice de table manquant (`-1`) échoue immédiatement. Une entrée non négative incohérente déclenche une recherche dans les emplacements existants, sans corriger la table. La copie peut avoir écrit un préfixe avant de rencontrer un bloc absent. Le gestionnaire de fichier remet alors toute la portion valide demandée à zéro, comme l’original.

Le diagnostic de manque de données a une particularité confirmée par les instructions : sa boucle n’avance pas le pointeur de client. Elle peut donc imprimer plusieurs fois la demande du premier client. En revanche, la recherche d’un emplacement réutilisable parcourt correctement **tous** les clients actifs et protège leurs plages inclusives. Les deux comportements sont conservés séparément.

Une demande se terminant exactement à une frontière de bloc inclut l’indice du bloc suivant. L’invalidation met les deux indices à `-1`, sans changer le drapeau d’activité. Le drapeau de manque de données persiste jusqu’à ce qu’un autre traitement le réinitialise ; le consommateur ne le remet pas spontanément à zéro.

Le lecteur de fichier borne les lectures au début et à la fin du sample. Lorsque le début demandé est négatif, il réduit la longueur et écrit les données valides au début du buffer destination, sans décalage correspondant à la partie négative. Le canal demandé au-delà du dernier canal est ramené au dernier. Les tailles nulles, les fichiers fermés et les métadonnées sans canal suivent leurs branches d’origine.

Le mode direct utilise le même verrou partagé pour les lectures normales et les lecteurs mono séparés. Le port reçoit ce verrou et la traduction des exceptions GN par des callbacks de plateforme. Un échec du lecteur libère le verrou et renvoie false. La création différée du mutex GN, le mécanisme réel de setjmp/exception et les objets GN de plateforme ne sont pas portés par cette API.

La lecture combinée prépare la plage de cache même si la lecture précédente a échoué, tant que le mode direct est désactivé. Ce détail est vérifié, notamment avec un fichier fermé dont la longueur est déjà connue. Le mode global original est un argument explicite dans l’API native, puis un champ du handle fourni au lecteur de blocs de voix.

## Unité des plages de cache confirmée

L’ouverture de fichier `0x1adbb6` appelle le getter du lecteur à l’offset de vtable `0x1b8`, puis stocke son résultat double dans `GNSoundFile + 0x18`. Pour WAVE, `0x249a24` renvoie le champ int32 du lecteur à `+0x24`, lu dans le chunk `fmt ` après le nombre de canaux : la fréquence d’échantillonnage.

Les deux valeurs de préparation sont donc multipliées par des frames/seconde. Elles représentent des extensions en secondes. Les constantes `100/100` du fournisseur de voix ne sont pas des pourcentages de gain. ELA004 avait identifié leur rôle dans le cache mais laissait l’unité ouverte ; ELA005 établit le lien avec la fréquence et nomme le champ natif `sample_rate`. Aucun gain n’est ajouté ni modifié.

Les additions d’indices et la conversion double vers int32 conservent les règles des instructions Intel, y compris le débordement sur 32 bits et la valeur indéfinie `0x80000000` des conversions NaN/dépassement. Les fréquences 44 100, 48 000 et 96 000 Hz, des valeurs fractionnaires, les limites et les entrées non finies sont incluses dans les comparaisons de préparation de plage.

## Comparaisons réalisées

| Corpus, par plateforme | Cas | Détail |
| --- | ---: | --- |
| Cache | 244 | 22 373 opérations de recherche, copie, réservation, invalidation et recherche d’emplacement réutilisable ; 2 932 172 octets comparés |
| Fichier et chemin de voix | 813 | Bornes, canaux, modes de lecture, erreurs, plages ; 1 641 lectures d’octets ; 2 315 081 octets comparés |

Les deux corpus passent bit à bit sur Linux x86-64 et AArch64 sous QEMU 7.2.0, sans reprise automatique de cas. Ils passent aussi avec le C++ x86-64 instrumenté par UBSan (`-fsanitize=undefined -fno-sanitize-recover=all`), notamment pour vérifier les calculs de bornes et les conversions exceptionnelles. Les hashes des cas concordent entre les trois variantes. Aucun arrêt QEMU n’a été observé dans ces essais ELA005 ; les observations antérieures restent conservées dans les preuves ELA003/ELA004.

Les 813 cas comprennent 198 intégrations avec le véritable lecteur de blocs de voix : boucles ordinaires et passant par la fin, sens normal/inverse, deux canaux, fondus simultanés et position suivante optionnelle. Vingt-quatre cas utilisent le WAV intégré inchangé, dont six passent par le bloc de voix. Le SHA-256 de ce WAV reste `3a34c829da83d0b79773927fd2d026479a8038f4f7666c29a745aff2968b342f`.

Le comparateur exécute les instructions i386 originales du fournisseur, du gestionnaire de fichier, du consommateur de cache et de la branche PCM WAVE vers le convertisseur, puis celles du bloc de voix lorsque demandé. Les getters WAVE de format/canaux/longueur et les petits accesseurs de handle/voix restent eux aussi des instructions originales. Les formats utilisés sur ce chemin sont PCM 8 bits non signé, 16/24/32 bits signé et float32 little-endian.

Les frontières adaptées sont `memcpy`/`memset`, le flux d’octets, le contexte local de thread, les callbacks du mutex et le mécanisme setjmp pour injecter une exception de lecteur. Les contextes d’exception sont dépilés par l’adaptateur de test ; cela vérifie la branche d’erreur et le déverrouillage, sans valider le runtime GN réel sur macOS. Tout appel d’hôte inattendu échoue. Les buffers, gardes, données du cache, tables, clients, diagnostics, traces de lectures/verrouillage et états de voix sont comparés.

Les en-têtes de fichiers et le contenu initial du cache sont fournis par les fixtures. Le banc ne parse pas encore les conteneurs avec le code original et ne lance pas le producteur asynchrone du cache. Il ne teste pas des mutations concurrentes du cache. Les callbacks de verrou sont observés et contrôlés, sans exécuter des lectures concurrentes de plateforme. Les tests ne chargent ni une banque utilisateur ni un instrument complet.

Les deux nouveaux sources compilent en objets Mach-O ARM64 (`0x0100000c`, `MH_OBJECT`). Les objets sont inclus dans l’archive détaillée. Il n’y a pas d’exécution macOS ni de validation `auval` à ce stade.

## Décompilation et suite

La phase Ghidra sélectionne 26 fonctions, dont neuf nouvelles, soit 227 fonctions distinctes décompilées au total. Les racines sont `analysis/ELA005-cache-lifecycle-roots.txt`. La session utilise `-readOnly` pour conserver le projet Ghidra existant ; les fichiers C, assembleur et le rapport sont sauvegardés séparément dans l’archive détaillée. Les tailles sans FDE de `0x2181d6`, `0x218cf6`, `0x218d48` et `0x249a24` sont vérifiées par instructions.

Le passage de remplissage `0x218d5e` (686 octets) parcourt les demandes de chaque client, réutilise ou ajoute un emplacement, appelle la lecture multicanal `0x1afed2` (695 octets), puis publie l’identifiant et la table de bloc. Sa routine d’allocation `0x21827e` (79 octets) est incorrectement typée void par Ghidra : les instructions renvoient bien l’ancien nombre d’emplacements dans EAX avant l’incrément. Ne pas recopier cette inférence de type. Ces fonctions, l’allocation initiale `0x217db8` et la sélection/ouverture des lecteurs sont sauvegardées pour la suite ; elles ne sont pas encore portées.

La prochaine étape est ce remplissage du cache et son cycle de vie, puis la planification hors du traitement audio et les conteneurs/codecs nécessaires. Le traitement complet d’une voix, le pitch/time stretching, les corps d’état et les liaisons AU/Cocoa restent à réaliser. L’ancien moteur instrumental n’est pas initialisé ni rendu, aucun ancien projet n’est restauré et aucune mesure de CPU du plugin sur Mac n’est disponible. Sophistry CP038 et CronoX CRX013 restent figés.

## Reproduction

Préparer l’original et le WAV selon ELA004. Avec le compilateur local Xcode/GCC :

```sh
python3 scripts/build_planar_sum_probe.py --kind sample-cache --output work/sample-cache-probe
python3 scripts/build_planar_sum_probe.py --kind sample-file --output work/sample-file-probe
work/venv/bin/python scripts/compare_original_sample_cache.py work/reference/Elastik.i386 work/sample-cache-probe --platform macos-local --output work/sample-cache-local.json
work/venv/bin/python scripts/compare_original_sample_file.py work/reference/Elastik.i386 work/sample-file-probe --wave work/builtin-demo/01drm120elastik_2.WAV --platform macos-local --output work/sample-file-local.json
```

Les sondes traitent toutes les fixtures dans un même processus, avec de nouveaux buffers pour chaque fixture. Les flags et empreintes de compilation se trouvent dans `evidence/ELA005/native-sample-path-build.json` ; les six rapports complets accompagnent cette preuve.

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -readOnly -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA005-cache-lifecycle analysis/ELA005-cache-lifecycle-roots.txt 1 ELA005
```

`analysis/ELA005-original-cache-file-decompiled.zip` conserve les 26 fonctions et les objets macOS ARM64. Le checkpoint public complet inclut aussi les sources, les scripts et les archives précédentes. L’installateur original, les banques, préférences, clés et projets personnels restent exclus. La publication relève de l’accord permanent dans `PUBLICATION_AUTHORIZATION.json`.
