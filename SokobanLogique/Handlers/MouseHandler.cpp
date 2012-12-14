#include "MouseHandler.h"
#include <osgViewer\Viewer>
#include "../GUI/View.h"

#include <iostream>

Sokoban::MouseHandler::~MouseHandler(void)
{
}



bool isHoveringAButton(const osgGA::GUIEventAdapter& ea) {
	osgUtil::LineSegmentIntersector* picker;
	picker = new osgUtil::LineSegmentIntersector( osgUtil::Intersector::WINDOW, ea.getX(),ea.getY() );
	osgUtil::IntersectionVisitor iv(picker);
	Sokoban::View::getInstance().getButtonsCamera()->accept(iv);
	if (picker->containsIntersections()) {
		osgUtil::LineSegmentIntersector::Intersection intersection = picker->getFirstIntersection();
		osg::ref_ptr<Sokoban::GUIButton> button = dynamic_cast<Sokoban::GUIButton*>(intersection.nodePath.at(2)->getUserData());
		if (button)
			return true;
	}
	return false;
}

osg::ref_ptr<osg::Switch> getHoveredButton(const osgGA::GUIEventAdapter& ea) {
	osgUtil::LineSegmentIntersector* picker;
	picker = new osgUtil::LineSegmentIntersector( osgUtil::Intersector::WINDOW, ea.getX(),ea.getY() );
	osgUtil::IntersectionVisitor iv(picker);
	Sokoban::View::getInstance().getButtonsCamera()->accept(iv);
	if (picker->containsIntersections()) {
		osgUtil::LineSegmentIntersector::Intersection intersection = picker->getFirstIntersection();
		osg::ref_ptr<osg::Switch> switchNode = dynamic_cast<osg::Switch*>(intersection.nodePath.at(3));
		return switchNode;
	}
	return NULL;
}

bool Sokoban::MouseHandler::setButtonToAlternateGeode(const osgGA::GUIEventAdapter& ea) {
	if (this->hoveredSwitch)
		return true;
	osg::ref_ptr<osg::Switch> switchNode = getHoveredButton(ea);
	if (!switchNode)
		return false;
	switchNode->setAllChildrenOff();
	switchNode->setSingleChildOn(1);
	this->hoveredSwitch = switchNode;
	return true;
}

bool Sokoban::MouseHandler::setButtonToPrimaryGeode(const osgGA::GUIEventAdapter& ea) {
	if (!this->hoveredSwitch)
		return true;
	this->hoveredSwitch->setAllChildrenOff();
	this->hoveredSwitch->setChildValue(this->hoveredSwitch->getChild(0), true);
	this->hoveredSwitch.release();
	return false;
}

bool Sokoban::MouseHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {
	osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
	if (!viewer) {
		return false;
	}
	switch(ea.getEventType())
	{
	case(osgGA::GUIEventAdapter::PUSH):
	case(osgGA::GUIEventAdapter::MOVE):
		{
			_mx = ea.getX();
			_my = ea.getY();
			if (isHoveringAButton(ea)) {
				std::cout << "A button is being hovered!" << std::endl;
				bool res = setButtonToAlternateGeode(ea);
				std::cout<< "To Alternate = " <<  res << "!" <<std::endl;
				return res;
			} else {
				bool res = setButtonToPrimaryGeode(ea);				
				std::cout<< "NO button IS being hovered!" << std::endl;
				std::cout<< "To Primary = " <<  res << "!" <<std::endl;
				return res;
			}
			break;
		}
	case(osgGA::GUIEventAdapter::RELEASE):
		{
			if (_mx == ea.getX() && _my == ea.getY()) {
				// only do a pick if the mouse hasn't moved
				return pick(ea);
			}
		}    
		break;
	default:
		return false;
	}
	return false;
}