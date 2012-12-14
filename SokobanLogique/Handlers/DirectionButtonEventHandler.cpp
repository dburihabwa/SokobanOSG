#include "DirectionButtonEventHandler.h"
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer\Viewer>
#include "../GUI/GUIButton.h"
#include "../GUI/View.h"

Sokoban::DirectionButtonEventHandler::DirectionButtonEventHandler(void)
{
}


Sokoban::DirectionButtonEventHandler::~DirectionButtonEventHandler(void)
{
}
bool Sokoban::DirectionButtonEventHandler::pick(const osgGA::GUIEventAdapter& ea) {
	osgUtil::LineSegmentIntersector* picker;
	picker = new osgUtil::LineSegmentIntersector( osgUtil::Intersector::WINDOW, ea.getX(),ea.getY() );

	osgUtil::IntersectionVisitor iv(picker);
	//We are only interested to get intersections in the buttonsCamera.
	Sokoban::View::getInstance()->getButtonsCamera()->accept(iv);

	if (picker->containsIntersections())
	{
		osgUtil::LineSegmentIntersector::Intersection intersection = picker->getFirstIntersection();
		//We used the UserData to add the GuiButton to the graphical object, with that no check to be made to know
		//which buttons has been clicked.
		osg::ref_ptr<GUIButton> button = dynamic_cast<GUIButton*>(intersection.nodePath.at(2)->getUserData());
		if(button) {
			return button->onClick();
		}
	}
	return false;

}