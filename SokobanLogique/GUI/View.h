#pragma once
#include <vector>
#include <osg/Camera>
#include <osgViewer/Viewer>
#include <string>
#include "TextPanel.h"
#include "../Constants.h"
#include "../Event.h"
#include "../Logic/Case.h"

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
		void init(unsigned int, unsigned int);
		
		osg::ref_ptr<osgViewer::Viewer> getViewer() const {
			return _viewer;
		}
		osg::ref_ptr<osg::Camera> getButtonsCamera() {
			return _buttons;
		}
		void addText(std::string str) const {
			this->addText(str, MSG_NORMAL);
		}
		///<summary>Display a text in the text panel with the wanted color</summary>
		void addText(std::string str, osg::Vec4 color) const {
			_textPanel->addText(str, color);
		}
		///<summary> Notify the view that it have to refresh</summary>
		void notify(Event);
		~View(void);
	private:
		osg::ref_ptr<osgViewer::Viewer> _viewer;
		osg::ref_ptr<osg::Camera> _buttons;	
		osg::ref_ptr<osg::Camera> _playBoard;	
		osg::ref_ptr<TextPanel> _textPanel;
		osg::ref_ptr<osg::Group> _level;
		View();
		View(View const&);              // Don't Implement
		void operator=(View const&); // Don't implement
		void resetLevel();
		void loadLevel(const std::vector<std::vector<osg::ref_ptr<Case>>>&,const std::vector<std::vector<osg::ref_ptr<Case>>> &);

	};
}

