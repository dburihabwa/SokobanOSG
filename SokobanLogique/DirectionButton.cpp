#include "DirectionButton.h"
#include <osg/PositionAttitudeTransform>
#include <osg/Quat>


Sokoban::DirectionButton::DirectionButton(int x, int y, int z, Sokoban::Direction direction) : Sokoban::Case(x, y, z) {
    this->_direction = direction;
}

Sokoban::Direction Sokoban::DirectionButton::getDirection() const {
    return this->_direction;
}

Sokoban::Type Sokoban::DirectionButton::getType() {
    return DIRECTION_BUTTON;
}
ref_ptr<Node> Sokoban::DirectionButton::createNode() {
	ref_ptr<PositionAttitudeTransform> node = dynamic_cast<PositionAttitudeTransform*>(Case::createNode().get());
	node->setUserData(this);
	if(_direction==UP) {
		node->setAttitude(Quat(3.1415,Z_AXIS));
	} else if(_direction == LEFT) {
		node->setAttitude(Quat(-1.57,Z_AXIS));
	} else if(_direction == RIGHT) {
		node->setAttitude(Quat(1.57,Z_AXIS));
	}
	return node;
}