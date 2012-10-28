#pragma once
namespace Sokoban
{
	class Direction
	{
	public:
		Direction(int x,int y) : _x(x),_y(y){}
		Direction() : _x(0),_y(0){}
		const int getX() const {
			return this->_x;
		}
		const int getY() const {
			return this->_y;
		}
		bool Direction::operator ==(Direction b) {
			return (this->_x == b._x && this->_y == b._y);
		}
		bool Direction::operator !=(Direction b) {
			return (this->_x != b._x || this->_y != b._y);
		}
		osg::Vec3 getVector() {
			return osg::Vec3(_x,_y,0);
		}

	private:
		int _x,_y;
	};
		//Directions
	static const Direction RIGHT(0,1);
	static const Direction LEFT(0,-1);
	static const Direction DOWN(1,0);
	static const Direction UP(-1,0);
	static const Direction NONE;
};


