# ELA007 — cycle de vie du cache et contrôle des timers

Les allocations et les états du cache étaient fournis par les fixtures ELA006. Ce checkpoint traduit les routines originales qui les initialisent et les gèrent, ainsi que le contrôle du timer déclenchant les passages de remplissage. Le backend de boucle d’événements macOS n’est pas encore raccordé.

| Adresse originale | Octets | Traduction |
| --- | ---: | --- |
| `0x217cd2` | 128 | Initialisation des champs du cache, hors objet GN de base |
| `0x217db8` | 291 | Allocation des slots, table et clients |
| `0x218b82` | 359 | Configuration depuis le fichier et scratch partagé |
| `0x2182e0` | 242 | Acquisition ou réutilisation d’un client |
| `0x2183d2` | 25 | Libération du client sans réduire le compteur maximal atteint |
| `0x217fe2` | 90 | Création et rétention du timer répété à 0,2 seconde |
| `0x21803c` | 49 | Annulation et libération du timer du cache |
| `0x217edc` | 151 | Nettoyage du timer, du délégué et des buffers/table/clients |
| `0x6fdb4` | 594 | Installation du timer à callback |
| `0x6faba` | 762 | Installation du timer à nom d’action et gestionnaire |
| `0x6f75c` | 173 | Annulation et retrait du registre de nettoyage |
| `0x6f80a` | 354 | Déclenchement direct, avec pool temporaire |
| `0x6fa3c` | 125 | Rappel événementiel avec indicateur global de suspension |
| `0x6f96c` | 82 | Nettoyage du timer et des objets d’action retenus |

Ces 14 routines représentent 3 425 octets d’origine. Le total est de 32 routines / 13 029 octets dans les domaines de validité documentés. Les assertions GN, échecs d’installation système, épuisement mémoire et mécanismes d’objets GN sont des frontières explicites, pas une implémentation complète du framework. Les sources utilisent des structures natives ; elles ne recopient pas les objets i386 sur ARM64.

## Cache : règles conservées

L’initialisation ne remet à zéro que les champs écrits par l’original. La taille de buffer initiale est `0x4000`. Les pointeurs de tableaux, compteur de clients, dimensions du fichier et autres champs non écrits restent inchangés. La construction spécialisée du cache audio et sa fabrique paresseuse sont analysées, mais ne font pas partie des 14 traductions.

L’allocation utilise `cache_bytes / block_bytes + 2`, ou `(0x40000000 / block_bytes) * 2 + 2` si la taille demandée vaut zéro. Le maximum de clients par défaut est `0x5000`. Les identifiants des slots et la table sont initialisés à `-1` ; les pointeurs inutilisés et les trois octets de padding de chaque client restent intacts. Les buffers sont alloués pour les slots déjà comptés. Cette méthode n’est pas un redimensionnement : elle remplace les tableaux sans libérer leur ancien stockage.

Le cache audio prend ses canaux et sa durée des getters originaux du fichier, choisit des blocs de `0x4000` frames et des buffers de `canaux * 0x10000` octets. Son scratch encodé partagé ne peut que croître. Une taille identique ou plus petite ne le réalloue pas. Le format encodé `file+0x20` est désormais représenté dans `OriginalSampleFile.h`, séparément du format de canaux. Ces formats du framework ne sont pas les numéros de formats des en-têtes WAV.

Un client libéré garde sa place ; l’acquisition réutilise le premier inactif et remet sa plage à `-1/-1`. Le compteur ne redescend pas. Le banc compare aussi l’alerte de capacité avec une frontière qui revient et du stockage physique supplémentaire ; il ne valide pas le comportement fatal du vrai dialogue GN.

Le nettoyage annule le timer, relit son pointeur avant de le libérer, puis libère délégué, buffers et trois tableaux dans l’ordre original. Un cas vérifie qu’une annulation effaçant déjà le pointeur du propriétaire n’entraîne pas de seconde libération. Les pointeurs de tableaux et compteurs restent inchangés : ce nettoyage s’utilise une seule fois. Le banc diffère la désallocation physique jusqu’à la fin de la fixture pour observer ces champs ; cela ne rend pas le stockage réutilisable dans le moteur.

## Timer : annulation et durée de vie

L’original utilise `NewEventLoopTimerUPP`, `GetCurrentEventLoop` et `InstallEventLoopTimer` dans la boucle courante. Un timer répété reprend son délai comme intervalle ; un timer ponctuel utilise l’intervalle zéro. Le cache choisit 0,2 seconde répétée. La traduction exprime ces opérations par une interface ; elle ne choisit pas un thread ou un autre mode de boucle.

Le slot de vtable `+0x48` est **autorelease**. Il ne représente pas une libération immédiate. Le démarrage retient le timer pour sa durée d’activité. L’annulation demande l’autorelease de cette référence s’il est actif, marque l’objet inactif, retire le handle système s’il existe, puis retire toujours son entrée du registre, même lors d’une seconde annulation.

Un rappel actif crée un pool temporaire de capacité 10. Un timer ponctuel s’annule **avant** le code utilisateur. Il transmet ensuite l’action éventuelle, appelle le callback s’il existe encore, vide la file globale d’après-dispatch, puis libère le pool en dernier. Un callback peut annuler son propre timer ; le vrai pool devra garantir sa durée de vie jusqu’à la fin de ce chemin. Le banc compare l’ordre autorelease/pool ; il ne teste pas encore le comptage réel des références ou la destruction par vidage du pool.

