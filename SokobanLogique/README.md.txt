#	SOKOBAN
##	C++ / Principes de programmation graphique
###	AUTEURS : AFLALO Antoine & BURIHABWA Dorian

##	Pr�sentation
Ce programme pr�sente un jeu de type sokoban o� un joueur doit d�placer des boites afin de les placer sur des cibles.
Le joueur peut interagir avec le jeu par le biais du clavier mais �galement gr�ce aux boutons graphiques au bas de l'�cran.
Afin de faciliter le jeu une fonction de zoom est disponible dans le jeu (par la molette de la souris ou par les boutons graphiques)

Parmi les options propos�es au joueur, on trouve la sauvgarde du jeu et le rechargement du niveau en cours.

Le joueur peut �galement cr�er ses propres fichiers de niveaux (� placer dans le r�pertoire de Ressources/Levels/).

Ce jeu est toujours en cours de d�veloppement.

##	R�gles sommaires du jeu
*	1 joueur
*	Le nombre de pi�ces est �gal au nombre de cibles
*	Le plateau de jeu est bord� par des murs (immobiles)
*	Les cibles sont des objets immobiles
*	Le joueur peut se d�placer dans quatre directions : haut, bas, gauche, droite
*	Les boites peuvent �tre d�plac�es dans quatre directions : haut, bas, gauche, droite
*	Le joueur d�place les bo�tes en les poussant
*	Le joueur ne peut d�placer qu'une seule boite � la fois (2 bo�tes adjacentes ne peuvent pas �tre d�plac�es)
*	Le niveau est termin� lorsque toutes les bo�tes sont plac�es sur des cibles

##	D�pendances
*	OpenScenegraph 3.0.1