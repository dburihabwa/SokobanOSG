#include "Hud.h"
#include "../Factories/NodeFactory.h"
#include "../Constants.h"
#include "LoadSavedGameButton.h"
#include "ReloadButton.h"
#include <osg/PositionAttitudeTransform>

/// Creates the new Hud
Sokoban::Hud::Hud(void) {
	this->_timer = clock();
	this->_nodes = new osg::Group();
	int posY = -10;
	osg::ref_ptr<DirectionButton> upDirectionButton =  new DirectionButton(-1, 1+posY, 0, Sokoban::UP);

	osg::ref_ptr<DirectionButton> downDirectionButton =  new DirectionButton(3, 1+posY, 0, Sokoban::DOWN);
	osg::ref_ptr<DirectionButton> leftDirectionButton =  new DirectionButton(1, -1+posY, 0, Sokoban::LEFT);
	osg::ref_ptr<DirectionButton> rightDirectionButton =  new DirectionButton(1, 3+posY, 0, Sokoban::RIGHT);

	this->_buttons.push_back(upDirectionButton);
	this->_buttons.push_back(downDirectionButton);
	this->_buttons.push_back(leftDirectionButton);
	this->_buttons.push_back(rightDirectionButton);
	
	// Game option buttons
	this->_saveButton = new SaveButton(0, 0, 0);
	this->_zoomInButton = new ZoomButton(-2, 0, 0, ZOOM_IN);
	this->_zoomOutButton = new ZoomButton(-2, 2, 0, ZOOM_OUT);

	this->_buttons.push_back(this->_saveButton);
	this->_buttons.push_back(this->_zoomInButton);
	this->_buttons.push_back(this->_zoomOutButton);
	this->_buttons.push_back(new LoadSavedGameButton(0,2,0));
	this->_buttons.push_back(new ReloadButton(2,0,0));

	createNodes();

	/*
	ref_ptr<osg::Geode> geodeText = new osg::Geode();
	ref_ptr<osgText::Text> text = new osgText::Text(); 
	text->setText("Score");
	text->setPosition(osg::Vec3(100, 100, 6));
	geodeText->addDrawable(text);
	this->_nodes->addChild(geodeText);
	*/
}


Sokoban::Hud::~Hud(void)
{
}

unsigned int Sokoban::Hud::getElapsedTime() const
{
	return (this->_timer - clock()) / CLOCKS_PER_SEC;
}

const std::vector<osg::ref_ptr<Sokoban::GUIButton> >& Sokoban::Hud::getButtons() const
{
	return this->_buttons;
}

osg::ref_ptr<osg::Group> Sokoban::Hud::getNodes() const
{
	return this->_nodes;
}
void Sokoban::Hud::createNodes() {
	std::vector<osg::ref_ptr<Sokoban::GUIButton> >::iterator it;
	for (it = this->_buttons.begin(); it < this->_buttons.end(); it++) {
		osg::Vec3 pos = (*it)->getPosition();
		osg::ref_ptr<osg::PositionAttitudeTransform> node = dynamic_cast<osg::PositionAttitudeTransform *> (NodeFactory::createNode(pos.x(),pos.y(),pos.z(),(*it)->getType()).get());
		node->setUserData(*it);
		
		// If the GUIButton is DirectionButton
		if ((*it)->getType() == DIRECTION_BUTTON) {
			osg::ref_ptr<DirectionButton> db = static_cast<DirectionButton *>((*it).get());
			Direction direction = db->getDirection();
			if(direction==UP) {
				node->setAttitude(DEGREE_180);
			} else if(direction == LEFT) {
				node->setAttitude(DEGREE_MIN_90);
			} else if(direction == RIGHT) {
				node->setAttitude(DEGREE_90);
			}
		}
		this->_nodes->addChild(node);
	}
}