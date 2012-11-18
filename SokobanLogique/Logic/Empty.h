#pragma once
#include "movable.h"
namespace Sokoban
{
	class Empty :
		public Movable
	{
	public:
		Empty(int x, int y, int z) : Movable(x, y, z) {}
		Type getType() {
			return EMPTY;
		}
		bool canMove(Direction) {
			return false;
		}
		void move(Direction) {
		}
	};
};

