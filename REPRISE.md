# Reprendre à CP029 — interface sans navigateur générique

## Autorisation et dernière orientation

Utilisateur propriétaire de la licence et des banques, publication déjà autorisée. Ne pas redemander clé, presets ou permission de publication. Branche autorisée : codex/sophistry-native-checkpoints ; ne pas modifier main. Aucun sous-agent sans demande explicite. Garder préférences, licence, chemins privés et rapports Mac bruts hors Git.

CP028 compile ; l’utilisateur confirme que toutes les commandes essayées fonctionnent. Il demande le retrait de « Commandes du son » et un état honnête des fonctions restantes. Il a expressément ANNULÉ les tests de charge DX Bass : ne pas les reprendre ni ajouter de stress ou télémétrie CPU à l’installation. Son M1 Ultra / 44,1 kHz / 256 frames et les samples reçus sont des éléments de recherche uniquement.

## Travail CP029

Le navigateur générique, recherche et liste sont supprimés du Cocoa editor. Largeur 762 au lieu de1120, hauteur477. Clavier/MIDI déplacé dans la ligne du preset ; banque/chargement/diagnostic/volume restent accessibles. Les522 paramètres AU restent accessibles aux hôtes et à l’automation. La vue générique de Logic/Live ne fait pas partie de notre éditeur. Tests Cocoa adaptés aux contrôles originaux, largeur762 et détection effective de la présence d’un navigateur.

SampleDisplay.h extrait le nom Windows/HFS/POSIX. Le Cocoa lit le texte entier via SpTx avant extraction pour éviter la limite128 du DTO. Le chemin et le chunk ne changent pas. Sens des35 tirettes d’enveloppe vérifié original8089a : minimum haut, maximum bas ; conservé.

Quatre commandes FullLoop On/Off52..55 étaient omises à cause du bitmap250 absent. Elles sont ajoutées au menu de type dans le seul mode Time Sampler, pour les quatre générateurs. Les menus utilisent AudioUnitGet/SetParameter sur les IDs existants, événements de geste/valeur, puis rafraîchissement. Leur activation/désactivation/restauration passe par les menus réels dans la prévalidation Cocoa. Les autres éléments du menu représentés par NSNumber restent les modules643..646 ; FullLoop utilise un NSDictionary pour ne pas être confondu avec les types.

Limites connues : aucun éditeur Enhanced exploitable récupéré pour les panneaux70/71/82..86 (fond246, aucun widget relevé) ; export généralFXP non proposé (sauvegardeAU). Ne pas prétendre que tous les chemins originaux sont couverts. MIDI learn/automation et cas particuliers d’hôtes ne sont pas tous certifiés. Voir docs/CP029.md.

Moteur, runtime et366 unités statiques inchangés ; identité aumu/Sop3/LinP, bundlecom.linplug.au.Sophistry, versionAU3.0.8, chunks et522IDs inchangés. Build29001, wrapperCP-029. Licence/banque et mécanismes de sauvegarde/restauration inchangés.

## Validation, cache et reprise

Travail/logs dans work/cp029 ; binaires Mac réutilisés dans work/cross-cp027. Ne pas reconstruire les366 unités. Les scripts cross-browser-final.py/cross-ui-final.py réutilisent les objets. Les premiers essais CPU ont été abandonnés et leurs fichiers de production supprimés : aucun RenderMetrics.h ni AudioUnitPerformanceProbe.mm ne doit être publié. NativeCompleteEditorProbe/compare_complete_editor et SophistryAU.cpp sont revenus exactement à CP028. Les anciens résultats18fichiers/stress dans work/cp029 ne décrivent pas la version finale ; ne pas les publier comme preuve CP029.

Les40 samples DX (112974552 octets) sont vérifiés contre les blobs GitHub et conservés dans work/cp029/dx-samples. DX Bass.FXP est dans work/cp029, hors paquet. Source utilisateur main d9fc740319b1bb3d3846df32f31e59bacf7df44c. Les sources, objets et rapports sont conservés. Des archives de téléchargement CP023/24/25 déjà vérifiées ont été supprimées du cache pour libérer l’espace ; journal work/cp029/rebuildable-cleanup.json. Les notes de recherche DX disent Voices=all et Release0.931 ; ce problème est classé à la demande de l’utilisateur.

CP027 avait arrêté la prévalidation avant remplacement (menu766/770), les WAV et contrôles Main/Filter/Loop passaient ; preuve filtrée dans evidence/mac-cp027-prevalidation.json. Dernière preuve d’installation par rapport reçu : CP025. CP028 confirmé fonctionnel par l’utilisateur sans nouveau ZIP. CP029 AppKit/auval/audio en attente du Mac ; ne pas annoncer une validation exécutée ici.

Publication CP029 : préparer les preuves, publier les sources, télécharger et vérifier chaque blob de l’archive, publier le lanceur épinglé avec SHA256, vérifier son téléchargement, puis enregistrer les métadonnées finales. Mettre à jour cette section après publication et régénérer checkpoints/Sophistry-history.bundle avec le dernier commit. Garder le dépôt propre. Les liens CP028 restent dans checkpoints/CP028-publication.json et CP028-launcher-verification.json.
