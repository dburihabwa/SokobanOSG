#include "ZoomButton.h"
#include "../Commands/CommandHandler.h"
#include "../Commands/ZoomCommand.h"
#include <osg/Camera>


Sokoban::ZoomButton::ZoomButton(int x, int y, int z, Sokoban::Type type) : GUIButton(x, y, z)
{
	if (type != ZOOM_IN && type != ZOOM_OUT)
		this->_type = ZOOM_OUT;
	else
		this->_type = type;
}

Sokoban::Type Sokoban::ZoomButton::getType() {
	return this->_type;
}


Sokoban::ZoomButton::~ZoomButton(void)
{
}

bool Sokoban::ZoomButton::onClick() {

	if(_type == ZOOM_OUT) {
		CommandHandler::getInstance()->executeCommand(new ZoomCommand(2));
	} else if(_type == ZOOM_IN) {
		CommandHandler::getInstance()->executeCommand(new ZoomCommand(-2));
	}
	return true;
}
