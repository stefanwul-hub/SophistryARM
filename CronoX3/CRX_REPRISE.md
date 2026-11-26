# CRX013 — référence validée et gelée par l’utilisateur (26 novembre 2026)

L’utilisateur confirme explicitement que le plugin compile et valide, et que le CPU s’arrête maintenant avec le son : le problème de réverbération est corrigé. Il demande de garder CRX013 comme version de référence puis confie un autre plugin, Elastik. Ne pas modifier le DSP, les gains, l’interface, les identifiants ou l’installeur CRX013 pendant ce nouveau travail. Aumu/CrT3/LinP reste le profil installé ; ne pas remplacer CrX3 sous prétexte de cette validation.

Référence immuable : source GitHub cf7fcf027da5f2415da11fdda2dad1623044169d, lanceur11303f66c6b627ed858bb83e871a08745aa286ed, ZIP https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/11303f66c6b627ed858bb83e871a08745aa286ed/CronoX3/Demarrer-CronoX-CRX013.zip . Sommes et preuves de téléchargement dans evidence/cronox-crx013-publication.json. Nouvelle preuve evidence/cronox-crx013-user-acceptance.json. Il n’y a pas de nouveau rapport CRX013 joint : cette validation est une confirmation utilisateur, pas un relevé quantitatif CPU ni une preuve exhaustive de tous les presets. La parité CPU de tout le synthétiseur n’est pas revendiquée.

Nouvelle tâche séparée /workspace/work/ElastikARM : archive ElastikAU.pkg.zip, Elastik1.5.2.3. Objectif confirmé via réponse utilisateur : RETROUVER LES ANCIENS PROJETS ELASTIK1. Ne pas substituer simplement Elastik3, même s’il existe en Apple Silicon, sans vérifier reprise d’état et son. Sophistry CP038 est toujours gelé. Aucun nouveau changement de moteur CronoX n’est requis.

---

# Reprise — CRX013 publié, téléchargement vérifié ; attendre le rapport Mac

Source GitHub `cf7fcf027da5f2415da11fdda2dad1623044169d`, source locale7f0c360 ; archive75348629octets, SHA256 `df027960359bb1dbffcd3b1a357e2df9a90c5b9d88106064aeb1ae83f160f7d2`. Les365 fichiers CronoX sont comparés aux blobs Git avec CRC/modes vérifiés. Lanceur GitHub `11303f66c6b627ed858bb83e871a08745aa286ed` : https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/11303f66c6b627ed858bb83e871a08745aa286ed/CronoX3/Demarrer-CronoX-CRX013.zip . ZIP1919octets, SHA256 `97ee981d42f3621bd5e0f316bba5fbf8e462b322406e56ec8a54aa8ece70ad99`, deux fichiers, .command exécutable. Téléchargement direct comparé octet pour octet. Seuls18 fichiers source puis3fichiers lanceur changent sous CronoX3 ; les46autres entrées racine restent identiques. Preuve evidence/cronox-crx013-publication.json.

Le rapport CRX012 échouait dans la compilation de CronoXCorrectionsProbe après signature, avant copie, audio ou auval. La collision ::cronox/sophistry::cronox a été reproduite et corrigée en renommant uniquement l’interne DSP en sophistry::native_reverb. Aucun calcul modifié. Le composant et TOUTES les13sondes des scripts sont recompilés/liés ARM64 ; le validateur de couverture refuserait de nouveau la preuve partielle CRX012. Les4sondes historiques/natives concernées passent aussi en exécution Linux ; les480blocs restent identiques aux instructions originales sur matériel Intel et ARM64/QEMU. Runtime, Dispatch et413unités de CRX012 sont conservés et leur cache reste utilisable. Version CRX-013/build13001, aumu/CrT3/LinP, CrX3 et Sophistry CP038 préservés.

