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
		osg::ref_ptr<UnDoableCommand> unCmd = _commands.top();
		_commands.pop();
		return unCmd->unExecute();
	}
	else if(osg::ref_ptr<UnDoableCommand> unDoableCmd = dynamic_cast<UnDoableCommand*>(command.get())){
		_commands.push(unDoableCmd);
	}
	return command->execute();
}
