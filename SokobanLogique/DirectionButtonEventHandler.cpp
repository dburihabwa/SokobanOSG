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
		events = ev->getEvents(); // R�cup�re les "�v�nements" dans la liste
		ref_ptr<GUIEventAdapter> ea = events.back(); // R�cup�re le dernier �l�ment de la liste
		events.pop_back(); // Supprime l'�l�ment r�cup�r� de la liste
		if(ea->getEventType()==GUIEventAdapter::RELEASE && ea->getButton() == GUIEventAdapter::LEFT_MOUSE_BUTTON) {

			// Intersecteur � partir du point de l'�cran (en pixels) au moment du click
			ref_ptr<LineSegmentIntersector> intersector = 
				new LineSegmentIntersector(Intersector::WINDOW,ea->getX(),ea->getY());
			// Visite des noeuds sp�cifi�s pour d�terminer si des Drawables entrent en intersection
			// avec la "ligne de mire" du click de la souris
			IntersectionVisitor iv(intersector.get());
			// chaque noeud visit� sera trait� pour la s�lection via un click de la souris
			node->accept(iv);
			// si au moins un Drawable est s�lectionn�
			if(intersector->containsIntersections()){
				// on r�cup�re le plus proche (?) et ses coordonn�es dans l'univers de dessin
				LineSegmentIntersector::Intersection result = intersector->getFirstIntersection();
				//R�cup�ration de l'userData qui est en fait notre bouton logique.
				ref_ptr<DirectionButton> button = dynamic_cast<DirectionButton*>(result.nodePath.at(3)->getUserData());
				if(button) {
					Board::getInstance().movePlayer(button->getDirection());
				}
			}
		}
	}
	traverse(node,nv);
}