# Suite après CP026

Le rapport CP025 confirme auval et l’installation, quatorze cas de générateurs, six clics de routage, quatre actions Edit, six actions Prev/Next, rappel du nom/type et douze WAV exacts à leurs références. L’utilisateur confirme ces corrections. Aucun nouveau preset ni licence à demander. Les chargements successifs et les noms dans Logic/Live restent confirmés depuis CP022.

[CP026](CP026.md) ajoute les croix X/Y Main/Filter, les champs Main, les commandes Filter et l’aperçu Loop en exécutant les routines originales statiquement traduites. Les comparaisons d’état/tracés à l’original et sous ARM64/QEMU passent ; les six binaires Mac concernés sont liés strictement. Le test Cocoa et auval CP026 restent à exécuter sur le Mac.

## Prochain retour utile

Examiner le ZIP CP026 : installation/build26001/auval, comparaisons originales de l’éditeur, sept commandes, huit croix et captures Filter/Loop, puis les contrôles audio précédents. Sur copies de projets Logic et Live, vérifier les valeurs, les gestes et le son des filtres, la forme d’onde d’un preset Loop avec sample chargé, puis la sauvegarde/réouverture et l’automation des paramètres publics. La création de vue distante est testée ; les captures de conteneurs peuvent rester noires et ne certifient pas la fidélité visuelle dans les DAW.

## Compléter l’interface

Terminer navigateur, liste/édition des zones, trim, zoom/boucles Loop, enveloppes graphiques de filtres, effets et modulation. Récupérer positions, sprites, tags, plages, textes, courbes et gestes depuis les constructeurs/routines originales. Conserver les 522 ID AU et les chunks. Les paramètres privés de l’éditeur restent privés. Comparer à chaque étape la sérialisation et, si une routine DSP change, ses sorties.

## Comparaisons musicales et charge

Étendre aux quatre modes de générateur, plusieurs notes/vélocités, relâchements, pédale, pitch bend, filtres, effets et buffers. Les états exacts du test d’éditeur ne démontrent pas l’identité sonore pour toutes les banques. Distinguer les instructions originales avec services hôtes adaptés de l’ancien convertisseur ou libm Apple. Mesurer temps réel, mémoire et polyphonie dans les DAW ; conserver les écarts libm internes déjà connus.

## Reprise

Publier sur `codex/sophistry-native-checkpoints`, garder `main` intacte, vérifier archives/lanceurs immuables et SHA-256. Mettre à jour `REPRISE.md`, `port-status.json`, preuves filtrées et bundle Git autonome. Préférences/licence/rapports bruts restent privés. L’installation conserve la transaction et la restauration.
