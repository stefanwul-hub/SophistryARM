# ELA016 — chargement des métadonnées dans ETSoundbank

27 novembre 2026. Reprise du checkpoint ELA015 au commit `3d068e484ecc30fad1b674a7348fc768b2964aa2`. L’image d’origine reste Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

`elastik_original_bank_archive_readonly` relie le chargeur paresseux `ETSoundbank` à l’ouverture GNFA en lecture seule, à la recherche de `/Info.plist`, à la lecture du membre et au parseur XML/OpenStep. Les deux points d’entrée réutilisent les règles de chargement de `0x1aa9c6`. Le point d’entrée historique continue de prendre ses appels à l’archive et au parseur dans ses liaisons d’origine.

L’adaptateur conserve le callback de résolution du fichier source, le test du système de fichiers et le repli sur les ressources. Il utilise les routines traduites `0xe13de` et `0xe1a68` pour l’ouverture et le chemin interne. Une erreur d’ouverture libère l’archive et remet le cache à vide. Une plist absente ou invalide laisse l’archive en cache et applique les valeurs de repli prévues par le chargeur. Changer la source invalide le cache, même si l’objet est identique. Changer simplement les octets derrière une archive déjà ouverte conserve le cache.

Le lecteur natif détient l’arbre de la liste de propriétés jusqu’à sa matérialisation par le runtime hôte. Ce runtime restitue un dictionnaire avec une référence détenue. Le chargeur retient les valeurs assignées avant de relâcher le dictionnaire. La sonde vérifie qu’elles survivent à cette libération et que le nettoyage final rend toutes les références qu’elle a créées.

La clé `gracePeriode` garde son orthographe. La vérification appelle le vrai getter `GNString` i386 `0x34496` sur les valeurs textuelles, puis le corps `ETSoundbank` convertit le float32 en double comme dans l’original. L’interprétation des types non textuels pour cette clé reste du ressort du runtime hôte. Les champs sans lien avec ces métadonnées sont observés dans les comparaisons d’état.

## Vérifications

| Corpus par configuration | Cas |
| --- | ---: |
| Plists XML et OpenStep, dispositions GNFA et modes de lecture | 112 |
| Banque intégrée et résolution de la source | 40 |
| Chemins absents ou imbriqués, troncatures, tentatives d’ouverture et réouvertures | 48 |
| Total | 200 |

Les **211 620 octets** de résultats concordent bit à bit sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. La comparaison inclut les valeurs retenues, les compteurs d’ouverture, le cache, la durée de grâce et l’ordre des diagnostics. Le test ASan active la détection des fuites. Deux objets Mach‑O ARM64 sont compilés et vérifiés. Les 2 062 résultats du chargeur ELA013 et les 2 121 résultats du lecteur de plist ELA015 gardent leurs empreintes sur x86‑64. [Rapports et objets](../evidence/ELA016)

La comparaison d’origine emploie trois VM. La première exécute les corps `ETSoundbank`. La deuxième exécute les corps de l’ouverture, de la recherche et de la lecture GNFA sur les octets réels de chaque fixture. La troisième exécute le parseur i386 et le getter de grâce, puis restitue les valeurs à la première. La sonde native exécute le raccordement en un seul processus. Les entrées/sorties brutes, le runtime des objets hôte et les cadres d’exception GN sont des liaisons de la sonde. Les banques protégées et les services macOS restent à vérifier.

## Reproduction

```sh
mkdir -p work reference
python3 -m pip install -r requirements-probe.txt
python3 scripts/inspect_elastik.py reference/ElastikAU.pkg.zip \
  --output work/installer.json --extract reference/original-payload
python3 scripts/build_planar_sum_probe.py --kind soundbank-archive --output work/SoundbankArchiveProbe
python3 scripts/compare_original_soundbank_archive.py reference/Elastik.i386 work/SoundbankArchiveProbe \
  --platform local --output work/soundbank-archive.json
```

La suite porte sur les objets et services natifs qui alimenteront cet adaptateur, puis sur le catalogue global, le vrai délégué de banque, le rappel d’état et la voix complète. Le composant installable, `auval` et la restauration d’un projet restent à réaliser.
