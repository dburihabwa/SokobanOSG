#pragma once
namespace Sokoban
{
	class Direction
	{
	public:
		Direction(int x,int y)	{
			this->_x = x;
			this->_y = y;
		}
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


