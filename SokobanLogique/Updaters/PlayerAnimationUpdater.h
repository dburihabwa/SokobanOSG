#pragma once
#include "AnimationUpdater.h"
#include "../Logic/Direction.h"
#include <osg/Quat>
namespace Sokoban {
	class PlayerAnimationUpdater : public AnimationUpdater
	{
	public:
		PlayerAnimationUpdater(void): _lastRot(0,osg::Z_AXIS) {}
		~PlayerAnimationUpdater(void);
		void setMovement(osg::Vec3, osg::Vec3, Direction);
	private:
		osg::Quat _lastRot;
	};
}

