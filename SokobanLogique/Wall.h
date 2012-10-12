#pragma once
#include "unmovable.h"
class Wall :
	public Unmovable
{
public:
	Wall(size_t x, size_t y, size_t z) : Unmovable::Unmovable(x,y,z) {}
	~Wall(void);
private:
		Wall(void);
};

