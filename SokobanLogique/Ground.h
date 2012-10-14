#pragma once
#include "unmovable.h"
#include <osg/Geode>
using namespace osg;
class Ground :
	public Unmovable
{
public:
	Ground(size_t x, size_t y, size_t z) : Unmovable(x, y, z) {}
	Geode* createGeode();
	~Ground(void);
private:
	Ground(void);
};

