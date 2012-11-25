#	SOKOBAN
##	C++ / Principes de programmation graphique
###	AUTEURS : AFLALO Antoine & BURIHABWA Dorian

##	Présentation
Ce programme présente un jeu de type sokoban où un joueur doit déplacer des boites afin de les placer sur des cibles.
Le joueur peut interagir avec le jeu par le biais du clavier mais également grâce aux boutons graphiques au bas de l'écran.
Afin de faciliter le jeu une fonction de zoom est disponible dans le jeu (par la molette de la souris ou par les boutons graphiques)

Parmi les options proposées au joueur, on trouve la sauvgarde du jeu et le rechargement du niveau en cours.

Le joueur peut également créer ses propres fichiers de niveaux (à placer dans le répertoire de Ressources/Levels/).

Ce jeu est toujours en cours de développement.

##	Règles sommaires du jeu
*	1 joueur
*	Le nombre de pièces est égal au nombre de cibles
*	Le plateau de jeu est bordé par des murs (immobiles)
*	Les cibles sont des objets immobiles
*	Le joueur peut se déplacer dans quatre directions : haut, bas, gauche, droite
*	Les boites peuvent être déplacées dans quatre directions : haut, bas, gauche, droite
*	Le joueur déplace les boîtes en les poussant
*	Le joueur ne peut déplacer qu'une seule boite à la fois (2 boîtes adjacentes ne peuvent pas être déplacées)
*	Le niveau est terminé lorsque toutes les boîtes sont placées sur des cibles

##	Dépendances
*	OpenScenegraph 3.0.1