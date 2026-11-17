# Suite après CP027

L’implémentation des pages visibles récupérées dans les constructeurs est maintenant dans CP027 : [description](CP027.md). Les données, fichiers et routines testés sont comparés à l’original et sous ARM64/QEMU ; sept binaires Mac sont liés strictement. Les espaces réservés sans commandes dans l’original et la ressource 250 absente sont documentés.

La prochaine étape est le rapport Mac CP027 : installation/build27001/auval, parcours Cocoa des pages et variantes, saisies Loop, captures et comparaisons audio. Vérifier dans Logic et Live le rendu visuel, les gestes, les menus de modules et la sauvegarde/réouverture sur des copies de projets. Aucun nouveau preset ni numéro de licence n’est à demander pour lancer ces vérifications.

Étendre ensuite les comparaisons musicales avec la licence locale aux générateurs, effets, notes/vélocités, relâchements, pédale, pitch bend et tailles de buffers. Mesurer charge, mémoire et polyphonie dans les DAW. Les états exacts et les tests sélectionnés ne démontrent pas une identité sonore sur toutes les banques ou tous les chemins ; les écarts libm internes déjà consignés restent à surveiller.

Conserver la publication sur `codex/sophistry-native-checkpoints`, les archives/lanceurs épinglés et vérifiés, les preuves filtrées et le bundle Git autonome. Garder les préférences/licence/rapports bruts privés. Conserver la transaction d’installation et sa restauration.
