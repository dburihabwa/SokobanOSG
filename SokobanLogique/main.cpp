#include <osgViewer/Viewer>
#include "Constants.h"
#include "Ground.h"
#include <osg/Group>
#include <string>
#include "Board.h"
using namespace osg;

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
	viewer->getCamera()->setViewMatrixAsLookAt(Sokoban::oeil, Sokoban::cible, Sokoban::normale); 
	viewer->getCamera()->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0)); 
	//ref_ptr<Sokoban::Case> ground = new Sokoban::Ground(0,0,0);
	//ref_ptr<Sokoban::Case> ground2 = new Sokoban::Ground(0,1,0);
	//root->addChild(ground->createGeode());
	//root->addChild(ground2->createGeode());
	//viewer->setSceneData(root.get());
	std::string level =
		"#######\n"
		"#     #\n"
		"#     #\n"
		"#. #  #\n"
		"#. $$ #\n"
		"#.$$  #\n"
		"#.#  @#\n"
		"#######";
	Sokoban::Board board =  Sokoban::Board(level);
	viewer->setSceneData(board.getLevel());
	return viewer->run();
}