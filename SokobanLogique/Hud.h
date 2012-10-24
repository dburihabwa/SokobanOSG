#pragma once

#include <time.h>
#include <vector>

#include "Board.h"
#include "DirectionButton.h"

namespace Sokoban 
{
    class Hud
    {
    public:
        Hud(void);
        ~Hud(void);
        unsigned int getElapsedTime() const;
        ref_ptr<Node> createNode();
        const std::vector<ref_ptr<DirectionButton> >& getButtons() const;
        const ref_ptr<osg::Group>& getNodes() const;
    private:
        clock_t _timer;
        std::vector<ref_ptr<DirectionButton> > _buttons;
        ref_ptr<osg::Group> _nodes;
    };
};