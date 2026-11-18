# Reprendre à CP033 — optimisation CPU

Publication autorisée uniquement sur `codex/sophistry-native-checkpoints`, sans modifier `main`. Licence, préférences, banques complètes et rapports bruts restent hors Git. Ne pas redemander la licence.

CP032 fonctionne chez l’utilisateur mais le CPU reste élevé. CP033 conserve le C++ original complet de référence et prépare avant compilation un stockage local des temporaires prouvés, registres et état d’exécution. Les 191379 instructions, opérations numériques, arrêts précis et limites restent présents. Le prototype DSP sélectionné passe avec une médiane 1,826 fois plus rapide sous Linux, sans écart de sortie ou d’état ; cela ne prouve pas la parité avec CronoX.

L’utilisateur demande explicitement la validation sur son Mac, comme auparavant. Les workflows GitHub ajoutés ont été retirés : leur disponibilité ne conditionne pas l’installation. Le lanceur exécute compilation ARM64, tests, auval, comparaisons audio et rollback. Si CP032 est installé, il mesure aussi cinq paires de rendus AU identiques à 44100 Hz/256 samples. Les préférences de licence et de banque restent réutilisées.

Huit tests de preuve des temporaires et six cas d’arrêt/limite/erreur du bloc optimisé passent localement. Les replays du prototype sont exacts. La validation complète ARM64 et l’audio musical CP033 restent à exécuter sur le Mac ; ne pas les annoncer déjà réussis. Build 33001, identité AU et 522 paramètres inchangés.

L’enquête de niveau et le stress DX Bass restent annulés. Le checkpoint conserve les sources, preuves, scripts et références originales ; poursuivre le CPU selon les mesures réelles reçues.

Publication source CP033 : `63fdae177535c81efb1cabd4413b9661e138798a` ; arbre `787e739d406bfec85c9646ca95784f9778287110`. Archive vérifiée : 44500488 octets, SHA256 `ab4e491f9bcff35324aa696eb225d4f1c92300f73a42dd9f36aa2328dce3fc52`, 4223 blobs exacts. Le lanceur est épinglé sur cette source et cette empreinte. Terminer sa publication et sa vérification puis régénérer et vérifier le bundle Git autonome. Garder le dépôt propre.
