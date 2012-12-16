#include "ScrollHandler.h"
#include <osgViewer\Viewer>
#include "../Commands/CommandHandler.h"
#include "../Commands/ZoomCommand.h"

Sokoban::ScrollHandler::ScrollHandler(void)
{
}


Sokoban::ScrollHandler::~ScrollHandler(void)
{
}

bool Sokoban::ScrollHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {

	osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
	if (!viewer) {
		return false;
	}
	switch(ea.getScrollingMotion())
	{
	case(osgGA::GUIEventAdapter::SCROLL_UP):
	case(osgGA::GUIEventAdapter::SCROLL_DOWN):
		return this->scrollHandle(ea.getScrollingMotion());
		break;
	default:
		return false;
	}

}
bool Sokoban::ScrollHandler::scrollHandle( osgGA::GUIEventAdapter::ScrollingMotion type) const {
	if(type == osgGA::GUIEventAdapter::SCROLL_DOWN) {
		CommandHandler::getInstance()->executeCommand(new ZoomCommand(1));
	} else if(type == osgGA::GUIEventAdapter::SCROLL_UP) {
		CommandHandler::getInstance()->executeCommand(new ZoomCommand(-1));
	}	
	return true;
}