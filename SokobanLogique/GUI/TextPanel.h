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
		osg::ref_ptr<osgText::Text> _movementScore;
		osg::ref_ptr<osgText::Text> _boxScore;
		unsigned int _nbTxt;
		unsigned int _maxHeight;
		unsigned int _mvntScore;
		unsigned int _bScore;
		static osg::ref_ptr<osgText::Font> _font;
		void updatePosition();
		std::map<std::string,osg::ref_ptr<osg::Geode>> _textCache;
		osg::ref_ptr<osg::Geode> getOrCreateGeode(std::string text, osg::Vec4 color);
		osg::ref_ptr<osgText::Text> generateText(std::string text, osg::Vec4 color);
		osg::ref_ptr<osg::Geode> generateGeode(osg::ref_ptr<osgText::Text>);
		static std::string _playerString;
		static std::string _boxString;
	};
}
