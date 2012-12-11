#pragma once
#include <osg/Geode>
#include "../Logic/GUITypes.h"
#include <osg/PositionAttitudeTransform>
#include <map>

namespace Sokoban
{
	class NodeFactory
	{
	public:
		///<summary>
		///Create the OSG Node that represent the wanted item</summary>
		static osg::ref_ptr<osg::PositionAttitudeTransform> createNode(int x,int y,int z, Type element);
	private:
		NodeFactory(void)
		{
		}
		static std::map<Type, osg::ref_ptr<osg::Node>> _geoCache;
		static osg::ref_ptr<osg::Node> getOrCreateGeode(Type);

		/// <summary>
		/// Creates and returns a ground object.
		///	</summary>
		/// <returns>Returns a ref_ptr to geometry object representing a Ground object.</returns>
		static osg::ref_ptr<osg::Geometry> createGround();

		///<summary>
		///	Applies the texture on the drawables of a Geode. If the texture cannot be loaded, the method returns NULL.
		///</summary>
		///	<param name = "geode">Geode object to apply the texture on</param>
		///	<param name = "type">Type of the object used to check if the texutre has already been loaded in the cache</param>
		///	<param name = "texturePath">File path of the texutreto apply</param>
		///	<returns>Returns the geode</retruns>
		static osg::ref_ptr<osg::Geode> setTexture(osg::ref_ptr<osg::Geode> geode, Type type, std::string& texturePath);
	};

}

