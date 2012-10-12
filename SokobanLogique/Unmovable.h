#pragma once
#include "case.h"
class Unmovable :
	public Case
{
public:
	Unmovable(size_t x, size_t y, size_t z) : Case::Case(x,y,z) {}
private:
	Unmovable();
};

