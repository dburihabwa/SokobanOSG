#pragma once
#include "case.h"
#include "Direction.h"
#include "../Updaters/AnimationUpdater.h"
#include "../Adapters/MoveAdapter.h"
namespace Sokoban
{
	class Movable :
		public Case
	{
	public:
		Movable(int x, int y, int z) : Case(x,y,z) {}
		///<summary>Check if the Movable can or not move in the wanted direction.</summary>
		virtual bool canMove(Direction)=0;
		///<summary>Move the Movable in the wanted direction.</summary>
		virtual void move(Direction);
		void setMoveAdapter(osg::ref_ptr<MoveAdapter> adapter) {
			_moveAdapter = adapter;
		}
		virtual ~Movable(void)
		{
		}
	protected:
		///<summary>Wrapper for ref_ptr<Case> getCase(unsigned int, unsigned int) const; of Board</summary>
		ref_ptr<Case> getCase(Direction) const;
		ref_ptr<MoveAdapter> _moveAdapter;

	};
};

