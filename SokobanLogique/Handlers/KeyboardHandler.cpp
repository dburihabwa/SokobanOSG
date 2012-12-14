#include "KeyboardHandler.h"
#include <osgGA/GUIEventAdapter>
#include <osgViewer/Viewer>
#include "../Logic/Board.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/ReloadCommand.h"
#include "../Commands/LoadCommand.h"
#include "../Commands/SaveCommand.h"
#include "../Commands/LoadNextLevelCommand.h"

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
		case osgGA::GUIEventAdapter::KEY_Right : // fl�che vers la droite
			Board::getInstance().movePlayer(RIGHT);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_Left : // fl�che vers la gauche
			Board::getInstance().movePlayer(LEFT);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_Down : // fl�che vers le bas
			Board::getInstance().movePlayer(DOWN);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_Up : // fl�che vers le haut
			Board::getInstance().movePlayer(UP);
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_N: //touche N
			CommandHandler::getInstance().executeCommand(new LoadNextLevelCommand());
			return true;
			break;
		case osgGA::GUIEventAdapter::KEY_R: //touche R
			CommandHandler::getInstance().executeCommand(new ReloadCommand());
			break;
		case osgGA::GUIEventAdapter::KEY_S: //touche S
			CommandHandler::getInstance().executeCommand(new SaveCommand());
			break;
		case osgGA::GUIEventAdapter::KEY_L: //touche L
			CommandHandler::getInstance().executeCommand(new LoadCommand());
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
