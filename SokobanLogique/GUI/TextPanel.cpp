#include "TextPanel.h"
#include <iostream>


Sokoban::TextPanel::TextPanel(osg::ref_ptr<osg::Camera> cam) : _camera(cam.get()), _nbTxt(0), _lastY(0)
{
	init();
}


Sokoban::TextPanel::~TextPanel(void) {
}

void Sokoban::TextPanel::reset() {
	_camera->removeChild(_textGroup);
	_textGroup.release();
	init();
}
void Sokoban::TextPanel::init() {
	_textGroup = new osg::Group;
	_camera->addChild(_textGroup);
}

void Sokoban::TextPanel::addText(std::string str) {
	std::cout<<str<<std::endl;
}
