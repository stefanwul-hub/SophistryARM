# ELA006 — remplissage du cache depuis les octets PCM

Ce checkpoint porte le passage de remplissage du cache. Le banc peut maintenant partir d’un cache vide, lire les octets encodés du sample, remplir ses blocs planaires, puis alimenter le fournisseur de samples et les blocs de voix. Les nouveaux blocs ne sont pas remplacés par des samples décodés fournis par le test.

| Adresse originale | Octets | Traduction native |
| --- | ---: | --- |
| `0x1afed2` | 695 | Lecture multicanal directe, bornes, lecteur commun ou paire mono, verrou et erreur |
| `0x21827e` | 79 | Allocation d’un buffer supplémentaire et retour de son indice |
| `0x218d5e` | 686 | Passage complet sur les demandes actives : réutilisation, croissance, lecture, publication |

Les 1 460 octets d’origine concernés portent le total à 18 routines traduites / 9 604 octets d’origine. Les sources sont `src/OriginalSampleFile.cpp/.h` et `src/OriginalCacheRefill.cpp/.h`. La représentation native du cache autorise désormais l’écriture des blocs et de leur table. Les formats et les données audio des routines précédentes restent inchangés.

## Règles originales conservées

Le passage parcourt les demandes de chaque client actif, borne de fin incluse. Un bloc déjà présent n’est pas relu. Il utilise la recherche d’emplacement réutilisable ELA005, qui protège les demandes de tous les clients. Si aucun emplacement ne convient, il alloue un buffer et incrémente le nombre d’emplacements. La table n’est pas réparée si une ancienne entrée incohérente retrouve malgré tout le bon bloc par recherche.

Avant la lecture, il retire l’ancienne correspondance du bloc réutilisé et met son identifiant à `-1`. Après la lecture, il écrit le nouvel identifiant, puis sa correspondance dans la table. Les sondes observent aussi cet état intermédiaire pendant les lectures : elles comparent les drapeaux, identifiants, liens de table et allocations, et pas seulement le résultat final.

**Le passage original ignore le booléen renvoyé par le lecteur multicanal.** Il publie donc aussi le bloc après une exception de lecture interceptée. Le port conserve ce comportement et les données restantes du buffer. Les tests de ces erreurs utilisent une mémoire initiale déterministe ; cela ne constitue pas un chargement réussi de banque ni une correction de cette règle d’origine.

Le lecteur multicanal remet les buffers non nuls à zéro lorsque la plage dépasse les limites du fichier, puis lit la portion valide. Comme le lecteur d’un canal, un début négatif réduit la longueur sans décaler la destination. La branche de lecteurs mono séparés appelle toujours ses deux lecteurs, même si une sortie est désactivée. Une erreur du second lecteur laisse les données déjà écrites par le premier ; le verrou partagé est libéré et le lecteur renvoie false. Aucun test de fermeture absent de cette routine originale n’est ajouté : un lecteur valide est requis si l’opération atteint réellement la lecture.

Le passage remet le drapeau de manque de données à zéro, marque le traitement en cours, puis enlève cette marque à la fin. Lorsque le profilage est actif, il soustrait puis ajoute l’horloge en double précision, dans l’ordre original. Les valeurs nulles, négatives nulles, les appels sans client, les passages répétés sans nouveau chargement et les limites d’allocation sont comparés.

## Comparaisons

| Corpus, par plateforme | Cas | Mesures du banc |
| --- | ---: | --- |
| Lecture multicanal | 301 | 942 lectures d’octets ; 884 421 octets de résultats, gardes, buffers et traces comparés |
| Remplissage et chemin jusqu’aux voix | 577 | 1 707 passages de remplissage, 9 402 lectures d’octets ; 3 304 055 octets comparés |
| Régression du cache ELA005 | 244 | Les 244 hashes de cas, couvrant 22 373 opérations, restent identiques au rapport ELA005 |
| Régression du chemin ELA005 | 813 | Chaque hash de cas est identique à ELA005, dont les 198 intégrations de blocs de voix |

Les 878 nouveaux cas concordent bit à bit avec les instructions originales i386 sur le C++ Linux x86-64 et le C++ AArch64 sous QEMU 7.2.0. Les deux nouveaux corpus passent aussi avec UBSan sur x86-64 (`-fsanitize=undefined -fno-sanitize-recover=all`). Les 1 057 cas ELA005 repassent sur x86-64 et AArch64, avec leurs hashes précédents inchangés. Aucun nouvel essai automatique n’est effectué après un échec et aucun arrêt QEMU n’a été observé dans ces essais ELA006.

Les scénarios couvrent le cache vide, les buffers préalloués, la protection et la réutilisation des blocs, les demandes qui se chevauchent, les passages suivants sans relecture, l’invalidation, la croissance et son retour d’indice, les fins de fichier avec padding, les erreurs de lecteurs et les lectures partielles. Deux cas jouent le traitement de bloc avant puis après le remplissage, avec inversion et fondus. Douze cas multicanaux et six cas de remplissage utilisent les véritables octets du WAV intégré, au début, au milieu et à la fin. Ce WAV n’est pas publié ; son SHA-256 reste `3a34c829da83d0b79773927fd2d026479a8038f4f7666c29a745aff2968b342f`.

La référence exécute le passage original, l’ajout de slot, la lecture multicanal, la branche PCM WAVE, le convertisseur, le consommateur du cache, le fournisseur et les blocs de voix. L’image i386 est imposée par son SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. Toute frontière d’hôte inattendue provoque un échec.

