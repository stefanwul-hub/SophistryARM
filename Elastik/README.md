# Elastik 1 — portage ARM64 en cours, ELA002

Objectif : rouvrir les anciens projets Audio Unit utilisant Elastik 1. L’original est Elastik 1.5.2.3, Intel 32 bits / PowerPC 32 bits, identité `aumu/ELSK/UBER`. Sophistry CP038 et CronoX CRX013 restent figés.

ELA002 apporte une première routine DSP intégralement traduite depuis ses 117 octets d’origine : la sommation des buffers float32 des voix. Les 73 comparaisons avec le code machine i386 concordent bit à bit, sur x86-64 et sur ARM64 exécuté sous QEMU. Le source est aussi compilé en objet macOS ARM64. Cela valide cette routine isolée ; le moteur complet reste à porter.

Le chemin audio des voix est identifié. Les décompilations sélectionnées couvrent maintenant 155 fonctions distinctes, et 12 classes utiles sont reliées à leurs tables virtuelles. L’analyse du format d’état a progressé : graphe `objects/@id/@isa`, archive binaire et primitives typées, vérifiées par exécution de l’original. Un inspecteur lit désormais les répertoires de classes et d’objets, sans restaurer le son.

**Aucun composant Elastik ARM64 installable n’est encore disponible.** Il n’y a pas encore de rendu du moteur complet, de validation `auval` ni de restauration de projet démontrée. Les tests ARM64 exécutés ici utilisent Linux sous QEMU ; le fichier Mach-O est un objet de compilation, pas un Audio Unit.

Vos banques « Elastik Tutorial.elastik » et « Ueberschall Liquid Instruments » sont notées. Leurs fichiers et un état `.aupreset` ou projet original restent attendus pour les vérifications correspondantes.

La sauvegarde contient les scripts, le source C++, les preuves de comparaison, les décompilations et les instructions de reprise. L’installateur original et les banques restent hors de Git ; les références exactes sont dans [reference-input.json](reference-input.json). Aucun script ne remplace de composant dans `/Library`.

[Notes et reproduction ELA002](analysis/ELA002-notes.md) · [Reprise](ELASTIK_REPRISE.md) · [État](elastik-status.json) · [Preuves](evidence/ELA002) · [Source de la routine portée](src/OriginalPlanarSum.cpp)

L’[archive détaillée des fonctions décompilées et de l’objet Mach-O ARM64](analysis/ELA002-original-state-render-decompiled.zip) est publiée séparément, après votre autorisation explicite. Elle contient 129 fonctions distinctes avec leur désassemblage et le relevé des classes utiles. L’[autorisation est enregistrée](evidence/ELA002/detailed-archive-publication-consent.json). Le ZIP du checkpoint source ELA002 reste inchangé ; l’archive détaillée se télécharge séparément.

Le checkpoint ELA001 et ses preuves restent conservés. L’existence d’Elastik 3 natif ARM ne démontre pas la reprise des projets Elastik 1.
