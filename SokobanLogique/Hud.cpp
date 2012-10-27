#include "Hud.h"
#include "DirectionButtonEventHandler.h"

/// Creates the new Hud
Sokoban::Hud::Hud(void) {
    this->_timer = clock();
    this->_nodes = new osg::Group();
	int posY = -10;
    ref_ptr<DirectionButton> upDirectionButton =  new DirectionButton(-1, 1+posY, 0, Sokoban::UP);
    ref_ptr<DirectionButton> downDirectionButton =  new DirectionButton(3, 1+posY, 0, Sokoban::DOWN);
    ref_ptr<DirectionButton> leftDirectionButton =  new DirectionButton(1, -1+posY, 0, Sokoban::LEFT);
    ref_ptr<DirectionButton> rightDirectionButton =  new DirectionButton(1, 3+posY, 0, Sokoban::RIGHT);
    
    this->_buttons.push_back(upDirectionButton);
    this->_buttons.push_back(downDirectionButton);
    this->_buttons.push_back(leftDirectionButton);
    this->_buttons.push_back(rightDirectionButton);
    
    std::vector<ref_ptr<Sokoban::DirectionButton> >::iterator it;
    for (it = this->_buttons.begin(); it < this->_buttons.end(); it++) {
        ref_ptr<osg::Node> node = (*it)->createNode();
		node->setUserData((*it));
        this->_nodes->addChild(node);
    }

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

const std::vector<ref_ptr<Sokoban::DirectionButton> >& Sokoban::Hud::getButtons() const
{
    return this->_buttons;
}

ref_ptr<osg::Group> Sokoban::Hud::getNodes() const
{
    return this->_nodes;
}