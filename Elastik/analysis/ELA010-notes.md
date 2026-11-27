# ELA010 — ouverture des samples et raccordement WAVE/cache/blocs de voix

27 novembre 2026. Référence Intel i386 Elastik 1.5.2.3, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. Sophistry CP038 et CronoX CRX013 restent figés. Publication couverte par [l’autorisation permanente](../PUBLICATION_AUTHORIZATION.json).

## Routines portées

| Adresse originale | Octets | Fonction |
| --- | ---: | --- |
| `0x219202` | 464 | Fabrique de lecteurs et gestion des formats refusés |
| `0x1adbb6` | 840 | Ouverture du fichier et association de lecteurs mono |
| `0x1ac9dc` | 105 | Création paresseuse du cache et lancement du timer |
| `0x219a4c` | 263 | Projection des métadonnées communes |
| `0x249f1e` | 126 | Projection WAVE et compteur Melodyne historique |

Total : cinq routines / 1 798 octets supplémentaires ; 49 routines / 31 062 octets traduits dans leur domaine valide. Les 23 anciens fichiers de sources natives sont inchangés. Les wrappers natifs ne reproduisent pas la disposition mémoire i386 : les objets, méthodes virtuelles, chemins et exceptions GN passent par des interfaces explicites.

La fabrique essaie AIFF, WAVE, SND puis SDII. Seule l’exception `GNSoundFileFormatNotSupportedException`, y compris ses sous-classes classées par la liaison, autorise l’essai suivant. Une erreur de lecture ou une autre exception doit remonter. Le cinquième passage original n’a aucun lecteur ; son cadre d’exception reste une opération du runtime GN.

Le lecteur principal est conservé avant ses getters. Une seule voie, exactement la valeur 1, déclenche la recherche d’un partenaire mono. La fréquence du candidat est lue avant celle du principal, puis le format et la longueur, avec arrêt à la première différence. L’égalité des fréquences est exacte et rejette les NaN. La fréquence, le format et la longueur suffisent à la décision originale : ne pas ajouter une vérification du nombre de canaux du partenaire. L’ordre des remplacements de chemins et des retain/release est conservé ; le lecteur principal reste le même même lorsqu’il représente le côté droit. Un échec ultérieur ne rétablit pas l’état antérieur.

La fonction `0x1ac468`, qui déduit le nom du fichier partenaire, n’est pas encore traduite : elle constitue une liaison déclarée. Les corps des lecteurs AIFF/SND/SDII restent également à porter. Le test continu fournit uniquement des WAVE valides et lie explicitement le rejet AIFF ; le test de contrôle vérifie séparément les quatre essais de lecteurs et leurs erreurs.

Les métadonnées `chunks` et `privateChunks` sont copiées par référence, dans cet ordre. La routine WAVE ajoute `Melodyne1WaveSampleCount = frames - data_offset / (channels * sample_bytes)`. Cette formule historique est conservée, y compris son décalage d’octets ; elle n’est pas utilisée pour changer le nombre de frames audio. La division entière et la soustraction 32 bits ont le comportement i386 dans le domaine documenté.

Le cache est publié sur le fichier avant sa configuration. Un cache existant provoque un retour immédiat ; les appels répétés ne recréent ni tableaux ni timer. La configuration, l’acquisition de clients et le remplissage exécutent les ports précédents. Le timer est encore une liaison de test avec remplissage déclenché séquentiellement ; l’ordonnancement macOS et la concurrence réelle ne sont pas validés.

## Vérifications

| Corpus | Cas par configuration | Octets comparés par configuration |
| --- | ---: | ---: |
| Fabrique, ouverture, association et métadonnées | 1 481 | 618 268 |
| Fichier WAVE → cache → fournisseur → blocs de voix | 74 | 18 131 090 |
| Total | 1 555 | 18 749 358 |

Chaque corpus passe bit à bit face aux instructions originales inchangées dans Unicorn : exécutable C++ x86-64, exécutable C++ ARM64 Linux sous QEMU, x86-64/UBSan, x86-64/ASan+UBSan. Les noms et empreintes de tous les cas sont identiques entre les quatre configurations, sans nouvelle tentative automatique. La fabrique, l’ouverture, la création paresseuse du cache, le parseur WAVE, les conversions PCM/ADPCM, le remplissage, le fournisseur et les blocs de voix s’exécutent réellement côté i386. Les champs d’en-tête et les données audio du cache ne sont pas injectés comme résultats attendus.

