#include "DirectionButton.h"
#include <osg/PositionAttitudeTransform>
#include "../Constants.h"
#include "../Logic/Board.h"


Sokoban::DirectionButton::DirectionButton(int x, int y, int z, Sokoban::Direction direction) : Sokoban::GUIButton(x, y, z) {
    this->_direction = direction;
}

Sokoban::Direction Sokoban::DirectionButton::getDirection() const {
    return this->_direction;
}

Sokoban::Type Sokoban::DirectionButton::getType() {
    return DIRECTION_BUTTON;
}
bool Sokoban::DirectionButton::onClick() {
	return Board::getInstance().movePlayer(this->_direction);
}