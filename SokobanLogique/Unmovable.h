#pragma once
#include "case.h"
namespace Sokoban
{
	class Unmovable :
		public Case
	{
	public:
		Unmovable(size_t x, size_t y, size_t z) : Case(x,y,z) {}
	};
};

