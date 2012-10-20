#include "PlayerPositionUpdater.h"
#include "Constants.h"


void Sokoban::PlayerPositionUpdater::operator()(Node* node, NodeVisitor* nv) {
	MatrixTransform* mt = static_cast<MatrixTransform*>(node); // Particularise le Node à traiter
	Direction move = _player->applyMove();
	if(move == NONE) {
		traverse(node,nv);
		return;
	}
	mt->setMatrix(Matrix::translate(Vec3(_player->getX(),_player->getY(),_player->getZ()))); // réinitialisation
	// Modifie la matrice de model-view du Node
	mt->postMult(Matrix::rotate(ROTATION));
	traverse(node,nv);
}



Sokoban::PlayerPositionUpdater::~PlayerPositionUpdater(void) {
	_player.release();
}
