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
		virtual bool canMove(Direction)=0;
		virtual Direction applyMove();
		virtual void move(Direction);
		~Movable(void)
		{
		}
	protected:
		Direction _nextMove;
	};
};

