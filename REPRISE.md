# Reprendre à CP037 — horloge native, noyau CP032 conservé

Publication autorisée seulement sur `codex/sophistry-native-checkpoints`, jamais main. Aucun secret, préférence, banque complète ou rapport Mac brut dans Git. Ne pas redemander la licence. Compilation/tests/auval sur le Mac de l’utilisateur, sans runner GitHub. Pas de délégation demandée.

CP033 est retiré : régression CPU Mac mesurée 3,306 fois CP032. Référence CP032 `1a32688cce7017bc40a6085563a0aa82edb08639`, archive `6859eaa4b3513b384ecab6bc6e5501174977dfb8`, SHA256 `0fa3d52b58c753ba5b2cee5dbc6cd13d5099191f78b18812e2274ceff0661d0a`. Retour disponible par `Revenir-Sophistry-CP032.command`, lanceur original conservé avec cache. Retour réellement installé sur Mac à confirmer.

Demande courante : concordance avec l’original, voix mal réutilisées, sans optimisation particulière. Niveau et stress extrême DX Bass classés. Ne pas reprendre l’optimiseur CP033.

CP036 : mêmes entrées donnent mêmes décisions i386/C++. Le contrat d’horloge simulée peut augmenter les voix/appels de quatre à cinq dans un cas contrôlé. Pas de fuite illimitée, compteur incohérent ou mesure des vraies enveloppes/CPU Live établie.

CP037 corrige le contrat monotone : `MonotonicClock.h`, option `LegacyEngineConfig.nativeMonotonicClock`, imports Mach avec ticks/timebase OS. Production AU activée ; mode déterministe gelé conservé. `_usleep` attend dans ce mode et ne rajoute pas deux fois du temps. Dates civiles et aléas inchangés. Timestamps AU en unités Mach natives. Saturation uint32 originale conservée, sonde d’installation vérifie sa plage.

Noyau `src/lifter/` et données originales byte-identiques à CP032. Diagnostic en lecture seule sur demande : `monotonic_clock`, `voice_activity` et comptes par partie. CP037/build37001, AU 3.0.8 aumu/Sop3/LinP, bundle et 522 paramètres conservés. Pas de navigateur générique réintroduit.

Tests : 9897 étapes et 85622244 octets i386/C++ sur trois profils ; sondes Linux et ARM64/QEMU ; retour ABI 64 bits via adaptateur complet ; pont AU ; 96 chargements stables ; 16 liens Mac ARM64 stricts. Sept tests de cache et cinq tests de la politique CPU passent. Preuves `evidence/cp037-*.json`, détails `docs/CP037.md`.

Cache qualifié CP032 réutilisable ; variable `SOPHISTRY_CP032_SOURCE` pour ancien dossier personnalisé. Tous les consommateurs de `LegacyEngineConfig` doivent être recompilés car sa disposition a changé. Ne pas réutiliser un ancien objet de sonde avec le nouvel Engine.o. Les données seules peuvent être réutilisées.

Garde avant copie : cinq passages alternés en processus neufs, Lightgarden/une note/44100/256/trois secondes ; WAV exact exigé et médiane CPU CP037/CP032 <=1,5. Référence absente, écart audio ou régression arrêtent avant remplacement. Licence locale, prévalidation, auval, Cocoa, audio enregistré et rollback conservés.

Prochaine preuve : rapport CP037 du Mac, diagnostic dans un vrai projet et comparaison CPU à jeu similaire. CPU Live, auval, vraies enveloppes, audio sous licence et rappel CP037 non exécutés ici. Mac M1 Ultra/macOS15.7.2/Xcode, Live11.3.2 en44100/256, Logic11, banque/licence locales. Ne pas annoncer le CPU résolu ou le moteur intégralement certifié. Services périodiques CP035 et autres adaptations restent à examiner ensuite selon résultats.

CP036 sources déjà publiées c8f4215bddbb8e45419346f2722f4a2705a236f8 ; archive SHA256 eeb473e7763aac402ef765994ed4e573c0c7d342f0f6c70730f987c23a8c8d8a,4245 blobs vérifiés. Ses quatre métadonnées finales étaient locales après rejet de revue automatique pour limite d’usage ; elles sont incluses dans CP037 préparé. Consulter le journal de publication CP037 avant d’affirmer une publication effective. Ne pas contourner un rejet par un autre canal d’écriture.

Conserver bundle Git autonome vérifié, journal local d’empreintes et backup Ghidra CP032. Les preuves de publication immuables sont dans checkpoints/CP037-publication.json une fois disponibles.

Publication CP037 confirmée : sources `ed090216afe2faf9058a5d3a5c2ea673d39da5ae`, arbre `dd2af2584c197a1474cd1234e0933ebfa21a3f79`, archive SHA256 `8620a385912dcaba8b46a3fd7c0c707105d6e55ee83ea481e5cceea6aa6232ef`, 4268 blobs vérifiés. Lanceur épinglé `0f53ef9bd972bdf4c7c610db7f7e89e660f47aac`, SHA256 `5954dee6322cfdb66daeeb059fe6bb4ae69e6070f372a1dd3d336dabc88a5cd9`, contenu brut téléchargé et comparé. Les quatre métadonnées CP036 sont désormais intégrées aux sources CP037 publiées. Main conservé. Les sorties complètes des sondes artificielles restent locales ; seules les propriétés utiles sont dans les preuves publiques. Validation Mac toujours en attente.
