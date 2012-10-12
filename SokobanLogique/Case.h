#pragma once

class Case
{
public:
    size_t getX() const;
    size_t getY() const;
protected:
    size_t _x;
    size_t _y;
};

class Direction {
protected:
    char _direction;
public:
    const char LEFT = 2;
    const char RIGHT = 1;
    const char UP = 3;
    const char DOWN = 4;
};
