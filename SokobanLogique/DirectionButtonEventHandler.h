#pragma once
#include <list>

#include <osg/NodeCallback>
#include <osgGA/GUIEventHandler>

#include "Board.h"
#include "DirectionButton.h"

using namespace osgGA;
using namespace osg;

namespace Sokoban {
	class DirectionButtonEventHandler : public GUIEventHandler
	{
	public:
		DirectionButtonEventHandler(void): _mx(0.0),_my(0.0) {};
		~DirectionButtonEventHandler(void);
		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	private:
		float _mx,_my;
		void pick(const osgGA::GUIEventAdapter& ea);
	};
};

