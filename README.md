# Sophistry — checkpoint CP023

Portage expérimental de Sophistry 3.0.8 vers Audio Unit ARM64 pour macOS. L’original est un binaire **i386 32 bits et PowerPC**. Les instructions originales sélectionnées sont traduites statiquement en C++ ; le moteur n’est pas une nouvelle synthèse approchée. La couverture complète de tous les chemins et de toutes les banques reste à démontrer.

**CP022 est confirmé par l’utilisateur dans Logic Pro 11 et Ableton Live 11.3.2** : chargements successifs sans blocage et nom du son conservé après réouverture. [Retour enregistré](evidence/mac-cp022-user-feedback.json). Les derniers journaux automatiques Mac examinés sont ceux de [CP021](evidence/mac-cp021-installed-audio.json) : installation, auval, oracle Core Audio et douze WAV de référence vérifiés.

**CP023 ajoute les commandes graphiques principales des quatre générateurs**, leur type, volume, balance, hauteur, routage et commandes propres au mode, avec les images et positions originales. Le sample courant s’affiche en lecture seule. Les zones détaillées Loop Sampler, le navigateur/trim de samples et les panneaux filtres/effets/modulation restent à compléter. Voir [CP023](docs/CP023.md) et [la suite](docs/SUITE.md).

Les 177 modifications testées sur quatorze combinaisons donnent les mêmes quatorze programmes et 42 états de banque que le code original. Le test passe aussi en C++ ARM64 sous QEMU. Les quatorze binaires Mac sont liés en ARM64 ; **les nouveaux panneaux Cocoa, auval et l’audio de CP023 attendent encore leur exécution sur votre Mac**. [Preuves](evidence/cp023-development-checks.json).

## Installer et tester

[Télécharger le lanceur CP023](https://raw.githubusercontent.com/stefanwul-hub/SophistryARM/codex/sophistry-native-checkpoints/Demarrer-Sophistry-CP023.command), fermer Logic et Live, puis exécuter :

```bash
bash "$HOME/Downloads/Demarrer-Sophistry-CP023.command"
```

Le script télécharge l’archive de sources épinglée, vérifie son SHA-256, l’extrait, compile, teste et valide auval. Licence et dossier de banque valides sont réutilisés. Il sauvegarde le composant précédent et installe dans `/Library/Audio/Plug-Ins/Components/Sophistry.component`, avec restauration si un contrôle échoue. Les droits administrateur sont demandés pour le remplacement système.

Attendre **« Installation CP023 confirmée »**, puis essayer les panneaux Generators 1–2 et 3–4 dans une copie de projet. Modifier quelques commandes, sauvegarder et réouvrir ; vérifier le son, les réglages et le nom dans les deux hôtes. Transmettre le ZIP CP023 produit automatiquement, qui contient notamment quatorze captures des nouveaux panneaux. Les contrôles ne peuvent certifier tous les projets privés ou toutes les banques.

Pour choisir une autre banque : `bash "$HOME/Downloads/Demarrer-Sophistry-CP023.command" --choose-bank`. Les options `--diagnose-only` et `--recenter-windows` restent disponibles sans installation.

## Compatibilité et reprise

L’identité historique `aumu / Sop3 / LinP`, le bundle `com.linplug.au.Sophistry`, les 522 paramètres et le format de chunks sont conservés pour les projets AU. Les anciens projets Logic sont de nouveau audibles selon les retours utilisateur ; le rappel des sons est également confirmé dans Live. La fidélité sonore générale reste à mesurer sur davantage de scénarios.

Sources, tests et preuves sont sur la branche `codex/sophistry-native-checkpoints`. [REPRISE.md](REPRISE.md) donne l’état courant et les étapes suivantes. Les archives vérifiées et lanceurs précédents restent décrits dans `checkpoints/`. Préférences privées, licence et rapports Mac bruts restent exclus de Git.
