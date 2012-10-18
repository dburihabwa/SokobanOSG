#pragma once
#include <osg/MatrixTransform>
#include "GUITypes.h"
using namespace osg;
namespace Sokoban
{
	class NodeFactory
	{
	public:
		static ref_ptr<MatrixTransform> createNode(size_t x,size_t y,size_t z, Type element);
	private:
		NodeFactory(void)
		{
		}

	};

}

