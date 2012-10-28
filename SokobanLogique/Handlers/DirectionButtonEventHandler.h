#pragma once
#include "MouseHandler.h"
namespace Sokoban {
	class DirectionButtonEventHandler : public MouseHandler
	{
	public:
		DirectionButtonEventHandler(void);
		~DirectionButtonEventHandler(void);
	protected:
		bool pick(const osgGA::GUIEventAdapter& ea);
	};

}