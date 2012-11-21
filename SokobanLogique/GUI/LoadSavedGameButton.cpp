#include "LoadSavedGameButton.h"
#include "../Logic/Board.h"


Sokoban::LoadSavedGameButton::LoadSavedGameButton(int x, int y, int z) : GUIButton(x, y, z) 
{
}


Sokoban::LoadSavedGameButton::~LoadSavedGameButton(void)
{
}
bool Sokoban::LoadSavedGameButton::onClick() {
	return Board::getInstance().loadSave();
}
