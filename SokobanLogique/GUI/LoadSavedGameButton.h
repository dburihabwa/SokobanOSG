#pragma once
#include "guibutton.h"

namespace Sokoban {
	class LoadSavedGameButton :
		public GUIButton
	{
	public:
		LoadSavedGameButton(int x, int y, int z);
		Type getType() {
			return LOAD_BUTTON;
		}
		bool onClick();
		~LoadSavedGameButton(void);
	};
};

