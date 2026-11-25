# Reprise CronoX — CRX011 (interface)

Priorité explicite de l’utilisateur : publier d’abord les menus de destinations et l’arpégiateur, puis reprendre le CPU. Cette version ne modifie donc pas le DSP, la polyphonie ni les outils de profilage. Base publiée locale CRX010 `cff3a84080cb73b6e0a4a25cad55f11c1fa2036d`. Le retour « Bon travail » est une acceptation de fonctionnement/interface, sans nouveau rapport automatique ni comparaison sonore exhaustive.

Matrix : `createMatrixEdits` 0x74874 crée dix destinations CMenuWithSub tags 670..679. `fill` 0x8f70, `nextIsSame` 0x91f2 et `getSubMenuNameLen` 0x91b8 construisent des catégories sur les préfixes adjacents séparés par $. `CMenuSimple::addItemShift` 0x9350 supprime les espaces finaux et remplace le premier $ par une espace. Le flag original de cette page ne retire pas le préfixe des libellés enfants : conserver ces libellés complets. 16 catégories, 58 destinations dont le choix vide ; ne pas trier ou renuméroter. Les actions Cocoa gardent les indices originaux, la sélection et l’automation. Les parcours de test des menus descendent maintenant dans les sous-menus.

Arp : `createArpEdits` 0x77786, CStepSeqPl constructeur 0xa5fc0 et dessin 0xa62f2. Rectangle (67,151,224,104) dans Modulation ; 4 colonnes, 8 lignes ; cellule 56x13, espace initial 16, indicateur bitmap 306 de 8x24 en deux états 8x12, valeur à x24 de 31x13. kNormalFontSmall Helvetica 11, gris 210 actif / 105 hors longueur. Les flags 108=0,109=1 signifient une seule valeur (vélocité/Off/Tie) par cellule ; l’ancienne vue ajoutait la note brute à côté. L’indice courant et la longueur sont les deux premiers octets, les valeurs à 3+2*i. Valeur 1=Off, 129=Tie. Le bitmap vert est peint à chaque ligne avec son état actif/inactif original. Timer Cocoa 20 ms uniquement visible ; pas de rafraîchissement complet du panneau à cette cadence.

Gestes : ordre colonne puis ligne, clic/glisser sur la valeur avec la règle originale du centre de ligne et deux pixels par unité, Option remet 100, molette +/-1, bornes 0..128. Écriture par le setter de chaîne original de 258 octets. Ne pas modifier les autres octets pour un geste.

Preuves reproductibles : `analysis/cronox/recover_modulation.py` exécute le code machine d’origine avec des adaptateurs de dessin/menus. Les 58 chaînes publiques de `tests/fixtures/cronox-modulation-destinations.json` proviennent du paramétrage original et sont vérifiées dans son image. Le test C++ `CronoXModulationProbe` compare les dix menus et 180 états d’arpégiateur au FNV original : menus `cfd70229ae74d452`, dessins `846b5a5e40732608` (11520 opérations). Tests C++ et 28 régressions/Bash 3.2 verts. L’installeur exécute la nouvelle sonde, puis Cocoa, rendu et auval. Compilation/lien strict Mach-O ARM64 effectué ; pas d’exécution Cocoa/auval CRX011 ici. Les 413 unités et LegacyEngine restent identiques à CRX010.

Recherches CPU sauvegardées séparément : branche locale `research/cronox-crx011-cpu-audit`, commit `1cb8ea00334f09584b38b5fe7764c1e2ff0836d6`. Ce commit n’est pas publié dans cette livraison. Il contient `analysis/cronox/compare_reverb_voices.py`, le brouillon `CronoXCPUProbe.mm` et son lanceur. Résultats dans work/crx011/dsp-concordance.json : 6144 étapes de comb::processMod 0xd6912 identiques (état, delay et retour x87), 1565 opérations PolyNoteTable identiques (compteurs, états et choix de vol/réutilisation) sous limites 1/4/12/32. Ce n’est pas une preuve de fin naturelle des enveloppes ou de CPU Mac. Les notes du gestionnaire ont été libérées explicitement dans ce test de contrat, sans audio ni clé ni contournement de licence.

L’utilisateur précise que la réverbération coûte sur tous ses presets, et cite Arpeggios/(SAW)tooth Arp pour les releases. Le paramètre Voices est 961, valeurs 1..12 puis 13 ; 13 affiche oo et utilise les 32 emplacements originaux. Ce n’est pas zéro voix. Souscodeoriginal, les releases peuvent se superposer jusqu’à cette limite, puis les routines de vol privilégient les voix en release (même hauteur/canal puis les autres), avant les notes maintenues. Le mode FTZ/DAZ est déjà appliqué comme AUBase::DoRender 0xc4280. Le surcoût du runtime par instruction est une piste à mesurer, sans le présenter comme diagnostic établi. Ne pas limiter la polyphonie ou raccourcir les releases pour masquer le problème. Le preset SAW n’est pas dans Presets sur main lors de la dernière consultation. Le brouillon CPU pourra mesurer un FXP local sur le Mac et suivre les voix avec/sans réverbération et Voices 4 ; terminer ses vérifications avant publication séparée.

Garder aumu/CrT3/LinP, original CrX3, Sophistry CP038 et gain avant Master +6 dB. Publier seulement sous CronoX3/, conserver les 46 autres entrées racine. Source, lanceur et vérification seront épinglés et sauvegardés en fin de session.

---

# Reprise CronoX — CRX010

Rapport CRX009 du Mac (macOS 15.7.2, Apple clang 17 arm64) reçu le 25 novembre 2026. Compilation, identité CrT3, 110 images, tests C++ d’interface, accords, boucles, gain, temporisateurs et destruction passent. La prévalidation Cocoa lève NSInvalidArgumentException dans `catalogBanks` : « NSString fileSystemRepresentation: Cannot form file system representation of empty string ». Une préférence facultative absente devient @"" dans `crxPreference`, puis est convertie sans garde. Arrêt 134 avant toute transaction de copie ; aucun auval CRX009 exécuté, version installée précédente conservée. Le rapport brut reste privé ; résumé sans chemins personnels dans `evidence/cronox-crx009-user-report.json`.

