#pragma once
#include "MoveAdapter.h"
#include "../Updaters/AnimationUpdater.h"
namespace Sokoban {
	class OSGMoveAdapter : public MoveAdapter
	{
	public:
		OSGMoveAdapter(osg::ref_ptr<AnimationUpdater> ani) : _aniUpdater(ani) {}
		void move(osg::Vec3 from,osg::Vec3 to,Direction dir) {
			_aniUpdater->setMovement(from,to,dir);
		}
		~OSGMoveAdapter(void) {}
	private:
		osg::ref_ptr<AnimationUpdater> _aniUpdater;
	};
}

