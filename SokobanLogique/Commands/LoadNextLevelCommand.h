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

		bool execute() {
			Board::getInstance().loadNextLvl();
			return true;
		}
	};
}