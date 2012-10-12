#include <osgViewer/Viewer>
using namespace osg;

int main(void) {
	// D�finition d'un viewer et d'une fen�tre d'�cran associ�e
	ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow(32, 32, 512, 512);
	// D�sactive le "manipulator" par d�faut du viewer
	viewer->getCamera()->setAllowEventFocus(false);
	return viewer->run();
}