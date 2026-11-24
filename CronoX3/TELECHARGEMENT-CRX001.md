# CronoX CRX001 — banc de compilation et de test

Télécharger [Demarrer-CronoX-CRX001.zip](Demarrer-CronoX-CRX001.zip), décompacter puis ouvrir `Demarrer-CronoX-CRX001.command` sur le Mac Apple Silicon. Si macOS n’autorise pas l’ouverture directe, le fichier peut être lancé avec `bash` depuis Terminal.

Le lanceur télécharge une archive GitHub épinglée, contrôle son SHA256, extrait seulement `CronoX3`, reconstitue les fichiers fragmentés et les sources vérifiées, puis compile et exécute les tests. Le projet et son cache restent dans `~/CronoX3-ARM64/projet`. Un rapport ZIP `CronoX3-rapports-CRX001-…` apparaît sur le Bureau.

La première compilation traite 415 fichiers. Les relances réutilisent l’archive vérifiée et les objets déjà compilés.

**Ce checkpoint ne fournit pas encore de composant Audio Unit installable.** Il n’installe rien dans `/Library`, ne lance pas auval et ne modifie aucune préférence de licence. Le noyau complet et le pont d’origine ont déjà passé les essais ARM64 sous QEMU ; le rapport Mac doit vérifier la compilation et les mêmes appels avec les outils Apple.

Pour le futur composant de comparaison : `aumu/CrT3/LinP`, nom « CronoX 3 ARM Test », bundle `com.linplug.au.CronoX3.ARMTest`, fichier `CronoX 3 ARM Test.component`. Le CronoX original `CrX3` reste installé et Sophistry reste à CP038. L’identité de restauration des anciens projets sera rétablie après validation utilisateur.

Les empreintes et les vérifications de téléchargement sont dans [le checkpoint](checkpoints/cronox/CRX001-publication.json).
