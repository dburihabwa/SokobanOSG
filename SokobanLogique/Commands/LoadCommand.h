#pragma once
#include "Command.h"
#include "../Logic/Board.h"
namespace Sokoban {
	class LoadCommand : public Command
	{
	public:

		LoadCommand(void)
		{
		}

		~LoadCommand(void)
		{
		}

		bool execute() const {
			return Board::getInstance().loadSave();
		}
	};
}