#pragma once
#include "unmovable.h"
class Ground :
    public Unmovable
{
public:
    Ground(void);
    Ground(size_t x, size_t y, size_t z) : Unmovable::Unmovable(x, y, z) {}
    ~Ground(void);
};

