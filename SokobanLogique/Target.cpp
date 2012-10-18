#include "Target.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Target::~Target(void)
{
}
ref_ptr<Node> Sokoban::Target::createNode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode;
}