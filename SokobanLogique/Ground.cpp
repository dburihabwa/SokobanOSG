#include "Ground.h"
#include <osg/Geode>
using namespace osg;
Sokoban::Ground::~Ground(void)
{
}
Geode* Sokoban::Ground::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode.get();
}

