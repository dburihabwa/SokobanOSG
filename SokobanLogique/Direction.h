#pragma once
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

private:
	int _x,_y;
};
const Direction UP = Direction(0,1);
const Direction DOWN = Direction(0,-1);
const Direction RIGHT = Direction(1,0);
const Direction LEFT = Direction(-1,0);