Les frontières adaptées sont l’allocateur GN et l’alerte de capacité, le flux d’octets, memcpy/memset, le mutex partagé, le contexte de thread et l’injection d’une exception de lecteur. L’horloge Carbon `_GetCurrentEventTime` est liée à des valeurs déterministes. Son retour i386 est fourni par de véritables instructions x87 FLD/RET, puis les FSTP et calculs SSE de l’original s’exécutent normalement. MXCSR est fixé à `0x1f80` et le contrôle x87 à `0x037f` ; les registres de statut d’exception flottante ne sont pas comparés.

Les pointeurs de buffers sont comparés sous forme d’indices logiques, car les adresses et tailles de pointeurs diffèrent entre i386 et ARM64. Les allocations du test renvoient des buffers préparés pour observer leur contenu initial et final. Les métadonnées de fichiers et la capacité physique des tables sont établies par la fixture. Les chemins d’épuisement mémoire GN, le véritable dialogue de capacité, le parseur d’en-têtes WAVE et des modifications concurrentes du cache ne sont pas validés. Les lecteurs fournissent un statut à l’interface native pour représenter l’exception GN interceptée ; son runtime macOS reste à adapter.

Trois objets Mach-O ARM64 sont compilés : consommateur de cache, gestionnaire de fichier et remplissage. Leurs en-têtes sont contrôlés (`0x0100000c`, `MH_OBJECT`) et leurs empreintes sont enregistrées. Ils ne constituent pas un Audio Unit.

## Cycle de vie et timer identifiés pour la suite

`GNSoundFile` crée paresseusement son cache dans `0x1ac9dc`, initialise `GNSoundFileCache` par `0x218aa6` puis `0x218b82`. Le code installe un `GNTimer` via `0x70218`, avec un intervalle répété de 0,2 seconde. `0x6fdb4` appelle `_GetCurrentEventLoop` puis `_InstallEventLoopTimer`. Le callback `0x217fd0` transmet l’appel à la vtable `+0x1a8`, soit le passage `0x218d5e` pour le cache de samples.

Cela identifie un timer Carbon lié à la boucle d’événements courante ; le banc ne lance pas un ordonnanceur natif ni ne démontre un thread autonome équivalent. La création, la rétention, l’annulation et la destruction du timer/cache, ainsi que l’adaptation à Cocoa/CFRunLoop et les garanties d’accès concurrent sur ARM64, restent à porter. Le test appelle directement les passages originaux et natifs.

Ghidra avait inféré void pour `0x21827e`. Les instructions `MOV EAX,[EDI+0x1c]`, `LEA EDX,[EAX+1]`, `MOV [EDI+0x1c],EDX` suivies de l’épilogue prouvent que EAX conserve l’ancien nombre de slots. Le script Ghidra vérifie ces octets et annote maintenant un retour int32 avec un paramètre de pile cdecl. Les anciens ZIP sont conservés ; aucune instruction du binaire n’est modifiée.

La phase ELA006 sauvegarde 24 fonctions sélectionnées, dont 11 nouvelles, soit 238 décompilations distinctes au total. Les racines et les tailles manuelles vérifiées des deux thunks sont enregistrées dans `analysis/ELA006-refill-lifecycle-roots.txt`. Le projet Ghidra est ouvert avec `-readOnly`, les sorties étant sauvegardées séparément.

## Reproduction

Préparer l’original et le WAV selon ELA004, puis utiliser Xcode/GCC :

```sh
python3 scripts/build_planar_sum_probe.py --kind sample-file --output work/sample-file-probe
python3 scripts/build_planar_sum_probe.py --kind cache-refill --output work/cache-refill-probe
work/venv/bin/python scripts/compare_original_multichannel_file.py work/reference/Elastik.i386 work/sample-file-probe --wave work/builtin-demo/01drm120elastik_2.WAV --platform macos-local --output work/multichannel-local.json
work/venv/bin/python scripts/compare_original_cache_refill.py work/reference/Elastik.i386 work/cache-refill-probe --wave work/builtin-demo/01drm120elastik_2.WAV --platform macos-local --output work/cache-refill-local.json
```

Les sondes traitent le corpus dans un seul processus, avec des buffers réinitialisés par fixture. Une réponse tronquée est désormais arrêtée après 15 secondes au lieu de pouvoir attendre indéfiniment la suite ; un test vérifie aussi le code d’échec et les échanges successifs normaux. Aucun cas n’est relancé. L’entrée/sortie commune aux deux sondes est dans `tests/SampleProbeIO.h`. Les flags, empreintes et résultats sont dans `evidence/ELA006/` ; les dix rapports complets incluent les régressions ELA005.

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -readOnly -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA006-refill-lifecycle analysis/ELA006-refill-lifecycle-roots.txt 1 ELA006
```

Le checkpoint complet inclut les sources, les rapports et les archives détaillées. `analysis/ELA006-original-refill-lifecycle-decompiled.zip` contient cette phase, les classes sélectionnées et les objets macOS ARM64. La publication est couverte par `PUBLICATION_AUTHORIZATION.json`. L’installateur, les banques et les données personnelles restent exclus.

Le moteur instrumental complet n’est pas encore initialisé ni rendu, les corps d’état et le rappel d’un ancien projet restent à établir, et aucun AU installable ou `auval` n’est disponible. Sophistry CP038 et CronoX CRX013 restent figés.
