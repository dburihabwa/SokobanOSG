#pragma once
#include "movable.h"
namespace Sokoban
{
	class Player :
		public Movable
	{
	public:
		Player(size_t x, size_t y, size_t z) : Movable(x,y,z) {}
		Type getType() {
			return PLAYER;
		}
		bool canMove(Direction) const;
		bool move(Direction);
		~Player(void);
	};
};

