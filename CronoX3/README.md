# CronoX 3 ARM64 — CRX007

CRX007 corrige les sept points signalés après le test réussi de CRX006 dans l’hôte :

- +6 dB fixe avant le Master, avec les valeurs, l’automation et les états sauvegardés du Master conservés.
- Nom du preset lu dans le format original et mémorisé au rappel ; « unknown » n’est plus considéré comme un nom valide.
- Deux colonnes File du sampler restaurées : 16 champs récupérés dans le constructeur CLabelPl original.
- Police Helvetica d’origine, tailles de 9 à 14 points suivant les champs ; colonnes File à 10 points et valeurs usuelles à 11 points.
- Suppression du texte « off » superposé aux boutons Chord et ECS ; leurs menus restent actifs.
- Boutons Charger un son…, Banque de sons… et Copier le diagnostic centrés entre le bas du clavier et le bas de la fenêtre.
- Pied de fenêtre : « CronoX 3 ARM64 port OA 2026 . CRX007 ».

Quitter Logic et Live, décompacter le ZIP `Demarrer-CronoX-CRX007.zip`, puis ouvrir `Demarrer-CronoX-CRX007.command`. Le lanceur télécharge les sources épinglées et vérifie leur SHA256. Il conserve le projet et les objets compilés sous `~/CronoX3-ARM64/projet`, lance la compilation ARM64, les tests C++, la prévalidation Cocoa/audio, l’installation transactionnelle et `auval -v aumu CrT3 LinP`. Le mot de passe administrateur sert à la copie dans `/Library`. Les rapports ZIP sont enregistrés sur le Bureau. En cas d’échec, la version ARM Test précédente est conservée ou restaurée.

Le composant est **CronoX 3 ARM Test**, identité **aumu/CrT3/LinP**, bundle `com.linplug.au.CronoX3.ARMTest`, installé dans `/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component`. CronoX 3 original **CrX3** et **Sophistry CP038** sont préservés. L’identifiant original sera rétabli après validation finale pour la restauration des anciens projets. Les états de test restent identifiés CrT3.

Les préférences de test utilisent `com.linplug.CronoX3.ARMTest`. Le moteur peut lire la licence déjà enregistrée dans `com.linplug.CronoX3`, sans écrire dans ce domaine. Les vérifications originales restent en place. Aucune clé ni préférence privée ne doit être publiée. « Banque de sons… » permet de changer le dossier de la banque ARM Test.

L’interface comprend Main, Gen 1+2, Gen 3+4, Filters, Effects, Modulation, Settings, le clavier et la vue 5.1. Panneaux, styles, coordonnées, menus, chaînes et dessins proviennent des routines originales traduites ; l’affichage et les gestes sont adaptés en Cocoa. Le navigateur de dossiers/catégories d’origine est remplacé par la sélection native FXP/AU et Prev/Load/Next/Save. Le moteur traduit comprend 413 unités C++, 211 282 instructions i386 et 786 267 opérations p-code, compilées pour ARM64, sans décodeur x86 à l’exécution. Ces unités n’ont pas changé depuis CRX001 ; le gain CRX007 est appliqué à la conversion du coefficient du Master dans l’adaptateur des imports.

Résultats : l’utilisateur a validé CRX005 pour l’Audio Unit, le son et plusieurs presets, avec une comparaison favorable non exhaustive. Il confirme le fonctionnement et l’affichage de CRX006. Les tests de développement CRX007 passent : 107 configurations d’interface, 54 cas de gain, 15 volumes sans modification et rappel de banque avec données inchangées. Le composant et les sondes passent la compilation et le lien strict Mach-O ARM64 ; les 110 images originales et les 3 symboles exportés sont contrôlés. **L’exécution Cocoa et auval de CRX007 restent à effectuer sur le Mac utilisateur.** Aucune équivalence sonore exhaustive ni comparaison CPU définitive n’est annoncée.

Checkpoints et reprise : `CRX_REPRISE.md`, `cronox-status.json`, `checkpoints/cronox/UI-Recovery-CRX007.tar.gz` et les preuves `evidence/cronox-crx007-*.json`. Les versions antérieures et leurs lanceurs restent disponibles.
