#pragma once
#include <osgGA/GUIEventHandler>
#include <osgGA/GUIEventAdapter>

namespace Sokoban {
	class ScrollHandler : public osgGA::GUIEventHandler
	{
	public:
		ScrollHandler(void);
		///<summary> Coming from the GUIEventHandler to handle an event</summary>
		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
		~ScrollHandler(void);
	private:
		bool scrollHandle(osgGA::GUIEventAdapter::ScrollingMotion) const;
	};
}

