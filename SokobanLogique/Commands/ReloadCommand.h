#pragma once
#include "Command.h"
#include "../Logic/Board.h"
namespace Sokoban {
	class ReloadCommand : public Command
	{
	public:

		ReloadCommand(void)
		{
		}

		~ReloadCommand(void)
		{
		}

		bool execute() const {
			Board::getInstance().reloadLvl();
			return true;
		}
	};
}