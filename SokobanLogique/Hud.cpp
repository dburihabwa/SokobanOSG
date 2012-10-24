#include "Hud.h"

Sokoban::Hud::Hud(void) {
    this->_timer = clock();
    ref_ptr<DirectionButton> upDirectionButton =  new DirectionButton(0, 0, 0, Sokoban::UP);
    ref_ptr<DirectionButton> downDirectionButton =  new DirectionButton(0, 0, 0, Sokoban::DOWN);
    ref_ptr<DirectionButton> leftDirectionButton =  new DirectionButton(0, 0, 0, Sokoban::LEFT);
    ref_ptr<DirectionButton> rightDirectionButton =  new DirectionButton(0, 0, 0, Sokoban::RIGHT);

    this->_buttons.push_back(upDirectionButton);
    this->_buttons.push_back(downDirectionButton);
    this->_buttons.push_back(leftDirectionButton);
    this->_buttons.push_back(rightDirectionButton);
}



Sokoban::Hud::~Hud(void)
{
}

unsigned int Sokoban::Hud::getElapsedTime() const
{
    return (this->_timer - clock()) / CLOCKS_PER_SEC;
}

const std::vector<ref_ptr<Sokoban::DirectionButton> >& Sokoban::Hud::getButtons() const
{
    return this->_buttons;
}

const ref_ptr<osg::Group>& Sokoban::Hud::getNodes() const
{
    return this->_nodes;
}