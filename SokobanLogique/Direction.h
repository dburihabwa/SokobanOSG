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

	private:
		int _x,_y;
	};
};


