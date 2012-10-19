#pragma once
#include "unmovable.h"
namespace Sokoban
{
	class Wall :
		public Unmovable
	{
	public:
		Wall(int x, int y, int z) : Unmovable(x,y,z) {}
		Type getType() {
			return WALL;
		}
	};
};

