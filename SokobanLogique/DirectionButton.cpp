#include "DirectionButton.h"


Sokoban::DirectionButton::DirectionButton(int x, int y, int z, Sokoban::Direction direction) : Sokoban::Unmovable(x, y, z) {
    this->_direction = direction;
}

Sokoban::Direction Sokoban::DirectionButton::getDirection() const {
    return this->_direction;
}

Sokoban::Type Sokoban::DirectionButton::getType() {
    return DIRECTION_BUTTON;
}