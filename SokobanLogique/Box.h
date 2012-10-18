#pragma once
#include "movable.h"
namespace Sokoban
{
	class Box :
		public Movable
	{

	public:
		Box(size_t x, size_t y, size_t z) : Movable(x,y,z) {}
		Type getType() {
			return BOX;
		}
		bool canMove(Direction) const;
		bool move(Direction);
		~Box(void);
	};
};