Dernier message utilisateur : « Pourquoi encore des tests de réverbération ? Publie CRX013 si c’est prêt ». Réponse donnée : ils étaient terminés et passaient ; publication lancée. Ne pas refaire de tests locaux sans nouveau motif et ne pas demander de nouveau diagnostic de réverbération avant installation confirmée. Attendre rapport CronoX3-rapports-CRX013-… de son Mac ; commencer par installation.json/stage et les .compile.log si échec. Aucune exécution macOS ou auval CRX013 n’est revendiquée. CRX011 est toujours le dernier installé accepté tant que ce retour n’est pas reçu. Le gain CPU réel de la réverbération reste à mesurer ensuite, et le CPU du synthétiseur sans réverbération reste un travail distinct.

Tous les checkpoints et preuves sont sauvegardés. Publier les métadonnées finales sous CronoX3/ uniquement ; ne jamais publier le rapport brut, les préférences, bookmarks ou clés privées. Conserver gain+6dB, interface et ancien composant si une validation échoue.

---

# CRX013 — contrôles complets réussis, publication à terminer

Le renommage sophistry::native_reverb est le seul changement des quatre fichiers DSP/sondes concernés, après normalisation vérifiée égale à CRX012. Toutes les 13 sondes des DEUX scripts ont été compilées réellement et liées en Mach-O ARM64, ainsi que le composant. Le validateur de couverture versionné refuse la preuve CRX012 partielle et accepte la preuve CRX013 complète. Preuves evidence/cronox-crx013-{macos-cross-link,checks}.json. La sonde Corrections qui échouait est compilée ET exécutée avec succès sous Linux ; de même LoopSampler, BrowserKeyboard et NativeReverb. Les480 blocs concordent encore bit à bit avec l’original sur matériel Intel et ARM64/QEMU ; la table de référence est inchangée. Les28 régressions Python, scripts et cache Bash3.2 passent.

Ni l’AU ni auval CRX013 ne sont exécutés ici sur Mac. Publier maintenant la source, vérifier son archive complète, créer le lanceur CRX013 épinglé et vérifier son ZIP direct, puis sauvegarder les métadonnées finales. Ne modifier aucun calcul pour résoudre ce problème de compilation. Les413 unités, Runtime et Dispatch restent ceux de CRX012, donc le cache utilisateur est conservé. Branch HEAD attendu7d05ab1d74d7f4c91fa6bfe8033298e184ef3961 ; les46 autres entrées racine, CrX3 et Sophistry CP038 doivent rester identiques.

---

# Reprise — rapport CRX012 reçu, correction de compilation CRX013

26 novembre 2026 : rapport utilisateur CronoX3-rapports-CRX012-20261126T134002Z.zip reçu. Le composant est construit et signé ; vérifications CrT3, symboles privés et110images réussies. Échec ENSUITE dans la compilation de CronoXCorrectionsProbe :8 erreurs « reference to cronox is ambiguous », entre ::cronox (interface) et sophistry::cronox (nouvel interne DSP) importé par using namespace sophistry. Ce n’est pas un échec de signature ni d’auval. La transaction système n’a pas commencé ; CRX011 reste installé. Aucune sonde audio, concordance réverbération, factory Cocoa ou auval CRX012 n’a été exécutée sur Mac. Preuve publique sans chemins : evidence/cronox-crx012-user-report.json ; rapport brut privé work/crx013/user-report.

La reproduction réelle au compilateur ARM64 retrouve exactement les8erreurs. La vérification croisée CRX012 avait omis les sondes historiques contenant directement LegacyEngine.cpp ; ne pas minimiser cet oubli. CRX013 renomme uniquement l’espace de noms interne de la réverbération en sophistry::native_reverb (4fichiers, normalisation prouvée égale aux octets CRX012). Aucun calcul, paramètre, seuil, queue, nombre de voix, cache d’unité, identifiant, licence ou préférence modifié. Version CRX-013, build13001, installateur distinct. Vérifier toutes les sondes réelles employées par scripts/build-cronox-engine.sh et scripts/build-cronox-audio-unit.sh, au lieu d’une liste partielle.

