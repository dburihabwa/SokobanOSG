#include "View.h"
#include "../Constants.h"
#include "../Handlers/DirectionButtonEventHandler.h"
#include "../Handlers/KeyboardHandler.h"
#include "../GUI/Hud.h"
#include "../Factories/NodeFactory.h"
#include "../Updaters/PlayerAnimationUpdater.h"
#include "../Adapters/OSGMoveAdapter.h"
#include "../Handlers/ScrollHandler.h"
#include "../Logic/Empty.h"
#include <osg/Quat>

osg::ref_ptr<Sokoban::View> Sokoban::View::instance = NULL;

Sokoban::View::View(void) {
}
void Sokoban::View::init(unsigned int height, unsigned int width) {
	osg::ref_ptr<osg::Group> root = new osg::Group();
	//Viewer Init
	_viewer = new osgViewer::Viewer;
	_viewer->setUpViewInWindow(32, 32, width, height);
	_viewer->setSceneData(root);
	//Camera init
	_playBoard = new osg::Camera();
	_buttons = new osg::Camera();
	osg::ref_ptr<osg::Camera> textCamera = new osg::Camera();

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
	_playBoard->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	_buttons->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	textCamera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);

	_playBoard->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	_buttons->setClearColor(osg::Vec4(0, 0, 0, 0));

	_playBoard->setProjectionMatrixAsPerspective( 
		Sokoban::FOVY, 
		restWidth/(double)playBoardHeight, 
		Sokoban::NEAR, 
		Sokoban::FAR 
		); 
	_buttons->setProjectionMatrixAsPerspective( 
		43.0f, 
		restWidth/(double)buttonsHeight, 
		Sokoban::NEAR, 
		100.0F
		); 
	textCamera->setProjectionMatrixAsPerspective( 
		80.0f, 
		textWidth/(double)height, 
		Sokoban::NEAR, 
		100.0F
		); 
	//Viewport
	_playBoard->setViewport(new osg::Viewport(0,buttonsHeight,restWidth,playBoardHeight));
	_buttons->setViewport(new osg::Viewport(0,0,restWidth,buttonsHeight));
	textCamera->setViewport(new osg::Viewport(restWidth,0,textWidth, height));

	//Text
	textCamera->setViewMatrixAsLookAt(osg::Vec3(0,0,10),osg::Vec3(0,0,0),osg::Y_AXIS);
	_textPanel = new TextPanel(textCamera);

	//lights
	setLights();

	//Board
	Sokoban::Board::getInstance().addView(osg::ref_ptr<IView>(this));
	_rotator = new osg::PositionAttitudeTransform();
	_playBoard->addChild(_rotator);
	//_buttons
	Hud hud;
	_buttons->addChild(hud.getNodes());
	_buttons->setViewMatrixAsLookAt(osg::Vec3(0,0,10),osg::Vec3(0,0,0),Sokoban::UP_AXIS);

	//Add keyboardController
	_viewer->addEventHandler(new KeyboardHandler());
	_viewer->addEventHandler(new DirectionButtonEventHandler());
	_viewer->addEventHandler(new ScrollHandler());
	this->addText("appuyer sur R.");
	this->addText("Pour recharger le niveau");
	this->addText("Bienvenue dans Sokoban.", MSG_OK);
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
		initLevel();
		break;
	case LOAD_SAVE:
		initLevel();
		_textPanel->setPlayerScore(Board::getInstance().getPlayerScore());
		_textPanel->setBoxScore(Board::getInstance().getBoxScore());
		break;
	case PLAYER_MOVED:
		_textPanel->setPlayerScore(Board::getInstance().getPlayerScore());
		break;
	case BOX_MOVED:
		_textPanel->setBoxScore(Board::getInstance().getBoxScore());
		break;
	case NORM_MSG:
	case OK_MSG:
	case WARN_MSG:
		manageMessage(modelEvent);
		break;
	default:
		break;
	}
}
void Sokoban::View::loadLevel(const std::vector<std::vector<osg::ref_ptr<Movable>>> &movable,const std::vector<std::vector<osg::ref_ptr<Unmovable>>>& unMovable) {
	_level = new osg::Group;
	if(movable.size() == 0) {
		addText("Probl�me lors du chargement du niveau", MSG_WARNING);
		return;
	}
	osg::Vec3 center = Board::getInstance().getCenter();
	_ambientLight->setPosition(osg::Vec4(center.x(),center.y(),2,0)); // Source directionnelle
	unsigned int lenght = movable[0].size();
	for(unsigned int i =0; i < movable.size(); i++) {
		for(unsigned int j = 0; j < lenght; j++) {
			osg::Vec3 pos = unMovable[i][j]->getPosition();
			_level->addChild(NodeFactory::createNode(pos.x(),pos.y(),pos.z(), unMovable[i][j]->getType()));
			osg::ref_ptr<Movable> mov = movable[i][j];
			if(dynamic_cast<Empty*>(mov.get())) {
				continue;
			}
			pos = mov->getPosition();
			osg::ref_ptr<osg::PositionAttitudeTransform> node = NodeFactory::createNode(pos.x(),pos.y(),pos.z(), mov->getType());
			osg::ref_ptr<AnimationUpdater> updater;
			if(dynamic_cast<Box*>(mov.get())) {
				updater= new AnimationUpdater();
			} else if(dynamic_cast<Player*>(mov.get())) {
				updater = new PlayerAnimationUpdater();
				node->addChild(_playerLight);
			}
			osg::ref_ptr<MoveAdapter> adapter = new OSGMoveAdapter(updater);
			node->setUpdateCallback(updater);
			mov->setMoveAdapter(adapter);
			_level->addChild(node);
		}
	}
	_rotator->addChild(_level);

	osg::Vec3 centerEye = osg::Vec3(center.x()+10,center.y(),16.0);
	_playBoard->setViewMatrixAsLookAt(centerEye, center, Sokoban::UP_AXIS); 
}

