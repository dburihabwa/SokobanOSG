#include "PlayerPositionUpdater.h"
#include "Constants.h"
#include <osg/Geode>
#include <osg/Drawable>


void Sokoban::PlayerPositionUpdater::operator()(Node* node, NodeVisitor* nv) {
	MatrixTransform* mt = static_cast<MatrixTransform*>(node); // Particularise le Node à traiter
	Direction move = _player->applyMove();
	if(move == NONE) {
		traverse(node,nv);
		return;
	}
	//Normal Case, only add the movement to the current object.
	if(mt->getMatrix() == Matrix::translate(Vec3(_player->getX()-move.getX(),_player->getY()-move.getY(),_player->getZ())))
		mt->postMult(Matrix::translate(move.getVector()));
	//Reinit, happens when the player is moving too fast for the graphical engine and there is a desynchro
	//Between the logical place and the graphical place of the object.
	else
		mt->setMatrix(Matrix::translate(Vec3(_player->getX(),_player->getY(),_player->getZ())));
	traverse(node,nv);
}



Sokoban::PlayerPositionUpdater::~PlayerPositionUpdater(void) {
	_player.release();
}
