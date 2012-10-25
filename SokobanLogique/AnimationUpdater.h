#pragma once
#include <osg/AnimationPath>
#include <osg/vec3>
#include "Direction.h"
using namespace osg;
namespace Sokoban {
	class AnimationUpdater : public AnimationPathCallback
	{
	public:
		AnimationUpdater(Vec3, Direction);
		~AnimationUpdater(void);
	};
}
