#include "Box.h"

Sokoban::Box::~Box(void)
{
}

bool Sokoban::Box::canMove(Direction dir) {
	osg::ref_ptr<Case> lvlCase = getCase(dir);
	if(lvlCase->getType() == WALL || lvlCase->getType() == BOX || lvlCase->getType() == PLAYER)
		return false;
	if(lvlCase->getType() == TARGET)
		_willBeOnTarget = true;
	return true;
}


void Sokoban::Box::move(Direction dir) {
	Movable::move(dir);
	_onTarget = _willBeOnTarget;
	_willBeOnTarget=false;
}