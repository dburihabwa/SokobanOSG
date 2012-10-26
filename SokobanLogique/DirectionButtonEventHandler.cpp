#include "DirectionButtonEventHandler.h"
#include <osgUtil/LineSegmentIntersector>
using namespace osgUtil;

Sokoban::DirectionButtonEventHandler::DirectionButtonEventHandler(void)
{
}


Sokoban::DirectionButtonEventHandler::~DirectionButtonEventHandler(void)
{
}

void Sokoban::DirectionButtonEventHandler::operator()(Node* node, NodeVisitor* nv) {
	std::list<ref_ptr<GUIEventAdapter>> events;
	EventVisitor* ev = dynamic_cast<EventVisitor*>(nv);
	if(ev) {
		events = ev->getEvents(); // Récupère les "évènements" dans la liste
		ref_ptr<GUIEventAdapter> ea = events.back(); // Récupère le dernier élément de la liste
		events.pop_back(); // Supprime l'élément récupéré de la liste
		if(ea->getEventType()==GUIEventAdapter::RELEASE && ea->getButton() == GUIEventAdapter::LEFT_MOUSE_BUTTON) {

			// Intersecteur à partir du point de l'écran (en pixels) au moment du click
			ref_ptr<LineSegmentIntersector> intersector = 
				new LineSegmentIntersector(Intersector::WINDOW,ea->getX(),ea->getY());
			// Visite des noeuds spécifiés pour déterminer si des Drawables entrent en intersection
			// avec la "ligne de mire" du click de la souris
			IntersectionVisitor iv(intersector.get());
			// chaque noeud visité sera traité pour la sélection via un click de la souris
			node->accept(iv);
			// si au moins un Drawable est sélectionné
			if(intersector->containsIntersections()){
				// on récupère le plus proche (?) et ses coordonnées dans l'univers de dessin
				LineSegmentIntersector::Intersection result = intersector->getFirstIntersection();
				//Récupération de l'userData qui est en fait notre bouton logique.
				ref_ptr<DirectionButton> button = dynamic_cast<DirectionButton*>(result.nodePath.at(3)->getUserData());
				if(button) {
					Board::getInstance().movePlayer(button->getDirection());
				}
			}
		}
	}
	traverse(node,nv);
}