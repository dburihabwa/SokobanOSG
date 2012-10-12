#pragma once
#include "movableobject.h"
class Box :
    public MovableObject
{

public:
	Box(size_t x, size_t y, size_t z) : MovableObject::MovableObject(x,y,z) {}
    ~Box(void);
private:
	Box();
};