Correctif : `src/au/CronoXCocoaPaths.h` retourne un std::filesystem::path vide pour nil/@"" avant d’appeler fileSystemRepresentation. Utilisé pour les deux racines facultatives et la source dans catalogBanks, ainsi que le chemin de repli du bookmark à l’ouverture. Le catalogue existant peut alors inférer le dossier du preset ou proposer « Choisir le dossier des banques… ». Aucun effacement de préférences ni changement de licence, DSP, gain, tri, typographie ou dessin du clavier.

La vraie sonde `CronoXComparisonProbe` vérifie nil, @"", un chemin avec espaces et le repli vers le dossier du preset sans racines configurées. Elle conserve les sélections NSMenu, le style, l’animation, le rappel, les rendus et les contrôles de non-modification des préférences originales. Un @catch Objective-C enregistre nom/raison et étape dans le JSON au lieu d’un abort sans rapport. Il laisse le résultat en échec ; aucun contrôle n’est retiré ou considéré comme réussi sur exception. Ces contrôles Cocoa sont compilés pour ARM64 mais attendent leur exécution réelle sur le Mac.

Versions : wrapper `CronoX3ARM CRX-010`, pied `CronoX 3 ARM64 port OA 2026 . CRX010`, bundle build 10001. Garder aumu/CrT3/LinP, le composant CronoX 3 ARM Test, l’original CrX3 et Sophistry CP038. Les 413 unités du noyau et LegacyEngine sont inchangés ; archive SHA256 `0897c74f4f6c41b6afe716fff9986cb4d8c507306af420416afd043e88a45c61`. Le cache local Mac est conservé ; pas de recompilation volontaire des 413 unités.

Contrôles de développement CRX010 : 28 régressions et vrai script sous Bash 3.2 avec outils Apple simulés verts. Composant et sondes compilés/liés strictement en Mach-O ARM64 ;110 images et trois exports isolés vérifiés. Les objets des sondes C++ inchangées sont réutilisés du checkpoint9 pour ce contrôle de lien. Ne pas confondre cette compilation avec une exécution Cocoa/auval CRX010. Prochaine étape : lancer le nouveau ZIP épinglé sur le Mac et obtenir le rapport ; vérifier ensuite menus et clavier dans Logic/Live. Référence UI acceptée CRX008, audio acceptée CRX005, dernier checkpoint local CRX009 `113ca5f0cb94a244ba80320196a7d49a53c9e116`.

Publication seulement sous CronoX3/, branche codex/sophistry-native-checkpoints. Préserver les 46 entrées racine hors CronoX3. Source, lanceur et vérification publiés séparément ; archive téléchargée comparée aux blobs Git, CRC et modes. Checkpoint local et bundle incrémental à enregistrer en fin de session. Preuves `evidence/cronox-crx010-local-checks.json`, `cronox-crx010-macos-cross-link.json` et résumé Mac CRX009.

---

# Reprise CronoX — CRX009

Demande du 25 novembre 2026 : menus sur les lignes banque/preset, position et typographie originales, clavier suivant les notes jouées. L’utilisateur accueille CRX008 puis demande ces trois corrections ; aucun nouveau rapport automatique n’est fourni. Référence locale de retour : `d4b6c6f42e373beff2fa6732cc82606ddf9f414f`. Conserver `aumu/CrT3/LinP`, l’original `CrX3`, le gain avant Master +6 dB et Sophistry définitif CP038. Publier uniquement sous `CronoX3/`.

Menus et style : `createFileEdits` 0x7850c crée les CMenuFileList 635/636, x27, y191/207, largeur138, hauteur14+1 ; panneau Main y37, soit (27,228,138,15) et (27,244,138,15). `createMenuFileList` 0x2b456 choisit kNormalFont Helvetica 12 et this+0x38, initialisé à D2 D2 D2 FF dans `KajaEditor` 0x72ec0. Les champs Cocoa utilisent le helper CoreText de la ligne de base originale (`drawText` 0xb6922 / `drawStringUTF8` 0xc1a44), sans les marges natives de NSTextField. Les clics ouvrent deux NSMenu.

Catalogue : `CMenuFileList::fill` 0x856a, `getFilenameDisplay` 0x306d8 (sans extension, « - - - » si vide), `Disk::fillFileList` 0xc4ac (banques = dossiers, presets = FXP), `FileList::addItem` 0x2fff6 (exclut « z patterns arp »), `FLSortLessthan` 0x302a0 (ordre lexical octet par octet sans casse). `Synth::setInsBnk` 0x1e89c charge le premier preset après changement de banque. L’adaptation native conserve aussi l’import AU et propose le choix explicite du dossier des banques. Elle ignore dossiers cachés et liens symboliques ; choisir une banque vide ne réinitialise pas l’audio.

Persistance : `CronoX3ARMPresetRoot` et `CronoX3ARMPresetBookmark` dans le domaine ARM Test ; accès sécurisé détenu par la vue. La propriété UTF-8 plate CxPs/0x43785073 (4096 octets max) et le champ d’état `CronoX3ARMPresetSource` conservent la source pour retrouver les menus après rappel. Ni ce chemin ni le bookmark ne sont ajoutés au diagnostic. Le bookmark n’est pas sérialisé dans l’état AU. Les états antérieurs restent compatibles, avec repli sur la banque connue et le dossier configuré.

Clavier : récupération de `CKeyboard2::drawKeys` 0xae772, sprites originaux 382/383. Les 72 bandes dépendent d’au plus deux notes adjacentes ; la table C++ préserve les raccords d’accords. `analysis/cronox/recover_keyboard_chords.py` exécute le code machine i386, compare les 62 états unitaires précédents, puis 4354 masques : toutes les combinaisons d’une octave, 256 accords déterministes sur 61 touches, toutes enfoncées et aucune. Tous les blits sont identiques ; FNV64 des u32 ordonnés `daac17be44d82b53`, header SHA256 `ae343c2a7dcd12565ac02d34adc71548971df682f853b883ee5b55edf3040004`.

