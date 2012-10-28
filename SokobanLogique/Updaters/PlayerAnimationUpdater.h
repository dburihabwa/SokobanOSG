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
		void setMovement(Vec3, Vec3);
		void setDirection(Direction dir) {
			_nextDir = dir;
		}
	private:
		Direction _nextDir;
		Quat _lastRot;
	};
}

