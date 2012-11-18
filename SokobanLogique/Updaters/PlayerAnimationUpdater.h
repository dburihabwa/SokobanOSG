#pragma once
#include "AnimationUpdater.h"
#include "../Logic/Direction.h"
#include <osg/Quat>
namespace Sokoban {
	class PlayerAnimationUpdater : public AnimationUpdater
	{
	public:
		PlayerAnimationUpdater(void): _nextDir(NONE),_lastRot(0,Z_AXIS) {}
		~PlayerAnimationUpdater(void);
		void setMovement(Vec3, Vec3, Direction);
	private:
		Quat _lastRot;
	};
}

