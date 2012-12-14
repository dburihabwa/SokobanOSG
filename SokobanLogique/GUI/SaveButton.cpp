#include "SaveButton.h"
#include "../Logic/Board.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/SaveCommand.h"



Sokoban::SaveButton::SaveButton(int x, int y, int z) : GUIButton(x, y, z)
{
}

Sokoban::Type Sokoban::SaveButton::getType() {
	return SAVE_BUTTON;
}
bool Sokoban::SaveButton::onClick() {
	return CommandHandler::getInstance()->executeCommand(new SaveCommand());
}