# Sophistry — CP037 : horloge native et réutilisation des voix

**CP037 fournit l’horloge Mach native aux routines originales de voix**, en conservant le noyau DSP CP032. Les 9897 étapes différentielles passent. Le diagnostic affiche maintenant les voix occupées et maintenues par partie. La baisse du CPU Live reste à mesurer sur le Mac. [Correction et limites CP037](docs/CP037.md).

Audio Unit ARM64 expérimental destiné à rouvrir les projets Sophistry 3.0.8 à partir de son code machine i386.

**CP033 est retiré.** Le rapport Mac mesure un coût CPU du rendu multiplié par **3,31** par rapport à CP032, malgré un audio identique. CP034 rétablit exactement les sources, les tests et l’installateur CP032. Aucune nouvelle optimisation DSP n’est introduite. [Audit et limites](docs/CP034.md).

## Essayer CP037

[Télécharger le lanceur CP037](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/0f53ef9bd972bdf4c7c610db7f7e89e660f47aac/Demarrer-Sophistry-CP037.command)

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP037.command"
```

Le lanceur `Demarrer-Sophistry-CP037.command` décompacte les sources vérifiées, compile et valide sur votre Mac, puis installe le composant. Fermer Logic et Live et lancer le fichier téléchargé avec `bash`. Licence et banque valides sont réutilisées. Les objets CP032 compatibles peuvent réduire la compilation.

Une référence CP032 est exigée. Cinq passages par version comparent CPU et audio avant remplacement ; un rapport médian CPU supérieur à 1,5 ou un WAV différent arrêtent l’installation. Les tests audio/Cocoa et auval avec restauration automatique restent obligatoires. Cela ne prouve pas encore une amélioration dans Live. [Détails](docs/CP037.md).

## Revenir à CP032 sur votre Mac

[Télécharger le lanceur de restauration](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/b57f576eb9b52928d9069446167a1b49f8a1ffbe/Revenir-Sophistry-CP032.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Revenir-Sophistry-CP032.command"
```

Le lanceur est identique au lanceur CP032 déjà vérifié. Il utilise [l’archive originale CP032](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/6859eaa4b3513b384ecab6bc6e5501174977dfb8), contrôle son SHA-256 et retrouve le dossier `~/Documents/SophistryARM-CP032` pour réutiliser les sources et objets valides existants. Il compile en ARM64, exécute les tests audio et auval sur votre Mac, sauvegarde le composant précédent puis installe dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. Un échec de validation déclenche la restauration du composant précédent. Aucun runner GitHub n’est requis.

Attendre **Installation CP032 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-032)** dans l’interface. CP034 désigne l’audit et la sauvegarde ; le composant reste volontairement CP032, build 32001. Licence et banque valides restent enregistrées localement. La restauration sur votre Mac reste à confirmer.

## Ce que l’audit établit

Les inventaires ne trouvent aucune cible originale identifiée manquante parmi les 191379 instructions. Les 704 comparaisons DSP sélectionnées avec l’i386, les replays de 11635 primitives et 1351 cas récupérés, ainsi que 12 comparaisons de sélection SSE/horloge passent. Ces contrôles ciblés ne certifient pas chaque comportement du moteur et de ses dépendances macOS.

L’écart d’horloge simulée constaté à CP034–CP036 est corrigé dans CP037. Les imports mathématiques et certains services système sont également adaptés. Le mode SSE3 original est bien sélectionné. Aucun de ces constats n’établit encore la cause du surcoût CPU de CP032 face à CronoX.

La traduction compilée en ARM64 conserve des registres virtuels, des contrôles mémoire et du suivi par instruction. Le code source C++ historique n’a pas été retrouvé. Présence du code traduit, fidélité des services système et parité CPU sont des vérifications distinctes.

Identité AU `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`, version AU 3.0.8 et 522 paramètres conservés.

[Audit CP035](docs/CP035.md) · [Audit CP034](docs/CP034.md) · [Preuve du retour exact](evidence/cp034-restored-baseline.json) · [Régression Mac CP033](evidence/mac-cp033-regression.json) · [Reprise](REPRISE.md).

[Archive des sources et de l’audit CP034](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/b57f576eb9b52928d9069446167a1b49f8a1ffbe) — le lanceur de restauration utilise l’archive CP032 originale indiquée plus haut.

[Archive des sources et de l’audit CP035](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/fa4d1996589ebf9ddce702ea7a2b7274c90e7926) — aucun changement du composant CP032.

[Archive des sources et de l’exploration CP036](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/c8f4215bddbb8e45419346f2722f4a2705a236f8) — composant CP032 inchangé.

[Archive des sources CP037 vérifiée](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/ed090216afe2faf9058a5d3a5c2ea673d39da5ae) — SHA256 `8620a385912dcaba8b46a3fd7c0c707105d6e55ee83ea481e5cceea6aa6232ef`, 4268 fichiers vérifiés. [Journal de publication](checkpoints/CP037-publication.json).
