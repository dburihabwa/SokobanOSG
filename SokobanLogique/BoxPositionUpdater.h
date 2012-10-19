#pragma once
#include <osg/Node>
#include "Box.h"
using namespace osg;
namespace Sokoban {
	class BoxPositionUpdater :  public NodeCallback
	{
	public:
		BoxPositionUpdater(ref_ptr<Sokoban::Box> box) : _box(box){}
		void operator()(Node* node, NodeVisitor* nv);
		~BoxPositionUpdater(void);
	private:
		ref_ptr<Sokoban::Box> _box;

	};
}

