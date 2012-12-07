#include "Box.h"
#include "Target.h"
#include "Ground.h"

Sokoban::Box::~Box(void)
{
}

bool Sokoban::Box::canMove(Direction dir) {
	osg::ref_ptr<Case> lvlCase = getCase(dir);
	if(dynamic_cast<Target*>(lvlCase.get())) {
		_willBeOnTarget = true;
		return true;
	}
	if(dynamic_cast<Ground *> (lvlCase.get()))
		return true;	
	return false;
}


void Sokoban::Box::move(Direction dir) {
	Movable::move(dir);
	_onTarget = _willBeOnTarget;
	_willBeOnTarget=false;
}