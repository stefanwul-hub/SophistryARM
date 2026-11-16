# Sophistry — checkpoint CP024

Portage expérimental de Sophistry 3.0.8 vers Audio Unit ARM64 pour macOS. L’original est un binaire i386 32 bits et PowerPC ; les instructions originales sélectionnées sont traduites statiquement en C++. La couverture complète de tous les chemins et de toutes les banques reste à démontrer.

**CP023 est installé et validé par le rapport Mac du 16 novembre 2026** : auval, quatorze cas Cocoa des générateurs, rappel du nom et du type dans une instance neuve, 32 cas PCM Apple, 96 chargements avec mémoire stable et douze WAV reçus comparés à leurs références. [Preuve vérifiée](evidence/mac-cp023-installed-generators.json). La création de vue distante et son audio passent ; sa capture noire ne certifie pas son affichage. Le fonctionnement des chargements successifs et du nom est également confirmé par l’utilisateur dans Logic et Live depuis CP022.

**CP024 corrige les libellés superposés et les boutons de routage des générateurs**, à partir des captures CP023. MIX/AM/FM utilise son sprite et sa position d’origine ; les signes ajoutés sur les flèches sont retirés. Le moteur reste inchangé. Les 56 états testés correspondent toujours au code original ; les cinq binaires Mac concernés sont liés en ARM64. Les six nouveaux tests de clics et le rendu Cocoa CP024 restent à exécuter sur le Mac. Voir [CP024](docs/CP024.md) et [les preuves de développement](evidence/cp024-development-checks.json).

Le navigateur/trim de samples, les zones et boucles détaillées du Loop Sampler et les panneaux filtres/effets/modulation restent à compléter. [Suite du travail](docs/SUITE.md).

## Installer et tester

[Télécharger le lanceur CP024](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/d0276a313c1764ee21885382998fca5fb63c1950/Demarrer-Sophistry-CP024.command), fermer Logic et Live, puis exécuter :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP024.command"
```

Le script télécharge [l’archive de sources épinglée](https://codeload.github.com/stefanwul-hub/SophistryARM/zip/01e41abeb56795685afce45f95a3cca88d0f39f0), vérifie son SHA-256, l’extrait, compile, teste et valide auval. Licence et dossier de banque valides sont réutilisés. Il sauvegarde le composant précédent et installe dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`, avec restauration si un contrôle échoue. Les droits administrateur sont demandés pour le remplacement système.

Attendre **« Installation CP024 confirmée »**, puis essayer les panneaux Generators 1–2 et 3–4 dans une copie de projet. Modifier quelques commandes, sauvegarder et réouvrir ; vérifier le son, les réglages et le nom dans les deux hôtes. Transmettre le ZIP CP024 produit automatiquement, qui contient les captures des quatorze cas de générateurs et des six clics de routage. Les contrôles ne peuvent certifier tous les projets privés ou toutes les banques.

Pour choisir une autre banque : `bash "$HOME/Downloads/Demarrer-Sophistry-CP024.command" --choose-bank`. Les options `--diagnose-only` et `--recenter-windows` restent disponibles sans installation.

## Compatibilité et reprise

L’identité historique `aumu / Sop3 / LinP`, le bundle `com.linplug.au.Sophistry`, les 522 paramètres et le format de chunks sont conservés pour les projets AU. Les anciens projets Logic sont de nouveau audibles selon les retours utilisateur ; le rappel des sons est également confirmé dans Live. La fidélité sonore générale reste à mesurer sur davantage de scénarios.

Sources, tests et preuves sont sur la branche `codex/sophistry-native-checkpoints`. [REPRISE.md](REPRISE.md) donne l’état courant et les étapes suivantes. Les archives vérifiées et lanceurs précédents restent décrits dans `checkpoints/`. Préférences privées, licence et rapports Mac bruts restent exclus de Git.
