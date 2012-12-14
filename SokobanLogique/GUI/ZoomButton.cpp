#include "ZoomButton.h"
#include "View.h"
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
		View::getInstance()->changeZoomOnBoard(2);
	} else if(_type == ZOOM_IN) {
		View::getInstance()->changeZoomOnBoard(-2);
	}
	return true;
}
