# Reprendre à CP-018 — paquet et publication en finalisation

L’utilisateur confirme : projets Logic ouverts mais SILENCIEUX, MIDI visible y compris ⌘K. Ne pas annoncer le rappel sonore réussi. Sa demande de changement de banque est couverte par le nouveau bouton « Banque de sons… » et `--choose-bank` dans le configurateur et l’installateur. La licence validée est réutilisée. Ancienne méthode donnée : fermer Logic/Live, `defaults delete com.linplug.Sophistry SophistryARMSampleRoot`, relancer CP016 et Entrée pour réutiliser l’enregistrement ; ne jamais supprimer tout le domaine.

Lire docs/CP018.md et evidence/cp018-development-checks.json. CP017 (20384dd) consigne le rapport CP016 réussi (auval0,522paramètres,sixWAV exacts,installation conservée). CP018 fournit une première vue Cocoa, sept fonds et quinze molettes Main, volume134, navigateur des522paramètres, importsFXP/AU, exportAU, nom/état du son et diagnostic licence/MIDI/rendu/samples. Interface incomplète, non exécutée surMac. Ne pas déclarer le silence résolu.

SpSt/SpPr/SpBr/SpRl transportent des octets plats, sans pointeurs CF, pour Logic séparant la vue et l’AU. SpSt=128KiB JSONz, SpPr=programme brut, SpBr=header(version,pathBytes,bookmarkBytes)+UTF8z+bookmark, SpRl=U32=1. BankAccess.h maintient l’accès Mac au dossier via URL/bookmark ; clé privée SophistryARMSampleBookmark ajoutée aux deux précédentes. Aucun bookmark/clé/chunk de projet dans rapports. Recharger et choix de banque réappliquent le dernier état chargé, pas les modifications ultérieures : tester sur copie.

Le chemin original fopen échoué→fprintf(stderr)→alerte Carbon de chargement manquait dansCP016. Adaptateurs bornés ajoutés pour stderr et quatre notifications de chargement à un bouton, aucune confirmation ni contrôle de licence contourné. Missing puis réindex/retry exact entre quatrebackends ; sérialisation de21072octetsSHA f0331943621b8a3aed132cf90b62f12c2da9df4cbc12f855cd01534f003e9e88. Huit régionsCP011,596textes contre référenceCP016,cinqscénarioschemins,huitcyclesAU Linux natif etARM64QEMU,28testsPython passent. Quatre binairesMac liés strictementARM64, factoriesAU+Cocoaexportées. Le code des instructionsDSP traduites n’a pas changé.

InstallerCP018 ajoute testsNativeBankDiagnosticsProbe et AudioUnitEditorProbe (avant remplacement puis hébergementAU séparé après auval/rendus). Nouveau probe chargeAUpreset AVANTInitialize, rend3s60/100off2s, compareWAV original-2, puis testeFXP/AU, images,15molettes,522paramètres,7filtres,volume etPNG. CP016 réappliquait état aprèsInitialize pouraudio, ce scénario n’était pas couvert. Aucun testCP018 macOS exécuté ici. Prochain retour : ZIPCP018 puis diagnostic copié depuis Éditeur Logic sur copie d’un projet silencieux AVANT toute autre modification. Mac utilisateur macOS15.7.2,Logic11,Live11.3.2. Ne pas redemander licence/presets déjà disponibles.

Publication autorisée sur codex/sophistry-native-checkpoints uniquement ; main inchangée. SourceWIP sauvegardée9c028d0. Finaliser docs/evidence, commit+push sources, télécharger et vérifier tous les blobs ZIP, créer lanceurCP018 figé et vérifier son téléchargement, puis sauver bundle autonome. État de publication actualisé ci-dessus une fois terminé. Work contient builds et rapports privés ignorés. Espace disque limité : 300Mo libres environ ; si nécessaire supprimer uniquement binaires reconstructibles identifiés, préserver sources,objets,snapshots,rapports,historique. Ne pas publier les logs bruts /Users,préférences/bookmarks ou clé.

Les notes suivantes sont historiques ; les mentions de rappel Logic en attente sont remplacées par le constat de silence ci-dessus.

# Reprendre à CP-017 — auval et installation CP-016 confirmés sur le Mac

Rapport Sophistry-rapports-CP016-20261115T124240Z.zip reçu. Lire evidence/mac-cp016-installed-au.json. Code testé f582f492ea3f26854e33d738ec0c19ff12ac7eb1. Compilation/signature/install système, auval(exit0,522paramètres), licence persistée/relecture fraîche et six WAV original/préflight/enregistré 2/6canaux exacts. Empreintes identiques aux CP013/15. L’installation est conservée et la clé reste enregistrée. Warning non bloquant : pas de channel layout pour6canaux. Le composant est fonctionnel sur le scénario fourni, couverture moteur/banque entière non démontrée.

