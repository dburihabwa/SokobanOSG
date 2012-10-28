#include "Movable.h"
#include "Board.h"
void Sokoban::Movable::move(Direction dir) {
	int newX = _x+dir.getX();
	int newY = _y+dir.getY();
	Board::getInstance().swapMovable(_x,_y,newX,newY);
	_aniUpdater->setMovement(getPosition(),Vec3(newX,newY,0));
	this->_x = newX;
	this->_y = newY;
}

ref_ptr<Sokoban::Case> Sokoban::Movable::getCase(Direction dir) const {
	return Board::getInstance().getCase(this->_x+dir.getX(),this->_y+dir.getY());
}
ref_ptr<Node> Sokoban::Movable::createNode() {
	_graphNode = Case::createNode();
	_aniUpdater = new AnimationUpdater();
	_graphNode->setUpdateCallback(_aniUpdater);
	return _graphNode;
}