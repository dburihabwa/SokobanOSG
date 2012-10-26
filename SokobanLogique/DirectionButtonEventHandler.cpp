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
}
