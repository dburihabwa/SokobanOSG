#include "Target.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Target::~Target(void)
{
}
ref_ptr<Geode> Sokoban::Target::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode;
}