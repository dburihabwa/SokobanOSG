#pragma once
#include <string>
#include <osg/Group>
#include <osg/Camera>
#include <osgText\Font>

namespace Sokoban {
	class TextPanel : public osg::Referenced
	{
	public:
		TextPanel(osg::ref_ptr<osg::Camera> cam);
		void addText(std::string);
		void reset();
		~TextPanel(void);
	private:
		void init();
		osg::ref_ptr<osg::Camera> _camera;
		osg::ref_ptr<osg::Group> _textGroup;
		unsigned int _lastY;
		unsigned int _nbTxt;
		static osg::ref_ptr<osgText::Font> _font;
	};
}
