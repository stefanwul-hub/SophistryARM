# CronoX 3 ARM64 — CRX001

Portage en cours du composant CronoX 3.6.6 fourni, distinct de Sophistry CP038. Les publications de ce projet sont dans le dossier `CronoX3` de la branche `codex/sophistry-native-checkpoints`. Sophistry reste à CP038.

Ce checkpoint contient le noyau original traduit statiquement en C++ et un banc de compilation/test Apple Silicon. **Il ne contient pas encore de composant Audio Unit installable.** Son script conserve les plugins et les préférences existants.

Sur le Mac, lancer `Compiler-et-tester-CronoX.command` depuis l’archive complète de ce dossier. Le script décompacte et vérifie les sources, compile pour ARM64, vérifie les architectures et exécute les tests. Le rapport ZIP apparaît sur le Bureau. La première compilation traite 415 fichiers ; les compilations suivantes réutilisent `work`.

Résultats déjà obtenus dans l’environnement Linux : démarrage du moteur, 522 paramètres AU issus de l’original, sauvegarde/restauration du programme, chargement du FXP Lightgarden et de son sample, appels MIDI et rendu de 2 048 trames sans valeurs non finies. L’audit retrouve les 211 282 instructions exportées, les 3 174 entrées de fonctions nommées et les 1 784 cibles virtuelles internes. Les 6 228 fixtures d’instructions SQRT passent ; le helper SQRTSD et l’ABI des chaînes sont aussi testés sur ARM64 avec QEMU.

Ces résultats ne certifient pas encore le son complet, les performances dans les hôtes, la réouverture des projets ou la validation `auval`. Les appels de l’interface hérités de Sophistry sont bloqués tant que les liaisons propres à CronoX ne sont pas vérifiées. Les contrôles de licence du code original sont conservés ; aucune clé ne doit être transmise ni publiée. Le gain de sortie CronoX reste celui de son DSP original, sans la compensation spécifique à Sophistry.

Original : `aumu / CrX3 / LinP`, bundle `com.linplug.au.CronoX3`, version 3.6.6. Le fichier original contient i386 et x86_64 ; la tranche i386 sert à la traduction et à la vérification des adresses de 32 bits. Le résultat C++ peut être compilé pour ARM64, sans décodeur x86 à l’exécution.

Voir [CRX_REPRISE.md](CRX_REPRISE.md) et [cronox-status.json](cronox-status.json) pour reprendre le développement. La décompilation complète et le projet Ghidra sont sauvegardés dans les archives de `checkpoints/cronox`.

La première version AU utilisera **`aumu / CrT3 / LinP`**, « CronoX 3 ARM Test », bundle `com.linplug.au.CronoX3.ARMTest`, fichier `/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`. Ce profil permettra la comparaison avec l’original `CrX3` déjà installé. Le remplacement de l’original est désactivé. Les bons identifiants de restauration seront rétablis après validation utilisateur ; conserver le moteur et le format interne de preset d’origine ne requiert pas de reprendre immédiatement son identifiant AU.

Le noyau entier et le pont AU sont également compilés en ARM64/Linux et exécutés sous QEMU : les 6 228 fixtures et le test complet de paramètres/état/premier rendu passent. Cette exécution reste distincte d’un Audio Unit validé sur macOS.
