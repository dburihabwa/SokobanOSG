#pragma once
#include "movableobject.h"
class Player :
	public MovableObject
{
public:
	Player(size_t x, size_t y, size_t z) : MovableObject::MovableObject(x,y,z) {}
public:
	~Player(void);
private:
	Player();
};