Travail en cours : work/crx013/cross-build-shipping.py compile réellement puis lie strictement le composant et les13sondes des scripts. Le validateur versionné analysis/cronox/check_shipping_build_coverage.py dérive leur liste des scripts et refuse une preuve incomplète ; la preuve CRX012 est explicitement rejetée. Le renommage doit repasser les480blocs de réverbération originaux et les sondes historiques avant publication. Conserver les413unités, Runtime et Dispatch de CRX012 : tous restent inchangés, donc cache réutilisable.

Publier seulement sous CronoX3/ dans codex/sophistry-native-checkpoints, en conservant les46autres entrées racine, CrX3 original et Sophistry CP038. Dernière tête distante connue7d05ab1d74d7f4c91fa6bfe8033298e184ef3961. Après compilation/lien complets, livrer un lanceur CRX013 épinglé/vérifié et sauvegarder les preuves et la reprise. Ne pas demander une nouvelle mesure CPU avant que le candidat ne puisse être installé ; le gain réel reste non mesuré.

---

# Reprise — CRX012 publié et téléchargements vérifiés, retour Mac attendu

Publication du 26 novembre 2026 : source GitHub `5ef81e18abfbee95d9c983a40bfe167dea1234d7` (base locale `55b111b65d2de7fafd4904143c768c32642b1ae6`), archive75329327octets SHA256 `b92d6de67b2bba6e5f854798bad992b171616fbb9875e6195bdee5da9a5f5745`. Les355 fichiers CronoX ont été comparés aux blobs Git, CRC et modes exécutables vérifiés. Préparation locale :415 fichiers du noyau/413 unités, image/imports/initialisateurs et110 images originaux vérifiés. Sources générées inchangées.

Lanceur GitHub `34154b97eda6a604ea35deb2755c18995d8cc769` : https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/34154b97eda6a604ea35deb2755c18995d8cc769/CronoX3/Demarrer-CronoX-CRX012.zip . ZIP2056octets, SHA256 `296c715a7e0f32279bc10e1ac70f191d5aedc90401d7de1413eb99cb36d8a772`, deux fichiers dont .command exécutable ; téléchargement direct comparé octet pour octet. Réutilise le cache Mac, ne remplace que ARM Test. La sonde de concordance est obligatoire avant copie ; restent les tests audio, rappel, interface, auval, rendu enregistré et rollback historiques. Identité aumu/CrT3/LinP, build12001, version CronoX3ARM CRX-012. Les46 autres entrées racine et les originaux CrX3/Sophistry CP038 sont préservés.

Résultat à attendre : rapport CronoX3-rapports-CRX012-… du Mac, puis comparaison Breath And Butter dans Live avec l’original. Vérifier native-reverb.json (160cas,480blocs,3vrais objets acceptés), installation/auval et les compteurs native_reverb_blocks/frames/fallbacks dans Copier le diagnostic. Si échec, lire native-reverb.log ou l’étape de prévalidation avant de proposer un autre changement. Aucun rendu CRX012 ni auval n’a été exécuté ici sous macOS ; la compilation croisée n’est pas une validation Mac. CRX011 reste le dernier installé accepté jusqu’au retour utilisateur.

Les nouvelles boucles sont identiques aux instructions i386 originales sur480blocs de référence (matériel Intel et ARM64/QEMU). Cela établit la concordance des cas d’effet couverts, pas une preuve exhaustive de tous les presets. Aucun seuil, voice stealing, timer, release, chemin de sample, préférence, licence ou gain n’a été changé. Le CPU hors réverbération est encore élevé dans RV003 ; ne pas présenter CRX012 comme correction de toute la surcharge. Le compteur de thread Intel RV003 est incohérent : retenir le temps de PROCESSUS, jamais le ratio automatique220×.

