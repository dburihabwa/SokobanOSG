#include <osgViewer/Viewer>

using namespace osg;

int main(void) {
	// Définition d'un viewer et d'une fenêtre d'écran associée
	ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow(32, 32, 512, 512);
	// Désactive le "manipulator" par défaut du viewer
	viewer->getCamera()->setAllowEventFocus(false);
	return viewer->run();
}