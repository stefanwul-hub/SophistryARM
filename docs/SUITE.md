# Suite après CP021

Le 15 novembre 2026, l’utilisateur confirme que les anciens projets produisent de nouveau du son et que les sons se chargent. CP021 reste la base fonctionnelle à conserver. Ce retour est une observation d’usage ; les résultats automatiques CP021 attendent encore l’examen du ZIP déjà créé. Aucun nouveau composant n’est livré par cette feuille de route.

## Consolider le rappel des projets

Examiner le rapport CP021 existant : version réellement installée, architecture, auval, oracle Core Audio, rendus D4U mono/stéréo, comparaison des rendus AU 2/6 canaux, éditeur local et distant. Identifier si le dernier essai porte sur Logic, Live ou les deux. Une réinstallation n’est pas nécessaire simplement pour transmettre le rapport existant.

Sur une copie d’un projet, vérifier le cycle complet : jouer, enregistrer sous un autre nom, fermer l’hôte, rouvrir et rejouer. Vérifier aussi la conservation d’un réglage modifié et la lecture d’une automation existante. Répéter dans l’autre hôte disponible, sans convertir le projet d’origine. Un son audible ne suffit pas à certifier que tous les réglages du projet sont rappelés.

## Prochain développement prévu : CP022, interface

Les 106 images originales sont conservées dans `reference/Resources` ; la planche `analysis/interface-contact-sheet.jpg` aide à les repérer. La vue actuelle comporte sept panneaux, 15 molettes Main et un volume. Elle donne accès aux 522 paramètres, mais plusieurs panneaux utilisent encore le navigateur de paramètres.

Compléter les commandes graphiques des générateurs 1–4, filtres, effets, modulation et réglages. Déduire leur position, type, sprite, identifiant, plage et comportement de la construction originale et du contrat AU. Vérifier les contrôles dépendant du mode sélectionné, les valeurs discrètes et les courbes de manipulation. Une ressemblance visuelle seule ne valide pas la commande.

Conserver l’identité `aumu/Sop3/LinP`, les identifiants des 522 paramètres, le format des chunks et les instructions DSP. Chaque geste graphique doit produire les notifications AU attendues, suivre les modifications venues de l’hôte et se conserver à la sauvegarde. Valider aussi la taille de fenêtre et l’utilisation dans les hôtes local et distant. Les diagnostics et le changement de banque doivent rester accessibles.

Préparer une nouvelle archive et un lanceur seulement lorsque le candidat est concret et vérifiable. Garder les sauvegardes et la restauration automatique du composant précédent.

## Étendre la fidélité sonore et les essais de charge

Étendre progressivement les comparaisons aux familles de presets et de générateurs, à plusieurs notes/vélocités, aux relâchements, à la pédale et au pitch bend, aux filtres et effets, et à plusieurs fréquences et tailles de buffers. Comparer au code original avec des services de plateforme documentés ; ne pas présenter l’hôte de référence comme l’exécution de l’ancien convertisseur ou de l’ancien libm Apple.

Les tests déjà passés ne démontrent pas une identité sonore pour l’ensemble des banques. Les différences d’état connues sur certains cas utilisant le libm natif restent consignées. Mesurer aussi mémoire, temps de traitement et comportement en polyphonie dans les hôtes ; un rendu hors temps réel ne démontre pas la tenue d’un projet chargé.

## Prochain retour utile

Transmettre le ZIP `Sophistry-rapports-CP021-<date>.zip` déjà produit et préciser l’hôte essayé. Le projet privé, la clé de licence et de nouveaux presets ne sont pas nécessaires pour cette première vérification. Les banques et la licence restent sur le Mac.
