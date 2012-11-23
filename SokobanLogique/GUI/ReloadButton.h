#pragma once
#include "GUIButton.h"

namespace Sokoban {
	class ReloadButton : public GUIButton
	{
	public:
		ReloadButton(int x, int y, int z);
		Type getType();
		bool onClick();
	};
};

