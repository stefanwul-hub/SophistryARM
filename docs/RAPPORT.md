> Rapport initial CP-003. Pour les résultats actuels, lire README.md et STATIC-LIFT.md ; les limites ci-dessous décrivent cette étape initiale.

# Audit et état technique

## Provenance contrôlée

Dépôt : https://github.com/stefanwul-hub/SophistryARM

Commit lu : `d0b62115360f1f3b993ae2c7c404c2ba74bdb2ab`.

| Élément | SHA-256 |
|---|---|
| `Sophistry.component.zip` | `c6fdd914f7388210a552706c3f0d2a845134fca13aa39fe85e31c415cc5ad5f1` |
| Exécutable universel original | `905569f5415aad5f713039e4064c620a77952583e0f5c42d67d76aced700b765` |
| Tranche i386 extraite | `17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12` |

Le script `scripts/analyze_binary.py` vérifie l’archive épinglée, extrait les deux informations d’architecture, lit les ressources classiques `thng`/`dlle`/`STR `, les segments Mach-O et les tables RTTI/vtables candidates. Il n’exécute pas le plugin.

## Pourquoi la conversion n’est pas terminée

Le fichier date de 2007 et est un bundle Mach-O universel **ppc + i386**, avec 2 symboles définis nommés. Le code DSP n’est donc pas un programme x86-64 dont il suffirait de changer la cible de compilation. Les tables RTTI conservent des noms de classes, mais les méthodes internes ont été dépouillées de leurs noms.

Rosetta 2 exécute les programmes Intel 64 bits, pas les plugins Intel 32 bits. Cette archive précise ne peut donc pas servir de référence exécutable dans Logic 11 ou Live 11 sur macOS 15, même avec leur mode Rosetta. Une autre version x86-64 du plugin, si elle existe, serait un autre binaire à auditer.

Le composant utilise Carbon, l’ancien Component Manager, VSTGUI et `libstdc++.6`. L’interface et l’enregistrement du composant doivent aussi être adaptés aux API 64 bits modernes. Le renommage du bundle ou l’ajout d’une entrée ARM64 au plist ne transforme pas son code.

## Ce que contient la décompilation

Ghidra 11.3.2, langage `x86:LE:32:default`, a produit un export pour 3 249 fonctions détectées. Aucun appel au décompilateur n’a échoué à émettre un résultat. Cela ne signifie ni que tout le code a été découvert, ni que toutes les sémantiques sont correctes : 1 847 fonctions comportent au moins un avertissement (beaucoup concernent les thunks PIC), et 207 messages signalent une table de sauts non reconstruite.

Les noms `_vslot_N` sont des **annotations inférées d’un emplacement de vtable**, pas des noms de méthodes originaux récupérés. Une même fonction partagée par plusieurs classes n’a qu’un premier nom. Les structures, pointeurs, alias et types produits par Ghidra nécessitent une vérification à partir des instructions. Exemple concret : la saturation est calculée en double précision SSE avec un arrondi final float, détail insuffisamment explicite dans le pseudo-code.

Le graphe d’appels exporté ne résout pas toutes les cibles virtuelles. Aucun lifter complet Mach-O i386 → C++ natif n’a été réalisé. Les `.c` exportés ne constituent pas un moteur prêt à compiler.

Parmi les classes retrouvées : `Synth`, `Kaja_c`, `Instrument_c`, `OscAnalog3_c`, `SamLoop_c`, `SamTC3_c`, `WaveRAM_c`, `EnvADSFR_c`, `AdvLFO_c`, `FilterMoogSI_c`, `FilterFree_c`, `Reverb2_c`, `DelayStereo_c`, `Chorus1_c`, `Phaser1S_c`, `EQ2_c`, `Amp_c`, `Satur_c` et les classes d’interface. Les tables brutes sont dans `analysis/vtables.json`.

## Traduction vérifiée du noyau de saturation

Portée exacte : arithmétique et chemins mono/stéréo de `Satur_c` à `0x73fb0`, avec addition par le callback original `0xc14e4`. Les coefficients `a` et `b` sont fournis à l’API du noyau ; le graphe de modules, leur allocation et la génération des coefficients ne sont pas portés.

La séquence originale convertit les floats en doubles, calcule `x * (b + a / (abs(x) + b))`, puis arrondit en float. Les modes de compilation excluent `fast-math` et la contraction des opérations.

Particularité conservée : en stéréo avec des destinations distinctes, l’original ne fait pas avancer les pointeurs sources. À `0x74112`, il recharge le même pointeur local à chaque itération. Ce chemin répète donc la lecture des premières valeurs du bloc, sauf effets d’alias. La première implémentation qui avançait les sources a échoué au test différentiel ; le code livré suit les instructions. L’incidence de ce chemin dans le graphe réel reste à déterminer.

Les tests font exécuter à Unicorn les **octets originaux non modifiés** de la routine. Seuls les callbacks d’acquisition des buffers sont remplacés par des buffers synthétiques. Le callback d’addition original est exécuté. Les cas couvrent mono/stéréo, en place/séparé, blocs de 0 à 4 096, cinq paires de coefficients, valeurs extrêmes finies, zéros signés et dénormalisés, avec MXCSR `0x1f80`. Résultat : aucune différence binaire sur 133 500 valeurs. Le mode désactivé est également vérifié.

Le test audio synthétique d’une seconde combine un balayage et du bruit/impulsions. Les WAV du noyau C++ et de la routine émulée ont les mêmes valeurs ; maximum d’erreur et RMSE nuls. Ils ne démontrent pas la reproduction des générateurs, des filtres ou d’un preset Sophistry.

