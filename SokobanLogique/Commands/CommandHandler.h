#pragma once
#include <stack>
#include "Command.h"
#include "UnDoableCommand.h"
#include "../Logic/IView.h"
#include <osg/ref_ptr>
namespace Sokoban {
	class CommandHandler : public IView
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
		bool executeCommand(osg::ref_ptr<Command> cmd);
		void notify(Event);

		~CommandHandler(void);
	private:
		std::stack<osg::ref_ptr<UnDoableCommand>> _commands;
		CommandHandler();
		CommandHandler(CommandHandler const&);              // Don't Implement
		void operator=(CommandHandler const&); // Don't implement
	};
}
