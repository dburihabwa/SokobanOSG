#pragma once
#include "movable.h"
class Player :
	public Movable
{
public:
	Player(size_t x, size_t y, size_t z) : Movable(x,y,z) {}
public:
	~Player(void);
private:
	Player();
};

