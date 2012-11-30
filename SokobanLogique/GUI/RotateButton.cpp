#include "RotateButton.h"

Sokoban::RotateButton::RotateButton(int x, int y, int z, Type type) : Sokoban::GUIButton(x, y, z), _type(type)
{

}

bool Sokoban::RotateButton::onClick()
{
	return false;
}

Sokoban::Type Sokoban::RotateButton::getType() const
{
	return this->_type;
}

Sokoban::RotateButton::~RotateButton(void)
{
}