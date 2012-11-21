#include "ZoomButton.h"
#include "View.h"


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
	return false;
}
