#include "DirectionButton.h"

Sokoban::DirectionButton::DirectionButton(Sokoban::Direction direction) : _direction(direction) {}

Sokoban::Direction Sokoban::DirectionButton::getDirection() const {
    return this->_direction;
}