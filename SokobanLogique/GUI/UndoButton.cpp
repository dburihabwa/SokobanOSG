#include "UndoButton.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/UndoCommand.h"

Sokoban::UndoButton::UndoButton(int x, int y, int z) : GUIButton(x, y, z) {}

Sokoban::Type Sokoban::UndoButton::getType() {
	return UNDO_BUTTON;
}

bool Sokoban::UndoButton::onClick() {
	return CommandHandler::getInstance()->executeCommand(new UndoCommand());
}

Sokoban::UndoButton::~UndoButton(void)
{
}
