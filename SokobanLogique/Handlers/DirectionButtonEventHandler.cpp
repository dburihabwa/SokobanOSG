#include "DirectionButtonEventHandler.h"
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer\Viewer>
#include "../GUI/View.h"
#include "../GUI/DirectionButton.h"
#include "../Logic/Board.h"
#include "../GUI/SaveButton.h"

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
	Sokoban::View::getInstance().getButtonsCamera()->accept(iv);

	if (picker->containsIntersections())
	{
		osgUtil::LineSegmentIntersector::Intersection intersection = picker->getFirstIntersection();
		//We used the UserData to add the DirectionButton to the graphical object, with that no check to be made to know
		//which buttons has been clicked.
		ref_ptr<DirectionButton> button = dynamic_cast<DirectionButton*>(intersection.nodePath.at(2)->getUserData());
		if(button) {
			Board::getInstance().movePlayer(button->getDirection());
			return true;
		}
		ref_ptr<SaveButton> saveButton = dynamic_cast<SaveButton*>(intersection.nodePath.at(2)->getUserData());
		if (saveButton) {
			Board::getInstance().save();
			return true;
		}
	}
	return false;

}