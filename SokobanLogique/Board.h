#pragma once
#include <string>
#include <vector>
#include "Movable.h"
#include "Unmovable.h"
class Board
{
	
public:
	Board(std::string);
	~Board(void);
private:
	std::vector<std::vector<Movable>> movable;
	std::vector<std::vector<Unmovable>> unMovable;
	Board();
};

