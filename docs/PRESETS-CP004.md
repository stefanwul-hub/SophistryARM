# CP-004 — paire Lightgarden réelle

## Entrée conservée

Les deux fichiers proviennent de `stefanwul-hub/SophistryARM/Presets` au commit consigné dans `analysis/preset-pair/source.json`. Les originaux ne sont pas modifiés.

- `.aupreset` : `aumu / CrX3 / LinP`, nom `PAD CronoX Lightgarden 02 BT`, CFData `vstdata` de 22 192 octets.
- `.FXP` : conteneur `FPCh`, identifiant `Crx3`, chunk de 20 640 octets. Le champ standard de taille du conteneur extérieur vaut 0 ; la longueur effective et la taille du chunk concordent. L’outil signale ce détail sans rejeter ce fichier réel.

L’utilisateur confirme que Sophistry est une déclinaison de CronoX 3 et utilise le même format de fichiers. Le binaire Sophistry conserve des classes `AUCronoX`, `Kaja` et les identifiants de blocs correspondants. Le partage de format de sérialisation est cohérent avec ces preuves. L’identité AU cible reste `aumu/Sop3/LinP`.

## Structure retrouvée

Les blocs ont un en-tête de trois UInt32 : **tag, taille totale en octets, indice d’instance**. Dans cette paire, les mots sont little-endian. Le tag numérique est un FourCC, ce qui explique l’apparence inversée des quatre caractères dans l’hexadump (`2GYS` pour `SYG2`). Un bloc `PROG` contient un autre flux de blocs à partir de l’octet 12.

L’état AU contient quatre blocs de premier niveau : `SYG0`, `SYG1`, `TUN0`, puis `PROG`. Après descente dans `PROG`, il contient 121 blocs feuilles. Le FXP contient directement 118 blocs. Le lecteur C++ valide les tailles et bornes, descend dans les enveloppes `PROG`, conserve les payloads inconnus et reconstruit les en-têtes à la réécriture. Les deux flux réécrits sont identiques octet par octet aux originaux.

Les tests de permutation d’endianness du lecteur C++ concernent **les en-têtes uniquement**. Ils ne démontrent pas le chargement d’un état PowerPC avec payload numérique big-endian.

## Schémas de paramètres issus du binaire

Sources : `ParaSet_c_vslot_2/3/4`, adresses i386 `0x11c3e`, `0x11d9a`, `0x1200a`. Le writer de `ParaSet_c` sérialise :

- un mot 32 bits pour les types numériques et booléens ;
- pour les types 2 (choix) et 7 (chaîne), une taille 32 bits puis une chaîne terminée par NUL, dans un espace arrondi à quatre octets ;
- pour le type 8, un nombre de valeurs puis des floats 32 bits.

Les octets de padding de certains champs FXP contiennent `0xcd` (initialisation mémoire Windows). Ils restent préservés ; ils ne sont pas traités comme du texte ni normalisés.

`recover_parameter_schemas.py` exécute les instructions originales de contrôle des descriptions de modules dans Unicorn, avec une mémoire de paramètres synthétique. Les constructeurs numériques/énumérés/chaînes sont interceptés pour relever leurs arguments. L’exécution s’arrête à la finalisation des descriptions ; les allocations, mathématiques de valeurs par défaut et traitements DSP ne sont pas exécutés. Résultat : 51 schémas de classes, 3 437 entrées de champs, dont des doublons entre classes apparentées. Les entrées sans constructeur observé restent annotées comme réservées / hypothèse de valeur initiale nulle. Les bornes relevées décrivent les arguments des constructeurs, pas forcément l’échelle de l’interface.

**Les indices de champs ne sont pas des identifiants d’automation AU.** La restitution complète du graphe et les migrations de versions restent à réaliser.

## Résultats et limites

- 117/121 blocs AU sont consommés intégralement par un schéma retrouvé.
- 116/118 blocs FXP sont consommés intégralement.
- Quatre blocs AU ont des données supplémentaires après le schéma connu : `SYG1` (12 octets), `SYG2` (4 octets), deux `VF01` (4 octets chacun).
- Deux blocs FXP `VF01` ont également quatre octets supplémentaires.
- 115 blocs peuvent être rapprochés par tag, indice d’instance et occurrence ; 3 829 valeurs décodées sont égales, 31 diffèrent. D’autres blocs ont des indices d’instance différents, donc ne sont pas associés automatiquement.

Les différences portent notamment sur :

- les libellés des destinations de modulation, au format plus récent `Filter 1$Cutoff` dans l’AU contre `Cutoff 1` dans le FXP ;
- quelques flags de modulation, un paramètre de LFO, une valeur de séquence et un état d’affichage ;
- le chemin du sample `BT_cronox18.wav`, sous `/Library/Application Support/LinPlug/CronoX 3 Banks/Samples/` dans l’AU et sous un chemin Windows dans le FXP.

Il ne faut pas simplement traiter les deux chunks comme des copies binaires du même état. Les changements peuvent provenir de l’importation et de migrations de versions. Le loader original d’énumérations, `0x10d02`, recherche un texte dans des listes à largeur fixe, puis dans des tables de noms historiques ; une traduction fidèle devra préserver ces correspondances et comprendre les libellés plus récents absents de Sophistry 3.0.8.

`LegacyStateReader` et le décodeur Python permettent l’inspection, la préservation des octets et la comparaison des champs. Ils **ne créent pas le graphe DSP, ne chargent pas les samples, ne rendent pas ce preset et ne rétablissent pas encore un projet**. Les fichiers JSON détaillés sont dans `analysis/preset-pair/decoded/`.

Pour poursuivre les tests de ce son, il manque le sample `BT_cronox18.wav`. D’autres presets pourront ensuite couvrir les générateurs TimeSampler/LoopSampler, les enveloppes, les effets et les différentes versions de sérialisation ; ils ne sont pas nécessaires pour continuer l’analyse structurelle actuelle.