Chaque scénario continu effectue trois lectures d’un bloc de voix : cache froid, cache rempli, puis lecture directe. Les buffers, états des rampes, positions, cartes du cache, samples de tous les blocs alloués et appels de plateforme sont comparés. PCM8/16/24/32, float32, MS/DVI ADPCM, métadonnées musicales, marche arrière, boucles et appels répétés de création de cache sont couverts. Les primitives GN, leur durée de vie réelle, les exceptions OS, le mutex, le timer et l’I/O restent des liaisons identifiées ; cela ne valide pas encore le framework GN complet.

Une seconde vérification extrait les 176 399 frames stéréo des onze blocs du cache issus du WAV intégré et les compare à `int16/32768` calculé indépendamment. Elle passe sur x86-64 et ARM64/QEMU. Le dernier bloc est complété par zéro et les échantillons de voix lus depuis le cache correspondent à la lecture directe. L’empreinte float32 entrelacée reste `555760159fb2f5e4331d3df06df12c1e659b27585601687f8ab364cd3e3d4ef3`. Aucun WAV original ou rendu n’est publié.

Un objet Mach-O `MH_OBJECT`, CPU `0x0100000c` ARM64, est compilé depuis `OriginalFileOpen.cpp`. Ce n’est pas un composant AU et il n’a pas été exécuté sous macOS. Les commandes, empreintes, contrôles syntaxiques stricts et rapports complets figurent dans [evidence/ELA010](../evidence/ELA010).

## Reproduction

Avec le binaire privé extrait du paquet original, le WAV intégré et l’environnement Python de recherche existant :

```sh
python3 scripts/build_planar_sum_probe.py --kind file-open --output work/ELA010-native/FileOpenProbe-host
python3 scripts/build_planar_sum_probe.py --kind file-pipeline --output work/ELA010-native/FilePipelineProbe-host
python3 scripts/compare_original_file_open.py reference/Elastik.i386 work/ELA010-native/FileOpenProbe-host --platform local --output work/file-open-local.json
python3 scripts/compare_original_file_pipeline.py reference/Elastik.i386 work/ELA010-native/FilePipelineProbe-host --wave work/builtin-demo/01drm120elastik_2.WAV --platform local --output work/file-pipeline-local.json
python3 scripts/verify_file_pipeline_audio.py work/ELA010-native/FilePipelineProbe-host --wave work/builtin-demo/01drm120elastik_2.WAV --platform local --output work/file-cache-audio-local.json
```

Sur Mac, le constructeur de sondes choisit `xcrun --find clang++`. Pour ARM64/QEMU et les détecteurs mémoire, [build-commands.json](../evidence/ELA010/build-commands.json) consigne les commandes exécutées ici. Les chemins de l’outil Zig et du cache sont propres à l’environnement ; les sources et options sont explicites. Les tests de comparaison nécessitent Unicorn. Aucune commande n’installe de plugin.

Ghidra 11.3.2, projet en lecture seule, profondeur d’appels directs 1 : 26 fonctions C/ASM sauvegardées, dont trois nouveaux constructeurs AIFF/SND/SDII ; 284 adresses distinctes décompilées au total. L’[archive détaillée](ELA010-original-file-open-decompiled.zip) conserve les sources C et ASM telles qu’exportées ; seuls les libellés de checkpoint et de portée de son manifeste sont adaptés depuis les valeurs génériques du script.

## Suite

Continuer vers les conteneurs de banques et les lecteurs nécessaires à Elastik, la recherche du partenaire mono et les objets GN natifs. La voix complète, le pitch/time stretching, les corps d’état sauvegardés, l’interface Cocoa et l’AU restent à réaliser. Aucun ancien projet Elastik n’a encore été restauré. Les références utilisateur aux banques sont enregistrées, leurs fichiers et un état réel ne sont pas encore reçus.