Notes : lecture seule de PolyNoteTable à Synth+0x3880, table+8, capacité+12, lignes 36 octets. `noteOn` 0x33c0a / `noteOff` 0x335ac : état 1 maintenu, état 2 relâché ; note+12, vélocité+16. La propriété plate CxKy/0x43784b79 transporte version 1 + 128 vélocités, soit 132 octets. La vue actualise les touches toutes les 20 ms, comme l’idle original, si visible ; elle combine souris locale et notes actives du moteur. Aucun callback par instruction ni changement des 413 unités audio.

Tests : `CronoXBrowserKeyboardProbe` compare les 4354 masques au hash original, vérifie catalogue et notes maintenues/relâchées. Son test de lecture utilise des lignes synthétiques et restaure pointeur/capacité avant arrêt ; aucun audio joué ni contrôle de licence modifié. Le vrai test Cocoa choisit banques/presets par les actions NSMenu sur des copies temporaires du FXP public, vérifie style, rappel de source et arrivée des notes au clavier pendant le rendu. Compilé pour ARM64, il doit encore s’exécuter sur le Mac ; l’installeur le lance avant copie puis en mode enregistré. Sa configuration temporaire ne persiste aucune préférence.

Résultats locaux : catalogue et 4354 accords verts, 107 configurations/863 tags / 6329 frontières, 54 cas de gain et 15 autres volumes inchangés, boucles/tracés/cache verts, 28 régressions et Bash 3.2. Lien strict Mach-O ARM64 réussi pour le composant et six sondes ; 110 images et trois exports isolés vérifiés. Noyau SHA256 inchangé `0897c74f4f6c41b6afe716fff9986cb4d8c507306af420416afd043e88a45c61`. Cocoa/auval CRX009 et manipulation Logic/Live attendent le prochain rapport. Ne pas déduire une exécution macOS ou une conformité sonore exhaustive du lien croisé.

Preuves : `evidence/cronox-crx009-{keyboard-recovery,browser-style,local-checks,macos-cross-link}.json`. Installation transactionnelle et cache conservés. Source et lanceur sont publiés dans deux commits distincts pour éviter une référence circulaire du SHA d’archive. Enregistrer les checkpoints et la publication vérifiée en fin de session.

---

# Reprise CronoX — CRX008

L’utilisateur accueille les modifications CRX007 et demande cinq corrections : boucles graphiques/numériques, saccades du Loop Sampler pendant les gestes, banque et preset sur deux lignes centrées, libellés d’effets non coupés, pied réduit et abaissé. Référence d’interface : CRX007, commit local `9effbfb72cd1cc123bba34c2ce5f9a199b3229cc`. Conserver `aumu/CrT3/LinP`, l’original `CrX3` et Sophistry CP038. Publier uniquement sous `CronoX3/`.

Loop Sampler : `createLopEdits` (0x78c3e) relie les slots 0..5 à 815/817/819/835/949/951 (+1 pour Gen 2). Les champs 953..960 affichent Sample S, Loop S, Loop E et X-Fade. Les vrais paramètres 815..820, 835/836 sont désormais éditables. La saisie utilise `Parameter_c::setValue` (0x131e8), puis rétablit les 28 octets de l’objet avant le setter original avec notifications. Modifier temporairement raw+0x14 ne recalculait pas normalized+8 et laissait la saisie sans effet. Limites et zero crossings restent originaux.

Tracés : `drawSample` (0x9d83c) appelle `getMaxMin` (0x9c8c4) puis `drawAllMinMax` (0x9d58c). `draw` (0x9d9ae) appelle ensuite `drawLoopPoints` (0x9cbb6), étape manquante rétablie. Le calcul des extrema différentiels, mode 1 explicite de createLopEdits, est extrait en C++ natif dans `CronoXLoopDisplay.h`. Le cache dépend du sample, de sa révision, du zoom et du défilement. Les positions changent les couleurs et repères, toujours peints par les routines originales, sans relire le sample. Une modification étrangère à la forme d’onde ne détruit plus ce cache. Les 413 unités audio sont inchangées.

Concurrence : `editorDrawing` accepte une frontière après chaque colonne terminée. Le wrapper relâche le mutex audio puis contrôle `editorGeneration`. Il reconstruit le scratch du dessin après les frontières. Aucun verrou n’est relâché au milieu d’une routine originale. Cocoa conserve le dernier tracé terminé en cas de lecture interrompue. Le nouveau test intercale 316 rendus aux frontières d’un changement de zoom.

Gestes : sélection et conversion tirées de `onMouseDown` (0x9d33e) / `onMouseMoved` (0x9d21e). Distance minimale, égalité préférant le dernier repère, règle directionnelle des débuts confondus, bande supérieure de 12 px pour le crossfade ; conversion par la fenêtre visible et la durée du sample. La vue écrit les vrais paramètres et relit les valeurs dans le moteur original.

Main : banque/dossier du FXP en première ligne (y=228), preset en seconde (y=242), Helvetica 11 centrée. Le nom est conservé dans `CronoX3ARMBankName` et transmis par CxBn en UTF-8 plat, 512 octets. Les anciens états sans ce champ utilisent le nom du dossier de sons configuré en repli. Ne pas inventer une banque absente de l’état. Le navigateur dossiers/catégories original reste adapté en choix de fichiers natif.

Effets Main : tags 579..584, rectangles originaux 64x11. Les textes Helvetica 11 sont peints en dernier dans une couche transparente, assez large et laissant passer les clics. Les zones de sélection sont conservées. Pied : Helvetica 9 comme l’activité, y=487 comme le haut des boutons. Texte exact : `CronoX 3 ARM64 port OA 2026 . CRX008`.

Tests : `CronoXLoopSamplerProbe` compare 164 colonnes d’extrema et les tracés complets à l’exécution originale, identiques bit à bit sur quatre vues zoom/défilement. Il vérifie les repères, éditions, cache et frontières audio. Initialiser/activer l’AU ; utiliser saveBank pour ses états plutôt que mélanger les sauvegardes programme VST et le cycle AU. Pas de licence ni de préférences privées, pas de comparaison sonore exhaustive. La sonde Cocoa contrôle les lignes centrées, le rappel de banque et le pied. Les tests existants passent : 107 configurations, gain, Bash 3.2 et 28 régressions. Lien strict Mach-O ARM64 réussi pour le composant et cinq sondes ; 110 images et trois symboles exportés vérifiés. Cocoa, auval et les manipulations/audio CRX008 dans Logic et Live attendent le retour Mac.

