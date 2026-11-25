# CronoX 3 ARM64 — CRX006

CRX005 a été validé sur le Mac de l’utilisateur : Audio Unit, son, chargement de plusieurs presets et comparaison favorable avec CronoX 3 original. Cette comparaison reste non exhaustive. Cette version reste la référence audio et le point de retour.

CRX006 ajoute les sept pages de l’interface dorée d’origine : Main, Gen 1+2, Gen 3+4, Filters, Effects, Modulation et Settings, ainsi que le clavier et la vue 5.1. Les panneaux, sprites, coordonnées, sélecteurs et styles proviennent de l’exécution enregistrée des constructeurs i386 de CronoX 3.6.6. Les valeurs, courbes, menus, commandes et dessins utilisent les routines originales traduites en C++. Les vues et gestes sont adaptés en Cocoa. Les 413 unités du noyau DSP et la politique de gain CRX005 sont conservées.

L’interface propose les formes d’onde et leurs marqueurs, les commandes +/−, les enveloppes, les matrices XY, l’arpégiateur et le Gator. Le choix de fichiers FXP/AU et les boutons Prev/Load/Next/Save remplacent le navigateur de dossiers/catégories d’origine. La saisie de licence reste dans la configuration locale de l’installateur ; elle n’est pas exposée dans les contrôles ni dans les rapports.

Le composant reste **CronoX 3 ARM Test**, identifiant **aumu/CrT3/LinP**, installé dans `/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`. Il cohabite avec CronoX 3 original. Sophistry CP038 est figé.

Ouvrir `Demarrer-CronoX-CRX006.command` depuis son ZIP télécharge les sources épinglées, vérifie leur empreinte, conserve le cache de compilation, lance la compilation ARM64, les tests des commandes, la prévalidation Cocoa/audio, puis l’installation transactionnelle et `auval`. En cas d’échec, ARM Test précédent est conservé ou restauré. Les rapports ZIP sont créés sur le Bureau. Quitter Logic et Live avant l’installation.

Vérifications de développement : 107 configurations de pages/modes, séquences et dessins originaux, absence de modification du preset par les lectures de l’interface, compilation et lien Mach-O ARM64. **L’exécution Cocoa et `auval` de CRX006 doivent encore être effectués sur Mac.** Les gestes et la disposition restent à contrôler visuellement dans Logic et Live ; la présence de ces tests ne prouve pas une équivalence exhaustive avec l’original.

Reprise : `CRX_REPRISE.md`, `evidence/cronox-crx006-ui-recovery.json`, `evidence/cronox-crx006-local-checks.json` et `checkpoints/cronox/UI-Recovery-CRX006.tar.gz`.

---

# CronoX 3 ARM64 — CRX005

Premier Audio Unit de comparaison pour le portage de CronoX 3.6.6. Sophistry reste définitivement à CP038. Les publications CronoX sont uniquement dans `CronoX3/`, branche `codex/sophistry-native-checkpoints` du dépôt SophistryARM.

Sur le Mac Apple Silicon avec Xcode, lancer `Demarrer-CronoX-CRX005.command` depuis le petit ZIP du lanceur. Il télécharge l’archive source épinglée, vérifie son SHA256, extrait uniquement `CronoX3/` et lance `Installer-CronoX-CRX005.command`. Le projet et son cache restent dans `~/CronoX3-ARM64/projet` : les 413 unités du noyau CRX001 n’ont pas changé. Quitter les hôtes audio pendant l’installation puis les rouvrir. Le mot de passe administrateur est demandé pour la copie dans `/Library`.

Le script compile en ARM64, vérifie l’identité et la signature du candidat, teste les temporisateurs et la destruction du moteur original, la vue Cocoa, le chargement de Lightgarden, le rendu audio et le rappel d’état. Il installe ensuite **`/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`**, exécute **`auval -v aumu CrT3 LinP`**, teste le composant enregistré en stéréo et six canaux, puis confirme l’installation. En cas d’échec après copie, il restaure uniquement la version ARM Test précédente. Les sauvegardes de transaction restent dans `/Library/Audio/Plug-Ins/CronoX3ARMTest-Rollback`.

Dans Logic ou Live, chercher **« CronoX 3 ARM Test »**. Sa vue compacte permet Load, Prev/Next, Save au format `.aupreset`, le choix de la banque et la copie du diagnostic. Elle indique le nom du son, l’arrivée MIDI et le niveau de sortie. Les 522 paramètres d’origine sont également exposés à l’hôte pour l’automation. **Les panneaux graphiques originaux 3.6.6 ne sont pas encore raccordés.** Utiliser le même preset, les mêmes notes et les mêmes réglages audio pour la comparaison avec l’original ; CRX005 ne certifie pas encore la conformité sonore ni les performances dans les hôtes.

