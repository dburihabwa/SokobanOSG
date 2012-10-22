#pragma once

#include <time.h>
#include "Board.h"

namespace Sokoban 
{
    class Hud
    {
    public:
        Hud(void);
        ~Hud(void);
        unsigned int getElapsedTime() const;
        ref_ptr<Node> createNode();
    private:
        clock_t _timer;
    };
};