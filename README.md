# Sophistry — CP038 : sortie +6 dB et profilage CPU

**CP038 applique une compensation globale de +6 dB à tous les sons, anciens projets compris.** Master, automatismes et niveaux sauvegardés restent à leurs valeurs d’origine. Le noyau DSP CP037 est conservé. [Détails et validation](docs/CP038.md).

Le rapport Mac CP037 confirme auval, l’interface et huit comparaisons audio exactes. Le CPU reste équivalent à CP032 : ratio médian 1,00143 (+0,14 %) dans le test à une note. La cause du surcoût face à CronoX reste à identifier. Un mode de profilage recueille désormais les piles CPU sur le composant installé.

Audio Unit ARM64 expérimental destiné à rouvrir les projets Sophistry 3.0.8 à partir de son code machine i386.

**CP033 est retiré.** Le rapport Mac mesure un coût CPU du rendu multiplié par **3,31** par rapport à CP032, malgré un audio identique. CP034 rétablit exactement les sources, les tests et l’installateur CP032. Aucune nouvelle optimisation DSP n’est introduite. [Audit et limites](docs/CP034.md).

## Utiliser CP038

Télécharger `Demarrer-Sophistry-CP038.command`, fermer Logic et Live, puis :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP038.command"
```

Le lanceur décompacte, compile en ARM64 avec les objets CP032 compatibles, compare CPU et audio avec la compensation demandée, valide auval/Cocoa et installe avec sauvegarde et restauration automatique. Licence et banque valides restent enregistrées.

Pour recueillir seulement les piles CPU du composant CP037 ou CP038 installé :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP038.command" --profile-only
```

Ce mode compile uniquement le petit hôte de mesure, sans réinstaller le plugin. [Procédure et limites](docs/CP038.md).

## Revenir à CP032 sur votre Mac

[Télécharger le lanceur de restauration](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/b57f576eb9b52928d9069446167a1b49f8a1ffbe/Revenir-Sophistry-CP032.command), fermer Logic et Live, puis lancer :

```bash
bash "$HOME/Downloads/Revenir-Sophistry-CP032.command"
```

Le lanceur est identique au lanceur CP032 déjà vérifié. Il utilise [l’archive originale CP032](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/6859eaa4b3513b384ecab6bc6e5501174977dfb8), contrôle son SHA-256 et retrouve le dossier `~/Documents/SophistryARM-CP032` pour réutiliser les sources et objets valides existants. Il compile en ARM64, exécute les tests audio et auval sur votre Mac, sauvegarde le composant précédent puis installe dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`. Un échec de validation déclenche la restauration du composant précédent. Aucun runner GitHub n’est requis.

Attendre **Installation CP032 confirmée**, puis vérifier **Sophistry ARM64 port OA 2026 (CP-032)** dans l’interface. Le lanceur de retour conserve CP032/build32001 comme solution de repli. Licence et banque valides restent enregistrées localement. CP037 est confirmé installé sur le Mac ; CP038 reste à valider.

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
