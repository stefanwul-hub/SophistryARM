# Suite après CP036

CP032 reste la référence fonctionnelle. CP036 explore les voix et conserve les sources, traces et conclusions, sans modifier le composant ni introduire d’optimisation.

La mauvaise datation peut modifier plus que l’identité de la voix reprise : un exemple contrôlé à sept notes passe de quatre à cinq voix occupées et appels dans la boucle originale. Sur un seul canal, un autre exemple change déjà le nombre de voix maintenues au note-off ; la persistance du nombre de voix occupées a été illustrée avec une fin de relâchement explicite de la sonde. Le vrai DSP des enveloppes reste à vérifier.

Préparer une correction de fidélité de l’horloge et des unités de timestamps AU en conservant les routines originales de sélection. Pour chiffrer l’impact CPU, observer séparément les voix occupées, maintenues et par partie dans le rendu du vrai preset. Les compteurs sont cohérents dans les cas testés ; éviter une réécriture arbitraire de l’allocation ou une limite forcée.

Le service périodique original étudié à CP035 reste un autre contrat d’intégration à examiner. Aucune conclusion de fuite illimitée, de parité CPU CronoX ou d’équivalence sonore exhaustive n’est acquise. Les demandes de niveau et de stress extrême DX Bass restent classées.
