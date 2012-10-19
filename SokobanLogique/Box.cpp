#include "Box.h"
#include "Direction.h"
#include "Board.h"
using namespace osg;

Sokoban::Box::~Box(void)
{
}

bool Sokoban::Box::canMove(Direction dir) {
	ref_ptr<Case> lvlCase = Sokoban::Board::getInstance().getCase(this->_x-dir.getX(),this->_y-dir.getY());
	if(lvlCase->getType() == WALL || lvlCase->getType() == BOX || lvlCase->getType() == PLAYER)
		return false;
	return true;
}