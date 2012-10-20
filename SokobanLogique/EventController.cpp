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
	//La classe osgGA::GUIEventAdapter gère tous les types d'évènemens  qui peuvent survenir
	std::list<ref_ptr<GUIEventAdapter>> events; // Structure de type liste (librairie standard)
	EventVisitor* ev = dynamic_cast<EventVisitor*>(nv); // Particularise le "visiteur" de noeuds
	if(ev) {
		events = ev->getEvents(); // Récupère les "évènements" dans la liste
		ref_ptr<GUIEventAdapter> ea = events.back(); // Récupère le dernier élément de la liste
		events.pop_back(); // Supprime l'élément récupéré de la liste
		switch(ea->getEventType())
		{
		case GUIEventAdapter::KEYDOWN: // Enfoncement d'une touche
			switch(ea->getKey()){
			case GUIEventAdapter::KEY_Right : // flêche vers la droite
				Board::getInstance().movePlayer(RIGHT);
				break;
			case GUIEventAdapter::KEY_Left : // flêche vers la gauche
				Board::getInstance().movePlayer(LEFT);
				break;
			case GUIEventAdapter::KEY_Down : // flêche vers la gauche
				Board::getInstance().movePlayer(DOWN);
				break;
			case GUIEventAdapter::KEY_Up : // flêche vers la gauche
				Board::getInstance().movePlayer(UP);
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
