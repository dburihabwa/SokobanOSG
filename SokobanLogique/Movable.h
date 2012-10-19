#pragma once
#include "case.h"
#include "Direction.h"
namespace Sokoban
{
	class Movable :
		public Case
	{
	public:
		Movable(size_t x, size_t y, size_t z) : Case(x,y,z) {}
		virtual bool canMove(Direction) const=0;
		virtual Direction applyMove();
		virtual bool move(Direction)=0;
		~Movable(void)
		{
		}
	protected:
		Direction nextMove;
	};
};