Disposition de référence : `checkpoints/cronox/UI-Recovery-CRX007.tar.gz` (1072 contrôles, 86 panneaux). Preuves : `evidence/cronox-crx008-local-checks.json`, `cronox-crx008-loop-port.json`, `cronox-crx008-macos-cross-link.json`. Archive du noyau SHA256 inchangée ; gain avant Master +6 dB conservé de CRX007. Installation transactionnelle, cache de compilation conservé.

---

# Reprise CronoX — CRX007

Le 25 novembre 2026, l’utilisateur confirme que CRX006 fonctionne et que l’interface s’affiche. Les sept corrections demandées sont traitées dans CRX007. Référence audio acceptée : CRX005 ; référence d’interface acceptée : CRX006 (a3a09d3e8e8bb59d548924525730f733c574022a). Sophistry reste définitivement CP038. Toujours publier uniquement sous CronoX3/, garder aumu/CrT3/LinP et préserver l’original CrX3.

Gain : +6 dB fixe demandé AVANT le Master, sans déplacer sa valeur affichée, son automation ni ses données sérialisées. Le paramètre Master est le tag 134. La routine originale Parameter_c::setValue 0x131e8 appelle pow à 0x1330c (retour 0x13311, EDI=this) puis stocke le coefficient float à+0xc. L’adaptateur mathématique multiplie seulement ce résultat pour l’objet Master par 10^(6/20). Les getParaVol 0x1418a/0x15aa2 restent originaux ; les autres volumes et les 413 unités traduites ne changent pas. Aucun second gain sur les buffers AU. refreshMasterGain réapplique cette conversion à l’initialisation et au rappel d’état, sans double multiplication.

Nom : le dispatch VST5 peut renvoyer unknown lorsque le navigateur Carbon n’est pas rempli. Lire le nom PrgName 618 via getParaDispStr 0x1c6cc ; pour les FXP FPCh utiliser aussi le nom de 28 octets à l’offset 28 du header et PresentPreset. unknown est traité comme un nom absent. Le nom natif est conservé dans l’état AU et vérifié après rappel dans une nouvelle instance.

Sampler : erreur de capture CRX006, adresse CLabelPl fausse (0x898a). Le constructeur correct est 0x847a ; l’exécution de createGenSamTable 0x77ae4 suivie de createGeneralPl 0x29984 récupère les 16 labels manquants : tags 841–848,889–896, panneaux 26/27. Le layout comporte maintenant 1072 contrôles et 877 tags distincts. Leur texte vient du formateur original (getLeaf) et non du chemin brut. Colonnes File alignées à gauche, Helvetica 10.

Police : initialisation originale 0x1f80, Helvetica plain 9/10/11/12/14 points suivant le type et la hauteur. Le dessin CoreText reproduit la ligne de base, l’alignement et le clipping de drawStringUTF8 rect 0xc1a44. Pas de libellé off superposé aux boutons bitmap Chord 612 / ECS 610 ; leurs menus conservent leurs choix et fonctionnement. Boutons utilitaires y 487, h 24, centre 499 entre le clavier fin 477 et le bas 521. Pied exact : CronoX 3 ARM64 port OA 2026 . CRX007.

Tests : CronoXCorrectionsProbe compare les coefficients originaux sans gain/avec +6 dB, 54 signaux, 15 autres volumes, l’état programme et la banque AU identiques, un vrai paramètre filename et les 16 polices. CronoXEditorProbe couvre 107 configurations, 863 tags, 15 éditions et 10 dessins. La sonde Cocoa vérifie le nom FXP, le rappel, le pied, Helvetica et le centrage des boutons. L’installeur CRX007 exécute ces sondes puis le rendu et auval. Les tests de développement et le lien strict Mach-O ARM64 sont effectués ici ; Cocoa/auval CRX007 restent à exécuter sur le Mac utilisateur. Ne pas les annoncer validés sans retour.

Reproduction : archive checkpoints/cronox/UI-Recovery-CRX007.tar.gz ; scripts analysis/cronox/recover_layout.py puis normalize_layout.py. Preuves evidence/cronox-crx007-{local-checks,ui-recovery,macos-cross-link}.json. Les points historiques ci-dessous décrivent leur version respective ; CRX007 les remplace pour le gain, la police et les champs du sampler. Le navigateur dossiers/catégories original reste remplacé par le choix natif FXP/AU ; aucune équivalence sonore exhaustive n’est revendiquée.

---

# Reprise CronoX — CRX006

Référence audio acceptée par l’utilisateur : CRX005 ; tag local `final/cronox-crx005-audio-validated`. L’original CrX3 et Sophistry CP038 restent préservés. L’identifiant de comparaison CrT3 est conservé.

Interface CRX006 : constructeurs originaux 0x72ec0 / 0x7f530 enregistrés, 86 panneaux, 1056 contrôles placés, 19 sélecteurs, 110 PNG originaux. Schéma de paramètres réel (967 emplacements, 918 définitions examinées hors clé), chaînes std::string ABI 32 bits. Aucune adresse de contrôle Sophistry n’a été réactivée sans remplacement : les anciens accès `generatorPanel` et `editorPanel` restent bloqués. La vue utilise le nouveau completeEditor.

Entrées principales : getParaPtr 0x1b16e ; getParaVal 0x1ade8 ; getParameterCore 0x1c5f2 (part UI) ; setParameterIntern 0x22066 ; getParaDispStr 0x1c6cc ; getParaString 0x1af8a ; setParaString 0x1b07a ; processGUICmd 0x4c206. Descripteurs : Synth+0xc610, stride52, total+0xcf10. Sérial protégé : tag766. ModuleManager+0x3fc4, handlePartFileIO0xd37f4 ; rappel arp lorsque l’éditeur Carbon absent supprime ce callback.

