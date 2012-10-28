#pragma once

#include <time.h>
#include <vector>
#include <osgText\Text>

#include "../Logic/Board.h"
#include "DirectionButton.h"

namespace Sokoban 
{
    class Hud
    {
    public:
        Hud(void);
        ~Hud(void);
        unsigned int getElapsedTime() const;
        osg::ref_ptr<osg::Node> createNode();
        const std::vector<osg::ref_ptr<DirectionButton> >& getButtons() const;
        osg::ref_ptr<osg::Group> getNodes() const;
    private:
        clock_t _timer;
        std::vector<osg::ref_ptr<DirectionButton> > _buttons;
        osg::ref_ptr<osg::Group> _nodes;
    };
};