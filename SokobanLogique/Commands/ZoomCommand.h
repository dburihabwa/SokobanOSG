#pragma once
#include "Command.h"
#include "../GUI/View.h"
namespace Sokoban {
	class ZoomCommand : public Command
	{
	public:

		ZoomCommand(int zoom) : _zoom(zoom)
		{
		}

		~ZoomCommand(void)
		{
		}

		bool execute()  {
			View::getInstance()->changeZoomOnBoard(_zoom);
			return true;
		}
	private:
		int _zoom;
	};
}