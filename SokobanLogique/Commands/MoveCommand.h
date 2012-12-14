#pragma once
#include "UnDoableCommand.h"
#include "../Logic/Board.h"
#include "../Logic/Direction.h"
#include "../Logic/Box.h"
namespace Sokoban {
	class MoveCommand : public UnDoableCommand
	{
	public:
		MoveCommand(Direction dir) : _dir(dir)
		{
		}

		~MoveCommand(void)
		{
		}

		bool execute() {
			return Board::getInstance().movePlayer(_dir,_movedBox);
		}
		bool unExecute() const {
			Board::getInstance().revertMove(_dir.getOpposite(),_movedBox);
			return true;
		}
	private:
		Direction _dir;
		osg::ref_ptr<Box> _movedBox;
	};
}