#include "DirectionButtonEventHandler.h"



Sokoban::DirectionButtonEventHandler::DirectionButtonEventHandler(Sokoban::Direction direction)
{
    this->_direction = direction;
}


Sokoban::DirectionButtonEventHandler::~DirectionButtonEventHandler(void)
{
}

void Sokoban::DirectionButtonEventHandler::operator()(Node* node, NodeVisitor* nv)
{
	std::list<ref_ptr<GUIEventAdapter>> events;
	EventVisitor* ev = dynamic_cast<EventVisitor*>(nv);
	if(ev) {
		events = ev->getEvents(); // R�cup�re les "�v�nements" dans la liste
		ref_ptr<GUIEventAdapter> ea = events.back(); // R�cup�re le dernier �l�ment de la liste
		events.pop_back(); // Supprime l'�l�ment r�cup�r� de la liste
		switch(ea->getEventType())
		{
		case GUIEventAdapter::PUSH: // Button Click
			switch(ea->getKey()){
            case GUIEventAdapter::LEFT_MOUSE_BUTTON:
                Sokoban::Board::getInstance().movePlayer(this->_direction);
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