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
		
		///	<summary>Checks whether the mouse pointer is hovergin over a button</summary>
		///	<param name = "ea">The GUIEventAdapter that caught the movement</param>
		///	<returns>Result of the test</returns>
		bool isHoveringAButton(const osgGA::GUIEventAdapter& ea);
		
		///	<summary>If the mouse is hovering a button, switches its visible geode to the alternate one.</summary>
		///	<param name = "ea">The GUIEventAdapter that caught the movement</param>
		///	<returns>True if the change has been made. False otherwise</returns>
		bool setButtonToAlternateGeode(const osgGA::GUIEventAdapter& ea);
		
		///	<summary>If the mouse has left a button, switches its visible geode to the primary one.</summary>
		///	<param name = "ea">The GUIEventAdapter that caught the movement</param>
		///	<returns>True if the change has been made. False otherwise</returns>
		bool setButtonToPrimaryGeode(const osgGA::GUIEventAdapter& ea);
	private:
		float _mx,_my;
		osg::ref_ptr<osg::Switch> hoveredSwitch;
	protected:
		virtual bool pick(const osgGA::GUIEventAdapter& ea) = 0;
	};
};

