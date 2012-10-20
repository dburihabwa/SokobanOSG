#include <osgViewer/Viewer>
#include "Constants.h"
#include "Ground.h"
#include <osg/Group>
#include <string>
#include "Board.h"
using namespace osg;
//#define lvl 1;
int main(void) {
	//ref_ptr<Group> root = new Group;
	// Définition d'un viewer et d'une fenêtre d'écran associée
	ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow(32, 32, 512, 512);
	// Désactive le "manipulator" par défaut du viewer
	viewer->getCamera()->setAllowEventFocus(false);
	viewer->getCamera()->setProjectionMatrixAsPerspective( 
		Sokoban::fovy, 
		Sokoban::ratio, 
		Sokoban::near, 
		Sokoban::far 
		); 
	viewer->getCamera()->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0)); 
	//ref_ptr<Sokoban::Case> ground = new Sokoban::Ground(0,0,0);
	//ref_ptr<Sokoban::Case> ground2 = new Sokoban::Ground(0,1,0);
	//root->addChild(ground->createNode());
	//root->addChild(ground2->createNode());
	//viewer->setSceneData(root.get());
	std::string level;
#ifdef lvl
	level =
		"#######\n"
		"#     #\n"
		"#     #\n"
		"#. #  #\n"
		"#. $$ #\n"
		"#.$$  #\n"
		"#.#  @#\n"
		"#######";
#else
	level = 
		"    #####          \n"
		"    #   #          \n"
		"    #$  #          \n"
		"  ###  $##         \n"
		"  #  $ $ #         \n"
		"### # ## #   ######\n"
		"#   # ## #####  ..#\n"
		"# $  $          ..#\n"
		"##### ### #@##  ..#\n"
		"    #     #########\n"
		"    #######        ";
#endif
	
	Sokoban::Board::getInstance().init(level);
	Vec3 center = Sokoban::Board::getInstance().getCenter();
	Vec3 centerEye = Vec3(center[0],center[1],15.0);
	viewer->getCamera()->setViewMatrixAsLookAt(centerEye, center, Sokoban::HAUT); 
	viewer->setSceneData(Sokoban::Board::getInstance().getLevel());
	//Sokoban::Board::getInstance().movePlayer(Sokoban::UP);
	Sokoban::Board::getInstance().displayLevel();
	return viewer->run();
}