#include "DirectionButtonEventHandler.h"
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer\Viewer>
#include "View.h"
using namespace osgUtil;


Sokoban::DirectionButtonEventHandler::~DirectionButtonEventHandler(void)
{
}

bool Sokoban::DirectionButtonEventHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {

	osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
	if (!viewer) {
		return false;
	}
	switch(ea.getEventType())
	{
	case(osgGA::GUIEventAdapter::PUSH):
	case(osgGA::GUIEventAdapter::MOVE):
		{
			_mx = ea.getX();
			_my = ea.getY();
			return false;
		}
	case(osgGA::GUIEventAdapter::RELEASE):
		{
			if (_mx == ea.getX() && _my == ea.getY())
			{
				// only do a pick if the mouse hasn't moved
				pick(ea);
			}
			return true;
		}    

	default:
		return false;
	}

}
void Sokoban::DirectionButtonEventHandler::pick(const osgGA::GUIEventAdapter& ea) {
	osgUtil::PolytopeIntersector* picker;
	double mx = ea.getXnormalized();
	double my = ea.getYnormalized();
	double w = 0.05;
	double h = 0.05;
	picker = new osgUtil::PolytopeIntersector( osgUtil::Intersector::PROJECTION, mx-w, my-h, mx+w, my+h );
	osgUtil::IntersectionVisitor iv(picker);

	Sokoban::View::getInstance().getButtonsCamera()->accept(iv);

	if (picker->containsIntersections())
	{
		osgUtil::PolytopeIntersector::Intersection intersection = picker->getFirstIntersection();
		ref_ptr<DirectionButton> button = dynamic_cast<DirectionButton*>(intersection.nodePath.at(2)->getUserData());
		if(button) {
			Board::getInstance().movePlayer(button->getDirection());
		}
	}

}