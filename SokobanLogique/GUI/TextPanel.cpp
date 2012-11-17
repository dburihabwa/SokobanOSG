#include "TextPanel.h"
#include "../Constants.h"

#include <osgText\Text>
#include <iostream>
#include <osg/Node>



osg::ref_ptr<osgText::Font> Sokoban::TextPanel::_font = osgText::readFontFile("fonts/arial.ttf");

Sokoban::TextPanel::TextPanel(osg::ref_ptr<osg::Camera> cam) : _camera(cam.get()), _nbTxt(0), _lastY(0)
{
	init();
	_maxHeight = (_camera->getViewport()->height()/2)- 110;
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
	updatePostion();
	osg::ref_ptr<osgText::Text> text = new osgText::Text;
	text->setFont(_font);
	text->setColor(osg::Vec4(0,0,0,1));
	text->setCharacterSize(0.4);
	text->setPosition(osg::Vec3(-3.3,8,0));
	text->setText(str);
	osg::ref_ptr<osg::Geode> message = new osg::Geode;
	message->setName(str);
	osg::ref_ptr<osg::StateSet> stateset;
	stateset = message->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
	message->addDrawable(text);
	_textGroup->addChild(message);
	_nbTxt++;
}
void Sokoban::TextPanel::updatePostion() {
	osg::ref_ptr<osg::Geode> toBeDeleted;
	for(unsigned int i = 0; i < _nbTxt; i++) {
		osg::ref_ptr<osg::Geode> node = static_cast<osg::Geode*>(_textGroup->getChild(i));
		osg::ref_ptr<osgText::Text> text = static_cast<osgText::Text*>(node->getDrawable(0));
		osg::Vec3 pos = text->getPosition();
		pos += osg::Vec3(0,-0.4,0);
		if(-pos.y() * text->getFontHeight()  >= _maxHeight) {
			toBeDeleted = node;
		}
		else {
			text->setPosition(pos);
		}
	}
	if(toBeDeleted) {
		_textGroup->removeChild(toBeDeleted);
		_nbTxt--;
#if DEBUG == TRUE
		std::cout<<"Child deleted : "<<toBeDeleted->getName()<<std::endl;
#endif
	}
}
