#include "Wall.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Wall::~Wall(void)
{
}
Geode* Sokoban::Wall::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode.get();
}