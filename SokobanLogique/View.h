#pragma once
#include <vector>
#include <osg/Camera>
#include <osgViewer/Viewer>
#include <string>
using namespace osg;
namespace Sokoban {
	class View
	{
	public:
		View(std::string);

		ref_ptr<osgViewer::Viewer> getViewer() const {
			return _viewer;
		}
		~View(void);
	private:
		ref_ptr<osgViewer::Viewer> _viewer;
	};
}

