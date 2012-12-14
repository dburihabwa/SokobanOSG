#pragma once
#include "Command.h"
#include "../Logic/Board.h"
namespace Sokoban {
	class LoadNextLevelCommand : public Command
	{
	public:

		LoadNextLevelCommand(void)
		{
		}

		~LoadNextLevelCommand(void)
		{
		}

		bool execute() const {
			Board::getInstance().loadNextLvl();
			return true;
		}
	};
}