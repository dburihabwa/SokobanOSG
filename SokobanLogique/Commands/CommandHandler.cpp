#include "CommandHandler.h"
#include "UndoCommand.h"
#include "UnDoableCommand.h"
#include "../Logic/Board.h"
#include "../Constants.h"

osg::ref_ptr<Sokoban::CommandHandler> Sokoban::CommandHandler::instance = NULL;

Sokoban::CommandHandler::CommandHandler(void) {
	Board::getInstance().addView(osg::ref_ptr<IView>(this));
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
		if(command->execute()) {
			_commands.push(unDoableCmd);
			return true;
		}
		return false;
	}
	return command->execute();
}

void Sokoban::CommandHandler::notify(Event sokoEvent) {
	switch(sokoEvent) {
	case LOAD_LVL:
	case LOAD_SAVE:
#if DEBUG==TRUE
		std::cout<<"Empty Commands"<<std::endl;
#endif
		while(!_commands.empty()) {
			_commands.pop();
		}
		break;
	default:
		break;
	}
}
