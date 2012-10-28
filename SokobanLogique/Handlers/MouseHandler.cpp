#include "MouseHandler.h"
#include <osgViewer\Viewer>


Sokoban::MouseHandler::~MouseHandler(void)
{
}

bool Sokoban::MouseHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {

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
			if (_mx == ea.getX() && _my == ea.getY()) {
				// only do a pick if the mouse hasn't moved
				return pick(ea);
			}
		}    

	default:
		return false;
	}

}