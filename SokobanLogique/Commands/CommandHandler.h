#pragma once
#include <stack>
#include "Command.h"
#include <osg/ref_ptr>
namespace Sokoban {
	class CommandHandler
	{
	public:
		static CommandHandler& getInstance() {
			// The only instance
			// Guaranteed to be lazy initialized
			// Guaranteed that it will be destroyed correctly
			//Explained : http://stackoverflow.com/questions/86582/singleton-how-should-it-be-used
			static CommandHandler instance;
			return instance;
		}
		bool emptyCommands() {
			return _commands.empty();
		}

		bool executeCommand(osg::ref_ptr<Command> cmd);

		~CommandHandler(void);
	private:
		std::stack<osg::ref_ptr<Command>> _commands;
		CommandHandler();
		CommandHandler(CommandHandler const&);              // Don't Implement
		void operator=(CommandHandler const&); // Don't implement
	};
}
