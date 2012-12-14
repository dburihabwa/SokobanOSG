#include "LoadSavedGameButton.h"
#include "../Logic/Board.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/LoadCommand.h"


Sokoban::LoadSavedGameButton::LoadSavedGameButton(int x, int y, int z) : GUIButton(x, y, z) 
{
}


Sokoban::LoadSavedGameButton::~LoadSavedGameButton(void)
{
}
bool Sokoban::LoadSavedGameButton::onClick() {
	return CommandHandler::getInstance()->executeCommand(new LoadCommand());
}
