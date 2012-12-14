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
		static osg::ref_ptr<CommandHandler> getInstance() {
			if(!instance) {
				instance = new CommandHandler();
			}
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
		static osg::ref_ptr<CommandHandler> instance;
	};
}
