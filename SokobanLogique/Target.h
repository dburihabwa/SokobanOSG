#pragma once
#include "unmovable.h"
namespace Sokoban
{
	class Target :
		public Unmovable
	{
	public:
		Target(int x, int y, int z) : Unmovable(x, y, z) {}
		Type getType() {
			return TARGET;
		}
	};
};