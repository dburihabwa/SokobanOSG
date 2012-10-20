#pragma once
#include <osg/NodeCallback>
using namespace osg;
namespace Sokoban
{
	class EventController : public NodeCallback
	{
	public:
		EventController(void);
		void operator()(Node* node, NodeVisitor* nv);
		~EventController(void);
	};
}

