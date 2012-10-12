#pragma once
#include "case.h"
#include "Direction.h"
class MovableObject : public Case
{
public:
    virtual bool canMove(Direction) const = 0;
    virtual bool move(Direction) = 0;
};