L’utilisateur teste des anciens projets dans Logic pendant que nous poursuivons l’interface. Ne pas marquer le rappel Logic réussi avant son retour, ne pas lui demander de remplacer le composant pendant ses essais. Continuer depuis les ressources graphiques originales et les constructeurs KajaEditor (55064,5efe2,5cce8 et sous-panneaux). Interface générique uniquement dans CP016 installé ; ne pas prétendre que l’interface fidèle existe déjà. Les anciennes notes d’attente CP016 ci-dessous sont historiques.

# Reprendre à CP-016 — corrections du rapport CP-015, nouveau test Mac à effectuer

Lanceur immuable téléchargé et vérifié : https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/3b81d8b39548536d1f8511e473fae3f8ee7dc141/Demarrer-Sophistry-CP016.command ; SHA256 8ca10a9dc3cd9678d1a22ecfe71c8419b48a20a5c9facc057d8976ea7203130e.

Source CP016 publiée/vérifiée : f582f492ea3f26854e33d738ec0c19ff12ac7eb1 ; archive https://codeload.github.com/stefanwul-hub/SophistryARM/zip/f582f492ea3f26854e33d738ec0c19ff12ac7eb1 ; SHA256 8a9b84cda354b50448ae478416ed3b7984d04153c237236b0d78299a49fa9132 ; 4039 blobs vérifiés. Le lanceur CP016 épingle cette archive et conserve les sources dans Documents/SophistryARM-CP016. Prochain rapport attendu : Sophistry-rapports-CP016-<date>.zip.

Lire d’abord docs/CP016.md et evidence/mac-cp015-installation.json. Le rapport Sophistry-rapports-CP015-20261115T112344Z.zip confirme la compilation, la persistance/réutilisation de la licence dans un nouveau processus, la découverte du candidat système et les WAV préflight 2/6 canaux byte-exact contre la référence originale. auval échoue : 297 erreurs de propriété33 pour99 paramètres et initialisation192k/4096. Le composant est retiré ; CP015 a aussi restauré les anciennes préférences, donc supprimé la clé juste validée. Ne pas redemander de clé en ligne.

CP016 : propriété33 raccordée à l’original829fc/82fd0 (CFNumber/dictionary/substring/array adaptés), cache du constructeur dérivé créé à la première demande, 596 résultats originaux exacts. Limite de contrôle300M pour construction des tables (192k exige55,6M), rendu30M inchangé. Tests du pont8cycles et factory Apple596cas + matrice auval. Réglages conservés après vérification dans un nouveau processus ; rollback des réglages incomplets seulement ; restauration volontaire des réglages avec --restore-settings. Interface générique et rappel Logic/Live toujours non validés. Les notes CP015 ci-dessous sont historiques et leur attente de premier rapport est résolue.

# Reprendre à CP-015 — installation de test en attente de son premier rapport Mac

Lire docs/CP015.md et evidence/cp015-development-checks.json. Source publiée/vérifiée : 5ad00df0defaf97d5090114bfedbcdfa130876ab, SHA ZIP 57918aebf451bb674a249e6f4ce08f3ffd201913a020f149aeb9fbda87812394. Lanceur immuable vérifié https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/a1a2fcf2f4d8240583dc23e5f48e13aa4277d5e9/Demarrer-Sophistry-CP015.command ; rapport attendu Sophistry-rapports-CP015-<date>.zip. CP-014 a confirmé le rapport CP-013 (détails ci-dessous) : vrais rendus AU natifs ARM64 sur le Mac, licence acceptée, six WAV factory/direct/original byte-exact pour 2/6 canaux, source 92d1d60d44e8cfa89d570721bfdbd9d52ad12adf. Ne pas le confondre avec le nouveau code CP-015, compilé/cross-lié mais pas encore exécuté sur Mac.

CP-015 ajoute ConfigureSophistry.mm (choix local du dossier, validation de licence intacte, sérialisation SysGlo originale puis CFPreferences utilisateur ; sauvegarde privée et restauration), recherche récursive de samples avec suffixes/priorités et refus des ambiguïtés, découverte AU enregistrée et marque SpVr=CP-015. Installer-ARM64.command devient une transaction d’essai autorisée : préflight strict avant sudo, copie/backup vérifiés, rename, auval limité180s, nouvelle comparaison des WAV enregistrés, commit uniquement si tout passe, rollback sinon. scripts/component_transaction.py cible uniquement /Library/Audio/Plug-Ins/Components/Sophistry.component. Copies anciennes et candidats rejetés restent sous /Library/Audio/Plug-Ins/SophistryARM-Rollback ; préférences privées et outil autonome sous ~/Library/Application Support/SophistryARM/Backups/<UUID>, jamais dans le ZIP.

Vérifications : 25 tests Python (dont12 transaction/3 auval), pont AU Linux natif et ARM64/QEMU avec refus d’écriture non enregistrée, 5 cas de chemins (objet/heap/globals/programme strictement identiques ou ambiguïté refusée), 8 régions CP-011 inchangées. Le sérialiseur SYPS original et traduit correspond sur défauts80octets et entrée publique volontairement invalide96octets. Plugin, helper Cocoa et factory probe sont liés en Mach-O ARM64 sans symboles non résolus. Les actions CFPreferences, panneau de dossiers, sudo/copie/xattrs Mac, auval et processus AU enregistrés nécessitent le prochain rapport Mac. Ne jamais annoncer auval ou réouverture de projets réussis avant ce retour.

