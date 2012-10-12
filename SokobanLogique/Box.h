#pragma once
#include "movable.h"
class Box :
    public Movable
{

public:
	Box(size_t x, size_t y, size_t z) : Movable(x,y,z) {}
    ~Box(void);
private:
	Box();
};

