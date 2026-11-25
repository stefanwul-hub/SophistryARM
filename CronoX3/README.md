# CronoX 3 ARM64 — CRX010

CRX010 corrige l’arrêt Cocoa de CRX009 quand un emplacement de banques ou de samples n’a pas encore été enregistré. Les chemins absents restent facultatifs ; il n’est pas nécessaire de supprimer vos préférences.

Les fonctions récupérées dans CRX009 sont conservées :

- Main : cliquer sur le nom de banque ouvre les banques ; cliquer sur le nom du preset ouvre les presets de cette banque. Le tri sans distinction de casse, les noms sans extension et le chargement du premier preset après changement de banque suivent les routines originales.
- Les deux lignes utilisent les rectangles et la ligne de base d’origine, Helvetica 12 points et le gris `#D2D2D2`. Elles restent centrées.
- Le clavier suit les notes actives du moteur, y compris les accords. Les images et raccords entre touches proviennent de `CKeyboard2::drawKeys` ; 4 354 combinaisons ont été comparées à l’exécution du code original.

Quitter Logic et Live, décompacter `Demarrer-CronoX-CRX010.zip`, puis ouvrir `Demarrer-CronoX-CRX010.command`. Le lanceur vérifie les sources épinglées, conserve le projet/cache dans `~/CronoX3-ARM64/projet`, compile pour ARM64 et teste les commandes, boucles, menus, clavier, vue Cocoa et rendu audio. Il installe avec sauvegarde transactionnelle et exécute `auval -v aumu CrT3 LinP`. Les rapports ZIP sont créés sur le Bureau. En cas d’échec, la version ARM Test précédente est conservée ou restaurée.

Si les banques ne sont pas proposées automatiquement, cliquer sur le nom de banque puis **Choisir le dossier des banques…** et sélectionner le dossier contenant les sous-dossiers de presets. Ce choix est conservé dans les préférences ARM Test. Le bouton **Banque de sons…** conserve sa fonction de choix de la banque de samples. Les menus acceptent les FXP et les états AU déjà pris en charge par l’importeur.

Composant **CronoX 3 ARM Test**, identité **aumu/CrT3/LinP**, bundle `com.linplug.au.CronoX3.ARMTest`, fichier `/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`. CronoX original **CrX3** et **Sophistry CP038** sont préservés. Les identifiants d’origine seront rétablis après validation finale pour rouvrir les anciens projets. Les états de test restent identifiés CrT3.

Le gain de **+6 dB avant le Master**, les corrections du Loop Sampler, le cache de forme d’onde, les noms d’effets et le pied de CRX008 sont conservés. Les 413 unités du moteur audio traduit sont inchangées. Le clavier lit la table de notes originale sans la modifier. Le chemin du preset est conservé dans les nouveaux états AU pour retrouver les menus ; il n’est pas ajouté au diagnostic copié. Un ancien état sans ce chemin conserve son audio et cherche sa banque dans le catalogue configuré.

Préférences de test : `com.linplug.CronoX3.ARMTest`, avec lecture possible de la licence originale sans écriture dans `com.linplug.CronoX3`. Aucune clé ni préférence privée ne doit être transmise ou publiée.

Le rapport Mac CRX009 confirme le passage des tests C++, des accords, des boucles et des temporisateurs. La vue Cocoa s’est ensuite arrêtée sur la conversion d’un chemin vide, avant la copie du composant. CRX010 ajoute un contrôle des chemins `nil`/vides et du repli vers le dossier du preset dans la vraie sonde Cocoa. Les exceptions Objective-C y produisent désormais un rapport d’échec structuré.

Vérifications CRX010 : 28 régressions et script Bash 3.2 réussis ; compilation et lien strict Mach-O ARM64 réussis, 110 images et trois exports vérifiés. Le moteur audio, le catalogue, la typographie et les découpes du clavier restent inchangés. **L’exécution Cocoa et auval de CRX010 reste à effectuer sur votre Mac.**

Reprise : `CRX_REPRISE.md`, `cronox-status.json`, `evidence/cronox-crx010-*.json` et `checkpoints/cronox/`. CRX008 reste disponible comme point de retour.
