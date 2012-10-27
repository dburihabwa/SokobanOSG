#include "View.h"
#include "Constants.h"
#include "DirectionButtonEventHandler.h"
#include "EventController.h"
#include "Hud.h"


Sokoban::View::View(void)
{

	

}
void Sokoban::View::init(std::string level, unsigned int height, unsigned int width) {
	ref_ptr<Group> root = new Group;
	//Viewer Init
	_viewer = new osgViewer::Viewer;
	_viewer->setUpViewInWindow(32, 32, width, height);
	_viewer->setSceneData(root);
	//Camera init
	ref_ptr<Camera> playBoard = new Camera;
	_buttons = new Camera;

	root->addChild(playBoard);
	root->addChild(_buttons);

	unsigned int playBoardHeight = height*(3/4.0);
	unsigned int buttonsHeight = height - playBoardHeight;

	//Camera init
	playBoard->setAllowEventFocus(false);
	_buttons->setAllowEventFocus(false);
	playBoard->setReferenceFrame(Camera::ABSOLUTE_RF);
	_buttons->setReferenceFrame(Camera::ABSOLUTE_RF);

	playBoard->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	_buttons->setClearColor(osg::Vec4(1.0, 1.0, 1.0, 0.0));

	playBoard->setProjectionMatrixAsPerspective( 
		Sokoban::fovy, 
		width/(double)playBoardHeight, 
		Sokoban::near, 
		Sokoban::far 
		); 
	_buttons->setProjectionMatrixAsPerspective( 
		Sokoban::fovy, 
		width/(double)buttonsHeight, 
		Sokoban::near, 
		100.0F
		); 
	//Viewport
	playBoard->setViewport(new Viewport(0,buttonsHeight,width,playBoardHeight));
	_buttons->setViewport(new Viewport(0,0,width,buttonsHeight));

	//Board
	Sokoban::Board::getInstance().init(level);
	playBoard->addChild(Sokoban::Board::getInstance().getLevel());
	Vec3 center = Sokoban::Board::getInstance().getCenter();
	Vec3 centerEye = Vec3(center[0],center[1],15.0);
	playBoard->setViewMatrixAsLookAt(centerEye, center, Sokoban::HAUT); 

	//_buttons
	Hud hud;
	_buttons->addChild(hud.getNodes());
	_buttons->setViewMatrixAsLookAt(Vec3(0,0,10),Vec3(0,0,0),Sokoban::HAUT);

	//Add keyboardController
	_viewer->addEventHandler(new EventController());
	_viewer->addEventHandler(new DirectionButtonEventHandler());
}

Sokoban::View::~View(void)
{
}
