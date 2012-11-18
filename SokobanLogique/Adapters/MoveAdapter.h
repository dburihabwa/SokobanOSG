#pragma once
#include <osg/Vec3>
#include "../Logic/Direction.h"
#include <osg/Referenced>
namespace Sokoban {
	class MoveAdapter : public osg::Referenced
	{
	public:

		MoveAdapter(void)
		{
		}

		virtual void move(osg::Vec3, osg::Vec3, Direction) const = 0;

		virtual ~MoveAdapter(void)
		{
		}
	};
}

