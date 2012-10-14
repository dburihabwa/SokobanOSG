#include <osgViewer/Viewer>
#include "Constants.h"
using namespace osg;

int main(void) {
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
	return viewer->run();
}