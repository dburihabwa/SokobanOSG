#include "View.h"
#include "../Constants.h"
#include "../Handlers/DirectionButtonEventHandler.h"
#include "../Handlers/KeyboardHandler.h"
#include "../GUI/Hud.h"


Sokoban::View::View(void)
{



}
void Sokoban::View::init(unsigned int height, unsigned int width) {
	ref_ptr<Group> root = new Group;
	//Viewer Init
	_viewer = new osgViewer::Viewer;
	_viewer->setUpViewInWindow(32, 32, width, height);
	_viewer->setSceneData(root);
	//Camera init
	_playBoard = new Camera;
	_buttons = new Camera;
	ref_ptr<Camera> textCamera = new Camera;

	root->addChild(_playBoard);
	root->addChild(_buttons);
	root->addChild(textCamera);

	unsigned int playBoardHeight = height*(3/4.0);
	unsigned int buttonsHeight = height - playBoardHeight;
	unsigned int textWidth = width/3;
	unsigned int restWidth = width - textWidth;

	//Camera init
	_playBoard->setAllowEventFocus(false);
	_buttons->setAllowEventFocus(false);
	textCamera->setAllowEventFocus(false);
	_playBoard->setReferenceFrame(Camera::ABSOLUTE_RF);
	_buttons->setReferenceFrame(Camera::ABSOLUTE_RF);
	textCamera->setReferenceFrame(Camera::ABSOLUTE_RF);

	_playBoard->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	_buttons->setClearColor(osg::Vec4(1.0, 1.0, 1.0, 0.0));

	_playBoard->setProjectionMatrixAsPerspective( 
		Sokoban::fovy, 
		restWidth/(double)playBoardHeight, 
		Sokoban::near, 
		Sokoban::far 
		); 
	_buttons->setProjectionMatrixAsPerspective( 
		50.0f, 
		restWidth/(double)buttonsHeight, 
		Sokoban::near, 
		100.0F
		); 
	textCamera->setProjectionMatrixAsPerspective( 
		80.0f, 
		textWidth/(double)height, 
		Sokoban::near, 
		100.0F
		); 
	//Viewport
	_playBoard->setViewport(new Viewport(0,buttonsHeight,restWidth,playBoardHeight));
	_buttons->setViewport(new Viewport(0,0,restWidth,buttonsHeight));
	textCamera->setViewport(new Viewport(restWidth,0,textWidth, height));

	//Board
	Sokoban::Board::getInstance().loadNextLvl();
	Vec3 center = Sokoban::Board::getInstance().getCenter();
	Vec3 centerEye = Vec3(center[0],center[1],16.0);
	_playBoard->setViewMatrixAsLookAt(centerEye, center, Sokoban::UP_AXIS); 

	//_buttons
	Hud hud;
	_buttons->addChild(hud.getNodes());
	_buttons->setViewMatrixAsLookAt(Vec3(0,0,10),Vec3(0,0,0),Sokoban::UP_AXIS);

	//Text
	textCamera->setViewMatrixAsLookAt(Vec3(0,0,10),Vec3(0,0,0),Y_AXIS);
	_textPanel = new TextPanel(textCamera);

	//Add keyboardController
	_viewer->addEventHandler(new KeyboardHandler());
	_viewer->addEventHandler(new DirectionButtonEventHandler());
}

void Sokoban::View::resetLevel(){
	if(_level) {
		const std::vector<osg::Group*>& parents = _level->getParents();
		for(unsigned int i = 0; i < parents.size(); ++i){
			osg::Group& parent = *parents[i];
			parent.removeChild(_level.get());
		}
		_level.release();
	}
}

void Sokoban::View::notify(Event modelEvent) {
	switch(modelEvent) {
	case LOAD_LVL:
	case LOAD_SAVE:
		this->resetLevel();
		loadLevel(Board::getInstance().getMovable(),Board::getInstance().getUnMovable());
		break;
	default:
		break;
	}
}
void Sokoban::View::loadLevel(const std::vector<std::vector<osg::ref_ptr<Case>>> &movable,const std::vector<std::vector<osg::ref_ptr<Case>>>& unMovable) {
	_level = new osg::Group;
	if(movable.size() == 0) {
		addText("Problème lors du chargement du niveau", MSG_WARNING);
		return;
	}
	unsigned int lenght = movable[0].size();
	for(unsigned int i =0; i < movable.size(); i++) {
		for(unsigned int j = 0; j < lenght; j++) {
			_level->addChild(unMovable[i][j]->createNode());
			_level->addChild(movable[i][j]->createNode());
		}
	}
	_playBoard->addChild(_level);
}
Sokoban::View::~View(void)
{
}
