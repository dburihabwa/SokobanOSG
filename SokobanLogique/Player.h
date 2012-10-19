#pragma once
#include "movable.h"
#include "Box.h"
namespace Sokoban
{
	class Player :
		public Movable
	{
	public:
		Player(int x, int y, int z) : Movable(x,y,z), _canMoveBox(false) {}
		Type getType() {
			return PLAYER;
		}
		ref_ptr<Node> createNode();
		bool canMove(Direction);
		void move(Direction);
		~Player(void);
	private:
		ref_ptr<Box> _lastBox;
		bool _canMoveBox;
	};
};

