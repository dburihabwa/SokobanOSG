#include "ReloadButton.h"
#include "../Logic/Board.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/ReloadCommand.h"



Sokoban::ReloadButton::ReloadButton(int x, int y, int z) : GUIButton(x, y, z)
{
}

Sokoban::Type Sokoban::ReloadButton::getType() {
	return RELOAD_BUTTON;
}
bool Sokoban::ReloadButton::onClick() {
	return CommandHandler::getInstance().executeCommand(new ReloadCommand());
}