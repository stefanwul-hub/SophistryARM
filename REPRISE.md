# Reprendre à CP036 — exploration des voix, composant CP032 conservé

Publication autorisée uniquement sur `codex/sophistry-native-checkpoints`, sans modifier `main`. Licence, préférences, banques complètes et rapports bruts restent hors Git. Ne pas redemander la licence.

Demande actuelle : explorer la piste des voix mal réutilisées. La priorité de concordance avec l’original et l’absence de nouvelle optimisation restent valides. CP033 est retiré ; le composant et l’installateur restent exactement CP032/build32001, référence `1a32688cce7017bc40a6085563a0aa82edb08639`. Aucun changement fonctionnel dans CP036.

Le lanceur de restauration conservé est https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/b57f576eb9b52928d9069446167a1b49f8a1ffbe/Revenir-Sophistry-CP032.command. Archive CP032 `6859eaa4b3513b384ecab6bc6e5501174977dfb8`, SHA256 `0fa3d52b58c753ba5b2cee5dbc6cd13d5099191f78b18812e2274ceff0661d0a`. Dossier et cache CP032 réutilisés. Le retour Mac à CP032 après CP033 reste à confirmer ; ne pas annoncer une installation déjà faite.

CP036 suit les routines originales complètes de gestion des voix : allocation2fb5c, note-off2fdc4, libération2f86e, changements d’état2f468, itération2f3da/2ecd6, reset2eb20. La boucle polyphonique Instrument0xd1a6 est exécutée avec notices, pré/post-traitements et fonctions DSP finaux contrôlés. Pas de DSP/enveloppe complet ni licence/preset privé utilisé.

Résultat : 63 scénarios, deux contrats d’horloge,6598étapes différentielles i386/Unicorn vs C++ CP032,57081496octets d’état comparés. Aucune différence pour des entrées identiques. Compteurs cohérents, nombre d’appels aux voix conforme aux entrées occupées, capacité du pool respectée et libérations explicites ramenant les compteurs à0. Cela ne teste pas l’extinction réelle par les vraies enveloppes.

Exemple réduit vérifié dans les deux exécutions : sept note-on, deux parties/deux canaux, pool8 et argument de limite2parpartie. Aucun note-off/fin d’enveloppe avant l’écart : temps écoulé4voix et4appels de traitement contre ticks synthétiques5voix/5appels. La sixième note transfère une voix de la mauvaise partie ; à la septième, cette partie alloue un emplacement libre. Il s’agit d’un choix modifié par les dates, pas d’un compteur incohérent. Le même exemple sur un seul canal reste4/4.

Un autre exemple, une partie/un canal/pool3, montre déjà2contre3voix maintenues au note-off après un mauvais vol. Après une fin de relâchement explicite250ms de la sonde, les voix occupées deviennent2contre3. Cette fin est modélisée, pas un DSP exécuté : ne pas annoncer ce résultat comme une mesure audio réelle. Les24variantes mono-canal de la matrice ont elles aussi certains écarts temporaires ; ne pas généraliser le contrôle mono-canal du seul exemple à sept notes.

Les cas nommés note seule/mélodie/accord sous limite ne créent pas de voix supplémentaire. Aucun débordement ou fuite illimitée observé. Piste de travail CPU plausible et confirmée au niveau des décisions et de la boucle originale, sans explication quantitative établie du facteur4 face à CronoX dans Live. La routine seule de réduction de limite conserve aussi son comportement original ; le setter complet Voices n’a pas été testé par ce cas.

Sources et preuves : analysis/cp036/compare_voice_lifetimes.py, docs/CP036.md, evidence/cp036-*.json, traces synthétiques complètes compressées. Tous les états de ces sondes sont publics et artificiels ; aucune clé ni préférence Mac. Les limites et résultats CP034/CP035 sur l’horloge, les timestamps AU, les timers et la fidélité globale restent valides.

Suite prioritaire : corriger sémantiquement l’horloge réelle en cohérence avec les timestamps AU, conserver la politique de voix originale, puis observer les voix occupées/maintenues par partie pendant le vrai rendu pour quantifier la contribution CPU. Aucun nouveau composant ou test Mac demandé pour ce checkpoint d’exploration. Ne pas reprendre les optimisations CP033, le stress extrême DX Bass ni l’enquête de niveau classés.

Après la publication finale, régénérer/vérifier le bundle Git autonome checkpoints/Sophistry-history.bundle et le journal local d’empreintes. Le backup Ghidra CP032 reste inchangé. Conserver une copie des résultats et des consignes de reprise.
