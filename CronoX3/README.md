# CronoX 3 ARM64 — CRX008

CRX008 corrige les cinq points signalés après CRX007 :

- Loop Sampler : repères de boucle dessinés par la routine originale, déplacement à la souris et saisie en cliquant sur les valeurs numériques. Les limites et le positionnement restent gérés par les paramètres originaux.
- Forme d’onde : cache conservé quand seuls les repères ou d’autres paramètres changent ; calcul d’affichage extrait du code original et lectures découpées pour laisser travailler l’audio.
- Main : banque sur la première ligne, preset sur la seconde, textes centrés. Le dossier du preset sélectionné est mémorisé dans l’état AU.
- Main : noms d’effets dessinés par-dessus les commandes avec assez de place, sans changer les zones de clic des menus.
- Pied réduit à 9 points et abaissé au niveau des boutons : « CronoX 3 ARM64 port OA 2026 . CRX008 ».

Quitter Logic et Live, décompacter `Demarrer-CronoX-CRX008.zip`, puis ouvrir `Demarrer-CronoX-CRX008.command`. Le lanceur vérifie les sources épinglées, conserve le projet/cache dans `~/CronoX3-ARM64/projet`, compile pour ARM64, teste les commandes, les boucles, la vue Cocoa et le rendu audio. Il installe avec sauvegarde transactionnelle et exécute `auval -v aumu CrT3 LinP`. Les rapports ZIP sont créés sur le Bureau. En cas d’échec, la version ARM Test précédente est conservée ou restaurée.

Composant **CronoX 3 ARM Test**, identité **aumu/CrT3/LinP**, bundle `com.linplug.au.CronoX3.ARMTest`, fichier `/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`. CronoX original **CrX3** et **Sophistry CP038** sont préservés. Les identifiants d’origine seront rétablis après validation finale pour rouvrir les anciens projets. Les états de test restent identifiés CrT3.

Le gain de **+6 dB avant le Master** de CRX007 est conservé, avec les valeurs, l’automation et la sérialisation originales du Master. Les 413 unités du moteur audio traduit sont inchangées. La correction de calcul concerne l’affichage. Préférences de test : `com.linplug.CronoX3.ARMTest`, avec lecture possible de la licence originale sans écriture dans `com.linplug.CronoX3`. Aucune clé ni préférence privée ne doit être transmise ou publiée.

L’interface comprend les sept pages, le clavier et la vue 5.1. Le navigateur original reste adapté en choix natif FXP/AU et Prev/Load/Next/Save. Pour un FXP, la banque affichée est son dossier ; cette information est conservée au rappel des nouveaux états AU. Un ancien état sans ce nom utilise le dossier de sons configuré en repli.

Tests acquis : 107 configurations, 54 cas de gain, 15 volumes inchangés, 28 régressions et Bash 3.2. Le nouveau test compare 164 colonnes d’extrema et les tracés complets à l’exécution originale sur quatre vues ; il vérifie les éditions et intercale 316 rendus aux frontières du zoom. Compilation et lien strict Mach-O ARM64 réussis ; 110 images et trois symboles exportés vérifiés. **Cocoa, auval et les manipulations/audio CRX008 doivent encore être exécutés sur votre Mac.** Les mesures de développement ne mesurent pas le CPU dans Live ni une conformité sonore exhaustive.

Reprise : `CRX_REPRISE.md`, `cronox-status.json`, `evidence/cronox-crx008-*.json` et `checkpoints/cronox/`. CRX007 reste disponible comme point de retour.
