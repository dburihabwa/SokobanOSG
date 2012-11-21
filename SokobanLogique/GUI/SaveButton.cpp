#include "SaveButton.h"
#include "../Logic/Board.h"



Sokoban::SaveButton::SaveButton(int x, int y, int z) : GUIButton(x, y, z)
{
}

Sokoban::Type Sokoban::SaveButton::getType() {
	return SAVE_BUTTON;
}
bool Sokoban::SaveButton::onClick() {
	Board::getInstance().save();
	return true;
}