Le profil temporaire est **`aumu / CrT3 / LinP`**, bundle `com.linplug.au.CronoX3.ARMTest`. Le composant original **`aumu / CrX3 / LinP`**, bundle `com.linplug.au.CronoX3`, et Sophistry CP038 sont conservés. Les états de test sont sauvegardés avec CrT3. Les `.aupreset` CronoX d’origine CrX3 peuvent être chargés explicitement dans la vue de test ; les anciens projets continuent à désigner leur original CrX3. Le retour aux identifiants d’origine aura lieu après votre validation.

Les préférences de banque et d’éditeur sont isolées dans `com.linplug.CronoX3.ARMTest`. La licence existante peut être lue dans `com.linplug.CronoX3`, sans écriture dans ce domaine. Les contrôles de licence originaux sont conservés ; aucune clé ne doit être transmise ni publiée. Le gain reste celui du DSP CronoX, avec compensation de sortie unitaire. Les noms natifs du moteur sont privés au bundle pour permettre la coexistence avec Sophistry.

Le rapport ZIP `CronoX3-rapports-CRX005-…` apparaît sur le Bureau. Il contient la compilation, les rendus WAV du preset public, les résultats des tests et la validation AU ; il n’exporte ni licence ni préférences privées. `Copier le diagnostic` fournit le diagnostic de l’instance utilisée dans l’hôte.

Résultats acquis : votre rapport CRX001 valide la compilation ARM64 et tous les tests C++ sur macOS 15.7.2 (6 228 fixtures SQRT, 14 contrats de chaînes, 522 paramètres, chargement et rendu Lightgarden). CRX005 passe les tests locaux du cycle de vie et 14 tests de récupération d’installation ; le composant et la sonde Cocoa sont compilés et liés en Mach-O ARM64. L’exécution du nouveau composant sous macOS et `auval` attendent votre prochain rapport.

La traduction statique utilise la tranche i386 de l’original fourni (également disponible en x86_64) : 211 282 instructions et 786 267 opérations p-code, 413 unités C++ plus dispatcher/runtime, sans décodeur x86 à l’exécution. L’inventaire retrouve les 3 174 entrées de fonctions nommées et les 1 784 cibles virtuelles. Cette couverture structurelle ne prouve pas à elle seule l’équivalence sonore. Projet Ghidra, décompilation et noyau C++ sont sauvegardés ; [CRX_REPRISE.md](CRX_REPRISE.md), [cronox-status.json](cronox-status.json) et les manifestes `checkpoints/cronox/` permettent de reprendre le développement.

CRX005 corrige l’arrêt `extra[*]: unbound variable` de CRX002 avec Bash 3.2. Les options de compilation sont désormais conservées dans un tableau toujours rempli, y compris pour les fichiers C++ sans ARC. Les instructions du DSP et les objets du noyau restent inchangés. L’échec CRX002 est survenu avant la construction/installation du composant AU.

CRX005 ajoute une détection explicite du composant installé avant auval : notification du dossier Components, redémarrage du registre de l’utilisateur, catalogue AU et sondes dans des processus neufs, avec attente bornée de 30 secondes et contrôle de la version réellement chargée. Une absence momentanée ou une ancienne version est réessayée ; les doublons et erreurs de factory arrêtent la tentative. Auval reste obligatoire. Les permissions, l’architecture, la signature et les messages du registre propres au composant sont joints au rapport en cas d’échec. Aucun cache AU global n’est supprimé.

Le rapport Mac CRX003 valide le vrai candidat AU, sa vue Cocoa, les 522 paramètres, le rendu audio, le rappel d’état et la préservation de l’original. Il échoue ensuite parce que le registre ne trouve pas CrT3 lors du premier auval ; la récupération transactionnelle a retiré le candidat non validé. La validation système et la conformité sonore restent à confirmer.

CRX005 corrige le collecteur de diagnostics sur Python Apple : `os.listxattr` n’est pas supposé disponible ; le collecteur utilise l’outil natif `xattr` pour lire seulement les noms d’attributs si nécessaire, et indique une valeur inconnue si la lecture échoue. La collecte initiale est facultative. Son échec reste dans le rapport mais la détection et auval continuent ; leurs propres échecs restent bloquants et déclenchent le rollback. Huit tests couvrent cette portabilité et le flux réel de validation sous Bash 3.2.

Le rapport CRX004 confirme un nouveau succès du candidat AU local, puis un arrêt du collecteur avant la détection (`AttributeError: os.listxattr`). Il ne permet donc pas encore d’évaluer l’attente ajoutée en CRX004. L’origine de l’absence du registre observée en CRX003 reste à confirmer sur le Mac après ce correctif.
