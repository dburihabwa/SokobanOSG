#pragma once
#include "movable.h"
class Player :
	public virtual Movable
{
public:
	Player(size_t x, size_t y, size_t z) : Movable(x,y,z) {}
	Geode* createGeode();
public:
	~Player(void);
private:
	Player();
};

