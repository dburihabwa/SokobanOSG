#include "Box.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Box::~Box(void)
{
}
Geode* Sokoban::Box::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode.get();
}
bool Sokoban::Box::canMove(Direction dir) const {
	return false;
}
bool Sokoban::Box::move(Direction dir) {
	return false;
}