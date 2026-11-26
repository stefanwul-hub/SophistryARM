# CronoX 3 ARM64 — CRX013

CRX013 corrige l’arrêt de compilation d’un outil de validation : le nouvel espace de noms interne de la réverbération pouvait entrer en conflit avec celui de l’interface dans les sondes historiques. Il porte désormais un nom distinct. Les calculs DSP, les paramètres, les queues sonores et la polyphonie sont inchangés par cette correction.

Le rapport CRX012 confirme que le composant avait été construit et signé, puis que CronoXCorrectionsProbe échouait sur huit références ambiguës à cronox. L’installation s’arrêtait avant copie, tests audio et auval ; la version ARM Test précédente est donc conservée. Le message « replacing existing signature » n’était pas la cause.

Quitter Logic et Live, décompacter Demarrer-CronoX-CRX013.zip puis ouvrir Demarrer-CronoX-CRX013.command. Le lanceur récupère les sources épinglées et contrôlées, réutilise le projet/cache dans ~/CronoX3-ARM64/projet et compile en ARM64. L’installeur conserve les vérifications C++, la concordance de réverbération, les rendus, le rappel d’état, l’interface, auval et la restauration automatique sur échec. Le rapport ZIP est créé sur le Bureau.

Le composant et les 13 sondes utilisées par les scripts moteur/AU ont tous été recompilés puis liés strictement en Mach-O ARM64. La couverture est contrôlée d’après les noms présents dans les scripts, et la preuve partielle CRX012 est rejetée. Les sondes de gain, sampler, banques/clavier et réverbération sont aussi exécutées sous Linux. Après le renommage, les 480 blocs de référence restent identiques aux instructions originales sur CPU Intel et en ARM64 sous QEMU ; leur table de résultats attendus est inchangée. Les 28 régressions de transaction/détection et les vérifications Bash 3.2 passent.

La réverbération C++ directe préparée dans CRX012 reste activée. Ses boucles reprennent les instructions originales, sans raccourcir la queue ni réduire les voix. Les 413 unités originales, le runtime et le dispatcher de CRX012 sont inchangés et leur cache reste utilisable.

**CRX013 attend son exécution et auval sur votre Mac.** Ces vérifications de développement ne constituent pas une validation de l’AU sous macOS. Le gain CPU réel dans Live/Logic reste à mesurer avec Breath And Butter après une installation confirmée. La surcharge du synthétiseur sans réverbération reste également à traiter.

Seul /Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component est ciblé, identité aumu/CrT3/LinP, build13001. CronoX original CrX3, Sophistry CP038, les préférences et la calibration de +6 dB avant Master sont conservés. Les identifiants originaux restent réservés à la restauration finale des projets.

Reprise : CRX_REPRISE.md, cronox-status.json, evidence/cronox-crx013-*.json et checkpoints/cronox/. Aucun numéro de série ou fichier de préférences privées ne doit être transmis ou publié.
