#include "ReloadButton.h"
#include "../Logic/Board.h"



Sokoban::ReloadButton::ReloadButton(int x, int y, int z) : GUIButton(x, y, z)
{
}

Sokoban::Type Sokoban::ReloadButton::getType() {
	return RELOAD_BUTTON;
}
bool Sokoban::ReloadButton::onClick() {
	Board::getInstance().reloadLvl();
	return true;
}