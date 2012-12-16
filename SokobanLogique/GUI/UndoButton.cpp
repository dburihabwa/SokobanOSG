#include "UndoButton.h"


Sokoban::UndoButton::UndoButton(int x, int y, int z) : GUIButton(x, y, z) {}

Sokoban::Type Sokoban::UndoButton::getType() {
	return UNDO_BUTTON;
}

bool Sokoban::UndoButton::onClick() {
	return false;
}

Sokoban::UndoButton::~UndoButton(void)
{
}
