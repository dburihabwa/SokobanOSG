#pragma once
#include "Command.h"
#include "../Logic/Board.h"
namespace Sokoban {
	class SaveCommand : public Command
	{
	public:

		SaveCommand(void)
		{
		}

		~SaveCommand(void)
		{
		}

		bool execute() {
			Board::getInstance().save();
			return true;
		}
	};
}