L’utilisateur a déjà autorisé installation/remplacement et publication ; ne pas redemander cette autorisation. Sa clé reste strictement sur son Mac. Les logs reçus CP-013 et les six WAV sont dans work/mac-report-cp013, pas dans Git. Interface Sophistry Cocoa toujours absente : seuls les contrôles génériques AU sont disponibles. Les 106 images et le code SynthEditor sont conservés pour cette suite. Horloge/timers et services hôtes restent partiellement modélisés ; pas de garantie complète sur tous presets/formats/chemins exécutables.

---

# Reprendre à CP-014 — Audio Unit testé sur le Mac utilisateur

Rapport reçu : Sophistry-rapports-CP013-20261115T083620Z.zip, source testée 92d1d60d44e8cfa89d570721bfdbd9d52ad12adf. Tout passe (exitcode0) sur macOS15.7.2 ARM64 / Apple clang17 : construction/signature du component, chargement par sa factory, métadonnées522, replays704DSP/11635instructions, quatre réinitialisations et rendus musicaux AU 2/6 canaux.

Lire evidence/mac-cp013-au-factory.json. Vérification indépendante des six WAV reçus : factory/direct/original identiques pour chaque configuration. 2 canaux : SHA WAV 5f5d161d3eeff49eb99b13f7008f19e0601b5a4464f85baa434483f67552ff39 ; 6 canaux : da29170f01481908abe380d027fdaf5f3225873688f5886fa51719ed08875134. 132300 frames à44100Hz / 3s / note60vel100off2s / ancien .aupreset Lightgarden CrX3. Le contrôle original accepte la licence, saisie uniquement sur Mac. Aucun secret ou chemin utilisateur n’est dans la preuve publique.

Le rendu dure ~0,60s pour3s de son, max appel4,96ms (stéréo) /3,21ms (six canaux) ; ne pas en déduire une garantie temps réel/polyphonie. Pas d’installation système, auval, interface Sophistry Cocoa ou rappel Logic/Live validés. Les rapports bruts et WAV sont dans work/mac-report-cp013, à ne pas publier tels quels.

Travail suivant autorisé : configuration locale de la licence par les routines SysGlo originales, choix local de la banque, puis installation de test avec sauvegarde et rollback automatique si auval échoue. Le remplacement est déjà autorisé par l’utilisateur ; le blocage de l’ancien script était technique. Ne jamais demander la clé dans le chat. L’interface fidèle reste à développer avec les images et le constructeur SynthEditor d’origine ; ne pas présenter les contrôles génériques comme cette interface.

---

# Reprendre à CP-013 (prototype AU, validation Mac en attente)

Lire docs/CP013.md et evidence/au-render-comparison-cp013.json. Sources CP-013 publiées et vérifiées : 92d1d60d44e8cfa89d570721bfdbd9d52ad12adf ; SHA ZIP a689527bb1d8b1d4c612d6444c7ee27bed97dda1b100d154962aa3209e64769c. Demarrer-Sophistry-CP013.command lance Verifier-AU-Mac.command. Lanceur immuable vérifié : https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/480349830f8c5ab65e4d169bde6a05780ff67caa/Demarrer-Sophistry-CP013.command. Le ZIP de résultats attendu s’appelle Sophistry-rapports-CP013-<date>.zip. Ne pas repartir de CP-008. Le rendu musical CP-011/CP-012 sur le Mac utilisateur est validé pour un scénario FXP, pas encore par le nouveau wrapper AU.

Travail CP-013 : constructeur AU original, un bus 2/6 canaux et 522 paramètres confirmés. src/engine/LegacyEngine.cpp possède un mode AU qui exécute les méthodes originales de construction, stream format, initialisation, MIDI et DoRender ; tests/probe_au_render.py compare le même chemin i386/Unicorn. Comparaison Linux byte-exact sur 3 s pour 2 et 6 canaux, mais sans licence et sans son musical. Ne pas transformer cette preuve de chemin d’exécution en preuve audio.

Le wrapper src/au/SophistryAU.cpp utilise le SDK Apple officiel vendored third_party/AudioUnitSDK, version 1.3.0 / e789bc83ddc07cbf80e7bfaf84f1ade975287400 / Apache-2.0. C++20, mapping MIDI/XML/MIDI2 désactivés. scripts/build-audio-unit.sh construit un candidat ARM64 non installé. tests/AudioUnitFactoryProbe.cpp charge sa factory dans son propre processus, teste métadonnées, ancien vstdata, rendu et réinitialisation ; ce test doit encore être exécuté sur Mac. Interface générique provisoire uniquement ; pas d’interface Sophistry Cocoa reproduite.

