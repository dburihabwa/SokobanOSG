#pragma once
#include "case.h"
namespace Sokoban
{
	class Unmovable :
		public Case
	{
	public:
		Unmovable(int x, int y, int z) : Case(x,y,z) {}
		virtual ~Unmovable() {}
	};
};

