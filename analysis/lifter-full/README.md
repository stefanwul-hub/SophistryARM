# Export p-code complet : étape de travail sauvegardée

`instructions.jsonl.gz` conserve les 186001 instructions internes reconnues par Ghidra 11.3.2, associées à 2845 fonctions détectées dans la tranche i386 originale. Il exclut les stubs d’imports à partir de `0x103000`. `provenance.json` identifie le binaire et la langue ; `archive.json` donne les empreintes des octets bruts et compressés. Ces fichiers ne sont pas un moteur DSP recompilé.

Pour reprendre sans refaire l’analyse Ghidra :

```sh
mkdir -p work/lifter-full
gzip -dc analysis/lifter-full/instructions.jsonl.gz > work/lifter-full/instructions.jsonl
python3 scripts/audit_pcode_support.py work/lifter-full/instructions.jsonl --output work/full-pcode-support-audit.json
```

L’audit sauvegardé dans `analysis/full-pcode-support-audit.json` compte 732177 opérations p-code ; 566 opérations de 337 instructions ne sont pas encore émises par le générateur actuel. Les manques incluent le décalage signé, les divisions/restes, la conversion entier vers stockage x87, une racine carrée et des userops. Une opération émise syntaxiquement peut encore contenir une erreur sémantique ; seuls les 3242 instructions sélectionnées et leurs tests ont été validés.

Le stockage temporaire maximal requis ici est de 1528580 octets, supérieur à celui du runtime sélectionné actuel. La prochaine étape est d’étendre les primitives avec comparaison différentielle, puis de découper le C++ généré en unités de compilation. L’initialisation du synthétiseur, les adaptateurs hôtes, le chargement complet du preset, le wrapper AU et l’interface restent à intégrer et tester. L’export complet ne prouve aucun de ces comportements.
