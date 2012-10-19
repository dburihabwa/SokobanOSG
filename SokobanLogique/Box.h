#pragma once
#include "movable.h"
namespace Sokoban
{
	class Box :
		public Movable
	{

	public:
		Box(int x, int y, int z) : Movable(x,y,z) {}
		Type getType() {
			return BOX;
		}
		bool canMove(Direction) const;
		bool move(Direction);
		~Box(void);
	};
};


