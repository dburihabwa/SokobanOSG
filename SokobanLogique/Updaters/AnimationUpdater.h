#pragma once
#include <osg/AnimationPath>
#include <osg/vec3>
#include "../Logic/Direction.h"

namespace Sokoban {
	class AnimationUpdater : public osg::AnimationPathCallback
	{
	public:
		AnimationUpdater(void);
		~AnimationUpdater(void);
		///<summary>Set the origin and the destination point for the animation</summary>
		virtual void setMovement(osg::Vec3, osg::Vec3, Direction);
	};
}
