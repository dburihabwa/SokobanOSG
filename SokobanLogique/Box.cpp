#include "Box.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Box::~Box(void)
{
}
ref_ptr<Geode> Sokoban::Box::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode;
}
bool Sokoban::Box::canMove(Direction dir) const {
	return false;
}
bool Sokoban::Box::move(Direction dir) {
	return false;
}