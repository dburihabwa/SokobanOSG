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
		///<summary> Check if the player will move a box when move(Direction) is called.</summaray>
		bool willMoveBox() const{
			return _canMoveBox;
		}
		ref_ptr<Box> movedBox() const {
			return _lastBox;
		}
		~Player(void);
	private:
		ref_ptr<Box> _lastBox;
		bool _canMoveBox;
	};
};

