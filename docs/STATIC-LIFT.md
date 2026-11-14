# Traduction statique sélectionnée — CP-008

## Provenance et méthode

Entrée : tranche i386 SHA-256 `17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12`. Ghidra 11.3.2, langage `x86:LE:32:default`.

`ExportPcode.java` relève les instructions et leurs opérations p-code brutes, avec les espaces mémoire, tailles et adresses des opérandes. Le résultat diffère du pseudo-C du décompilateur : il conserve les chargements, copies partielles, arrondis float/double, flags et sauts.

`lift_pcode_cpp.py` produit des opérations C++ et des labels fixes. Les appels et retours maintiennent la pile 32 bits dans un espace mémoire possédé par le runtime. Les cibles directes deviennent des branchements compilés ; les cibles indirectes passent par un dispatch vers le code sélectionné ou des adaptateurs hôtes explicites. Il n’existe aucun lecteur/décodeur d’opcodes x86 au runtime. Un PC absent ou un accès hors mémoire fait échouer le probe ; les opérations non prises en charge font échouer la génération.

Le lifter est expérimental, sélectionné et incomplet. Il ne doit pas être présenté comme une conversion du moteur entier. Les appels indirects et données d’initialisation du synthétiseur complet ne sont pas encore reconstruits. La liste exacte des 19 fonctions et les 3 242 instructions est dans `analysis/lifter-all/`.

## Routines couvertes

- `0x73fb0` : saturation, avec l’addition de sortie originale `0xc14e4`.
- `0x7a1ac` : dispatch de FilterMoogSI et huit chemins internes mono/stéréo pour les quatre modes de dispatch testés.
- `0xaf2b2` : moyenne des canaux stéréo vers mono ; libération remplacée par un no-op dans le seul contexte des buffers possédés par le test.
- `0x32430` : normalisation par les extrema, avec le seuil original de non-intervention autour de l’unité.
- `0x8de6a` et `0x8d9dc` : construction et interpolation/crossfade des 64 tables Schrader de 128 floats, avec atténuation des bords et normalisation.
- `0x38f48` : lecteur Schrader, interpolation de phase et entre tables, états de voix et chemins de routage testés.
- Helpers de division et thunks PIC directement appelés par ces routines.

Les conversions IEEE vers stockage étendu x87 et inversement sont explicites et ne dépendent pas de la taille du `long double` ARM64. L’arithmétique générale en 80 bits n’est pas implémentée ; elle est refusée si nécessaire. Les cas de conversion vérifiés couvrent les valeurs canoniques finies, en arrondi au plus proche pair ; pas une reproduction de tous les flags d’exception x87.

## Référence et résultats

Le test différentiel exécute les octets originaux sous Unicorn 2.1.4 et le C++ compilé avec `-O2 -fno-fast-math -ffp-contract=off`. Il utilise les mêmes buffers d’entrée et adaptateurs hôtes. Le sample est le WAV fourni. Le test vérifie aussi les zones de mémoire de l’objet pour détecter les divergences qui ne seraient pas encore audibles.

Résultats CP-008 : 704 cas, 5 420 672 octets comparés, aucune différence avec les mêmes réponses hôtes. 3 113 adresses d’instructions ont été exécutées sur les 3 242 exportées. Ces nombres ne démontrent ni la couverture de toutes les entrées de ces routines, ni celle des fonctions non sélectionnées.

Le probe autonome rejoue les entrées et sorties de référence du fichier `SLFT0003`. Pour chaque appel math enregistré, il contrôle aussi que les arguments correspondent avant d’injecter la réponse. Ce replay passe sous Linux x86_64, dans un exécutable ARM64/Linux musl exécuté sous QEMU 7.2.0, et nativement sur le Mac ARM64 de l’utilisateur sous macOS 15.7.2. Le journal reçu confirme les 704 cas, 5 420 672 octets et zéro différence en mode réponses ABI enregistrées ; son rapport structuré sans chemin personnel est `evidence/mac-cp008-native-replay.json`.

Les helpers de conversion du stockage 80 bits ont été comparés sur 20 000 cas au type étendu natif Intel : aucun écart. Ce test de référence est indisponible sur les plateformes où `long double` n’est pas le format x87 ; il renvoie alors un statut de test ignoré.

## Sonde audio continue

La sonde de trois secondes utilise les tables produites depuis le sample après moyenne mono et normalisation. Le lecteur est configuré explicitement à la fréquence MIDI 60, avec des contrôles fixes. Les deux WAV de sonde, référence i386 et C++ traduit, sont identiques. Ils n’incluent pas les enveloppes, la matrice de modulation, les autres générateurs, le mixage et les effets du preset Lightgarden. Aucun note-on MIDI complet du synthétiseur ni chargement sémantique de son preset n’est impliqué.

Le PCM16 est décodé selon la convention standard pour ces tests. Le loader original appelle AudioConverter (format signé/packed vers float32 non entrelacé) ; cet appel Apple n’a pas été exécuté. Les routines de préparation et de lecture sélectionnées sont ensuite réellement exécutées, sans reconstruction de leurs algorithmes à partir d’un modèle sonore approximatif.

## Écart entre bibliothèques mathématiques

Les adaptateurs partagés servent à séparer la traduction d’instructions de la bibliothèque mathématique. `--native-math` utilise le libm de la plateforme. Sous Linux x86_64, le résultat est identique. Sous ARM64/Linux musl/QEMU, il y a sept octets différents dans l’état interne et zéro octet différent dans les buffers de sortie vérifiés. La comparaison stricte échoue donc dans ce mode. Ce constat n’établit pas que tous les futurs rendus resteront inchangés : les états peuvent influer sur la suite d’un traitement.

Sur le Mac ARM64 de l’utilisateur, la comparaison séparée avec les maths natives a renvoyé un code non nul. Le détail est dans les rapports séparés non encore reçus : aucune quantité d’octets différents ni cause exacte n’est confirmée sur cette plateforme. Le replay avec les réponses enregistrées est bien passé. L’ancien libm Intel 32 bits Apple n’a pas été exécuté. Une fidélité globale au plugin et aux projets ne peut pas être garantie par ces seules références.

## Travail restant

Étendre les opérations couvertes seulement avec des références appropriées, reconstruire l’initialisation et les liens des objets, le MIDI, les enveloppes, les oscillateurs, les autres samplers et effets, le chargement sémantique des chunks et les IDs AU, puis développer l’AU moderne et l’interface. La compilation et la validation `auval` sur Mac, ainsi que des copies de projets Logic et Live, restent nécessaires. Le `.component` installable n’existe pas dans ce checkpoint.
