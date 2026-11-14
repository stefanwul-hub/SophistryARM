# Reprendre à CP-008, correctif Mac 1

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
