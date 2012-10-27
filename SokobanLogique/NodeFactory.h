#pragma once
#include <osg/Geode>
#include "GUITypes.h"
#include <map>
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
		static std::map<Type,ref_ptr<Geode>> _geoCache;
		static ref_ptr<Geode> getOrCreateGeode(Type);

	};

}

