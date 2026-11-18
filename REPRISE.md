# Reprendre à CP035 — concordance temporelle, composant CP032 conservé

Publication autorisée uniquement sur `codex/sophistry-native-checkpoints`, sans modifier `main`. Licence, préférences, banques complètes et rapports bruts restent hors Git. Ne pas redemander la licence.

L’utilisateur demande de poursuivre la recherche de concordance avec le code original, sans optimisation particulière. CP033 reste retiré après la régression Mac de 3,306 fois le coût de CP032. Le composant, l’interface et l’installateur restent exactement CP032/build32001, référence `1a32688cce7017bc40a6085563a0aa82edb08639`. Aucun changement fonctionnel dans CP035.

Le lanceur de restauration conservé est https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/b57f576eb9b52928d9069446167a1b49f8a1ffbe/Revenir-Sophistry-CP032.command. Il utilise l’archive source CP032 `6859eaa4b3513b384ecab6bc6e5501174977dfb8`, SHA256 `0fa3d52b58c753ba5b2cee5dbc6cd13d5099191f78b18812e2274ceff0661d0a`, et son ancien dossier pour réutiliser le cache valide. Identité AU, licence et banque conservées. Le retour Mac à CP032 après CP033 reste à confirmer ; ne pas annoncer une installation déjà faite.

CP035 ajoute 984 cas différentiels sous Linux x86_64, instructions i386 sous Unicorn contre C++ CP032 : 8 capacités AU, 512 choix de voix, 48 transitions/compteurs, 216 NRPN, 72 accélérations de commande, 16 rappels génériques, 64 rappels AU avec leur condition, 48 notifications originales. 7224440 octets d’état comparés, retours et appels de présentation contrôlés, aucune différence dans ce périmètre. Code de présentation final et services système contrôlés ; aucune validation audio du moteur complet ou exécution Mac supplémentaire.

Deux scénarios montrent dans les deux exécutions que le contrat d’horloge synthétique peut changer des décisions : mauvaise ancienneté relative d’une voix après réutilisation d’un emplacement, et donnée NRPN acceptée cinq secondes après la sélection alors qu’elle expire avec le temps écoulé. Ce sont des conséquences fonctionnelles contrôlées, pas une reproduction du CPU Live.

Un observateur propre à l’exécutable Linux compile le LegacyEngine actuel sans le modifier et intercepte sl_run en lecture seule. Il confirme l’enregistrement à l’activation de la fonction AU `0x3aba`, délai initial5ms, intervalle250ms. L’adaptateur commun stocke les timers sans les planifier. La chaîne `0x3aba -> 0x1a004 -> 0x1a54a` n’est pas exécutée dans la séquence observer. Le drapeau original demandant ce service (outer+0x32b418) reste aussi0 ; la file observée reste vide. Ne pas annoncer une accumulation, une fuite, une cause CPU ou une correction par simple activation du timer. L’interface originale fait aussi son service idle ; les getters de la vue Cocoa ne le remplacent pas à eux seuls.

Conserver CP032 pendant cette recherche. CP035 est un checkpoint d’audit, sans nouveau lanceur de composant ni test Mac demandé. Priorité suivante : fidélité de l’horloge réelle et des unités de timestamps AU, puis contrat de demande/déclenchement du service périodique et des notifications, avant d’appliquer une correction sémantique distincte. Ne pas reprendre les optimisations CP033.

Les preuves sont dans evidence/cp035-*.json et docs/CP035.md ; sondes reproductibles dans analysis/cp035. Les limites CP034 sur bibliothèques mathématiques, services système et absence de preuve exhaustive restent valides. La parité CPU CronoX n’est pas démontrée. L’enquête de niveau et le stress extrême DX Bass restent classés.

Après la publication finale, régénérer et vérifier le bundle Git autonome checkpoints/Sophistry-history.bundle. Le backup Ghidra CP032 est inchangé, empreinte et journal dans les checkpoints locaux ignorés de Git. Conserver les entrées de reprise et les empreintes sans publier de données privées.

Publication CP035 : fa4d1996589ebf9ddce702ea7a2b7274c90e7926, arbre 59be88cdb719b4a53b60d6b0abfda881ec972ab5. Archive téléchargée et vérifiée : 44521714 octets, SHA256 8b6539505f45946ba305ff3d9d7644c3780770542ef0d9770313cb3b8c094471, 4236 blobs exacts. Preuve publique dans checkpoints/CP035-publication.json.
