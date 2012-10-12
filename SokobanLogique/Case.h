#pragma once
#include <osg\MatrixTransform>
using namespace osg;

class Case
{
public:
    size_t getX() const;
    size_t getY() const;
protected:
    size_t _x;
    size_t _y;
};