Les modifications sont dans le dépôt partagé, la publication est déjà autorisée. Les outils de cross-compilation/SDK Mac téléchargés sont dans /workspace/work/tools et ne sont pas distribués. Ne pas inclure les logs Mac privés ou la clé dans un commit. Le test de licence doit rester local et utiliser le contrôle original intact. Installer-ARM64.command doit rester bloqué jusqu’aux validations nécessaires, sans nouvelle demande d’autorisation pour les sauvegardes/push déjà autorisés.

---

# Reprendre à CP-012

**Le rapport Mac CP-011 reçu confirme un premier rendu musical complet réussi.** Lire evidence/mac-cp011-licensed-render.json. Le code source testé est 452c29a90a95628a56437b10b30fbf1ea0c69b97. macOS 15.7.2 ARM64 / Apple clang17 : tous les builds et tests passent. Licence privée acceptée ; ne jamais demander ou récupérer la clé. Le WAV natif de 3s, six canaux VST, 132300 frames / 793800 floats, est byte-exact avec le WAV original i386/Unicorn. SHA-256 WAV ac22cf3fb678d935629ca4454bd61c6db1215be0f79d6226d628744132ddaec7 ; PCM 8087271859e6f18cc09c9d286d5a389e9368a4186c73acd7dda734b8dadaf39c. Cas : FXP Lightgarden, note60/vélocité100/off à2s, 44100Hz/bloc512. Pics L/R 0.0863 / 0.0631 ; ce ne sont plus les offsets quasi silencieux de CP-010. Les appels hôtes correspondent aussi. Le libm Apple i386 n’est pas exécuté.

La preuve indépendante et anonymisée est sauvegardée ; les logs bruts avec chemins /Users restent dans work/mac-report-cp011 et la pièce jointe, à ne pas publier. Pas de données de licence collectées. Le .component, son auval et le rappel des projets ne sont toujours pas validés.

**Travail suivant :** couche AU moderne. SDK officiel Apple cloné dans work/apple-audio-unit-sdk, commit bd98b31feff57a15989fcfab4cd86dc63382b1ac ; inspecter/vendorer include/src/LICENSE si utilisé. Vérifier la construction AU originale et ses bus : constructeur AUBase0inputs/1output mais nombre de canaux/support à confirmer ; sous-objet Kaja change de vtable à f2208. Les paramètres AU listés sont522, les alias de validation56. Ne pas les remplacer par602 sliders normalisés VST. Voir analysis/au-parameter-contract.json.

Les notes CP-011 suivantes restent utiles ; leurs mentions de test Mac en attente et de rendu silencieux sont historiques.

Lire `docs/CP011.md`, `port-status.json`, `evidence/cp011-validation.json` et `analysis/au-parameter-contract.json`. Les sources `src/engine/LegacyEngine.cpp` et `LegacyImageData.cpp` fournissent maintenant un hôte C++ autonome. Les états FXP/AU, programmes sauvegardés et zones mémoire correspondent à l’original sous Linux natif et ARM64/Linux/QEMU. Le rendu non enregistré est identique mais reste sous −100 dBFS : le test sonore est en échec. Aucun AU installable n’est disponible.

Les 191378 instructions / 758579 opérations p-code sont sauvegardées, avec 366 objets du moteur vérifiés en Mach-O ARM64 à CP-010. Le nouvel hôte C++ et sa branche CoreFoundation ne sont pas encore compilés ou exécutés sous macOS. Les 704 cas DSP et 11635 cas d’instructions/gardes passent ; les résultats natifs Mac reçus concernent CP-008.

**Licence :** l’utilisateur a confirmé la posséder. Ne jamais demander sa clé dans le chat/GitHub. `Verifier-Moteur-Mac.command` prévoit une saisie locale masquée par stdin, ou la lecture des préférences existantes de com.linplug.Sophistry. La saisie utilise le setter original de SysGlo, avant l’activation des écritures de préférences. Les contrôles originaux restent intacts. Les modes privés désactivent les captures mémoire et sauvegardes de programme. Une entrée invalide est refusée ; aucune licence réelle n’a encore été testée ici.

Le vérificateur Mac prépare, après réussite du rendu natif, une référence Python/Unicorn locale et compare les WAV strictement. Les paquets de référence sont installés dans work/reference-python, pas dans le moteur C++. La lecture des préférences par defaults est capturée en mémoire. Ne pas publier d’exports privés. La comparaison complète licenciée doit encore être exercée sur le Mac ; l’ancien libm Apple i386 reste hors du test.

**Prochaine action :** analyser le ZIP de rapports CP-011 du Mac. En cas de PC manquant, récupérer l’adresse dans Ghidra, réexporter et régénérer avec --reuse-layout. Le dernier build complet local est work/fxp-complete-build ; le nouvel hôte natif est work/native-engine-cp011 et ARM64/Linux sous work/native-host-arm64. Les builds Mac sont dans work/native-engine et work/lifter-whole.