Le rappel Carbon ignore l’événement si l’indicateur global de suspension est non nul ; le déclenchement direct l’ignore. Les écritures moins habituelles de l’original restent présentes : le démarrage à fonction efface l’ancien nom d’action sans le libérer et laisse le gestionnaire ; le nettoyage sans handle n’impose pas un nouveau drapeau actif. Les tests couvrent ces états sans en faire des recommandations d’usage.

Les getters de classe `0x217c04`, `0x218a58` et `0x6f604` ne sont pas des destructeurs. Les commentaires des racines ont été corrigés après inspection des instructions et des slots de vtable. Le nettoyage GN est au slot `+0x4c`.

## Comparaisons et limites

| Corpus, par plateforme | Cas | Comparaison |
| --- | ---: | --- |
| Cycle de vie du cache | 195 | 244 192 124 octets d’états, tables, clients et traces ; 2 276 événements de frontière |
| Contrôle des timers | 280 | 184 208 octets d’états et traces ; 3 446 événements de frontière |
| Régression de lecture et blocs de voix | 813 | Tous les hashes de cas ELA005/ELA006 restent identiques |
| Régression de remplissage | 577 | Tous les hashes ELA006 restent identiques ; 1 707 passages, 9 402 lectures |

Les deux nouveaux corpus concordent bit à bit sur x86-64, ARM64 Linux sous QEMU 7.2.0 et x86-64 avec UBSan. Les états sont comparés après chaque opération et les appels de plateforme dans l’ordre. Les pointeurs sont normalisés en identifiants logiques ; les pointeurs inutilisés empoisonnés par l’allocateur ne sont pas déréférencés. Le padding des clients est comparé. Les 1 390 scénarios de régression repassent sur x86-64 et ARM64. Aucun retry automatique n’est effectué.

La référence exécute les instructions originales inchangées des 14 routines, les getters de métadonnées et la recherche de largeur PCM. Le SHA-256 i386 est imposé : `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. Les frontières remplacées sont les allocateurs GN, les objets opaques, la fabrique de timer du cache, les API Carbon et le registre de nettoyage, les pools/actions temporaires et les corps de callbacks. Ces derniers peuvent annuler ou modifier le timer pour vérifier les écritures réentrantes.

La création des tableaux et le contrôle du timer sont testés séparément. Les fixtures délivrent les événements directement ; elles ne lancent pas une horloge réelle ou un thread natif. La concurrence, le vrai runtime GN, l’épuisement mémoire et les erreurs d’installation système ne sont pas validés. Ces nouveaux essais ne constituent pas un test audio du moteur complet. Les régressions conservent les comparaisons PCM et blocs de voix précédentes.

Deux objets Mach-O ARM64 sont compilés et leur en-tête est contrôlé (`0x0100000c`, `MH_OBJECT`). Ils ne sont pas des Audio Units et ne sont pas exécutés sous macOS. Sources, versions, empreintes et rapports sont dans `evidence/ELA007/`. Ghidra conserve 40 fonctions pour cette phase, dont 24 nouvelles, soit 262 décompilations distinctes au total. Le projet est ouvert avec `-readOnly` ; le ZIP conserve C, assembleur, rapport, racines et objets compilés.

## Reproduction

Avec l’original extrait et les dépendances Unicorn/Capstone des checkpoints précédents :

```sh
python3 scripts/build_planar_sum_probe.py --kind cache-lifecycle --output work/cache-lifecycle-probe
python3 scripts/build_planar_sum_probe.py --kind timer --output work/timer-probe
work/venv/bin/python scripts/compare_original_cache_lifecycle.py work/reference/Elastik.i386 work/cache-lifecycle-probe --platform macos-local --output work/cache-lifecycle-local.json
work/venv/bin/python scripts/compare_original_timer.py work/reference/Elastik.i386 work/timer-probe --platform macos-local --output work/timer-local.json
```

La recette suppose l’original sous `work/reference`, comme l’extraction proposée précédemment ; notre environnement garde sa copie privée sous `reference/Elastik.i386`. Sur macOS le script choisit le `clang++` de Xcode. Ces commandes sont facultatives à ce stade : elles ne compilent ni n’installent de plugin.

Pour l’analyse :

```sh
analyzeHeadless work/ghidra-project Elastik1 -process Elastik.i386 -readOnly -noanalysis -scriptPath scripts/ghidra -postScript AuditElastikFunctions.java evidence/ELA001/function-ranges.csv work/ELA007-lifecycle analysis/ELA007-lifecycle-roots.txt 1 ELA007
```

Le checkpoint public comprend sources, rapports, schémas et archives détaillées. L’accord permanent `PUBLICATION_AUTHORIZATION.json` couvre cette publication ; installateur, banques et données privées restent exclus. La sauvegarde privée locale comprend aussi le binaire et un bundle Git.

Prochaine étape : poursuivre le lecteur de fichiers, en commençant par le parseur WAVE original `0x24ce76`, déjà décompilé (11 316 octets), puis les chemins nécessaires aux voix/pitch. Le raccordement natif des timers et objets GN, les conteneurs de banques/codecs et les corps d’état restent à traiter. Aucun AU installable, `auval`, moteur instrumental complet ou rappel de projet n’est encore disponible. Sophistry CP038 et CronoX CRX013 restent figés.
