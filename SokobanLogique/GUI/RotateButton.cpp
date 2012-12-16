#include "RotateButton.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/RotateCommand.h"

Sokoban::RotateButton::RotateButton(int x, int y, int z, Type type) : Sokoban::GUIButton(x, y, z), _type(type) {}

bool Sokoban::RotateButton::onClick()
{
	osg::ref_ptr<RotateCommand> cmd;
	if(_type == ROTATE_LEFT_BUTTON)
		cmd = new RotateCommand(0.1);
	
	else
		cmd = new RotateCommand(-0.1);
	return CommandHandler::getInstance()->executeCommand(cmd);
}

Sokoban::Type Sokoban::RotateButton::getType() {
	return this->_type;
}

Sokoban::RotateButton::~RotateButton(void)
{
}