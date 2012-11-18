#include "SaveButton.h"


Sokoban::SaveButton::SaveButton(int x, int y, int z) : GUIButton(x, y, z)
{
}

Sokoban::Type Sokoban::SaveButton::getType() {
	return SAVE_BUTTON;
}