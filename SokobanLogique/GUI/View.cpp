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
	ref_ptr<Camera> playBoard = new Camera;
	_buttons = new Camera;
	ref_ptr<Camera> textCamera = new Camera;

	root->addChild(playBoard);
	root->addChild(_buttons);
	root->addChild(textCamera);

	unsigned int playBoardHeight = height*(3/4.0);
	unsigned int buttonsHeight = height - playBoardHeight;
	unsigned int textWidth = width/3;
	unsigned int restWidth = width - textWidth;

	//Camera init
	playBoard->setAllowEventFocus(false);
	_buttons->setAllowEventFocus(false);
	textCamera->setAllowEventFocus(false);
	playBoard->setReferenceFrame(Camera::ABSOLUTE_RF);
	_buttons->setReferenceFrame(Camera::ABSOLUTE_RF);
	textCamera->setReferenceFrame(Camera::ABSOLUTE_RF);

	playBoard->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	_buttons->setClearColor(osg::Vec4(1.0, 1.0, 1.0, 0.0));

	playBoard->setProjectionMatrixAsPerspective( 
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
	playBoard->setViewport(new Viewport(0,buttonsHeight,restWidth,playBoardHeight));
	_buttons->setViewport(new Viewport(0,0,restWidth,buttonsHeight));
	textCamera->setViewport(new Viewport(restWidth,0,textWidth, height));

	//Board
	if(!Sokoban::Board::getInstance().loadSave()) {
		Sokoban::Board::getInstance().loadNextLvl();
	}
	playBoard->addChild(Sokoban::Board::getInstance().getLevel());
	Vec3 center = Sokoban::Board::getInstance().getCenter();
	Vec3 centerEye = Vec3(center[0],center[1],16.0);
	playBoard->setViewMatrixAsLookAt(centerEye, center, Sokoban::UP_AXIS); 

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

Sokoban::View::~View(void)
{
}
