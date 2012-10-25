#pragma once
#include <osg/MatrixTransform>
#include "GUITypes.h"
using namespace osg;
namespace Sokoban
{
	class NodeFactory
	{
	public:
		///<summary>
		///Create the OSG Node that represent the wanted item</summary>
		static ref_ptr<Node> createNode(int x,int y,int z, Type element);
	private:
		NodeFactory(void)
		{
		}

	};

}

