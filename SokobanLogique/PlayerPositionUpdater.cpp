#include "PlayerPositionUpdater.h"
#include "Constants.h"


void Sokoban::PlayerPositionUpdater::operator()(Node* node, NodeVisitor* nv) {
	MatrixTransform* mt = static_cast<MatrixTransform*>(node); // Particularise le Node � traiter
	Direction move = _player->applyMove();
	if(move == NONE) {
		traverse(node,nv);
		return;
	}
	// Modifie la matrice de model-view du Node
	mt->setMatrix(Matrix::identity()); // r�initialisation
	Vec3 moveVec = ROTATION* Vec3(move.getX(),move.getY(),0);
	mt->postMult(Matrix::translate(moveVec));
	traverse(node,nv);
}



Sokoban::PlayerPositionUpdater::~PlayerPositionUpdater(void) {
}