Dessins : XY drawLine0x940c6 ; pointeurs LoopSample Synth+0x67920c ; waveform getStartEndDisplayed0x9d0f6 / drawSample0x9d83c. Cache conservé ; lectures terminées avant de rendre la main au thread audio. Les widgets Cocoa possèdent des noms Objective-C CronoX3 distincts de Sophistry, et seuls les trois symboles du factory sont exportés.

Récupération reproductible : `analysis/cronox/recover_layout.py` puis `analysis/cronox/normalize_layout.py`. Entrées brutes, schéma et sonde de recherche archivés dans UI-Recovery-CRX006.tar.gz. Les images sont extraites par prepare-cronox-source.py depuis l’archive originale vérifiée, sans dépendre des images bleues de Sophistry.

Validation CRX006 : lire les preuves locales et de lien croisé, puis obtenir le rapport Mac de l’installateur. Le test Cocoa parcourt les sept pages et contrôle les propriétés/images. Le test C++ contrôle 107 configurations et les commandes particulières. Il ne faut pas déclarer Cocoa/auval CRX006 validés avant le retour Mac. Le navigateur de fichiers de presets est une adaptation native ; ce n’est pas une copie complète de l’ancien navigateur dossiers/catégories. L’équivalence sonore exhaustive n’est pas démontrée.

# Reprise CronoX 3 ARM64 — CRX005

Décisions utilisateur : Sophistry définitif = CP038 ; développer CronoX 3.6.6 séparément et publier uniquement sous `CronoX3/` dans le dépôt existant, branche `codex/sophistry-native-checkpoints`. Ne pas reprendre l’expérience CP040. Ne jamais remplacer les fichiers Sophistry ni pousser ce worktree directement sur cette branche : ses chemins racine doivent être préfixés `CronoX3/` pour la publication.

La copie de travail CronoX est une branche `cronox/arm64-checkpoints`, basée sur le commit CP038 `4c24b4bf01d9cc8c2fb266cc8cec026aa8ff84fb`. Premier checkpoint local `bfdfdef`. Les recherches Sophistry CP040 sont sauvegardées séparément et suspendues.

Original fourni : CronoX 3.6.6, AU `aumu/CrX3/LinP`, bundle `com.linplug.au.CronoX3`, version AU `0x30606`. VST UID `Crx3` (attention à la casse). SHA256 i386 : `fe5f50d2213cfdd072c98cd4083d92bf24d9dc5ea8115b25a64cc8df08ed9969`. Sources, image, p-code et inventaire portent cette empreinte. L’original contient également x86_64. La traduction prend la tranche i386 pour conserver les structures et adresses de 32 bits du banc hérité, puis compile les opérations pour ARM64.

Ghidra : 3 174 fonctions nommées internes, 211 282 instructions, 786 267 opérations p-code ; 413 unités C++ plus dispatcher et runtime. Décompilation : 3 587 unités incluant les imports, aucune erreur déclarée. Projet Ghidra et décompilation archivés et vérifiés ; génération reproductible avec les scripts et le p-code. L’inventaire des entrées et cibles virtuelles est complet pour les instructions exportées, sans constituer une preuve exhaustive du comportement sonore. Le manifest du générateur conserve des avertissements historiques génériques ; utiliser ses compteurs et la liste réelle des gardes (vide pour cette génération).

Tests Linux réalisés : démarrage VST ; sérialisation 20 928 octets ; pont AU d’origine avec ses 522 paramètres et métadonnées, aller-retour d’état, activation, MIDI, rendu et reset ; restauration du FXP public Lightgarden et sample. Tests SQRT : 6 228 fixtures originales, dont 5 190 double précision vérifiées aussi sur ARM64/QEMU. ABI libstdc++ 32 bits : 14 contrats vérifiés Linux et ARM64/QEMU. Le noyau entier et le pont complet passent aussi sur ARM64/Linux sous QEMU ; le rapport utilisateur CRX001 valide ensuite ces tests C++ sur macOS.

Adresses AU 3.6.6 raccordées : LPAUSynth ctor `0x7930`, Kaja ctor `0x4a420`, PostConstructor `0x9ee38`, VerifySynthOpened `0x5034`, Get/SetParameter `0x50ee/0x5066` (Set prend aussi offset=0), CheckParameterID `0x9e10c`, GetInfo `0x9e92c`, GetList `0x9e99c`, GetProperty `0x9ea40`, GetValueStrings `0x6712`, DispatchSetProperty `0xc4a4e`, DoInitialize `0xc5bfe`, DoCleanup `0xc213e`, MIDI `0x5ce0`, DoRender `0xc4280`, Reset `0x7014`.

Synth = `0x1000000`, outer = Synth − `0x108`, heap débute à `0x2000000`. Kaja fait près de 6,8 Mo : les anciennes adresses Sophistry provoqueraient des chevauchements. Vtables dérivées : outer+0=`0x125348`, +8=`0x125498`, +0x100=`0x1254ac`, +0x108=`0x125500`. Champs AU : ouvert +`0x6795e4`, restauration banque +`0x6795e7`, dictionnaire enum +`0x6795e0`. Callbacks tempo/musique/transport : outer+`0xec/f0/f4`.

Licence : exécuter exclusivement le contrôle original. Préférence originale `KajaSysGlo` dans `com.linplug.CronoX3` ; SysGlo = Synth+`0xb4`, descripteur +`0x130`, nom +`0x1c1`, état rappelé +`0x301`. Part::setParaCharPtr `0x15ad6`. Sérialiseur ParaSet : vtable+`0x80` taille, +`0x84` données. Indicateur accepté Synth+`0xf229` ; +`0xf22e` est le mode démo et ne signifie PAS accepté. Ne jamais publier de clé/préférence ni déduire leur acceptation d’une ancienne adresse Sophistry.

