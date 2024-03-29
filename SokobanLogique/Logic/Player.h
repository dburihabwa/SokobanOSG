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
		bool canMove(Direction);
		void move(Direction);
		///<summary> Check if the player will move a box when move(Direction) is called.</summaray>
		bool willMoveBox() const{
			return _canMoveBox;
		}
		///<summary>Get the box that will be moved.</summary>
		osg::ref_ptr<Box> getMovedBox() const {
			return _lastBox;
		}
		osg::ref_ptr<osg::Node> createNode();
		~Player(void);
	private:
		osg::ref_ptr<Box> _lastBox;
		bool _canMoveBox;
	};
};

