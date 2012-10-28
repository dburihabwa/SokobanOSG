#pragma once
#include <osg/Geode>
#include "GUITypes.h"
#include <map>

namespace Sokoban
{
	class NodeFactory
	{
	public:
		///<summary>
		///Create the OSG Node that represent the wanted item</summary>
		static osg::ref_ptr<osg::Node> createNode(int x,int y,int z, Type element);
	private:
		NodeFactory(void)
		{
		}
		static std::map<Type, osg::ref_ptr<osg::Geode>> _geoCache;
		static osg::ref_ptr<osg::Geode> getOrCreateGeode(Type);

	};

}

