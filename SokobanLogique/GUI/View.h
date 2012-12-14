#pragma once
#include <vector>
#include <osg/Camera>
#include <osgViewer/Viewer>
#include <string>
#include "TextPanel.h"
#include "../Constants.h"
#include "../Event.h"
#include "../Logic/Movable.h"
#include "../Logic/Unmovable.h"
#include <osg/LightSource>
#include "../Logic/IView.h"

namespace Sokoban {
	class View : public IView
	{
	public:
		static osg::ref_ptr<View> getInstance() {
			if(!instance) {
				instance = new View();
			}
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
		///<summary> Notify the view that it have to refresh</summary>
		void notify(Event);
		~View(void);
		void changeZoomOnBoard(double) const;
		///<summary> tries to rotate the playground within predefined limits</summary>
		bool rotatePlayGround(Type type);
	private:
		osg::ref_ptr<osgViewer::Viewer> _viewer;
		osg::ref_ptr<osg::Camera> _buttons;	
		osg::ref_ptr<osg::Camera> _playBoard;
		osg::ref_ptr<TextPanel> _textPanel;
		osg::ref_ptr<osg::Group> _level;
		osg::ref_ptr<osg::LightSource> _playerLight;
		osg::ref_ptr<osg::Light> _ambientLight;
		View();
		View(View const&);              // Don't Implement
		void operator=(View const&); // Don't implement
		void resetLevel();
		void loadLevel(const std::vector<std::vector<osg::ref_ptr<Movable>>>&,const std::vector<std::vector<osg::ref_ptr<Unmovable>>> &);
		void initLevel();
		void setLights();
		static osg::ref_ptr<View> instance;
		///<summary>Display a text in the text panel with the wanted color</summary>
		void addText(std::string str, osg::Vec4 color = MSG_NORMAL) const {
			_textPanel->addText(str, color);
		}
		void manageMessage(Event);
		
	};
}

