#include "BoxPositionUpdater.h"
#include "Direction.h"
#include "Constants.h"

void Sokoban::BoxPositionUpdater::operator()(Node* node, NodeVisitor* nv) {
	MatrixTransform* mt = static_cast<MatrixTransform*>(node); // Particularise le Node à traiter
	Direction move = _box->applyMove();
	if(move == NONE) {
		traverse(node,nv);
		return;
	}
	// Modifie la matrice de model-view du Node
	mt->postMult(Matrix::translate(move.getVector()));

	traverse(node,nv);
}

Sokoban::BoxPositionUpdater::~BoxPositionUpdater(void) {
	_box.release();
}
