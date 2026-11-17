# Checkpoints

- **CP-001 — audit original** : archive épinglée, architectures i386/PPC, identité AU, ressources, segments Mach-O et tables de classes candidates.
- **CP-002 — Ghidra** : base de projet enregistrée et export des 3 249 fonctions détectées. Le pseudo-code conserve des avertissements et n’est pas compilable tel quel.
- **CP-003 — noyau et tests** : traduction de Satur_c, tests par exécution des instructions originales, fixtures, preuve de compilation ARM64 du noyau, diagnostic Mac et rapport de reprise. **Le moteur complet et l’AU natif ne sont pas implémentés.**

L’historique Git est conservé dans `Sophistry-history.bundle`. Le projet Ghidra complet est dans `ghidra-project/`, avec son fichier `.gpr` et son dossier `.rep`.

- **CP-004 — états réels** : paire Lightgarden conservée, 51 schémas de classes récupérés depuis les descriptions originales, lecteur C++ de conteneur et décodage structurel des valeurs, comparaison des deux états. Le moteur complet, le chargement sémantique DSP et l’AU natif restent absents.

- **CP-005 — sauvegarde après interruption** : sample BT_cronox18.wav et provenance conservés ; autorisation de publication consignée ; publication non confirmée. Les résultats techniques validés restent ceux de CP-004.

- **CP-006 — traduction statique sélectionnée** : export p-code, génération C++ de 2518 instructions, tests différentiels de saturation et FilterMoogSI sur 148 cas sans écart de sortie ou d’état. Aucun moteur complet ni AU natif obtenu.

- **CP-007 — replay natif sélectionné** : programme autonome de replay, objets Mach-O ARM64, exécution du probe ARM64/Linux sous QEMU sans différence sur les 148 cas. Les appels math sont isolés par réponses ABI enregistrées ; aucun test macOS/AU effectué.

- **CP-008 — Schrader et sonde audio** : préparation mono/normalisation/tableaux et jeu Schrader statiquement traduits, 704 cas et sonde de trois secondes identiques avec réponses hôtes partagées, replay ARM64/Linux/QEMU vérifié. Écart de sept octets d’état interne avec libm ARM64 natif consigné. Le synthétiseur et l’AU complets restent à faire.

- **CP-009 — listing étendu** : 186001 instructions détectées compilées sous Linux et en objets Mach-O ARM64 ; 121 initialisateurs et constructeur comparés ; code manquant atteint à l’ouverture. Sources et analyse conservées dans l’historique Git.

- **CP-010 — ouverture et états** : 191378 instructions après récupération de blocs manquants ; ouverture, import FXP/AU et sérialisation comparés à l’original dans un hôte de test. Références DSP et primitives toujours exactes sous Linux natif et ARM64/QEMU. Le rendu de trois secondes produit seulement un signal sous −100 dBFS et reste en échec. Base Ghidra enrichie et preuves sauvegardées. Aucun AU installable.

- **CP-011 — hôte C++ et contrat de paramètres AU** : hôte C++ autonome, import/sérialisation et régions mémoire exacts sous Linux natif et ARM64/QEMU ; métadonnées des 522 paramètres et 56 alias de validation vérifiés sur les routines originales/traduites. Test Mac avec licence saisie localement et comparaison i386 prévue, non encore exécuté. Licence invalide refusée, captures mémoire privées désactivées. Aucun AU installable.

- **CP-016 — retour CP-015 et corrections auval** : compilation/persistance de licence et audio préflight confirmés sur Mac, auval échoué et rollback confirmé. Propriété33 raccordée à l’original (596cas), initialisation192k/4096 débloquée et réglages validés conservés après échec. Prochain auval Mac et rappel de projets à vérifier.

- **CP-017 — Mac CP-016 confirmé** : auval et installation ARM64 réussis, 522 paramètres validés, six WAV originaux/prévalidation/enregistrés exacts. Licence persistée puis réutilisée. L’utilisateur teste ses projets Logic ; interface fidèle en développement.

- **CP-026 — affichages Main/Filter et Loop** : CP025 installé/auval/audio/actions confirmés ; getter/setter et tracés originaux raccordés, huit croix et forme d’onde exacte,136 modifications/cinq programmes exacts,ARM64/QEMU et six liens Mac stricts. Exécution Mac CP026 en attente. Voir [CP026](../docs/CP026.md).

- **CP-027 — interface des constructeurs originaux** : 86 panneaux/1 067 définitions, effets/modulation/Loop/Arp/clavier/sorties/modules raccordés ; comparaisons i386, ARM64/QEMU et liens Mac stricts. Validation Mac CP027 en attente. Voir [CP027](../docs/CP027.md).
