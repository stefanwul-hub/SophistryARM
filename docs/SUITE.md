# Suite après CP023

Le 16 novembre 2026, l’utilisateur confirme dans Logic et Live que les chargements successifs et le nom du son après réouverture sont corrigés. [CP022](CP022.md) est la base fonctionnelle rapportée. Les résultats automatiques CP021 ont déjà été examinés : auval, installation, 32 cas PCM Apple, éditeurs local/distant et douze WAV comparés. Ne pas redemander ces rapports ni l’hôte utilisé.

[CP023](CP023.md) poursuit les commandes graphiques des quatre générateurs. Les contrôles principaux, types et routages ont passé les comparaisons d’état au code original sur Linux et ARM64/QEMU. Le rendu Cocoa et le fonctionnement de ce nouveau checkpoint dans les hôtes attendent les tests Mac du lanceur CP023.

## Prochain retour utile

Examiner le ZIP CP023 : version réellement installée, auval, résultats audio, quatorze cas Cocoa et captures, rappel du type et du nom dans une instance neuve, vue distante. Sur copies de projets Logic et Live, vérifier que les nouvelles commandes correspondent au son entendu et que leurs modifications, le nom et le type sont rappelés après sauvegarde et réouverture. Contrôler une automation existante et une nouvelle automation de paramètre public. Licence et banques restent sur le Mac ; aucun nouveau preset n’est nécessaire à ce stade.

## Compléter l’interface

Comparer les captures automatiques aux 106 images originales et aux constructeurs KajaEditor. Corriger les gestes, textes ou positions si les essais natifs révèlent un écart. Ajouter ensuite le navigateur et le trim de samples, l’éditeur des zones et boucles Loop Sampler, puis les panneaux filtres, effets, modulation et réglages.

Pour chaque commande, relever position, type, sprite, identifiant, plage, texte et courbe depuis l’original. Garder les 522 identifiants AU, les chunks d’état et l’identité `aumu/Sop3/LinP`. Les commandes privées de l’éditeur ne doivent pas être ajoutées arbitrairement à la liste publique. Conserver une fenêtre utilisable, les diagnostics, le changement de banque et les tests d’hébergement distant.

## Étendre les comparaisons musicales

Étendre les tests aux familles de presets et aux quatre modes de générateur, à plusieurs notes et vélocités, relâchements, pédale, pitch bend, filtres, effets et tailles de buffers. Les états exacts du test de commandes ne démontrent pas à eux seuls une identité sonore pour toutes les banques. Distinguer l’exécution des instructions originales avec services hôtes adaptés de l’exécution de l’ancien convertisseur ou de l’ancien libm Apple.

Mesurer mémoire, temps de traitement et polyphonie dans les hôtes. Un rendu hors temps réel ne démontre pas la tenue d’un projet chargé. Conserver les différences connues de certains états avec libm natif et les limites de couverture du moteur.

## Sauvegardes

Publier les checkpoints sur `codex/sophistry-native-checkpoints`, conserver les archives immuables avec SHA-256 et vérifier les téléchargements. Garder `REPRISE.md`, `port-status.json`, les preuves filtrées et le bundle Git autonome à jour. L’installation garde sa transaction avec copie de l’ancien composant et restauration en cas d’échec.
