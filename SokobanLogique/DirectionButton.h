#pragma once
#include "Unmovable.h"
#include "Direction.h"

namespace Sokoban {
    class DirectionButton :
        public Sokoban::Unmovable
    {
    public:
         DirectionButton(Direction direction);
        Direction getDirection() const;
    private:
        Direction _direction;
    };
};

