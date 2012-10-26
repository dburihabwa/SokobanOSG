#include "EventController.h"
#include <osgGA/GUIEventAdapter>
#include <osgGA/EventVisitor>
#include "Board.h"
#include "Direction.h"

using namespace osg;
using namespace osgGA;

Sokoban::EventController::EventController(void)
{
}

void Sokoban::EventController::operator()(Node* node, NodeVisitor* nv)
{
	//La classe osgGA::GUIEventAdapter g�re tous les types d'�v�nemens  qui peuvent survenir
	std::list<ref_ptr<GUIEventAdapter>> events; // Structure de type liste (librairie standard)
	EventVisitor* ev = dynamic_cast<EventVisitor*>(nv); // Particularise le "visiteur" de noeuds
	if(ev) {
		events = ev->getEvents(); // R�cup�re les "�v�nements" dans la liste
		ref_ptr<GUIEventAdapter> ea = events.back(); // R�cup�re le dernier �l�ment de la liste
		events.pop_back(); // Supprime l'�l�ment r�cup�r� de la liste
		switch(ea->getEventType())
		{
		case GUIEventAdapter::KEYDOWN: // Enfoncement d'une touche
			switch(ea->getKey()){
			case GUIEventAdapter::KEY_Right : // fl�che vers la droite
				Board::getInstance().movePlayer(RIGHT);
				break;
			case GUIEventAdapter::KEY_Left : // fl�che vers la gauche
				Board::getInstance().movePlayer(LEFT);
				break;
			case GUIEventAdapter::KEY_Down : // fl�che vers la gauche
				Board::getInstance().movePlayer(DOWN);
				break;
			case GUIEventAdapter::KEY_Up : // fl�che vers la gauche
				Board::getInstance().movePlayer(UP);
				break;
            case GUIEventAdapter::LEFT_MOUSE_BUTTON:
                break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	traverse(node,nv);
}

Sokoban::EventController::~EventController(void)
{
}
