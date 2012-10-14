#include "Ground.h"
Ground::~Ground(void)
{
}
Geode* Ground::createGeode()
{
	ref_ptr<Geode> geode = new Geode;
	return geode.get();
}

