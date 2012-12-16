#pragma once
#include "GUIButton.h"
namespace Sokoban {
	class UndoButton :
		public Sokoban::GUIButton
	{
	public:
		UndoButton(int x, int y, int z);
		Type getType();
		bool onClick();
		~UndoButton(void);
	private:
	};
};
