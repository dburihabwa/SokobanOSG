#pragma once
#include "case.h"
#include "Direction.h"
class Movable :
	public Case
{
public:
	Movable(size_t x, size_t y, size_t z) : Case(x,y,z) {}
	virtual bool canMove(Direction) const =0;
	virtual bool move(Direction) = 0;
	~Movable(void)
	{
	}
};


