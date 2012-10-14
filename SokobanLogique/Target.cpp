#include "Target.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Target::~Target(void)
{
}
Geode* Sokoban::Target::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode.get();
}