#pragma once
#include <osgGA/GUIEventHandler>
#include "../GUI/GUIButton.h"

namespace Sokoban {
	class MouseHandler : public osgGA::GUIEventHandler
	{
	public:
		MouseHandler(void): _mx(0.0),_my(0.0) {};
		~MouseHandler(void);
		///<summary> Coming from the GUIEventHandler to handle an event</summary>
		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
		bool setButtonToAlternateGeode(const osgGA::GUIEventAdapter& ea);
		bool setButtonToPrimaryGeode(const osgGA::GUIEventAdapter& ea);
	private:
		float _mx,_my;
		osg::ref_ptr<osg::Switch> hoveredSwitch;
	protected:
		virtual bool pick(const osgGA::GUIEventAdapter& ea) = 0;
	};
};

