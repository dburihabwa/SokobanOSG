#pragma once

#include <osg/NodeCallback>

#include "DirectionButton.h"

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

