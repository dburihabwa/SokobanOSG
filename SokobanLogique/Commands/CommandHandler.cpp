#include "CommandHandler.h"
#include "UndoCommand.h"
#include "UnDoableCommand.h"

Sokoban::CommandHandler::CommandHandler(void)
{
}


Sokoban::CommandHandler::~CommandHandler(void)
{
}

bool Sokoban::CommandHandler::executeCommand(osg::ref_ptr<Command> command) {
	if(dynamic_cast<UndoCommand*>(command.get())) {
		if(_commands.empty())
			return false;
		osg::ref_ptr<UnDoableCommand> unCmd;
		do {
			unCmd = dynamic_cast<UnDoableCommand*>(_commands.top().get());
			_commands.pop();
		} while(!_commands.empty() && !unCmd);
		if(unCmd)
			return unCmd->unExecute();
		return false;
	}
	else {
		_commands.push(command);
		return command->execute();
	}
	return false;
}