**Contrat AU récupéré :** 522 identifiants publics discontinus de 0 à 555, 56 alias anciens de validation, noms/unités/plages/défauts comparés à l’original. Les méthodes sont testées avec une fixture d’objet AU externe limitée, pas l’AUBase complet. L’entrée réelle originale remplace la vtable du sous-objet Kaja par 0xf2208 ; ses variantes de callbacks/connexion et la disposition des bus doivent encore être vérifiées. Ne pas assimiler les six sorties VST à trois bus AU, ni publier 602 paramètres VST normalisés comme contrat AU.

Le projet Ghidra fermé/enrichi est dans checkpoints/ghidra-project ; brut compressé dans analysis/lifter-full. Trois conflits de chevauchement restent consignés. L’hôte C++ reste limité : PCM16 stéréo, namespace d’assets de référence, scénarios d’erreur des dossiers/GUI, timers non pompés, mutex mono-CPU, cycle de vie non finalisé. Le wrapper AU, l’interface Cocoa, auval, le rappel Logic/Live et l’installation avec sauvegarde restent à réaliser.

Les sections ci-dessous conservent les étapes historiques et leurs limites datées.

Objectif utilisateur : portage **complet et fidèle** de Sophistry Audio Unit vers Apple Silicon, à partir du code machine original, en conservant le rappel d’anciens projets AU Logic et Live. L’utilisateur possède les samples/presets externes. Son Mac est sous macOS 15.7.2, avec Xcode, Ableton Live 11.3.2 et Logic Pro 11. Pas de plugin ARM64 complet obtenu à ce checkpoint.

## Commencer ici

1. Lire `port-status.json`, `README.md` et `docs/RAPPORT.md`. Ne pas confondre le pseudo-code avec un portage ou l’objet du noyau avec un `.component`.
2. Vérifier le SHA-256 de `reference/Sophistry.component.zip` avec celui du rapport ; l’original est figé au commit indiqué.
3. Ouvrir `checkpoints/ghidra-project/Sophistry.gpr` avec **Ghidra 11.3.2 / JDK 21**. Le dossier `.rep` adjacent est indispensable. Copier le projet vers un dossier de travail avant de le modifier.
4. Utiliser `analysis/vtables.json`, `analysis/ghidra/function-index.jsonl`, `analysis/ghidra/calls.tsv` et le dossier `functions/`. Les `_vslot_N` sont des annotations inférées, partagées entre classes ; ne pas leur inventer des noms sémantiques.
5. Pour récupérer l’historique depuis une archive locale contenant le bundle : `git clone checkpoints/Sophistry-history.bundle work/reprise`. Depuis la distribution GitHub, cloner plutôt `git clone --branch codex/sophistry-native-checkpoints https://github.com/stefanwul-hub/SophistryARM.git work/reprise`. Le dépôt original est conservé ; la distribution du checkpoint utilise une branche dédiée, sans remplacer `main`.
6. Ajouter de vrais états `.aupreset`/`.fxp` et les samples référencés dans un dossier de travail, sans les publier automatiquement. La paire réelle est dans `reference/Presets/`, les schémas dans `analysis/parameter-schemas.json`, la comparaison dans `analysis/preset-pair/decoded/`. Les tests synthétiques ne prouvent pas le rappel sonore, et la lecture structurelle des vraies données non plus.

## Points d’entrée importants

- Sauvegarde/restauration CFData `vstdata` : i386 `0x3d14`, `0x3e30`.
- Dispatch chunks : `0x1b998`, `0x216fe`. Dans la table Synth/Kaja, indices 176/177 : `0x19986` / `0x1beb0` (branches de sauvegarde/restauration de banque à examiner).
- Kaja initialisation moteur : `0x4efca` (fonction volumineuse, graphe de modules à reconstruire).
- Noyau saturateur déjà traduit : `0x73fb0`, addition `0xc14e4`, configuration coefficients `0x742fa` encore hors du périmètre traduit.
- Identité originale : `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`.

## Vérifications déjà faites

`evidence/` contient les résultats exacts. Dix tests d’outils et d’états passent. Le noyau C++ correspond à la routine i386 émulée sur 160 cas ; les fixtures natives ajoutent un cas désactivé. Le rendu de test du noyau a une erreur nulle. L’objet Mach-O du noyau est ARM64, type objet relogeable. Aucun test natif Mac, `auval`, test du synthé complet ou réouverture de projet n’a été exécuté.

## Reproduire Ghidra seulement si nécessaire

L’analyse enregistrée évite de recommencer. Pour une nouvelle analyse indépendante, installer Ghidra 11.3.2 et un JDK 21 complet, définir `GHIDRA_HOME` et `JAVA_HOME`, puis lancer `bash scripts/run-ghidra.sh`. Les nouveaux résultats restent dans `work/`. L’archive officielle utilisée est `ghidra_11.3.2_PUBLIC_20250415.zip`, SHA-256 `99d45035bdcc3d6627e7b1232b7b379905a9fad76c772c920602e2b5d8b2dac2`, distribuée depuis le dépôt officiel NationalSecurityAgency/ghidra.

## Garder un nouveau checkpoint

