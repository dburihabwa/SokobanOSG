#pragma once
#include <vector>
#include <osg/Camera>
#include <osgViewer/Viewer>
#include <string>

namespace Sokoban {
	class View
	{
	public:
		static View& getInstance() {
			// The only instance
			// Guaranteed to be lazy initialized
			// Guaranteed that it will be destroyed correctly
			//Explained : http://stackoverflow.com/questions/86582/singleton-how-should-it-be-used
			static View instance;
			return instance;
		}
		///<summary>Init the viewer with the size of the window.</summary>
		void init(std::string,unsigned int, unsigned int);
		
		osg::ref_ptr<osgViewer::Viewer> getViewer() const {
			return _viewer;
		}
		osg::ref_ptr<osg::Camera> getButtonsCamera() {
			return _buttons;
		}
		~View(void);
	private:
		osg::ref_ptr<osgViewer::Viewer> _viewer;
		osg::ref_ptr<osg::Camera> _buttons;	
		View();
		View(View const&);              // Don't Implement
		void operator=(View const&); // Don't implement

	};
}

