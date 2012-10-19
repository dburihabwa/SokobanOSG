#pragma once
#include "Unmovable.h"
namespace Sokoban
{
	class Ground :
		public Unmovable
	{
	public:
		Ground(int x, int y, int z) : Unmovable(x, y, z) {}
		Type getType() {
			return GROUND;
		}
	};
};

