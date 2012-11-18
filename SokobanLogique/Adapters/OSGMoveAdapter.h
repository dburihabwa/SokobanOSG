#pragma once
#include "MoveAdapter.h"
namespace Sokoban {
	class OSGMoveAdapter : public MoveAdapter
	{
	public:
		OSGMoveAdapter(void);
		void move(osg::Vec3,osg::Vec3,Direction);
		~OSGMoveAdapter(void);
	};
}

