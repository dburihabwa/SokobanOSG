#include "Hud.h"

Sokoban::Hud::Hud(void) : _timer(clock()) {}


Sokoban::Hud::~Hud(void)
{
}

unsigned int Sokoban::Hud::getElapsedTime() const
{
    return (this->_timer - clock()) / CLOCKS_PER_SEC;
}