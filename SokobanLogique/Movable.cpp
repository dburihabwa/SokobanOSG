#include "Movable.h"
#include "Direction.h"
#include "Constants.h"
Sokoban::Direction Sokoban::Movable::applyMove() {
	Direction tmp = _nextMove;
	_nextMove = NONE;
	return tmp;
}
void Sokoban::Movable::move(Direction dir) {
	_nextMove = dir;
	this->_x -= dir.getX();
	this->_y -= dir.getY();
}