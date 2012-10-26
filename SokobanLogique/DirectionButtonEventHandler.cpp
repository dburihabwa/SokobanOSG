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
        events = ev->getEvents(); // Récupère les "évènements" dans la liste
        ref_ptr<GUIEventAdapter> ea = events.back(); // Récupère le dernier élément de la liste
        events.pop_back(); // Supprime l'élément récupéré de la liste
        switch(ea->getEventType())
        {
        case GUIEventAdapter::PUSH: // Button Click
            switch(ea->getButton()){
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