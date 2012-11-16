#include "TextPanel.h"
#include <iostream>
#include "../Constants.h"
#include <osgText\Text>

osg::ref_ptr<osgText::Font> Sokoban::TextPanel::_font = osgText::readFontFile("fonts/arial.ttf");

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
#if DEBUG==TRUE
	std::cout<<str<<std::endl;
#endif
	osg::ref_ptr<osgText::Text> text = new osgText::Text;
	text->setFont(_font);
	text->setColor(osg::Vec4(0,0,0,1));
	text->setCharacterSize(0.5);
	text->setPosition(osg::Vec3(1,1,0));
	text->setText(str);
	osg::ref_ptr<osg::Geode> message = new osg::Geode;
	osg::ref_ptr<osg::StateSet> stateset;
	stateset = message->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
	message->addDrawable(text);
	_textGroup->addChild(message);
}
