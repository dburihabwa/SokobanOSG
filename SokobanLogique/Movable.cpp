#include "Movable.h"
#include "Direction.h"
#include "Constants.h"
Sokoban::Direction Sokoban::Movable::applyMove() {
	Direction tmp = _nextMove;
	_nextMove = NONE;
	return tmp;
}