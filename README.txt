groupe 4 - bataille navale
LEFEBVRE Tristan
HAJEK Simon

L2 Informatique 2015 Université de Lorraine - Faculté de Science.
Rendu 19 novembre.

--------------------------------------------------------------------------------------


Jeu de bataille navale en C++ avec SFML, opposant un joueur à une IA réglable, et utilisant un fichier txt pour gérer le placement des bateaux.

Pour placer ses bateaux, il suffit de modifier le fichier config.txt.
Le fichier contient un tableau de caractère, representant le plateau de jeu de dimension 10*10, pouvant être remplie avec :
    0 : case vide.
    1 : un rocher.
    ^ : case du haut d'un bateau vertical (1 par bateau)
    | : case du milieu d'un bateau vertical ( 0 ou plus par bateau)
    v : case du bas d'un bateau vertical (0 par bateau)
    < : case de gauche d'un  bateau horizontal (1 par bateau)
    = : case du milieu d'un bateau horizontal (0 ou plus par bateau)
    > : case de droite d'un bateau horizontal (1 par bateau)
Quelque soit le nombre de bateau, ainsi que le nombre de rocher, l'ordinateur aura le même nombre, afin de ne pas créer d'inégalité.

Lors du lancement d'une partie le Joueur peut lancer directement le jeu, ou choisir la difficulté de l'ordinateur :
    *facile : l'ordinateur tape au hazard dans le plateau tout le long de la partie
    *moyen : l'ordinateur se comporte comme un humain mais peux commetre des erreurs
    *difficile : l'ordinateur est invincible et ne commet aucune erreur

Une fois la difficulté choisie et la partie démarré, le joueur se sert de la souris pour cliquer sur le plateau ennemis pour trouver/chercher ses bateaux. Si le joueur ou l'ordinateur tombe sur un rocher, il ne jouera pas au prochain tour.

Le premier à avoir éliminé tous les bateaux de l'adversaire gagne la partie.
