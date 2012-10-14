#include <osgViewer/Viewer>
#include "Constants.h"
using namespace osg;

int main(void) {
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
	return viewer->run();
}