Preuves : evidence/cronox-crx012-{publication,reverb-differential,native-reverb-checks,macos-cross-link,regressions}.json ; sources/tests dans les commits locaux f6c0c7e,a9bfb8f,7e8a28c,55b111b,8191861. Rapport brut privé work/reverb-RV003/user-report ; ne pas publier de chemins personnels, état AU, clé, bookmark ou préférences. Toute publication reste limitée à CronoX3/. Continuer à sauvegarder source/lanceur/checkpoint et préserver Sophistry CP038.

---

# Reprise — CRX012 en préparation, réverbération originale en C++ direct

Point local enregistré le 26 novembre 2026. Le nouveau `CronoXNativeReverb.h` retranscrit les instructions float32 de comb::processMod, render12/render22 et leur sélecteur render 0xd42d8. Le dispatcher est dérivé hors de src/lifter/cronox ; les 413 unités et le runtime restent inchangés. L’activation est explicite dans le composant CrT3 ; les états inconnus reprennent le code généré complet. Aucun seuil de silence, release, timer de queue ou nombre de voix n’est changé.

Preuve : 160 cas × 3 blocs, tous les octets d’état/délais/sorties/buffers égaux aux instructions i386 originales exécutées sur CPU Intel. Oracle ELF64 avec passage matériel en mode compatibilité 32 bits, adaptateur memcpy seulement. Unicorn diffère sur 45 blocs FTZ/subnormaux et n’est pas utilisé comme référence pour ceux-ci ; l’exécution matérielle concorde avec le code générique et le nouveau code. Les mêmes 480 résultats passent en ARM64/Linux sous QEMU. Trois vrais objets de réverbération créés/configurés par les routines originales acceptent le précontrôle natif après un bloc vide sans MIDI ; pas de clé ni de contournement de licence. Un repli pour effet désactivé est testé. Les gains de vitesse sur ces petits états Linux ne prédisent pas ceux de Live. Fichiers preuves evidence/cronox-crx012-{reverb-differential,native-reverb-checks}.json.

Compilations et liens croisés Mach-O ARM64 stricts de l’engine, dispatcher, AU, éditeur, sondes Cocoa/registre et nouvelle sonde de réverbération terminés. Les 110 images et trois exports isolés sont vérifiés ; preuve evidence/cronox-crx012-macos-cross-link.json. Nouveau candidat CRX012, build12001. Installer-CronoX-CRX012.command lance la concordance sur Mac avant toute copie puis garde les contrôles historiques, auval et rollback. Le cache des 413 unités est maintenu : sous Bash3.2 le test de vraie orchestration montre que seul Dispatch.o change ; répétition sans source modifiée : zéro objet recompile.

Le lien ARM64 strict passe ; vérifier encore le ZIP public avant livraison. CRX011 est encore le dernier installé/accepté ; aucun résultat de performance CRX012 sur Mac. La charge hors réverbération de RV003 reste élevée et n’est pas traitée par ce seul changement. Conserver CrT3, CrX3 original, Sophistry CP038, +6 dB avant Master et les 46 entrées racine hors CronoX3. Publication autorisée.

---

# Reprise — RV003 reçu, réverbération native à traduire (26 novembre 2026)

Les quatre mesures utilisateur RV003 sont valides : même banque et même manifeste de samples. Résumé public sans chemins privés : `evidence/cronox-RV003-measured-cpu.json`, figure associée PNG ; analyse reproductible dans `analysis/cronox/analyze_reverb_measurements.py`. Le rapport brut reste seulement sous work/reverb-RV003/user-report (non suivi).

Utiliser CLOCK_PROCESS_CPUTIME_ID : dans CET essai Intel/Rosetta, le temps du seul thread est environ 42 fois inférieur au temps de processus et au temps écoulé de rendu ; le ratio automatique 220× du résumé RV003 est donc inexploitable. Accord .35–1.2 s : ARM 56.64 %, original 10.86 % (5.22×). Queue 10–12 s : ARM 42.74 %, original 2.91 % (14.70×). Repos 20–23 s : ARM 3.38 %, original .58 %. Ce sont des pourcentages d'un cœur par seconde audio dans les hôtes de mesure, pas l'indicateur Live.

