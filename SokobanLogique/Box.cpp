#include "Box.h"
#include "Direction.h"
#include "Board.h"
#include "BoxPositionUpdater.h"
using namespace osg;

Sokoban::Box::~Box(void)
{
}

bool Sokoban::Box::canMove(Direction dir) {
	ref_ptr<Case> lvlCase = getCase(dir);
	if(lvlCase->getType() == WALL || lvlCase->getType() == BOX || lvlCase->getType() == PLAYER)
		return false;
	if(lvlCase->getType() == TARGET)
		_willBeOnTarget = true;
	return true;
}

ref_ptr<Node> Sokoban::Box::createNode() {
	ref_ptr<Node> matrix = Case::createNode();
	ref_ptr<NodeCallback> posUpdater = new BoxPositionUpdater(ref_ptr<Box>(this));
	matrix->setUpdateCallback(posUpdater);
	return matrix;
}

void Sokoban::Box::move(Direction dir) {
	Movable::move(dir);
	_onTarget = _willBeOnTarget;
	_willBeOnTarget=false;
}