void Sokoban::View::changeZoomOnBoard(double fovDiff) const{
	double fov, ar,NEAR,FAR;
	_playBoard->getProjectionMatrixAsPerspective(fov,ar,NEAR,FAR);
	fov+=fovDiff;
	_playBoard->setProjectionMatrixAsPerspective(fov,ar,NEAR,FAR);
}

Sokoban::View::~View(void) {
}

void Sokoban::View::rotatePlayGround(float rotation) {
	osg::Quat rot = _rotator->getAttitude();
		rot+=osg::Quat(rotation,osg::Z_AXIS);
		_rotator->setAttitude(rot);
}

void Sokoban::View::initLevel() {
	this->resetLevel();
	_rotator->setAttitude(osg::Quat(0,osg::Z_AXIS));
	if(this->_textPanel) {
		this->_textPanel->reset();
	}
	loadLevel(Board::getInstance().getMovable(),Board::getInstance().getUnMovable());
}

void Sokoban::View::setLights() {
	osg::StateSet *lightStateSet = _playBoard->getOrCreateStateSet();
	//Player Light
	osg::ref_ptr<osg::Light> lightForPlayer = new osg::Light;
	lightForPlayer->setLightNum(0);
	lightForPlayer->setAmbient(osg::Vec4(0,0,0,1));
	lightForPlayer->setDiffuse(osg::Vec4(0,1,0,1));
	lightForPlayer->setPosition(osg::Vec4(0,0,0,1));
	lightForPlayer->setConstantAttenuation(1.5);
	_playerLight = new osg::LightSource();
	_playerLight->setLight(lightForPlayer);
	_playerLight->setLocalStateSetModes(osg::StateAttribute::ON);
	_playerLight->setStateSetModes(*lightStateSet,osg::StateAttribute::ON);


	//Ambient light
	_ambientLight = new osg::Light;
	_ambientLight->setLightNum(1);
	_ambientLight->setDiffuse(osg::Vec4(1,0,0,1));
	_ambientLight->setAmbient( osg::Vec4(0,0, 0, 1.0));

	osg::ref_ptr<osg::LightSource> ambient = new osg::LightSource(); 
	ambient->setLight(_ambientLight);
	ambient->setReferenceFrame(osg::LightSource::ABSOLUTE_RF);
	ambient->setLocalStateSetModes(osg::StateAttribute::ON);
	ambient->setStateSetModes(*lightStateSet,osg::StateAttribute::ON); // Active la lumi�re AmbientLight


	//Set on Camera
	_playBoard->addChild(ambient);

}

void Sokoban::View::manageMessage(Event sokoEvent) {
	switch(sokoEvent)
	{
	case NORM_MSG:
		addText(Board::getInstance().getMessage());
		break;
	case OK_MSG:
		addText(Board::getInstance().getMessage(),MSG_OK);
		break;
	case WARN_MSG:
		addText(Board::getInstance().getMessage(),MSG_WARNING);
		break;
	default:
		break;
	}
}