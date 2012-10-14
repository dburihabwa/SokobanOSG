#pragma once
#include <string>
#include <vector>
#include "Case.h"

using namespace osg;
namespace Sokoban
{
	class Board
	{
	public:
		Board(std::string);
		~Board(void);
	private:
		std::vector<std::vector<ref_ptr<Case>>> movable;
		std::vector<std::vector<ref_ptr<Case>>> unMovable;
	};
};

