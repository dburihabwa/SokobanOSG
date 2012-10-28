#pragma once
#include <list>

#include <osg/NodeCallback>
#include <osgGA/GUIEventHandler>

#include "Board.h"
#include "DirectionButton.h"


namespace Sokoban {
	class MouseHandler : public osgGA::GUIEventHandler
	{
	public:
		MouseHandler(void): _mx(0.0),_my(0.0) {};
		~MouseHandler(void);
		///<summary> Coming from the GUIEventHandler to handle an event</summary>
		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	private:
		float _mx,_my;
	protected:
		virtual bool pick(const osgGA::GUIEventAdapter& ea) =0;
	};
};

