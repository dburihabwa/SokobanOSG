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

		bool execute()  {
			return Board::getInstance().loadSave();
		}
	};
}