Les trois voix sont libérées à 2.07238 s. Dernier intervalle non nul identique : 16.87510 s avec réverbération, 8.98032 s sans. Ce cas ne montre pas de voix bloquée ; la queue existe dans les deux moteurs mais son calcul traduit coûte beaucoup plus. Niveau ARM environ +6 dB attendu (calibration demandée), ne pas le modifier. Piles ARM : unités 0384 (render22) et 0388 (comb::processMod) dominent, avec sl_tick et le coût du runtime par instruction.

Suite autorisée : retranscrire directement les instructions SSE float32 des fonctions originales Reverb2_c::render12 0xd3d70, render22 0xd400e et comb::processMod 0xd6912 en C++ natif ; préserver ordre des arrondis, absence de FMA, délais, modulation, diffusors, entrées/sorties, scheduling et code générique de repli. Aucune réduction de polyphonie ni coupure de queue. Comparer bit à bit états, lignes de retard et sorties aux instructions i386 originales avant livraison. Garder les 413 unités inchangées et leur cache ; un dispatcher dérivé hors des sources générées pourra sélectionner les routines confirmées. CRX011 reste installé et inchangé pour l'instant ; aucun gain CPU réel d'un nouveau candidat n'est encore mesuré.

Conserver aumu/CrT3/LinP, original CrX3, Sophistry CP038, +6 dB avant Master. Publication autorisée uniquement sous CronoX3/ avec les 46 autres entrées racine préservées. Ne pas demander un nouveau diagnostic de chemins : RV003 a réussi.

---

# Reprise CronoX — CRX011 conservé, chemins des samples RV003

Publication RV003 : GitHub `7539e519cc1c6166fa1786ce54516c2cb5366bf5`, source locale `ffae974d9e5b5adf4335e9180a48712d43a9030c`. ZIP direct https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/7539e519cc1c6166fa1786ce54516c2cb5366bf5/CronoX3/Diagnostiquer-CronoX-Reverbe-RV003.zip . 20478octets, SHA256 `5c0204f66083d6abff03cddb3b73e61b93e2200b02215ad7c0d74136d4079372`, retéléchargé puis vérifié (7fichiers, CRC, modes exécutables). Seuls15 fichiers attendus changent sous CronoX3 ;46 autres entrées racine, composant et anciens diagnostics préservés. Preuve `evidence/cronox-reverb-RV003-publication.json`. Prochaine donnée attendue : nouveau ZIP RV003 Bureau sur Breath and Butter ; ne pas annoncer de baisse CPU sans ces mesures.

Retour utilisateur après RV002 : « File error - load failed », ancien chemin c:/VSTPlugins/Sophistry ; étape confirmée explicitement « 1/4 — Original Intel ». Le diagnostic atteint donc l'essai Intel, mais l'état commun conserve des chemins Windows que le port ARM résout avec sa banque enregistrée. Ne pas attribuer cette erreur au moteur DSP ni inférer des chiffres CPU. L'utilisateur demande de continuer. RV001/RV002 restent historiques ; aucun fichier du composant CRX011 ni de Sophistry CP038 n'est modifié.

RV003 prépare des liens symboliques dans un dossier privé temporaire puis utilise ce dossier comme répertoire courant de l'hôte Intel avant création/rappel AU. Le bank vstdata est conservé octet pour octet pour les quatre essais. Pas de réécriture binaire, de setter de sample (qui risquerait de recalculer ses réglages), d'interposition de fopen/stat, de suppression de licence ni de modification de DSP/polyphonie. Le stat/fopen normal de l'original suit les liens vers les vrais fichiers Mac. Les deux écritures c:/... et c/... sont couvertes ; l'exécution du constructeur Path_c traduit conserve le deux-points dans le cas de référence. Les requêtes sont seulement des lectures de samples, et les liens temporaires disparaissent avec le dossier privé sans suivre leurs cibles.

