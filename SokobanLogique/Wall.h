#pragma once
#include "unmovable.h"
namespace Sokoban
{
	class Wall :
		public Unmovable
	{
	public:
		Wall(size_t x, size_t y, size_t z) : Unmovable(x,y,z) {}
		ref_ptr<Geode> createGeode();
		~Wall(void);
	};
};

