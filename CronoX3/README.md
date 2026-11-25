# CronoX 3 ARM64 — CRX011

CRX011 corrige les deux points d’interface demandés, d’après l’exécution du code original :

- Matrix : les dix menus de destinations retrouvent leurs 16 catégories et leurs 58 choix. Les caractères `$` internes sont remplacés comme dans l’original. Les numéros de paramètres et l’automation sont conservés.
- Arpeggiator : quatre colonnes de huit valeurs, chacune précédée des indicateurs originaux. Le triangle vert utilise le bitmap 306 d’origine, avec ses deux états et ses coordonnées exactes. Les valeurs supplémentaires de notre ancienne vue sont supprimées ; les affichages numériques, Off/Tie, couleurs, clics et défilement reprennent les règles originales. La progression est actualisée toutes les 20 ms quand la vue est visible.

Quitter Logic et Live, décompacter `Demarrer-CronoX-CRX011.zip`, puis ouvrir `Demarrer-CronoX-CRX011.command`. Le lanceur télécharge les sources épinglées et contrôlées, conserve le projet/cache dans `~/CronoX3-ARM64/projet`, compile pour ARM64 et lance les tests d’interface, de rendu et `auval -v aumu CrT3 LinP`. Le rapport ZIP est créé sur le Bureau. L’installation conserve ou restaure la version ARM Test précédente si une étape échoue.

Composant **CronoX 3 ARM Test**, identité **aumu/CrT3/LinP**, bundle `com.linplug.au.CronoX3.ARMTest`, fichier `/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`. L’original **CrX3** et **Sophistry CP038** restent conservés. Les identifiants de l’original seront rétablis après validation finale pour la restauration des anciens projets.

Les corrections antérieures de gain (+6 dB avant Master), de boucles, de banques/presets et de clavier sont conservées. Le moteur audio et ses 413 unités traduites sont inchangés. Cette publication porte sur l’interface ; les recherches sur la consommation CPU sont sauvegardées séparément pour la suite.

Vérifications : les menus sont comparés aux routines CMenuWithSub originales ; 180 états d’arpégiateur donnent les mêmes 11 520 opérations de dessin (textes, couleurs et découpes du bitmap). Les dix menus et leurs associations de paramètres passent le test C++. Les 28 régressions et le script sous Bash 3.2 passent. Compilation et lien strict Mach-O ARM64 réussis, 110 images et trois exports isolés vérifiés. **L’exécution Cocoa/auval de CRX011 et la vérification visuelle dans vos hôtes restent à faire sur votre Mac.**

Les tests Cocoa de l’installeur contrôlent aussi les catégories, le nombre de destinations et le chargement du bitmap d’arpégiateur. Aucun nouveau test de charge CPU n’est lancé par cet installeur.

Reprise : `CRX_REPRISE.md`, `cronox-status.json`, `evidence/cronox-crx011-*.json` et `checkpoints/cronox/`. Préférences de test : `com.linplug.CronoX3.ARMTest`. Ne pas transmettre de clé de licence ni de préférences privées.
