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
