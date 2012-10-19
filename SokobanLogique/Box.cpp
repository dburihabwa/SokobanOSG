#include "Box.h"
#include "Direction.h"
using namespace osg;

Sokoban::Box::~Box(void)
{
}

bool Sokoban::Box::canMove(Direction dir) const {
	return false;
}