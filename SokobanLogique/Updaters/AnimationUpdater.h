#pragma once
#include <osg/AnimationPath>
#include <osg/vec3>
#include "../Logic/Direction.h"
using namespace osg;
namespace Sokoban {
	class AnimationUpdater : public AnimationPathCallback
	{
	public:
		AnimationUpdater(void);
		~AnimationUpdater(void);
		///<summary>Set the origin and the destination point for the animation</summary>
		virtual void setMovement(Vec3, Vec3, Direction);
	};
}
