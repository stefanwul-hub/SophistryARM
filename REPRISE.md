# Reprendre à CP032 — intégration du code original

Publication autorisée sur `codex/sophistry-native-checkpoints` seulement ; ne pas modifier `main`. Préférences, licence, chemins privés, banques complètes et rapports bruts restent hors publication. Aucun numéro de licence n’est à redemander.

Dernière priorité explicite de l’utilisateur : commencer par le portage complet du code original avant l’optimisation CPU. L’enquête de niveau est mise de côté sauf défaut DSP réel. La référence comparative annoncée est CronoX 3.6.6 dans Live 11. Le rapport CP031 confirme installation/auval et huit comparaisons PCM exactes dans les cas testés. Le DAW activait déjà le mode flottant corrigé à CP031.

L’audit CP032 a trouvé trois blocs réellement absents, huit instructions au total :184d4/184d7,23f70/23f73/23f78/23f7b,54534/54539. Ghidra avait interprété des octets de tables avec un alignement incorrect ; huit anciennes entrées recouvrant les vrais blocs ont été retirées. Le dernier bloc a été retrouvé par une lecture indépendante des tables. Toutes les autres instructions existantes sont inchangées.

L’ancien cœur échoue à184d4 avec fault 3 dans la nouvelle référence. Le cœur corrigé passe1351 cas (512 pour les instructions et839pour33 tables), avec registres et mémoire comparés. Les11635 cas précédents et704 cas DSP passent également sous Linux et ARM64/QEMU. L’éditeur conserve17 résultats exacts et852 métadonnées ; l’intégration AU conserve522 paramètres et huit cycles. Neuf liens Mac ARM64 stricts sont vérifiés. Voir [les preuves](evidence/cp032-development-checks.json).

L’inventaire contrôlé comprend2845 fonctions,1625 cibles virtuelles,1890 entrées de déroulement de pile et26544destinations directes, sans cible manquante. Ghidra ne signale plus de candidat absent ni de conflit. L’entrée du générateur est identique au nouvel export corrigé, SHA2561982dac58e305b5773ce9f358ab3ae47da831466de124adb6be3044fca712a5b. Le total191379 n’a pas changé, car huit mauvaises entrées ont été remplacées par huit bonnes. Le comptage seul était insuffisant.

Le flux complet est reproductible avec le fichier de base historique, les additions CP032 et les exclusions d’alignement. Les scripts d’audit, de récupération Ghidra et les fixtures figées sont conservés. La disposition des364 unités reste stable ; seuls Dispatch et les unités0049/0073/0158 ont été régénérés. Les objets réutilisables, le projet Ghidra corrigé et les recherches détaillées sont sauvegardés localement. Les commandes publiques sont dans [CP032](docs/CP032.md).

Le code interne identifié est intégré ; l’identité sonore sur toute la banque et les interactions d’hôtes n’est pas certifiée. Ne pas confondre l’inventaire complet actuel avec une preuve de tous les chemins possibles. Les adaptateurs natifs restent nécessaires. Aucun changement de formule DSP, d’approximation numérique, de licence, de paramètres AU ou de gain n’est ajouté.

AppKit, auval et audio musical de CP032 restent à exécuter sur le Mac de l’utilisateur. Le lanceur conserve les tests, les comparaisons, la licence persistée et le rollback. Build 32001, wrapper CP-032, identitéAU 3.0.8 et522 paramètres conservés. Après validation de cette intégration, reprendre la recherche CPU sur cette base ; le scénario DX Bass avec release extrême reste annulé.

Publication CP032 : en cours. Vérifier les blobs de l’archive et le lanceur téléchargé, inscrire les commits et empreintes immuables puis régénérer et vérifier le bundle Git autonome. Garder le dépôt propre.
