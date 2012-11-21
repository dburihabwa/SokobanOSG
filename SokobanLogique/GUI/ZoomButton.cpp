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
	osg::ref_ptr<osg::Camera> board = View::getInstance().getBoardCamera();
	double fov, ar,near,far;
	board->getProjectionMatrixAsPerspective(fov,ar,near,far);
	if(_type == ZOOM_OUT) {
		fov+=2;
	} else if(_type == ZOOM_IN) {
		fov-=2;
	}
	board->setProjectionMatrixAsPerspective(fov,ar,near,far);
	return false;
}
