#include "PlayerPositionUpdater.h"
#include "Constants.h"


void Sokoban::PlayerPositionUpdater::operator()(Node* node, NodeVisitor* nv) {
	MatrixTransform* mt = static_cast<MatrixTransform*>(node); // Particularise le Node à traiter
	Direction move = _player->applyMove();
	if(move == NONE) {
		traverse(node,nv);
		return;
	}
	// Modifie la matrice de model-view du Node
	Vec3 moveVec = ROTATION * Vec3(move.getX(),move.getY(),0);
	mt->postMult(Matrix::translate(moveVec));
	//Save the last applied move
	//used to define the rotation to have the face were we want.
	//TODO : Rotation of the face
	_lastAppliedMove = move;
	traverse(node,nv);
}



Sokoban::PlayerPositionUpdater::~PlayerPositionUpdater(void) {
	_player.release();
}
