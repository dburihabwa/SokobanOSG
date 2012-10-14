#include <osgViewer/Viewer>
#include "Constants.h"
#include "Ground.h"
#include <osg/Group>
using namespace osg;

int main(void) {
	ref_ptr<Group> root = new Group;
	// D�finition d'un viewer et d'une fen�tre d'�cran associ�e
	ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow(32, 32, 512, 512);
	// D�sactive le "manipulator" par d�faut du viewer
	viewer->getCamera()->setAllowEventFocus(false);
	viewer->getCamera()->setProjectionMatrixAsPerspective( 
		Sokoban::fovy, 
		Sokoban::ratio, 
		Sokoban::near, 
		Sokoban::far 
		); 
	viewer->getCamera()->setViewMatrixAsLookAt(Sokoban::oeil, Sokoban::cible, Sokoban::normale); 
	viewer->getCamera()->setClearColor(osg::Vec4(0.0, 0.0, 0.0, 0.0)); 
	ref_ptr<Sokoban::Ground> ground = new Sokoban::Ground(0,0,0);
	ref_ptr<Sokoban::Ground> ground2 = new Sokoban::Ground(0,1,0);
	root->addChild(ground->createGeode());
	root->addChild(ground2->createGeode());
	viewer->setSceneData(root.get());
	return viewer->run();
}