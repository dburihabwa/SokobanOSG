#include "TextPanel.h"
#include "../Constants.h"

#include <osgText\Text>
#include <iostream>
#include <osg/Node>
#include <osg/PositionAttitudeTransform>
#include <sstream>



osg::ref_ptr<osgText::Font> Sokoban::TextPanel::_font = osgText::readFontFile("fonts/arial.ttf");
std::string Sokoban::TextPanel::_playerString = "Joueur: ";
std::string Sokoban::TextPanel::_boxString = "Boite: ";

Sokoban::TextPanel::TextPanel(osg::ref_ptr<osg::Camera> cam) : _camera(cam.get()), _nbTxt(0), _mvntScore(0), _bScore(0)
{
	init();
	_maxHeight = (_camera->getViewport()->height()/2)- 110;
	_camera->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	//Set Score text
	std::stringstream buffer;
	buffer<<_playerString<<_mvntScore;
	std::stringstream buffer2;
	buffer2<<_boxString<<_bScore;
	//Text
	_movementScore = generateText(buffer.str(), MSG_NORMAL);
	_boxScore = generateText(buffer2.str(), MSG_NORMAL);

	//PostAtt
	osg::ref_ptr<osg::PositionAttitudeTransform> posPlayer = new osg::PositionAttitudeTransform();
	osg::ref_ptr<osg::PositionAttitudeTransform> posBox = new osg::PositionAttitudeTransform();
	posPlayer->addChild(generateGeode(_movementScore));
	posBox->addChild(generateGeode(_boxScore));

	posPlayer->setPosition(osg::Vec3(-2.7,8,0));
	posBox->setPosition(osg::Vec3(1,8,0));
	_camera->addChild(posPlayer);
	_camera->addChild(posBox);
}


Sokoban::TextPanel::~TextPanel(void) {
}

void Sokoban::TextPanel::reset() {
	_camera->removeChild(_textGroup);
	_textGroup.release();
	_textCache.clear();
	_nbTxt = 0;
	init();
}
void Sokoban::TextPanel::init() {
	_textGroup = new osg::Group;
	_camera->addChild(_textGroup);
}

void Sokoban::TextPanel::addText(std::string str, osg::Vec4 color) {
#if DEBUG==TRUE
	std::cout<<str<<std::endl;
#endif
	updatePosition();
	osg::ref_ptr<osg::PositionAttitudeTransform> pos = new osg::PositionAttitudeTransform();
	pos->addChild(this->getOrCreateGeode(str,color));
	pos->setPosition(osg::Vec3(-3.3,7.2,0));
	pos->setName(str);
	_textGroup->addChild(pos);
	_nbTxt++;
}
void Sokoban::TextPanel::updatePosition() {
	osg::ref_ptr<osg::Node> toBeDeleted;
	for(unsigned int i = 0; i < _nbTxt; i++) {
		osg::ref_ptr<osg::PositionAttitudeTransform> posAtt = static_cast<osg::PositionAttitudeTransform *>(_textGroup->getChild(i));
		osg::ref_ptr<osg::Geode> node = static_cast<osg::Geode*>(posAtt->getChild(0));
		osg::ref_ptr<osgText::Text> text = static_cast<osgText::Text*>(node->getDrawable(0));
		osg::Vec3 pos = posAtt->getPosition();
		pos += osg::Vec3(0,-0.4,0);
		if(-pos.y() * text->getFontHeight()  >= _maxHeight) {
			toBeDeleted = posAtt;
		}
		else {
			posAtt->setPosition(pos);
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

osg::ref_ptr<osg::Geode> Sokoban::TextPanel::getOrCreateGeode(std::string str, osg::Vec4 color) {
	if(_textCache.find(str) != _textCache.end()) {
		return _textCache[str];
	}
	osg::ref_ptr<osgText::Text> text = generateText(str,color);
	osg::ref_ptr<osg::Geode> message = generateGeode(text);
	_textCache.insert(std::make_pair(str,message));
	return message;
}

osg::ref_ptr<osgText::Text> Sokoban::TextPanel::generateText(std::string str, osg::Vec4 color) {
	osg::ref_ptr<osgText::Text> text = new osgText::Text;
	text->setFont(_font);
	text->setColor(color);
	text->setCharacterSize(0.4);
	text->setText(str);
	return text;
}

osg::ref_ptr<osg::Geode> Sokoban::TextPanel::generateGeode(osg::ref_ptr<osgText::Text> text) {
	osg::ref_ptr<osg::Geode> message = new osg::Geode;
	osg::ref_ptr<osg::StateSet> stateset;
	stateset = message->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
	message->addDrawable(text);
	return message;
}