Les références viennent de32 paramètres chaîne de fichiers connus et de candidats encadrés dans les chaînes sérialisées d'origine (lecture seule, représentation de ParaSet_c::setChunk 0x1438c). Seuls les noms effectivement ouverts par le port ARM sont requis ; les anciens noms de modules inactifs ne bloquent pas le preset. Le moteur ARM et le nouveau résolveur appliquent le même ordre de racines et la même sélection par suffixe ; les doublons ambigus restent des erreurs. Racines : dossier CronoX3ARMSampleRoot déjà enregistré, puis Resources/Samples et Resources/Presets du composant ARM. Le bookmark de lecture existant est rouvert dans chaque hôte, jamais écrit ni inclus au rapport. Le tag de licence766 n'est pas lu par le diagnostic.

Le manifeste des liens reste privé, associé au SHA256 de vstdata. Leur contenu est contrôlé par SHA256 avant chaque essai ; les quatre rapports doivent porter le même hash de banque ET de manifeste avant de calculer un rapport CPU. Le ZIP de rapport contient des noms de fichiers sans chemins et leurs empreintes, jamais le bank AU, les chemins complets du manifeste ou ses bookmarks. Le .command ne recompile que les deux petits hôtes et ne touche pas à /Library. Protocole 44,1kHz/256, accord60/64/67, 4x32s et profil ARM séparé inchangé.

Preuve de développement `tests/CronoXReverbSamplePathsProbe.cpp` : vrai FXP Lightgarden,32 chaînes sûres,5 cas du constructeur original traduit0x1db0,2 liens,2 références AKAI inactives ignorées. Disk_c::open original traduit0xcbf4 échoue sans lien puis lit les mêmes octets via les liens. Recherche fallback désactivée et index vidé, rappel COMPLET de la banque dans une seconde instance VIERGE réussi sans alerte ; aucun sample en cache et bank inchangé. Nettoyage du répertoire temporaire testé, fichier source intact.3 chemins dangereux rejetés,4 décisions de doublons comparées au résolveur de production inchangé. ASan/UBSan verts. Ceci exécute le code traduit/Linux, sans notes, audio sous licence, préférences privées ou validation AU ; pas encore l'original x86_64 sous macOS. Compilation et lien Mach-O strict des hôtes ARM64 ET x86_64 verts (SDK11.3). Le rapport RV003 réel reste attendu ; aucune correction CPU revendiquée.

---

# Reprise CronoX — CRX011 conservé, diagnostic corrigé RV002

Publication RV002 : commit GitHub `d2c45e64e20a6cf1e166292d1a00c1d27ff5cdc7`. ZIP direct https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/d2c45e64e20a6cf1e166292d1a00c1d27ff5cdc7/CronoX3/Diagnostiquer-CronoX-Reverbe-RV002.zip . 13932octets, SHA256 `4bacc4bf533e47ac8dd72ce3160f11659080c4309b93a9e1d42e454202646448`, téléchargé puis vérifié (5sources, CRC, modes). Les14 fichiers publiés attendus, et eux seuls, changent sous CronoX3 ; les46 autres entrées racine et tous les sources du composant/RV001 sont préservés. Preuve `evidence/cronox-reverb-RV002-publication.json`. Attendre maintenant le rapport RV002 Mac ; aucun résultat CPU réel n'a été obtenu avec RV001.

