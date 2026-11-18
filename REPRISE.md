# Reprendre à CP030

La publication du port est autorisée sur la branche `codex/sophistry-native-checkpoints`. Ne pas modifier `main`. Licence, préférences, chemins privés, banques complètes et rapports Mac bruts restent hors publication. Aucun numéro de licence ni nouveau preset n’est nécessaire pour reprendre.

La dernière demande concerne les craquements spécifiques à Gen1+2, le coût CPU par rapport à CronoX 3, le sens des enveloppes, les textes blancs et le pied de page. Le scénario extrême DX Bass annulé précédemment reste exclu. Les changements, leurs raisons et les limites sont décrits dans [CP030](docs/CP030.md).

Le rapport CP029 confirme installation, auval, Cocoa local et distant, quatre menus Full Loop et huit comparaisons PCM exactes. Les seuls faits publiables sont dans [la preuve filtrée](evidence/mac-cp029-installed.json). Ce succès ne prouve pas l’absence de craquements en lecture temps réel.

CP030 récupère le drapeau d’inversion du constructeur original des Drawbar, prépare les tracés Loop au chargement, relâche le verrou entre les getters terminés et réduit les redessins. Les conversions numériques courantes sont raccourcies avec repli général exact. Les 366 unités traduites et le contrat des 522 paramètres AU sont conservés. Le pied de page devient « Sophistry ARM64 port OA 2026 (CP-030) », build30001.

Les tests sélectionnés passent sur Linux natif et ARM64/QEMU : 3 503 936 résultats de conversion sans écart, 704 cas DSP, 11 635 instructions, 852 métadonnées, 676 positions de pointeur, 17 fichiers exacts et 6 327 interruptions entre getters sans corruption. Huit binaires Mac modifiés sont liés strictement en ARM64. Les preuves, empreintes de sources et limites se trouvent dans [cp030-development-checks.json](evidence/cp030-development-checks.json).

L’exécution Cocoa, auval et audio de CP030 reste à faire sur le Mac de l’utilisateur. Le nouvel essai ordinaire compare Main/Gen1+2 avec une note tenue à44,1kHz/256frames, sur deux instances fraîches. Les durées sont observationnelles et sans seuil matériel. Ne pas annoncer une baisse CPU globale chiffrée ni la parité avec CronoX avant mesure comparable.

Ne pas reconstruire inutilement les unités traduites déjà compilées. Les objets réutilisables, journaux détaillés, rapports reçus et notes propres à l’environnement sont conservés dans la sauvegarde locale ; ils ne font pas partie de la publication. Les procédures d’installation conservent licence et banque validées, toutes les validations habituelles et la restauration du composant précédent en cas d’échec.

Limites restantes : pas d’éditeur Enhanced exploitable récupéré pour les panneaux réservés70/71/82..86 ; export général FXP absent (AU et MOD disponibles) ; couverture exhaustive des chemins DSP et variantes MIDI/hôtes non certifiée. Le navigateur générique en double reste supprimé. L’identité `aumu/Sop3/LinP`, le bundle et la version AU3.0.8 restent conservés.

Publication CP030 : en cours. Après publication, inscrire les commits et empreintes immuables, vérifier les blobs du ZIP et le lanceur téléchargé, puis régénérer et vérifier le bundle Git autonome avec le dernier commit. Garder le dépôt propre. Le prochain retour utile est le rapport CP030 et l’écoute Main/Gen1+2 dans Logic/Live.
