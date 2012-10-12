#pragma once
#include "case.h"
class MovableObject :
    public Case
{
protected:
    Direction nextPosition = NULL;
public:
    virtual bool canMove(Direction) const;
    virtual bool move(Direction);
};