À terminer : ABI de l’interface (types, tags et offsets changés, OscAnalog4 au lieu de OscAnalog3), panneaux graphiques, commandes de fichiers et gestes de l’original ; exécution macOS du nouvel AU CRX002 et auval, comparaison audio/CPU et, après validation utilisateur, profil de restauration des anciens projets CrX3. Les méthodes d’interface héritées de Sophistry et son ancien installateur restent bloqués. Le nouvel installateur et la vue compacte CRX002 sont séparés. Gain global = 1 pour CronoX, Sophistry +6 dB inchangé.

Mac utilisateur : M1 Ultra, macOS 15.7.2, Xcode, Logic Pro 11, Live 11.3.2, 44,1 kHz/256. Rapports et licences restent locaux. `Compiler-et-tester-CronoX.command` fournit un banc sans installation et conserve le cache de compilation.

Dernière instruction utilisateur : faire d’abord cohabiter l’AU ARM avec son CronoX original pour les comparaisons audio. Profil par défaut et seul profil activé : `config/au-identity-test.json`, aumu/CrT3/LinP, bundle `com.linplug.au.CronoX3.ARMTest`, exécutable/factory/classes Cocoa propres, fichier `CronoX 3 ARM Test.component`. NE PAS installer sous le nom de l’original ni reprendre CrX3 à ce stade. Générer Info.plist et CronoXIdentity.h via le script dédié. Les états VST gardent leur UID original Crx3 ; les futurs états AU de test doivent porter CrT3. Après validation utilisateur, un profil de restauration permettra CrX3 pour les anciens projets. Garder Sophistry CP038 intact. Noyau complet ARM64 compilé, 6 228 fixtures et pont AU complet passent sous QEMU ; auval/macOS toujours non exécuté.

CRX002 isole les préférences de banque/éditeur dans `com.linplug.CronoX3.ARMTest`. Le moteur peut lire la licence existante `KajaSysGlo` dans `com.linplug.CronoX3`, sans réécrire les préférences de l’original. Cette isolation des écritures est raccordée et testée ; le banc CRX001 utilise `useLocalMacPreferences=false` et ne lit/écrit aucune préférence macOS.


## CRX002 — reprise du 24 novembre 2026

Le rapport privé CRX001 fourni par l’utilisateur valide tous les tests C++ sur son Mac ARM64 sous macOS 15.7.2 : 6 228 fixtures SQRT, 14 contrats string, pont AU 522 paramètres, rappel et rendu Lightgarden. Résumé public sans données privées : `evidence/cronox-crx001-macos-results.json`. Ce rapport ne valide pas encore un composant AU enregistré.

CRX002 prépare le premier AU de comparaison `aumu/CrT3/LinP`, composant `CronoX 3 ARM Test.component`, bundle `com.linplug.au.CronoX3.ARMTest`. Il garde l’original CrX3 et Sophistry CP038. Préférences de test isolées dans `com.linplug.CronoX3.ARMTest`, lecture de la licence originale en repli uniquement. Ne jamais publier la valeur de KajaSysGlo ni un état brut contenant les préférences.

Le noyau traduit (413 unités) reste inchangé. Nouveautés de l’hôte : temporisateurs originaux activés avec horloge native, destruction D1 originale et callbacks globaux, adaptateur stat Darwin i386, wrapper AU MIDI/état/522 paramètres, vue Cocoa compacte de comparaison (chargement/sauvegarde, banque et diagnostic). Les panneaux graphiques originaux 3.6.6 ne sont pas encore raccordés et leurs propriétés privées restent désactivées.

Tests locaux verts : cycle activate/render/saveBank/restoreBank/deactivate/shutdown avec et sans Lightgarden, thread de contrôle et réinitialisation 48 kHz, 14 régressions de l’installation transactionnelle. Compilation complète Mach-O ARM64 effectuée ; assemblage strict du bundle et vérification des 3 symboles exportés réussis (`evidence/cronox-crx002-macos-cross-link.json`). Aucune exécution macOS du nouveau composant, aucune validation auval et aucune conformité sonore comparative à annoncer avant réception du prochain rapport.

La publication CRX002 inclut un manifeste source séparé et un lanceur épinglé. Préserver les caches du Mac sous `~/CronoX3-ARM64/projet/work` : la génération DSP n’a pas changé et ne doit pas être recompilée inutilement. L’installeur CRX002 prévalide le candidat, utilise une transaction avec sauvegardes dans `/Library/Audio/Plug-Ins/CronoX3ARMTest-Rollback`, ne confirme qu’après auval et rendus enregistrés, et restaure uniquement l’ancien ARM Test en cas d’échec.


Contrôles CRX002 supplémentaires : `tests/CronoXComparisonProbe.mm` exerce la factory native et Cocoa, les 522 paramètres, le chargement FXP par la vue, les sorties 2/6 canaux, le rappel dans une instance neuve et la réinitialisation 48 kHz. Il vérifie aussi que les préférences originales et le nombre de composants CrX3 n’ont pas changé, sans exporter leur contenu. Ces contrôles doivent être exécutés sur le Mac de l’utilisateur par l’installeur ; la compilation croisée ne remplace pas cette exécution.

Les objets SDK sont inchangés depuis CP038 ; aucun code DSP Sophistry n’est réutilisé à la place de CronoX. La liste d’export natif comporte uniquement la factory CrT3 et sa classe/metaclasse Cocoa. Ne pas l’élargir aux symboles `sl_*`, `sophistry::*` ou SDK : cela risquerait une coalescence dyld avec les autres plugins.


## Publication CRX002 vérifiée

Source : `d811b6cfc65813450d64a00177bde7b7f3c93be7` ; archive SHA256 `0731b4700dd3da883f6a0391037a43ca1d1935f4c871d8f2fe0a259afac5e269` (74 571 897 octets). Les 156 fichiers CronoX de l’archive ont été vérifiés contre leurs blobs Git, ainsi que les CRC et permissions exécutables. Préparation des sources et 14 tests transactionnels repassés depuis l’archive publique.

Lanceur : commit `460c5d3c7dfa978562ad0fede0956e600d13ef5e`, fichier `CronoX3/Demarrer-CronoX-CRX002.zip`, SHA256 `7a7166166f656ea7c80258f44de1ed0e7806b676ec1abe18b731b75dcb6bc952` (1 811 octets). Son téléchargement direct a été comparé octet par octet à l’original local. La branche distante se termine au commit d’enregistrement `e02b18b9b8e012aff62fd03542605c91cfccb470`. Les 46 entrées racine hors CronoX3 sont préservées.

