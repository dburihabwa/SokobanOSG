#pragma once

#include <time.h>
#include <vector>
#include <osgText\Text>

#include "../Logic/Board.h"
#include "DirectionButton.h"
#include "SaveButton.h"
#include "ZoomButton.h"

namespace Sokoban 
{
    class Hud
    {
    public:
        Hud(void);
        ~Hud(void);
        unsigned int getElapsedTime() const;
        osg::ref_ptr<osg::Node> createNode();
        const std::vector<osg::ref_ptr<GUIButton> >& getButtons() const;
		const osg::ref_ptr<SaveButton> getSaveButton() const;
        osg::ref_ptr<osg::Group> getNodes() const;
    private:
        clock_t _timer;
        std::vector<osg::ref_ptr<GUIButton> > _buttons;
        osg::ref_ptr<osg::Group> _nodes;
		osg::ref_ptr<SaveButton> _saveButton;
		osg::ref_ptr<ZoomButton> _zoomInButton;
		osg::ref_ptr<ZoomButton> _zoomOutButton;
		void createNodes();
    };
};