L’objet ARM64 est vérifié par son en-tête Mach-O : CPU `0x0100000c`, type `MH_OBJECT` (1). Il a été compilé avec Zig 0.14.1, cible `aarch64-macos`. Aucun code ARM64 n’a été exécuté dans cet environnement Linux. Le test natif fourni doit encore être lancé sur votre Mac.

## Identité Audio Unit et anciens projets

Les ressources `thng`, id 1000, donnent :

| Champ | Valeur originale |
|---|---|
| Type | `aumu` |
| Sous-type | `Sop3` (respecter la casse) |
| Fabricant | `LinP` (respecter la casse) |
| Version composant | `0x00030008` |
| Identifiant bundle | `com.linplug.au.Sophistry` |
| Entrée historique | `AUCronoXEntry` |

La ressource `thng` id 2000 désigne l’ancien éditeur `auvw / Sop3 / LinP`, entrée `LPAUViewEntry`. Elle n’est pas un instrument indépendant à remplacer par un synthétiseur.

Conserver l’identité est nécessaire pour que les hôtes puissent rechercher un remplacement. **Cela ne prouve pas le rappel d’un projet.** Il faut aussi conserver les IDs et valeurs des paramètres AU automatisés, le format des états, les bus et canaux, le chargement des samples, la réponse MIDI, les chemins, la gestion des voix et les conventions de rendu.

Preuves du chemin d’état :

- `0x3d14`, sauvegarde de l’AU : demande un chunk au moteur via la vtable, supprime la clé `data` et écrit les octets sous **`vstdata`** dans le dictionnaire CF.
- `0x3e30`, restauration : exige un dictionnaire contenant un CFData `vstdata`, appelle le lecteur de chunk du moteur, puis restaure les propriétés AU de base après retrait de `element-name`.
- `0x1b998` et `0x216fe` : distribution des opérations de chunk au moteur `Synth`/`Kaja`.
- Les CFString correspondantes sont visibles à `0xfb598` (`element-name`), `0xfb5a8` (`vstdata`) et `0xfb5b8` (`data`).

`inspect_presets.py` lit les enveloppes `.aupreset` et FXP/FXB standard et extrait les chunks sans les interpréter. Ce n’est pas un décodeur du format interne Sophistry. Aucun ancien projet Logic ou Live n’a été ouvert ou modifié.

## Interface

L’archive contient 106 PNG, dont le cadre 762 × 477, sept fonds de panneaux 762 × 290 et des bandes de sprites pour les molettes. Ce sont les ressources de l’original, pas des captures d’une application exécutée ici. La visionneuse `Interface.html` les affiche sans simuler des commandes audio.

Le catalogue de 554 appels de construction relève les noms, unités et arguments visibles dans le pseudo-code de 47 classes. Il ne constitue pas encore une correspondance vérifiée avec les IDs AU. Une interface Cocoa à comportements identiques reste à construire : hit-tests, menus, plages, valeurs neutres, modulation, souris/clavier et notification de l’hôte.

## Validation restant à réaliser

1. Charger de vrais presets et états AU de référence, établir la structure du chunk, les conventions de taille et d’endianness et les liens vers les samples.
2. Reconstruire le graphe `Synth`/`Kaja`, les générateurs, la polyphonie, le MIDI, les filtres, enveloppes, modulations et tous les effets. Vérifier chacun par les instructions originales, puis par des rendus de l’original sur un environnement capable de l’exécuter.
3. Implémenter l’Audio Unit moderne avec les mêmes identifiants et IDs de paramètres, l’état opaque compatible et une interface Cocoa. Ne pas installer un squelette qui s’enregistrerait avec l’identité de l’original.
4. Compiler avec le SDK macOS dans Xcode, cible ARM64 ; inspecter `lipo`, dépendances `otool -L`, signature locale et absence de dépendances 32 bits. Installer d’abord le candidat dans un environnement de test maîtrisé.
5. Exécuter `arch -arm64 auval -v aumu Sop3 LinP` et les tests de rendu. `AUStateProbe.cpp` prépare des snapshots d’état, une liste de paramètres et un rendu de trois secondes à 120 BPM (note 60, vélocité 100, note-off à deux secondes). Son code n’a pas été compilé avec un SDK Mac ici.
6. Comparer les rendus de référence aux mêmes presets, samples, fréquences (44,1/48/96 kHz), blocs et séquences MIDI. Le comparateur ne décale, ne normalise et ne rééchantillonne pas les fichiers ; il rejette une référence silencieuse. Les presets aléatoires demandent une stratégie de graine de référence, encore absente.
7. Tester des **copies** de projets Logic Pro 11 et Ableton Live 11.3.2 : chargement des sons, automations, boucles, tempo, sauvegarde, fermeture et réouverture. Un succès `auval` ne suffit pas pour certifier ces projets.
8. Quand ces tests seront concluants, fournir l’installateur effectif : extraction, compilation, tests, sauvegarde datée de l’ancien `.component`, copie atomique dans `/Library/Audio/Plug-Ins/Components`, validation de l’instance effectivement sélectionnée et restauration de la sauvegarde si échec. Les doublons dans `~/Library/Audio/Plug-Ins/Components` devront être identifiés pour éviter de valider un autre bundle.

Aucune de ces étapes restantes n’est déclarée réussie dans ce checkpoint. Le script d’installation livré refuse explicitement l’installation et ne demande pas `sudo`.