Prochaine étape : attendre le rapport CRX002 du Mac. Il doit valider la factory/Cocoa, le rappel d’état et l’audio en stéréo/six canaux, puis auval et l’installation CrT3. Vérifier ensuite les comparaisons son/CPU de l’utilisateur avant de poursuivre les panneaux originaux et avant d’autoriser CrX3. Ne pas déclarer ces validations faites sur la base de la compilation croisée.


## CRX003 — correction du 25 novembre 2026

Le rapport utilisateur CRX002 confirme un arrêt du script `scripts/build-cronox-audio-unit.sh`, ligne 22 : `extra[*]: unbound variable`. Le noyau et les sondes C++ ont compilé ; aucun AU n’a été construit, enregistré, testé ni installé par cette tentative. Les deux avertissements codecvt ne sont pas la cause. Ne pas demander à l’utilisateur de changer son shell ni de supprimer son cache.

Cause : Bash 3.2 de macOS traite le tableau vide `extra=()` comme non défini avec `set -u`. Correction : créer `source_flags` à partir des options communes toujours présentes, puis y ajouter `-fobjc-arc` uniquement pour les fichiers `.mm`. Aucune option vide n’est passée au compilateur. Le DSP, son runtime et les 413 unités générées restent inchangés.

Le test `tests/CronoXBuildScriptProbe.py` exécute le vrai script dans un dossier avec espaces en redirigeant seulement les outils Apple vers des doubles de test. Il vérifie le passage C++/Objective-C++, les arguments, l’ARC, la réutilisation du cache et l’invalidation d’une seule source. GNU Bash 3.2 est compilé localement depuis l’archive GNU pour reproduire l’erreur originale et vérifier la correction ; ce test ne compile pas un AU et ne remplace pas auval. Les tests de transaction et preuves de compilation ARM64 CRX002 restent applicables ; seule la version affichée et le marqueur de contrôle de la sonde deviennent CRX003.

Garder CrT3 et le nom CronoX 3 ARM Test. La prochaine tentative utilisera `Demarrer-CronoX-CRX003.command` et produira un ZIP `CronoX3-rapports-CRX003-…`. L’original CrX3 et Sophistry CP038 ne doivent jamais être ciblés.


## Publication CRX003 vérifiée

Source `83f3d437eada4fc2cb6b859b2cbcd213583d9c6a` ; archive SHA256 `b99f152f4b8478e7447ae43444f72ae2723e641494048b4db34170e46f1ed7c4` (74 600 892 octets). Les 167 fichiers CronoX de cette archive ont été comparés aux blobs Git, avec vérification des CRC et des permissions exécutables. Le test du script publié repasse sous GNU Bash 3.2, reproduit l’ancien échec puis valide le correctif, les options et le cache. Le nouvel AU et sa sonde Cocoa compilent et s’assemblent strictement en Mach-O ARM64.

Lanceur `fc9a2bf82ab44794f929c41f336ccfca0304095a`, fichier `CronoX3/Demarrer-CronoX-CRX003.zip` ; SHA256 `c8a4784696cb80172e1d80e797e0c1f3fc4520aea3c126d354208de2d0214b03` (1 852 octets). Le téléchargement direct a été vérifié octet par octet, ainsi que ses CRC et la permission d’exécution du .command. Commit de métadonnées `f32e387d5994721af1919cd6701af39017c9ddd9`. Les 46 entrées racine hors CronoX3 restent inchangées.

Prochaine étape : attendre le rapport CRX003 du Mac. Il doit enfin dépasser la compilation et valider le vrai AU, la vue Cocoa, les rendus, le rappel et auval. Aucun AU n’a encore été exécuté avec succès sur macOS ; ne pas déduire la conformité sonore ou CPU des tests de scripts et de la compilation croisée. Le cache du noyau, CrX3 et Sophistry CP038 sont conservés.


## CRX004 — registre AU, 25 novembre 2026

Rapport privé CRX003 : compilation et prévalidation réelle macOS réussies. AU ARM64, vue Cocoa 600×220, 522 paramètres, MIDI/rendu 8 192 trames, rappel d’état dans une instance neuve, préférences et inscription CrX3 préservées. Temporisateurs, destruction et réinitialisation 48 kHz passent. Le nom du son de test est « unknown » : conserver ce point pour la reprise des libellés après la validation système ; ne pas prétendre à un nom de preset restauré fidèlement ni à une comparaison sonore avec l’original.

Échec suivant : auval dit « didn't find the component » (code 2) immédiatement après la copie de CrT3 et le redémarrage du registre. Aucune erreur DSP ou factory locale. Le candidat est correctement conservé hors Components par rollback ; aucun précédent ARM Test n’était installé. Original CrX3 et Sophistry CP038 préservés.

CRX004 reprend le principe de détection bornée déjà présent dans l’installeur Sophistry CP038 : toucher seulement le nouveau bundle et le dossier Components après copie, redémarrer AudioComponentRegistrar de l’utilisateur, interroger le catalogue et tester CrT3 dans des processus neufs avant auval. Le scanner peut être asynchrone ; ce diagnostic de course reste à confirmer sur le Mac. `CronoXRegistrationProbe` n’appelle jamais AudioComponentRegister ni CFBundleLoadExecutable ; il exige un composant unique du registre système et vérifie sa version via SpVr. `wait-cronox-registration.py` réessaie absence/version ancienne pendant 30 s, pas les doublons/erreurs de factory. Aucun succès de découverte ne remplace auval et les rendus enregistrés.

Diagnostics de registre : métadonnées installées, permissions de la chaîne de dossiers, architecture, signature, présence de quarantaine (sans valeur), lignes du catalogue limitées à CronoX ; sur échec, journal macOS filtré sur le nom/identifiant CrT3. Les rapports restent privés. Ne pas supprimer de cache Audio Unit global ou écrire dans les préférences de l’original. Les instructions du DSP restent inchangées depuis CRX001.


