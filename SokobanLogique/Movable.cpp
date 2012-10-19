#include "Movable.h"
#include "Direction.h"
#include "Constants.h"
Sokoban::Direction Sokoban::Movable::applyMove() {
	Direction tmp = nextMove;
	nextMove = NONE;
	return tmp;
}