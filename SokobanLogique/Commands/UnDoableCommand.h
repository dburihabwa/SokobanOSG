#pragma once
#include "Command.h"
namespace Sokoban {
class UnDoableCommand : public Command
{
public:

	UnDoableCommand(void)
	{
	}

	~UnDoableCommand(void)
	{
	}
	virtual bool unExecute() const = 0;
};
}