Enregistrer le projet Ghidra fermé, les sources, les tests, les preuves et les limites. Mettre à jour `port-status.json` uniquement en fonction de vérifications réelles. Créer un commit local puis un nouveau bundle hors de son propre suivi : `git bundle create checkpoints/Sophistry-history.bundle --all`. Ne pas remplacer l’ancien composant tant que le moteur, les états et les copies de projets n’ont pas été vérifiés.

## Ajout CP-004

La paire Lightgarden est analysée. L’identité AU fournie est `CrX3`, et l’utilisateur confirme que Sophistry/CronoX 3 partagent le format des fichiers ; ne pas demander de nouveau un `.aupreset` Sophistry qu’il ne peut pas créer avec son ancien binaire 32 bits. Conserver `Sop3` pour le futur composant.

`LegacyStateReader.cpp` lit/réécrit les enveloppes de blocs ; aucune sémantique DSP complète n’est chargée. Le lecteur Python applique les schémas issus du flux de contrôle original. Résultats et limites dans `docs/PRESETS-CP004.md`. La demande du sample `BT_cronox18.wav` est en cours ; ne pas le synthétiser artificiellement en prétendant avoir reproduit le preset.

Le paquet CP-003 local est toujours intact dans l’environnement de travail. Son upload monolithique GitHub n’a pas abouti et a bloqué l’outil ; pour les sauvegardes distantes, utiliser des objets plus petits et vérifier le téléchargement. Ne pas renouveler un envoi monolithique de 43 Mo en base64.


## CP-005 — sauvegarde après interruption de publication

L’utilisateur a explicitement autorisé la publication de l’archive complète (binaire original, décompilation et projet Ghidra compris) dans le dépôt public stefanwul-hub/SophistryARM. Ne pas redemander cette autorisation pour cette publication.

Le sample demandé a été récupéré depuis Presets/BT_cronox18.wav au commit 0ecf4ccfabcb154fa793d08df26d56b501df8656. Il est conservé dans reference/Samples/ ; sa provenance est dans analysis/preset-pair/sample-source.json. Il n’a pas encore été utilisé pour un rendu du synthétiseur complet.

Une seconde tentative d’envoi monolithique de l’archive par github_create_blob a bloqué et a été interrompue par l’utilisateur. Aucun succès de publication n’est confirmé. Ne plus recommencer cet envoi monolithique. La branche distante créée précédemment était codex/sophistry-cp003-20261114 ; aucun lien de téléchargement du checkpoint n’a été vérifié. Le dépôt main utilisateur n’a pas été modifié par nos opérations.

Les archives CP-003 et CP-004 restent conservées localement. CP-005 contient l’état actuel, le sample et l’historique Git. Le moteur DSP complet, l’Audio Unit ARM64, sa validation et le rappel des projets restent à réaliser ; ne pas les déclarer fonctionnels.


## CP-006 — première traduction statique d’instructions

Le sample est analysé : PCM16 stéréo 44100 Hz, 334664 frames, 7,588752834 s ; pas de boucle smpl embarquée. Échantillon exploité dans des tests isolés de filtre, pas dans un rendu du synthé complet.

`scripts/ghidra/ExportPcode.java` exporte les opérations p-code brutes des instructions sélectionnées. `scripts/lift_pcode_cpp.py` émet un C++ à opérations et labels fixes, sans décodeur x86 au runtime. Export sélectionné : 2518 instructions, 12 fonctions (saturation, dispatch et huit variantes de FilterMoogSI, addition de sortie, thunk PIC). Les fonctions non sélectionnées ne sont pas portées par ce résultat. Les opérations et formats non pris en charge entraînent une erreur explicite de génération.

Le test est `tests/compare_lifted_dsp.py`. Il compare l’exécution C++ à Unicorn sur les octets originaux et contrôle les sorties et la mémoire de l’objet. 148 cas, 14544 valeurs de buffers comparées, aucun écart, 2450 adresses d’instructions exécutées sur 2518 exportées. Les deux exécutions partagent un adaptateur Python math.log10 ; le libm Apple original n’a pas été exécuté. Ne pas déclarer la fidélité du synthétiseur entier ni la validation AU.

Sources : `src/lifter/LifterRuntime.h/.cpp`, `src/lifter/GeneratedDsp.cpp`. Rapport : `evidence/static-lift-comparison.json`. Fixtures natives : `evidence/static-lift-comparison.fixtures`. Un programme de replay natif et les vérifications ARM64 sont l’étape suivante.


## CP-007 — replay autonome et vérification ARM64 sélectionnée

`tests/LiftedProbeMain.cpp` rejoue les fixtures sans Python/Unicorn. Le format actuel des fixtures est SLFT0002 ; les réponses log10 enregistrées sont vérifiées sur leurs arguments puis réinjectées, afin d’isoler le code statiquement traduit du libm de la plateforme. Le mode `--native-math` teste séparément le libm de la plateforme. Les deux modes passent sous Linux x86_64.

