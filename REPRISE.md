# Reprendre à CP-003

Objectif utilisateur : portage **complet et fidèle** de Sophistry Audio Unit vers Apple Silicon, à partir du code machine original, en conservant le rappel d’anciens projets AU Logic et Live. L’utilisateur possède les samples/presets externes. Son Mac est sous macOS 15.7.2, avec Xcode, Ableton Live 11.3.2 et Logic Pro 11. Pas de plugin ARM64 complet obtenu à ce checkpoint.

## Commencer ici

1. Lire `port-status.json`, `README.md` et `docs/RAPPORT.md`. Ne pas confondre le pseudo-code avec un portage ou l’objet du noyau avec un `.component`.
2. Vérifier le SHA-256 de `reference/Sophistry.component.zip` avec celui du rapport ; l’original est figé au commit indiqué.
3. Ouvrir `checkpoints/ghidra-project/Sophistry.gpr` avec **Ghidra 11.3.2 / JDK 21**. Le dossier `.rep` adjacent est indispensable. Copier le projet vers un dossier de travail avant de le modifier.
4. Utiliser `analysis/vtables.json`, `analysis/ghidra/function-index.jsonl`, `analysis/ghidra/calls.tsv` et le dossier `functions/`. Les `_vslot_N` sont des annotations inférées, partagées entre classes ; ne pas leur inventer des noms sémantiques.
5. Pour récupérer l’historique local : `git clone checkpoints/Sophistry-history.bundle work/reprise`. Le dépôt original est conservé ; la distribution du checkpoint utilise une branche dédiée, sans remplacer `main`.
6. Ajouter de vrais états `.aupreset`/`.fxp` et les samples référencés dans un dossier de travail, sans les publier automatiquement. Les seules fixtures de preset présentes dans les tests sont synthétiques et ne prouvent pas le décodage DSP.

## Points d’entrée importants

- Sauvegarde/restauration CFData `vstdata` : i386 `0x3d14`, `0x3e30`.
- Dispatch chunks : `0x1b998`, `0x216fe`. Dans la table Synth/Kaja, indices 176/177 : `0x19986` / `0x1beb0` (branches de sauvegarde/restauration de banque à examiner).
- Kaja initialisation moteur : `0x4efca` (fonction volumineuse, graphe de modules à reconstruire).
- Noyau saturateur déjà traduit : `0x73fb0`, addition `0xc14e4`, configuration coefficients `0x742fa` encore hors du périmètre traduit.
- Identité originale : `aumu/Sop3/LinP`, bundle `com.linplug.au.Sophistry`.

## Vérifications déjà faites

`evidence/` contient les résultats exacts. Six tests d’outils passent. Le noyau C++ correspond à la routine i386 émulée sur 160 cas ; les fixtures natives ajoutent un cas désactivé. Le rendu de test du noyau a une erreur nulle. L’objet Mach-O du noyau est ARM64, type objet relogeable. Aucun test natif Mac, `auval`, test du synthé complet ou réouverture de projet n’a été exécuté.

## Reproduire Ghidra seulement si nécessaire

L’analyse enregistrée évite de recommencer. Pour une nouvelle analyse indépendante, installer Ghidra 11.3.2 et un JDK 21 complet, définir `GHIDRA_HOME` et `JAVA_HOME`, puis lancer `bash scripts/run-ghidra.sh`. Les nouveaux résultats restent dans `work/`. L’archive officielle utilisée est `ghidra_11.3.2_PUBLIC_20250415.zip`, SHA-256 `99d45035bdcc3d6627e7b1232b7b379905a9fad76c772c920602e2b5d8b2dac2`, distribuée depuis le dépôt officiel NationalSecurityAgency/ghidra.

## Garder un nouveau checkpoint

Enregistrer le projet Ghidra fermé, les sources, les tests, les preuves et les limites. Mettre à jour `port-status.json` uniquement en fonction de vérifications réelles. Créer un commit local puis un nouveau bundle hors de son propre suivi : `git bundle create checkpoints/Sophistry-history.bundle --all`. Ne pas remplacer l’ancien composant tant que le moteur, les états et les copies de projets n’ont pas été vérifiés.
