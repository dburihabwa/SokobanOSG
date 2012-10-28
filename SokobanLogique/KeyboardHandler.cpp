#include "KeyboardHandler.h"
#include <osgGA/GUIEventAdapter>
#include <osgViewer/Viewer>
#include "Board.h"
#include "Direction.h"

using namespace osg;
using namespace osgGA;

Sokoban::KeyboardHandler::KeyboardHandler(void)
{
}

bool Sokoban::KeyboardHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {

	osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
	if (!viewer) {
		return false;
	}
	switch(ea.getEventType())
	{
	case GUIEventAdapter::KEYDOWN: // Enfoncement d'une touche
		switch(ea.getKey()){
		case GUIEventAdapter::KEY_Right : // fl�che vers la droite
			Board::getInstance().movePlayer(RIGHT);
			return true;
			break;
		case GUIEventAdapter::KEY_Left : // fl�che vers la gauche
			Board::getInstance().movePlayer(LEFT);
			return true;
			break;
		case GUIEventAdapter::KEY_Down : // fl�che vers le bas
			Board::getInstance().movePlayer(DOWN);
			return true;
			break;
		case GUIEventAdapter::KEY_Up : // fl�che vers le haut
			Board::getInstance().movePlayer(UP);
			return true;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return false;
}


Sokoban::KeyboardHandler::~KeyboardHandler(void)
{
}
