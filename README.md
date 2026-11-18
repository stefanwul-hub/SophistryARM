# Sophistry — CP036 : exploration des voix, composant CP032

**CP036 confirme que l’horloge simulée peut modifier le nombre de voix occupées.** Un cas contrôlé à sept notes produit cinq appels de voix au lieu de quatre dans la boucle originale. Les 63 scénarios et 6598 étapes comparées restent identiques entre i386 et C++ pour un même contrat d’horloge. [Résultats et limites CP036](docs/CP036.md). Le facteur CPU observé dans Live reste à quantifier. Aucun changement du composant ni optimisation n’est livré dans ce checkpoint ; CP032 reste la référence.

Audio Unit ARM64 expérimental destiné à rouvrir les projets Sophistry 3.0.8 à partir de son code machine i386.

**CP033 est retiré.** Le rapport Mac mesure un coût CPU du rendu multiplié par **3,31** par rapport à CP032, malgré un audio identique. CP034 rétablit exactement les sources, les tests et l’installateur CP032. Aucune nouvelle optimisation DSP n’est introduite. [Audit et limites](docs/CP034.md).

## Revenir à CP032 sur votre Mac

[Télécharger le lanceur de restauration](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/b57f576eb9b52928d9069446167a1b49f8a1ffbe/Revenir-Sophistry-CP032.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Revenir-Sophistry-CP032.command"
```

Le lanceur est identique au lanceur CP032 déjà vérifié. Il utilise [l’archive originale CP032](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/6859eaa4b3513b384ecab6bc6e5501174977dfb8), contrôle son SHA-256 et retrouve le dossier `~/Documents/SophistryARM-CP032` pour réutiliser les sources et objets valides existants. Il compile en ARM64, exécute les tests audio et auval sur votre Mac, sauvegarde le composant précédent puis installe dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. Un échec de validation déclenche la restauration du composant précédent. Aucun runner GitHub n’est requis.

Attendre **Installation CP032 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-032)** dans l’interface. CP034 désigne l’audit et la sauvegarde ; le composant reste volontairement CP032, build 32001. Licence et banque valides restent enregistrées localement. La restauration sur votre Mac reste à confirmer.

## Ce que l’audit établit

Les inventaires ne trouvent aucune cible originale identifiée manquante parmi les 191379 instructions. Les 704 comparaisons DSP sélectionnées avec l’i386, les replays de 11635 primitives et 1351 cas récupérés, ainsi que 12 comparaisons de sélection SSE/horloge passent. Ces contrôles ciblés ne certifient pas chaque comportement du moteur et de ses dépendances macOS.

Un écart d’adaptation est confirmé : le composant de production utilise encore une horloge simulée et une base de temps fixe. Les imports mathématiques et certains services système sont également adaptés. Le mode SSE3 original est bien sélectionné. Aucun de ces constats n’établit encore la cause du surcoût CPU de CP032 face à CronoX.

La traduction compilée en ARM64 conserve des registres virtuels, des contrôles mémoire et du suivi par instruction. Le code source C++ historique n’a pas été retrouvé. Présence du code traduit, fidélité des services système et parité CPU sont des vérifications distinctes.

Identité AU `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`, version AU 3.0.8 et 522 paramètres conservés.

[Audit CP035](docs/CP035.md) · [Audit CP034](docs/CP034.md) · [Preuve du retour exact](evidence/cp034-restored-baseline.json) · [Régression Mac CP033](evidence/mac-cp033-regression.json) · [Reprise](REPRISE.md).

[Archive des sources et de l’audit CP034](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/b57f576eb9b52928d9069446167a1b49f8a1ffbe) — le lanceur de restauration utilise l’archive CP032 originale indiquée plus haut.

[Archive des sources et de l’audit CP035](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/fa4d1996589ebf9ddce702ea7a2b7274c90e7926) — aucun changement du composant CP032.
