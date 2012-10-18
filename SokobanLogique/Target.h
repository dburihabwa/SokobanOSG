#pragma once
#include "unmovable.h"
namespace Sokoban
{
	class Target :
		public Unmovable
	{
	public:
		Target(size_t x, size_t y, size_t z) : Unmovable(x, y, z) {}
		Type getType() {
			return TARGET;
		}
	};
};