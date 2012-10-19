#include "BoxPositionUpdater.h"
#include "Direction.h"
#include "Constants.h"

void Sokoban::BoxPositionUpdater::operator()(Node* node, NodeVisitor* nv) {
	MatrixTransform* mt = static_cast<MatrixTransform*>(node); // Particularise le Node � traiter
	Direction move = _box->applyMove();
	if(move == NONE) {
		traverse(node,nv);
		return;
	}
	// Modifie la matrice de model-view du Node
	Vec3 moveVec = ROTATION * Vec3(move.getX(),move.getY(),0);
	mt->postMult(Matrix::translate(moveVec));

	traverse(node,nv);
}

Sokoban::BoxPositionUpdater::~BoxPositionUpdater(void) {
	_box.release();
}
