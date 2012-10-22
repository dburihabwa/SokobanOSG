#pragma once
#include "Unmovable.h"
#include "Direction.h"

namespace Sokoban {
    class DirectionButton :
        public Sokoban::Unmovable
    {
    public:
        DirectionButton(int x, int y, int z, Direction direction);
        Type getType();
        Direction getDirection() const;
    private:
        Direction _direction;
    };
};