Rapport utilisateur reçu : CronoX3-reverbe-RV001-20261125T231003Z.zip. Les deux compilations Mac ont réussi et la sonde ARM a été exécutée, mais la préparation s'est arrêtée sur « Expected a chunk-based CronoX FXP ». Aucun AU n'a été créé et aucune mesure CPU n'a commencé dans ce rapport. La somme du source utilisé correspond exactement à RV001 publié. L'erreur appartient au diagnostic : il comparait le mot big endian à l'offset12 (version de fichier, normalement1) au sous-type AU CrX3. L'identifiant VST est à16 et vaut Crx3, avec un x minuscule, dans le vrai lightgarden 02 BT.FXP et dans Kaja_c::Kaja_c 0x4a420 (0x43727833). Le sous-type Audio Unit reste CrX3 (0x43725833). Aucun nom du preset sélectionné n'était enregistré dans RV001 ; ne pas prétendre l'avoir identifié dans ce rapport.

RV002 remplace seulement l'outil autonome, dans `diagnostics/reverb-RV002/`. RV001 est gardé comme historique du défaut. Le nouveau `CronoXFxpHeader.h` est compilé dans l'hôte Mac ET dans `tests/CronoXReverbFxpProbe.cpp`. Il reprend les contrôles de structure de l'éditeur CRX011 qui charge déjà les presets : CcnK, FPCh, taille du chunk à56, contenu à60, limite d'import1MiB. Les métadonnées version/VST ID/version plugin/nombre de programmes sont lues séparément aux offsets12/16/20/24 ; pas de comparaison entre identifiant de fichier et sous-type AU. L'interprétation du chunk reste au moteur existant. La sonde journalise seulement ces champs publics d'en-tête, le nom de fichier sans chemin, et l'étape précise de préparation. Le contenu AU commun, licence et préférences restent privés sur le Mac. La synthèse du rapport distingue désormais un arrêt en préparation de mesures effectivement exécutées.

Test réel : fichier de référence20700octets, chunk20640octets, nom BT_lightgarden_02, version1, ID Crx3. Le test reproduit explicitement le rejet de RV001 et vérifie la lecture corrigée, puis67 entrées tronquées/malformées, limite1MiB, indépendance des champs et byteSize VST zéro/non nul. Exécuté avec AddressSanitizer et UndefinedBehaviorSanitizer. Tests de synthèse numérique : véritable erreur reçue résumée sans faux essais, comparaison refusée si banques différentes, ratio synthétique4 et fenêtres après silence. Bash3.2 et compilation/lien Mach-O strict arm64/x86_64 verts. Ce sont des tests de développement, pas encore le rendu AU Mac RV002 ; aucun résultat CPU réel disponible.

Protocole audio inchangé : même état AU temporaire, 44,1kHz/256, accord60/64/67 vélocité100, environ1seconde ; quatre essais de32secondes, réverbération active/coupée sur original Intel et ARM, puis un profil ARM séparé. Lancer le nouveau .command avec Breath and Butter puis attendre le ZIP Bureau. Pas de recompilation, copie ou remplacement du plugin. Tous les fichiers de production CRX011, ses anciens diagnostics, les originaux et Sophistry CP038 sont préservés. Prochain travail dépendant : analyser les traces et piles RV002, sans qualifier le surcoût de normal ni raccourcir les queues sonores pour le cacher. Preuves `evidence/cronox-reverb-RV002-{report-analysis,checks,cross-link,package}.json`.

---

# Reprise CronoX — CRX011 accepté, enquête réverbération RV001

RV001 publié : commit GitHub `b4d7ab36d36d4bde40a574b243dd46a4e951feaf`, base locale `a97d35942436893ab6f4cae13894e10549d08fb7`. Téléchargement direct : https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/b4d7ab36d36d4bde40a574b243dd46a4e951feaf/CronoX3/Diagnostiquer-CronoX-Reverbe-RV001.zip . ZIP 12167 octets, SHA256 `7d5f23022b6dc3c5e972f8458c0f0e3ccf0a65d5925c3ab1cfe9501617becf18`, téléchargé puis vérifié (4 sources, CRC, modes dont .command exécutable). Les 46 autres entrées racine et tous les fichiers du composant/installeurs ont été comparés et préservés. Preuve : `evidence/cronox-reverb-RV001-publication.json`. Prochaine donnée attendue : ZIP Bureau du diagnostic RV001 lancé sur Breath and Butter ; ne pas annoncer de baisse CPU avant ce retour.

