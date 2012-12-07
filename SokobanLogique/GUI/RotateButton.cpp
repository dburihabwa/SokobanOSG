#include "RotateButton.h"
#include "View.h"

Sokoban::RotateButton::RotateButton(int x, int y, int z, Type type) : Sokoban::GUIButton(x, y, z), _type(type) {}

bool Sokoban::RotateButton::onClick()
{
	return View::getInstance().rotatePlayGround(this->_type);
}

Sokoban::Type Sokoban::RotateButton::getType() {
	return this->_type;
}

Sokoban::RotateButton::~RotateButton(void)
{
}