#pragma once
#include "movableobject.h"
class Box :
    public MovableObject
{
public:
    Box(void);
    bool canMove(Direction d) const;
    ~Box(void);
};