Les objets Mach-O ARM64 du runtime et du code généré compilent avec Zig 0.14.1. Le même probe, compilé en ARM64/Linux musl statique, passe sous QEMU 7.2.0 les 148 cas et 1203328 octets comparés, sans différence. Cela ne constitue pas une exécution macOS ni un test sur du matériel Apple Silicon. Aucun Audio Unit n’est construit/validé. `Verifier-Mac.command` compile et lance les probes sur Mac ; il n’installe rien.

Sources/tests et objets sont dans le checkpoint ; Zig, QEMU et l’exécutable ARM64/Linux de travail ne sont pas des dépendances nécessaires sur le Mac utilisateur. Les URL et SHA des outils sont consignés dans `evidence/static-lift-arm64-provenance.json`.

Étape suivante : mode Schrader (`SamWT_c`). Le traitement original du sample est identifié : `0xaf2b2` mélange les deux canaux par moyenne, `0x32430` normalise, `0x8de6a` construit 64 tables de 128 floats en appelant le resampler/crossfade `0x8d9dc`, applique un bord progressif et normalise chaque table. `0x38f48` joue les tables. Pas encore traduit/testé à CP-007.


## CP-008 — préparation du sample et lecteur Schrader traduits

`analysis/lifter-all/` fusionne les exports initiaux et `lifter-sampler/` : 3242 instructions, 19 fonctions. `GeneratedDsp.cpp` est émis depuis ce dossier. Ne pas régénérer à partir du seul export initial `analysis/lifter/`, qui ne contient que les premiers blocs.

La chaîne de tests utilise le sample PCM16 fourni comme entrée standard décodée, exécute la moyenne mono originale (0xaf2b2), la normalisation (0x32430), la construction des tables (0x8de6a, 0x8d9dc) et le lecteur Schrader (0x38f48). 704 cas, 5420672 octets comparés, zéro différence avec les mêmes adaptateurs hôtes. Deux sondes mono de trois secondes sont dans evidence/audio/schrader-root60-*.wav : mêmes échantillons, sans rendu du preset complet. Les contrôles sont explicites dans le test, pas importés du preset.

Le format des fixtures est maintenant **SLFT0003**, avec appels math à taille variable (log10/pow). Le probe natif et les objets Mach-O ont été mis à jour. Les 704 cas passent sous Linux x86_64 et ARM64/Linux/QEMU avec les réponses ABI enregistrées. Avec le libm natif ARM64/Linux musl : sept octets d’état interne différents, aucun octet différent dans les buffers de sortie vérifiés ; échec strict conservé dans les rapports. Ne pas annoncer une fidélité globale ni un résultat macOS. Les conversions de stockage x87/IEEE ont passé 20000 cas canoniques finis contre le type étendu natif Intel.

Le decoder de fichiers Apple AudioConverter n’est pas exécuté. Son usage et ses formats ont été relevés à 0xaef4c ; la préparation et le jeu des tables sont exécutés à partir des floats d’entrée. Aucun allocateur complet, chargement sémantique du preset, note-on du synthé complet, GUI native ou Audio Unit n’est prêt.

L’autorisation de publication publique est toujours acquise. Les envois monolithiques de dizaines de Mo par create_blob ont bloqué deux fois. Ne pas les renouveler. Les archives locales antérieures restent conservées ; tester tout nouveau canal de livraison sur un petit objet, avec délai limité et vérification indépendante avant de l’annoncer.


## Publication distante résolue

La connexion Git classique est authentifiée par l’environnement et fonctionne. Le push standard vers `https://github.com/stefanwul-hub/SophistryARM.git`, branche `codex/sophistry-native-checkpoints`, a réussi pour les huit checkpoints. Ne pas repasser par github_create_blob avec un payload géant. Le dépôt `main` n’a pas été modifié.

L’archive codeload du commit a1b6c7eacfcc196bc057d1e9853c2a10296e79a8 a été téléchargée : 28517842 octets, 3483 fichiers, SHA-256 0b7aadf2dc5a38f442dfbb04357f72d1768df606a486a524aa102fb0b5925801. Chaque blob de l’archive correspond au commit. Le projet Ghidra et ses données `.rep` sont présents. Le `.bundle` local ignoré n’est pas inclus dans une archive GitHub ; l’historique complet est disponible par clone de la branche. L’autorisation publique est acquise.


Le lanceur `Demarrer-Sophistry-CP008.command` automatise le téléchargement de l’archive source vérifiée, son empreinte, son extraction et les probes Mac. Il pointe vers le commit source 9b0cf0f5a35ecf85aae8dd026a3f12fd56411040 ; les sources DSP sont identiques au checkpoint CP-008 testé, avec une clarification de l’historique distant et de la sortie de diagnostic math. Les données de publication sont dans checkpoints/CP008-publication.json. Les tests sous macOS et la compilation de AUStateProbe avec un SDK Mac n’ont pas été exécutés ici.

## CP-008, correctif Mac 1 — premier retour du Mac utilisateur

