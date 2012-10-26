#pragma once
#include <list>

#include <osg/NodeCallback>
#include <osgGA/GUIEventAdapter>
#include <osgGA/EventVisitor>

#include "Board.h"
#include "DirectionButton.h"

using namespace osgGA;
using namespace osg;

namespace Sokoban {
    class DirectionButtonEventHandler : public osg::NodeCallback
    {
    public:
        DirectionButtonEventHandler(Direction direction);
        ~DirectionButtonEventHandler(void);

        void operator()(Node* node, NodeVisitor* nv);
    private:
        Sokoban::Direction _direction;
    };
};