Retour utilisateur : « Très bien tes corrections sont parfaites » pour les menus Matrix et l'arpégiateur CRX011. Le problème CPU reste ouvert. Cas précis : Pads / Airy pads / Breath and Butter, accord de trois notes ; après la fin audible, charge élevée pendant environ sept secondes, phénomène supprimé lorsque la réverbération est coupée. L'utilisateur confirme que l'original 3.6.6 n'a pas cette charge prolongée visible et coûte environ quatre fois moins. Ne pas présenter ce comportement comme normal, ni prétendre l'avoir reproduit sur Mac ici.

Recherche sauvegardée : `analysis/cronox/compare_reverb_tail.py` exécute les routines de planification originales i386 ET x86_64 (Unicorn) et le noyau statique C++. 81 cas, 44100/48000/96000 Hz, blocs 64/256/1024, trois RevTime et trois prédélais non synchronisés. Compteurs, appels DSP et reprise identiques entre les trois moteurs. Le callback DSP de ce test produit volontairement zéro : aucune licence, aucun son de preset ni rendu AU complet. Les deux originaux possèdent le délai 1,4*(RevTime + prédélai replié <=125 ms), décompté en samples après la fin du drapeau d'entrée. i386 : renderII 0x35990, render(bool,int) 0x35a18, getFadeTime 0xd4d6e ; x86_64 : 0x3328e, 0x332f4, 0xc8a02. Ce constat isolé ne prouve pas l'égalité du signal d'activité dans un vrai preset et n'explique pas l'écart CPU observé. Preuve : `evidence/cronox-reverb-RV001-tail-concordance.json`.

RV001 est un outil autonome dans `diagnostics/reverb-RV001/`, pas une nouvelle version du composant. Xcode compile deux petits hôtes, arm64/CrT3 et x86_64/Rosetta/CrX3, qui chargent les deux AU déjà installées. Sélection locale d'un FXP ou aupreset ; conversion via le portage en une banque AU commune temporaire 0600, sous dossier 0700. Aucun état brut dans les rapports, aucun changement de DSP, de licence, de nombre de voix, de gain ou d'installation. Chargement en processus demandé et présence du bon exécutable vérifiée dans dyld avant de mesurer le CPU appelant. Si l'original est distant, absent ou silencieux, le test échoue explicitement ; ne pas interpréter une mesure silencieuse comme une amélioration CPU.

Protocole : même banque brute (SHA dans les quatre rapports), 44,1 kHz/256, 120 BPM, notes 60/64/67 vélocité100 pendant environ une seconde, 32 secondes par essai avec cadence réelle. Réverbération active/coupée pour chaque architecture ; trace ~100 ms CPU thread/processus, pic/RMS, zéros exacts, flag AU de silence, compteurs de voix ARM hors mesure du rendu. Un cinquième essai ARM distinct fournit 20 secondes de piles `sample` pour localiser le coût sans contaminer les quatre comparaisons. Rapport ZIP sur le Bureau, état commun supprimé en fin de script. Les ratios de CPU audio ne sont pas directement les pourcentages du vu-mètre Live. Le test hors DAW/sans éditeur peut ne pas reproduire un problème propre au contexte Live.

Compilation et lien Mach-O strict arm64 ET x86_64 de la sonde effectués avec SDK11.3. Bash3.2 vérifié, intégrité de la synthèse numérique vérifiée sur traces synthétiques (seuils, périodes CPU, données manquantes, rapport connu de 4). Ce n'est pas une exécution macOS ; le premier rapport RV001 réel reste attendu. Le noyau, l'interface et les installeurs CRX011 restent identiques au commit `caf61ae5b730122354e820c6da87143ab20331cb`. Sophistry CP038 et les 46 entrées externes à CronoX3 sont préservés. Aucune correction CPU revendiquée.

---

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