## Publication CRX004 vérifiée

Source `fc8500c095dfead0ea884ebc3a5a6007814f2cf7` ; archive SHA256 `d4127496b5fc27241bef6bd3f738bb320292fa3df7acb8eafe3f5dfb8e9edcdb` (74 634 765 octets). Les 181 fichiers CronoX ont été vérifiés contre les blobs Git ; CRC et permissions exécutables vérifiés. Les cinq tests de détection sont verts depuis la copie publique. Le composant, la sonde Cocoa et la nouvelle sonde de registre compilent et s’assemblent strictement en Mach-O ARM64. Le noyau traduit n’a pas changé.

Lanceur `a18cde516ee12e7301ff772420dc449217e27c95`, fichier `CronoX3/Demarrer-CronoX-CRX004.zip` ; SHA256 `7dca971142f038af5277c0822b08dd789933012ee8dea571d65c1f6b903ad5f7` (1 957 octets). Téléchargement direct comparé octet par octet ; CRC et permission du .command vérifiés. Commit de métadonnées `7e7b9aec0a1b6d4c312b248a84997bcb104966e8`. Les 46 entrées racine hors CronoX3 sont préservées.

Prochaine étape : rapport CRX004 du Mac. Vérifier d’abord registration-initial.json, discovery-*.json et registration-result.json, puis auval et les rendus enregistrés. Si la détection manque encore, analyser registration-failure.json (permissions, architecture, signature, catalogue et journal ciblé), sans conclure automatiquement à un problème DSP. CRX003 est le dernier candidat réellement exécuté sur le Mac : il passe en chargement direct mais n’est pas installé après son rollback. Ne pas déclarer CRX004 validé avant le rapport.


## CRX005 — diagnostic Python Apple, 25 novembre 2026

Le rapport CRX004 valide à nouveau le candidat natif local (522 paramètres, vue Cocoa, son, rappel, licence originale acceptée et préférences originales préservées). Le collecteur `diagnose-cronox-registration.py` s’arrête sur AttributeError : Python Apple n’expose pas `os.listxattr`. registration-initial.json est vide ; aucune sonde de découverte ni auval n’a ensuite été exécutée. Le rollback retire le candidat non confirmé. Ne pas considérer ce rapport comme une preuve d’échec de l’attente CRX004.

Correction CRX005 : getattr pour l’API optionnelle, repli sur `/usr/bin/xattr` en ne lisant que les noms (aucune valeur d’attribut exportée), valeur inconnue sur erreur. La collecte initiale est entourée d’un if non bloquant et son stderr est conservé dans registration-initial.log. La détection de la bonne version, auval et les rendus enregistrés restent strictement nécessaires pour confirmer l’installation. Aucune nouvelle modification DSP.

Huit tests `test_cronox_registration_diagnostics.py` couvrent l’absence effective de l’API dans un module os simulé, le repli natif, les erreurs/absences et le collecteur complet ; les mêmes tests exécutent le vrai bloc de l’installeur sous Bash 3.2 avec injection de résultats de processus. L’ancien arrêt prématuré est reproduit, la collecte facultative échouée laisse passer détection et auval, et une erreur de détection/auval reste bloquante. Aucun composant système n’est installé par ces tests.

Garder CrT3, CrX3 original et Sophistry CP038. Le nom de preset « unknown » et les panneaux originaux restent à reprendre après l’installation système validée. Ne pas annoncer la correction du registre comme confirmée avant le prochain rapport Mac.


## Publication CRX005 vérifiée

Source `3dbb3354f032029eae7d3e1d9471495e4e914d54` ; archive SHA256 `4d864ee3ff53dd63198eb310976b13825549741fdd0b8ace705f1ecc6cd25dae` (74 666 039 octets). Les 192 fichiers CronoX sont vérifiés contre les blobs Git ; CRC et permissions vérifiés. Les huit tests du diagnostic et du vrai bloc d’installation repassent depuis l’archive publique sous Bash 3.2, notamment sans os.listxattr et avec diagnostic défaillant. Le composant, la sonde Cocoa et la sonde de registre compilent et s’assemblent en Mach-O ARM64. DSP inchangé.

Lanceur `80e6b882a45a4032c1a392513a6948ac088264d4`, fichier `CronoX3/Demarrer-CronoX-CRX005.zip` ; SHA256 `11591ccf15c9e3c8e89da426d0598983883933e3e2ba9cc45629352a6c70d882` (1 898 octets). Téléchargement direct vérifié octet par octet, CRC et permission du .command vérifiés. Commit de métadonnées `8f623a3b1b429dc79ece9a14bce6d27293e58f95`. Les 46 entrées racine hors CronoX3 sont préservées.

Prochaine étape : rapport CRX005 du Mac. L’attente du registre n’a toujours pas été testée après le candidat local (CRX004 arrêté avant elle). Examiner registration-initial.json/log, discovery-*.json, registration-result.json puis auval et les rendus enregistrés. La collecte est facultative ; la détection/auval/rendus restent obligatoires pour confirmer. Ne pas déclarer le registre ou la conformité sonore validés avant les résultats Mac. Garder les questions de nom FXP « unknown » et de panneaux graphiques pour la suite après installation validée.


## Validation CRX005 confirmée par l’utilisateur — interface autorisée

Le 25 novembre 2026, l’utilisateur confirme : plugin validé, lancé et audible ; plusieurs presets chargés avec succès ; comparaison avec CronoX original concluante mais non exhaustive. Il autorise de passer à l’interface. Cette confirmation remplace l’attente du rapport CRX005 ; aucun nouveau ZIP automatique n’est fourni. Ne pas présenter cette écoute comme une preuve exhaustive ou bit à bit.

Conserver CRX005 comme référence audio stable. Garder CrT3 et le nom ARM Test pendant le travail de l’interface pour les comparaisons ; ne pas rétablir CrX3 sans phase de restauration explicite. Sophistry reste CP038. L’interface originale CronoX 3.6.6 a des offsets et tags différents : ne pas enlever les garde-fous hérités de Sophistry sans vérifier les fonctions et tables correspondantes.
