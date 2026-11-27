# ELA015 — listes de propriétés XML des banques GNFA

27 novembre 2026. Reprise depuis le checkpoint ELA014 publié au commit `477ac9de26c4ac816d8913c8a6a481bfbd7b44fb`. L’original Elastik 1.5.2.3 i386 a pour SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

La route XML de `0x670cc` alimente désormais les mêmes valeurs natives que la branche OpenStep. L’ouverture d’archive et la résolution de `/Info.plist` transmettent les octets au parseur selon le format détecté. Les cas XML archivés sont des banques GNFA synthétiques. La banque intégrée à l’installateur fournit toujours une plist OpenStep.

## Comportements reproduits

- Recherche de l’élément `plist` et choix de son premier enfant élément, exigé de type `dict`. Les valeurs acceptées sont les dictionnaires, tableaux, chaînes, entiers, réels, booléens, dates et données.
- Projection des nœuds par `0x66e46`, `0x673d2` et `0x67a06`. Elle conserve l’ordre du premier emplacement d’une clé répétée et remplace sa valeur. Le texte dépend du premier enfant du nœud, qui peut être un commentaire, un élément ou un nœud inconnu dans l’ancien DOM.
- Les références numériques livrent un octet dans le mode inconnu ou historique du DOM. Une déclaration UTF‑8 ou une marque UTF‑8 au début sélectionne la conversion en UTF‑8. La réduction des espaces s’applique au texte source et préserve les espaces introduits par les références.
- GN représente `-2147483648` sur 64 bits et `-2147483647` sur 32 bits. Le scanner des réels reprend la conversion d’origine en float32, avec le signe et l’exposant de la route XML.
- La date projette les six arguments calendaires transmis au constructeur `0x1a7df0`, dont les champs minute et seconde permutés. Une date vide porte une demande de date par défaut. La conversion CoreFoundation vers un instant absolu reste à raccorder au runtime.
- Le décodeur Base64 prend le préfixe valide après retrait des caractères LF et TAB. Il conserve la longueur du tampon GN. Un essai avec un remplissage mémoire `0xa5` montre que le décodeur d’origine laisse des octets de fin intacts. La version native les initialise à zéro.

Le DOM natif repose sur TinyXML‑2 11.0.0, inclus avec sa licence et ses octets amont vérifiés. La bibliothèque traite la déclaration de DTD comme du texte de déclaration et ne la charge pas. Le parseur conserve la limite de profondeur native de 128 valeurs. Le XML déclaré UTF‑8 passe une vérification de son encodage. Le test du texte brut après le document établit un rejet natif et une récupération du dictionnaire par l’i386. [Sources TinyXML‑2 11.0.0](https://github.com/leethomason/tinyxml2/tree/11.0.0)

## Vérifications

| Corpus par configuration | Cas |
| --- | ---: |
| Sélection de format et documents ELA014 | 1 680 |
| Ouverture, recherche et lecture GNFA ELA014 | 45 |
| Nouveaux documents XML | 378 |
| Nouveaux documents XML dans GNFA | 18 |
| Total | 2 121 |

Les 42 737 octets de résultats par configuration concordent bit à bit sur Linux x86‑64, ARM64/Linux sous QEMU, x86‑64 avec UBSan et x86‑64 avec ASan+UBSan. Les 1 696 résultats ELA014 dont le contrat préexistant s’applique gardent leurs empreintes. Les 29 cas qui traversaient la route XML ont désormais un verdict ou un résultat de décodage. Les trois objets Mach‑O ARM64 du parseur et de sa dépendance sont compilés et vérifiés. [Rapports et objets](../evidence/ELA015)

La référence exécute le DOM i386, la projection GN des valeurs, les scanners numériques et le calcul de longueur/décodage Base64. Allocation, stockages GN, conversions de chaînes aux frontières indiquées dans la sonde, fonctions de libc et appel du constructeur de date sont des liaisons. Les cas GNFA utilisent les octets effectivement lus dans une première VM, puis le parseur dans une seconde VM. Côté natif, les mêmes opérations s’enchaînent dans un processus. La décompilation Ghidra en lecture seule couvre 55 fonctions, dont 21 nouvelles, pour 446 fonctions sélectionnées au total. [Archive d’analyse](ELA015-original-xml-plist-decompiled.zip)

## Reproduction

```sh
mkdir -p work reference
python3 -m pip install -r requirements-probe.txt
python3 scripts/inspect_elastik.py reference/ElastikAU.pkg.zip \
  --output work/installer.json --extract reference/original-payload
python3 scripts/build_planar_sum_probe.py --kind property-list --output work/PropertyListProbe
python3 scripts/compare_original_xml_property_list.py reference/Elastik.i386 work/PropertyListProbe \
  --platform local --output work/xml-property-list.json
```

La validation du chargeur `ETSoundbank` avec les objets et durées de vie GN reste le prochain jalon. Le catalogue global et le vrai délégué, les états enregistrés, la voix complète et Cocoa/AU restent à établir. Aucun composant installable, essai dans Logic Pro ou Live, ni restauration de projet n’est produit dans ELA015.
