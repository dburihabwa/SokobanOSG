#pragma once
#include <string>
#include <osg/Group>
#include <osg/Camera>
#include <osgText\Font>
#include <map>

namespace Sokoban {
	class TextPanel : public osg::Referenced
	{
	public:
		TextPanel(osg::ref_ptr<osg::Camera> cam);
		///<summary>Display a text in the panel with the wanted color</summary>
		void addText(std::string, osg::Vec4);
		void reset();
		~TextPanel(void);
	private:
		void init();
		osg::ref_ptr<osg::Camera> _camera;
		osg::ref_ptr<osg::Group> _textGroup;
		unsigned int _nbTxt;
		unsigned int _maxHeight;
		static osg::ref_ptr<osgText::Font> _font;
		void updatePosition();
		std::map<std::string,osg::ref_ptr<osg::Geode>> _textCache;
		osg::ref_ptr<osg::Geode> getOrCreateGeode(std::string text, osg::Vec4 color);
	};
}
