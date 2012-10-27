#pragma once
#include <osg/NodeCallback>
#include <osgGA/GUIEventHandler>
using namespace osg;
namespace Sokoban
{
	class EventController  : public osgGA::GUIEventHandler
	{
	public:
		EventController(void);
		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
		~EventController(void);
	};
}

