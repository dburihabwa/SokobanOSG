#pragma once
#include <osg/AnimationPath>
#include <osg/vec3>
#include "Direction.h"
using namespace osg;
namespace Sokoban {
	class AnimationUpdater : public AnimationPathCallback
	{
	public:
		AnimationUpdater(void);
		~AnimationUpdater(void);
		void setMovement(Vec3, Vec3);
	};
}
