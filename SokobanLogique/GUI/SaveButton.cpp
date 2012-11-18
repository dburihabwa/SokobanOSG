#include "SaveButton.h"
#include <osg/PositionAttitudeTransform>


Sokoban::SaveButton::SaveButton(int x, int y, int z) : GUIButton(x, y, z)
{
}

Sokoban::Type Sokoban::SaveButton::getType() {
	return SAVE_BUTTON;
}

osg::ref_ptr<osg::Node> Sokoban::SaveButton::createNode() {
	osg::ref_ptr<osg::PositionAttitudeTransform> node = dynamic_cast<osg::PositionAttitudeTransform*>(Case::createNode().get());
	node->setUserData(this);
	return node;
}