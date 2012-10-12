#pragma once
#include "case.h"
#include "Direction.h"
class MovableObject : public Case
{
public:
	MovableObject(size_t x, size_t y, size_t z) : Case::Case(x,y,z) {}
    virtual bool canMove(Direction) const = 0;
    virtual bool move(Direction) = 0;
private:
	MovableObject();
};

