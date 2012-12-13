#pragma once
#include "Command.h"
namespace Sokoban {
	class UndoCommand : public Command
	{
	public:

		UndoCommand(void)
		{
		}

		~UndoCommand(void)
		{
		}
		bool execute() {
			return false;
		}
	};
}

