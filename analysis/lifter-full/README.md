# Export p-code étendu — CP-010

`instructions.jsonl.gz` conserve les 191378 instructions internes reconnues après récupération des blocs manquants avec Ghidra 11.3.2, associées à 2845 fonctions détectées dans la tranche i386 originale. Il exclut les stubs d’imports à partir de `0x103000`. `provenance.json` identifie le binaire et la langue ; `archive.json` donne les empreintes des octets bruts et compressés. La couverture de tout le code atteignable n’est pas établie.

Pour reprendre sans refaire l’analyse Ghidra :

```sh
mkdir -p work/lifter-full
gzip -dc analysis/lifter-full/instructions.jsonl.gz > work/lifter-full/instructions.jsonl
python3 scripts/audit_pcode_support.py work/lifter-full/instructions.jsonl --output work/full-pcode-support-audit.json
```

L’audit sauvegardé dans `analysis/full-pcode-support-audit.json` compte 758579 opérations p-code, toutes émises syntaxiquement, dont cinq opérations protégées par des erreurs terminales explicites dans quatre instructions. Ces quatre instructions sont des données de tables de sauts interprétées comme du code ; elles ne sont pas remplacées par des no-op. Une opération émise peut encore contenir une erreur sémantique.

Le runtime réserve les 1528580 octets temporaires requis. Le C++ généré est sauvegardé dans `src/lifter/whole/` ; 704 cas DSP, 11635 cas primitifs/gardes et les comparaisons d’initialisation/chargement/sérialisation du prototype passent. Le rendu sonore complet, les adaptateurs C++ de production, le wrapper AU et l’interface restent à terminer. Voir `docs/CP010.md`.

Les rapports `recovered-*.json` consignent les adresses récupérées, les trois conflits d’instructions laissés intacts et l’absence d’échec de décompilation des 2845 fonctions examinées. Le projet Ghidra enrichi est sauvegardé sous `checkpoints/ghidra-project/`.
