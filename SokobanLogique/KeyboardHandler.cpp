#include "KeyboardHandler.h"
#include <osgGA/GUIEventAdapter>
#include <osgViewer/Viewer>
#include "Board.h"
#include "Direction.h"


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
	case osgGA::GUIEventAdapter::KEYDOWN: // Enfoncement d'une touche
		switch(ea.getKey()){
		case osgGA::GUIEventAdapter::KEY_Right : // flêche vers la droite
			Board::getInstance().movePlayer(RIGHT);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_Left : // flêche vers la gauche
			Board::getInstance().movePlayer(LEFT);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_Down : // flêche vers le bas
			Board::getInstance().movePlayer(DOWN);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_Up : // flêche vers le haut
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
