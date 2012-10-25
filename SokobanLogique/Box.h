#pragma once
#include "movable.h"
namespace Sokoban
{
	class Box :
		public Movable
	{

	public:
		Box(int x, int y, int z) : Movable(x,y,z), _onTarget(false), _willBeOnTarget(false) {}
		Type getType() {
			return BOX;
		}
		bool canMove(Direction);
		void move(Direction);
		~Box(void);
		bool isOnTarget() const {
			return _onTarget;
		}
	private:
		bool _onTarget;
		bool _willBeOnTarget;
	};
};


