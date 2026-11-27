# ELA011 — conteneur GNFA et lecture WAVE à l’intérieur de la banque

27 novembre 2026. Binaire original Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`. [Autorisation de publication permanente](../PUBLICATION_AUTHORIZATION.json). Sophistry CP038 et CronoX CRX013 sont conservés.

## Portage

| Adresse | Octets | Rôle |
| --- | ---: | --- |
| `0xe0a4c` | 1 815 | Lecture de l’en-tête GNFA et du répertoire |
| `0xe05a2` | 154 | Test « fichier » du chemin d’archive |
| `0xe09c0` | 139 | Taille du fichier, mot inférieur |
| `0xe3e38` | 443 | Choix du flux partagé ou d’un lecteur dédié |
| `0xe4172` | 663 | Lecture d’un membre et position logique 64 bits |
| `0xe440a` | 336 | Déplacement dans un membre |
| `0xe455a` | 362 | Déplacement à la fin d’un membre |
| `0xe063c` | 577 | Lecture matérialisée et appel du délégué de banque |

Huit routines / 4 489 octets supplémentaires ; total 57 routines / 35 551 octets dans leur domaine valide. Les 25 fichiers de sources natives d’ELA010 et antérieurs sont inchangés. Les fonctions internes `0xe0a4c` et `0xe063c` utilisent des registres i386 : les tests d’origine les appellent avec EAX et EDX, tandis que le C++ possède une interface typée native.

Le parseur ne se contente pas de reconnaître `GNFA`. Il lit les champs big endian, les noms UTF‑16, les longueurs signées/positions 64 bits et les deux dispositions du répertoire. Les objets GN, l’allocation, le flux brut, les exceptions, la résolution du chemin et les mutex sont des liaisons explicites. Le lecteur ne modifie aucune banque.

## Détails originaux conservés

L’en-tête fait au moins 20 octets. Le champ `+8`, conservé sans interprétation supplémentaire, n’est pas limité à une version supposée. Le champ `+12` non nul sélectionne le répertoire regroupé et positionne le drapeau de lecture seule ; la valeur zéro ne remet pas à zéro un ancien drapeau. Le nombre d’entrées peut être zéro, sans nouvelle allocation ni libération d’un ancien tableau. Les écritures partielles de l’état avant une exception sont conservées.

Chaque enregistrement lu contient 556 octets, tandis que le descripteur i386 en mémoire en utilise 576. La représentation native a sa propre disposition. Les noms comportent 256 unités UTF‑16 ; le contrat documenté exige un terminateur dans cette zone. Le champ final 64 bits est conservé sans lui attribuer de nouvelle fonction. Une longueur signée positive désigne un fichier, négative un répertoire ; une longueur zéro ne passe pas le test « fichier » original. La méthode de taille renvoie seulement le mot inférieur lorsque la longueur n’est pas négative.

Avec le répertoire regroupé, le champ de stockage contient la position des données. Avec les enregistrements successifs, les données commencent après l’enregistrement et le même champ sert à avancer au suivant. Le contrôle de limite porte sur la position de début d’enregistrement, avant la lecture obligatoire des 556 octets. Ne pas ajouter au cœur porté des règles de taille d’enregistrement ou de version absentes de l’original. Les allocations et indices doivent respecter les contrats exposés dans l’en-tête C++.

Si le flux peut être dupliqué et si l’option originale ne force pas le partage, la routine ouvre un lecteur dédié, le place sur le début des données et le conserve. Sinon, chaque lecture partagée verrouille, sauvegarde la position physique, se déplace vers le membre, lit, rétablit la position physique et déverrouille. Les positions et déplacements physiques utilisent le mot inférieur 32 bits comme l’original ; la position logique conserve ses 64 bits. L’ordonnancement concurrent réel reste à vérifier.

Une lecture arrivée à la limite peut copier un préfixe et renvoyer faux. Une demande de zéro octet dans le chemin d’archive renvoie aussi faux. Le résultat négatif d’une primitive de lecture fait d’abord avancer la position logique avec extension signée, puis le compte renvoyé devient zéro. Ces comportements sont comparés, sans correction de convenance. Les tests de positions négatives réservent des buffers assez grands pour observer les écritures originales, même quand le calcul historique augmente la taille demandée.

La lecture matérialisée vérifie le numéro et le type d’entrée, alloue avec le mot inférieur de longueur, verrouille les données et exige que le compte lu étendu corresponde à la longueur 64 bits. En cas d’erreur, l’exception survient avant le déverrouillage du chemin normal : le statut et le buffer partiel sont comparés, la durée de vie GN restant à intégrer. Après succès, le délégué optionnel reçoit les données, le bon objet de nom, puis les champs `field7` et `field6` dans cet ordre. Les tests utilisent des délégués synthétiques qui renvoient les mêmes données ou nul. Le traitement réel des banques protégées et de leur autorisation n’est pas encore porté ; il n’est pas remplacé par un succès forcé.

## Vérifications

| Corpus | Cas par configuration | Octets comparés par configuration |
| --- | ---: | ---: |
| Parseur, descripteurs, données et flux | 600 | 9 881 777 |
| GNFA → WAVE → PCM/MS/DVI | 64 | 4 222 190 |
| Total | 664 | 14 103 967 |

Les deux corpus passent bit à bit sur x86‑64, ARM64 Linux sous QEMU, x86‑64/UBSan et x86‑64/ASan+UBSan. Les noms et empreintes de tous les cas correspondent entre les quatre configurations ; aucune nouvelle tentative automatique. Les contrôles couvrent notamment les lectures courtes, erreurs, deux dispositions, champs 64 bits, noms vides/longs/surrogates UTF‑16, flux partagé/dédié, fin de fichier, conservation de la position physique et identité des objets de nom transmis au délégué. Les noms GN sont représentés par des objets de test ; leur implémentation Unicode et leurs références réelles restent des liaisons.

Le test d’intégration C++ utilise un seul exécutable : le décodeur WAVE appelle directement le lecteur de membre GNFA. La référence utilise deux VM i386 épinglées : l’I/O brute du parseur WAVE appelle les vraies routines du lecteur d’archive dans la seconde VM. Les octets WAVE ne sont pas extraits avant l’essai, et ni les métadonnées d’en-tête ni les samples décodés ne sont injectés. Les appels de plateforme des deux couches et les buffers sont comparés. La banque d’origine contient aussi `Info.plist`, dont le rejet en tant que WAVE est testé.

La banque intégrée est le fichier `Elastik.elastik` livré dans le composant fourni, 708 820 octets, SHA-256 `9b4aca313f9ba24da8c4c2b2473f4023ca9a3efcd009d117644c3a46e2be0f84`. Ses trois entrées comprennent le répertoire `elastik`, le WAV de 707 036 octets et `Info.plist`. La référence WAV privée sert seulement au contrôle audio indépendant ; elle n’est pas fournie à l’exécutable natif de lecture de banque.

Les 176 399 frames stéréo du sample sont identiques à `int16/32768` sur x86‑64 et ARM64/QEMU, avec les deux modes de flux. Empreinte float32 entrelacée inchangée : `555760159fb2f5e4331d3df06df12c1e659b27585601687f8ab364cd3e3d4ef3`. Le lecteur conserve la position du flux du conteneur. La banque, le WAV et les rendus audio ne sont pas publiés.

Un objet Mach-O `MH_OBJECT`, CPU `0x0100000c` ARM64, est compilé depuis `OriginalFileArchive.cpp`. Ce n’est pas un composant AU ; pas d’exécution macOS ou d’`auval`. Les commandes, empreintes, contrôles stricts et huit rapports de comparaison sont dans [evidence/ELA011](../evidence/ELA011).

## Reproduction

Avec l’environnement Python de recherche, le binaire et les ressources privés extraits du paquet fourni :

```sh
python3 scripts/build_planar_sum_probe.py --kind file-archive --output work/ELA011-native/FileArchiveProbe-host
python3 scripts/build_planar_sum_probe.py --kind archive-wave --output work/ELA011-native/ArchiveWaveProbe-host
python3 scripts/compare_original_file_archive.py reference/Elastik.i386 work/ELA011-native/FileArchiveProbe-host --platform local --output work/file-archive-local.json
python3 scripts/compare_original_archive_wave.py reference/Elastik.i386 work/ELA011-native/ArchiveWaveProbe-host --wave work/builtin-demo/01drm120elastik_2.WAV --platform local --output work/archive-wave-local.json
python3 scripts/verify_archive_wave_audio.py work/ELA011-native/ArchiveWaveProbe-host --wave work/builtin-demo/01drm120elastik_2.WAV --platform local --output work/archive-audio-local.json
```

Le chemin par défaut de la banque intégrée est conservé dans le comparateur ; `--builtin` permet d’indiquer le même fichier ailleurs. Son SHA-256 est exigé pour les cas de référence. Les archives synthétiques sont générées par les tests. Sur Mac, le script choisit `xcrun --find clang++`. Les variantes ARM64/QEMU et celles avec détecteurs d’erreurs sont consignées dans [build-commands.json](../evidence/ELA011/build-commands.json).

Ghidra 11.3.2, projet en lecture seule, profondeur 1 : [racines archive](ELA011-archive-roots.txt) et [racines parseur](ELA011-parser-roots.txt). Deux jeux de 44 et 26 fonctions, soit 58 distinctes dont 38 nouvelles ; total 322 distinctes. L’[archive détaillée](ELA011-original-gnfa-decompiled.zip) conserve les C/ASM exportés et les manifestes. Les libellés génériques de checkpoint/portée des manifestes sont adaptés à ELA011.

## Suite

Porter la recherche de chemin `0xdf8d2`, les fabriques `0xe3ff4` et `0xe2c14` et leur durée de vie GN, puis le catalogue et le délégué `ETSoundbank`. Le choix d’un membre par indice dans ces tests ne prouve pas encore le chargement d’une banque utilisateur par son nom. La construction du flux du système et la base GNFile restent des liaisons. Continuer ensuite les formats nécessaires, la voix complète, le pitch/time stretching, les états, Cocoa et l’AU. Les banques personnelles et un état Elastik réel restent à recevoir ; leur compatibilité, l’activation, les anciens projets et les performances du moteur complet ne sont pas validés.

Les sauvegardes précédentes sont conservées. Pour libérer de la place, seules huit copies isolées de bundles Git, strictement identiques à leurs copies dans les ZIP privés vérifiés, ont été retirées. Le relevé privé précise chaque archive, membre, chemin et empreinte pour les réextraire ; aucun ZIP de checkpoint, original ou fichier de source n’a été supprimé.
