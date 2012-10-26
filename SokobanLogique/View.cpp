#include "View.h"
#include "Constants.h"
#include "DirectionButtonEventHandler.h"
#include "Hud.h"


Sokoban::View::View(std::string level)
{

	unsigned int height = 800;
	unsigned int width = height;
	ref_ptr<Group> root = new Group;
	//Viewer Init
	_viewer = new osgViewer::Viewer;
	_viewer->setUpViewInWindow(32, 32, width, height);
	_viewer->setSceneData(root);
	//Camera init
	ref_ptr<Camera> playBoard = new Camera;
	ref_ptr<Camera> buttons = new Camera;

	root->addChild(playBoard);
	root->addChild(buttons);

	unsigned int playBoardHeight = height*(3/4.0);
	unsigned int buttonsHeight = height - playBoardHeight;

	//Camera init
	playBoard->setAllowEventFocus(false);
	buttons->setAllowEventFocus(false);
	playBoard->setReferenceFrame(Camera::ABSOLUTE_RF);
	buttons->setReferenceFrame(Camera::ABSOLUTE_RF);

	playBoard->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	buttons->setClearColor(osg::Vec4(1.0, 1.0, 1.0, 0.0));

	buttons->setEventCallback(new DirectionButtonEventHandler());

	playBoard->setProjectionMatrixAsPerspective( 
		Sokoban::fovy, 
		width/(double)playBoardHeight, 
		Sokoban::near, 
		Sokoban::far 
		); 
	buttons->setProjectionMatrixAsOrtho(-12,12,-3,3,0.5,5);
	//Viewport
	playBoard->setViewport(new Viewport(0,buttonsHeight,width,playBoardHeight));
	buttons->setViewport(new Viewport(0,0,width,buttonsHeight));

	//Board
	Sokoban::Board::getInstance().init(level);
	playBoard->addChild(Sokoban::Board::getInstance().getLevel());
	Vec3 center = Sokoban::Board::getInstance().getCenter();
	Vec3 centerEye = Vec3(center[0],center[1],15.0);
	playBoard->setViewMatrixAsLookAt(centerEye, center, Sokoban::HAUT); 

	//Buttons
	Hud hud;
	buttons->addChild(hud.getNodes());
	buttons->setViewMatrixAsLookAt(Vec3(0,0,7),Vec3(0,0,0),Sokoban::HAUT);

}


Sokoban::View::~View(void)
{
}
