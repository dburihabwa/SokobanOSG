#pragma once
#include "case.h"
#include "Direction.h"
namespace Sokoban
{
	class Movable :
		public Case
	{
	public:
		Movable(int x, int y, int z) : Case(x,y,z) {}
		virtual bool canMove(Direction) const=0;
		virtual Direction applyMove();
		virtual bool move(Direction)=0;
		~Movable(void)
		{
		}
	protected:
		Direction _nextMove;
	};
};

