#pragma once
#include <osg\MatrixTransform>
using namespace osg;

class Case
{
public:
	Case(size_t x,size_t y, size_t z) : _x(x), _y(y), _z(z) {}
	size_t Case::getX() const {
		return this->_x;
	}

	size_t Case::getY() const {
		return this->_y;
	}
	size_t getZ() const {
		return this->_z;
	}
	virtual Geode createGeode() = 0;
protected:
	size_t _x;
	size_t _y;
	size_t _z;
private:
	Case();
};