Le journal reçu confirme macOS 15.7.2 ARM64, Apple clang 17.0.0 et SDK 15.5. La compilation de SaturProbe termine sans erreur, puis `lipo -verify_arch arm64 fichier` échoue : Apple lipo interprète tous les arguments restants comme des architectures. Aucun replay, compilation du lifter ou auval n’a été atteint. Le journal ne constitue donc pas un résultat DSP négatif.

Les quatre appels sont corrigés en `lipo fichier -verify_arch arm64`, et les étapes sont annoncées dans le journal. `port-status.json` porte `mac_verifier_revision: 1` ; le lanceur ne doit pas réutiliser silencieusement une ancienne copie locale de CP-008. Les calculs DSP et les fixtures sont inchangés. Les 704 cas repassent localement. La syntaxe shell et les contrôles d’objets Mach-O ARM64 avec llvm-lipo 19.1.7 sont vérifiés ; ce n’est pas une exécution du script sur macOS. Le rapport de diagnostic sans chemin personnel est `evidence/mac-cp008-verifier-fix.json`. Attendre le nouveau retour Mac pour déclarer les probes exécutés sur Apple Silicon.

La distribution corrigée est figée au commit `1f85c63cff513d0ccf9e93d12711eed910fbc056`, archive téléchargée et chaque blob vérifié, SHA-256 `1ec9e3a784d30506367c92f9a01d0255db7a59f6eed5d7988cd905c00033ae6c` (28523059 octets). Le lanceur pointe désormais vers cette source. Métadonnées : `checkpoints/CP008-correctif1-publication.json`.

Travail indépendant en cours : l’export brut complet compte 186001 instructions / 2845 fonctions internes. `analysis/full-pcode-support-audit.json` recense les opérations manquantes de l’émetteur ; cet audit syntaxique n’est ni un moteur complet ni une exécution réussie. Le gros export brut est sauvegardé sous `analysis/lifter-full/instructions.jsonl.gz` (4,4 Mo compressés, 124593872 octets bruts), avec provenance et empreintes. Le décompresser vers `work/` pour reprendre, ou le régénérer avec `ExportPcode.java --all` depuis le projet Ghidra sauvegardé.

## Second retour Mac — replay natif confirmé

Le journal du run `20261114T161942Z`, source `1f85c63cff513d0ccf9e93d12711eed910fbc056`, confirme la fin du vérificateur avec code 0. SaturProbe : 161 cas / 133502 échantillons, sans différence. Lecteur d’états : 22192 et 20640 octets réécrits sans changement ; aucune restauration sémantique DSP n’est testée. LiftedProbe : 704 cas / 5420672 octets, 3113 adresses d’instructions exécutées, sans différence avec les réponses ABI enregistrées. AUStateProbe compile en Mach-O ARM64 ; il s’agit de l’hôte de test, pas d’un Audio Unit.

Le test `--native-math` a renvoyé un code non nul. Le journal ne contient pas ses résultats détaillés : collecter `static-lift-native-libm.json`, `static-lift-native-libm-errors.log` et l’exitcode avant d’attribuer le problème à un arrondi particulier. Ne pas lui attribuer les sept octets de Linux/musl. `auval` a été exécuté sur l’identité existante et a renvoyé 2 ; son journal détaillé manque également, donc la raison précise n’est pas établie. Aucun nouveau composant, rendu du preset complet ou rappel Logic/Live n’est validé.

`Recuperer-Rapports-Mac.command` rassemble les rapports existants en ZIP sans compilation et sans installation, en recherchant le dernier journal Sophistry sous son dossier et Downloads, ou en acceptant un dossier de rapports explicite. Le résultat structuré reçu est sauvegardé dans `evidence/mac-cp008-native-replay.json`. Le journal original contenant des chemins personnels reste dans les pièces jointes locales et n’est pas publié.

## Rapports détaillés reçus — écart math confirmé

L’archive utilisateur `Sophistry-rapports-20261114T162903Z.zip` contient les neuf rapports attendus. Le mode natif Mac compare 5420672 octets et trouve les sept mêmes octets d’état interne que ARM64/Linux musl (cas 117 et 123), sans différence des buffers audio comparés. Ce résultat ne suffit pas à conclure qu’un rendu complet serait inchangé. Le mode avec réponses ABI enregistrées reste exact. Ne pas remplacer les maths par une table des cas de test, arrondir artificiellement les états ou désactiver leur comparaison pour annoncer un succès. L’adaptateur mathématique de référence utilise Python/Linux ; l’ancien libm Apple i386 n’a pas été exécuté.

`auval-existing.log` confirme « FATAL ERROR: didn't find the component » : l’identité `aumu/Sop3/LinP` n’est pas trouvée sur ce run. Il ne s’agit pas d’un nouvel AU refusé, puisqu’aucun n’a été produit. Les détails sans chemin personnel sont dans `evidence/mac-cp008-native-math-details.json` et les trois petits rapports préfixés `mac-cp008-`. Aucun autre fichier utilisateur n’est requis pour poursuivre ce périmètre d’analyse.
