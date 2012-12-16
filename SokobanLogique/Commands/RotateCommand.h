#pragma once
#include "Command.h"
#include "../GUI/View.h"
namespace Sokoban {
	class RotateCommand : public Command
	{
	public:

		RotateCommand(float rotation) : _rotation(rotation)
		{
		}

		~RotateCommand(void)
		{
		}

		bool execute()  {
			View::getInstance()->rotatePlayGround(_rotation);
			return true;
		}
	private:
		float _rotation;
	};
}