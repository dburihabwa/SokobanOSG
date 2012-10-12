#pragma once
#include "unmovable.h"
class Target :
    public Unmovable
{
public:
    Target(size_t x, size_t y, size_t z) : Unmovable::Unmovable(x, y, z) {}
    ~Target(void);
};