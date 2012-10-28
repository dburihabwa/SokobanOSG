#include "DirectionButton.h"
#include <osg/PositionAttitudeTransform>
#include "Constants.h"


Sokoban::DirectionButton::DirectionButton(int x, int y, int z, Sokoban::Direction direction) : Sokoban::Case(x, y, z) {
    this->_direction = direction;
}

Sokoban::Direction Sokoban::DirectionButton::getDirection() const {
    return this->_direction;
}

Sokoban::Type Sokoban::DirectionButton::getType() {
    return DIRECTION_BUTTON;
}
osg::ref_ptr<osg::Node> Sokoban::DirectionButton::createNode() {
	osg::ref_ptr<osg::PositionAttitudeTransform> node = dynamic_cast<osg::PositionAttitudeTransform*>(Case::createNode().get());
	node->setUserData(this);
	if(_direction==UP) {
		node->setAttitude(DEGREE_180);
	} else if(_direction == LEFT) {
		node->setAttitude(DEGREE_MIN_90);
	} else if(_direction == RIGHT) {
		node->setAttitude(DEGREE_90);
	}
	return node;
}