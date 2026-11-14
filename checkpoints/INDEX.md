# Checkpoints

- **CP-001 — audit original** : archive épinglée, architectures i386/PPC, identité AU, ressources, segments Mach-O et tables de classes candidates.
- **CP-002 — Ghidra** : base de projet enregistrée et export des 3 249 fonctions détectées. Le pseudo-code conserve des avertissements et n’est pas compilable tel quel.
- **CP-003 — noyau et tests** : traduction de Satur_c, tests par exécution des instructions originales, fixtures, preuve de compilation ARM64 du noyau, diagnostic Mac et rapport de reprise. **Le moteur complet et l’AU natif ne sont pas implémentés.**

L’historique Git est conservé dans `Sophistry-history.bundle`. Le projet Ghidra complet est dans `ghidra-project/`, avec son fichier `.gpr` et son dossier `.rep`.
