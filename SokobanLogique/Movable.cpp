#include "Movable.h"
#include "Direction.h"
#include "Constants.h"
#include "Board.h"
Sokoban::Direction Sokoban::Movable::applyMove() {
	Direction tmp = _nextMove;
	_nextMove = NONE;
	return tmp;
}
void Sokoban::Movable::move(Direction dir) {
	_nextMove = dir;
	int newX = _x-dir.getX();
	int newY = _y-dir.getY();
	Board::getInstance().swapMovable(_x,_y,newX,newY);
	this->_x -= newX;
	this->_y -= newY;
	
}