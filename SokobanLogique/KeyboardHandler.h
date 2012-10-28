#pragma once
#include <osg/NodeCallback>
#include <osgGA/GUIEventHandler>
using namespace osg;
namespace Sokoban
{
	class KeyboardHandler  : public osgGA::GUIEventHandler
	{
	public:
		KeyboardHandler(void);
		///<summary> Coming from the GUIEventHandler to handle an event</summary>
		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
		~KeyboardHandler(void);
	};
}

