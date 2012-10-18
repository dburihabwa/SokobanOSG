#pragma once
#include "Unmovable.h"
namespace Sokoban
{
	class Ground :
		public Unmovable
	{
	public:
		Ground(size_t x, size_t y, size_t z) : Unmovable(x, y, z) {}
		Type getType() {
			return GROUND;
		}
	};
};

