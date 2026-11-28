# ELA020 — du programme enregistré à l’échantillon

28 novembre 2026. Référence Elastik 1.5.2.3 i386, SHA-256 `5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920`.

Le résolveur natif reçoit le `ProgramState` issu d’ELA019. Il lit les références de chemin, d’identifiant de banque et de programme dans l’ordre des affectations. Pour la lecture directe de l’échantillon source, il consulte le cache, teste le chemin local et, en l’absence d’un fichier local, consulte le catalogue et construit le chemin absolu du membre GNFA. La fabrique de fichiers traduite ouvre ensuite le chemin obtenu. Le moteur peut distinguer un lien incomplet, une banque indisponible et un échec d’ouverture. [Source C++](../src/OriginalProgramSamples.h)

La routine i386 `0x15f48c` garde les ouvertures réussies dans un cache indexé par le chemin, y compris après une recherche dans une banque. Le port conserve cette clé et limite le cache à une session. Deux affectations de même chemin réutilisent la première ouverture de cette session, même si leurs identifiants de banque diffèrent. Un échec reste éligible à une nouvelle recherche. Le lecteur i386 renvoie l’échec quand un fichier local trouvé ne peut pas être ouvert. La fabrique de chemin `0xe1a68` exige un chemin commençant par `/`.

Le catalogue hôte fournit une banque utilisable selon les règles du moteur. La préparation de l’archive, les chemins système et la gestion de la durée de vie des lecteurs restent des liaisons hôte. Ce jalon porte sur l’échantillon source. Le pitch, l’étirement temporel et l’application des réglages de voix interviennent ensuite.

## Vérification

Le banc produit des états d’instance synthétiques avec l’écrivain i386, les relit via le chargeur i386 et exécute la recherche `0x15f48c`. Une VM distincte traite réellement le GNFA et les appels `0xe13de`, `0xe1a68`, `0xe3ff4` et `0xe4172`. Le port exécute le décodeur d’état, la recherche et le lecteur dans un même processus. Les décisions relatives aux fichiers physiques et au catalogue sont des fixtures. Les membres GNFA sont lus octet par octet par les routines d’archive puis transmis au lecteur WAVE natif.

Les **26 cas et 80 affectations** concordent sur Linux x86‑64, ARM64 sous QEMU, UBSan et ASan+UBSan. Le membre `/elastik/01drm120elastik_2.WAV` de la banque fournie par l’installateur restitue ses **176 399 trames** stéréo à 44,1 kHz, lues en mode partagé et en mode cloné. Les échantillons float32 des deux canaux correspondent à une conversion PCM16 indépendante. Les chemins synthétiques vérifient notamment les noms Unicode, la priorité du fichier local, les échecs, les nouvelles tentatives et la mise en cache. La suite de 40 états d’ELA019 repasse à l’identique. Un objet Mach‑O ARM64 a été compilé et vérifié. [Rapports ELA020](../evidence/ELA020)

Ghidra a produit les décompilations et désassemblages de 43 fonctions, dont 4 nouvelles. Le total sélectionné atteint 554. [Archive d’analyse](ELA020-original-sample-lookup-decompiled.zip)

## Reproduction

Depuis le dossier Elastik, avec le binaire i386 et la banque fournie dans l’installateur d’origine.

```sh
python3 scripts/build_planar_sum_probe.py --kind program-samples --output work/ProgramSamplesProbe
python3 scripts/compare_original_program_samples.py reference/Elastik.i386 work/ProgramSamplesProbe \
  --builtin /chemin/vers/Elastik.elastik --platform local --output work/program-samples.json
```

Le raccordement au catalogue de banques de macOS, l’application des paramètres au moteur ARM64 et le rappel dans Logic ou Live restent à réaliser. ELA020 est un checkpoint de développement sans Audio Unit installable.
