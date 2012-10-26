#pragma once
#include "case.h"
#include "Direction.h"
#include "AnimationUpdater.h"
namespace Sokoban
{
	class Movable :
		public Case
	{
	public:
		Movable(int x, int y, int z) : Case(x,y,z) {}
		virtual bool canMove(Direction)=0;
		virtual void move(Direction);
		virtual ref_ptr<Node> createNode();
		virtual ~Movable(void)
		{
			_graphNode.release();
			_aniUpdater.release();
		}
	protected:
		///<summary>Wrapper for ref_ptr<Case> getCase(unsigned int, unsigned int) const; of Board</summary>
		ref_ptr<Case> getCase(Direction) const;
		ref_ptr<Node> _graphNode;
		ref_ptr<AnimationUpdater> _aniUpdater;
	};
};

