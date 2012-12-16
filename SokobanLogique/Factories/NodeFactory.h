#pragma once
#include <osg/Geode>
#include "../Logic/GUITypes.h"
#include <osg/PositionAttitudeTransform>
#include <map>
#include <string>

namespace Sokoban
{
	class NodeFactory
	{
	public:
		///	<summary>
		///		Creates the OSG Node that represent the wanted item.
		///	</summary>
		///	<param name = "x">x coordinate of the object</param>
		///	<param name = "y">y coordinate of the object</param>
		///	<param name = "z">z coordinate of the object</param>
		///	<param name = "element">type of the object</param>
		///	<returns></returns>
		static osg::ref_ptr<osg::PositionAttitudeTransform> createNode(int x,int y,int z, Type element);
		
	private:
		NodeFactory(void)
		{
		}
		static std::map<Type, osg::ref_ptr<osg::Node>> _geoCache;
		static std::map<Type, std::string> _textures;
		static std::map<Type, std::string> _switchTextures;

		static void settingTextures();
		
		///	<summary>
		///		Creates or fetches the requested Node from the cache.
		///	</summary>
		///	<param name = "type">The logical type of the requested Node</param>
		static osg::ref_ptr<osg::Node> getOrCreateGeode(Type);

		/// <summary>
		///		Creates and returns a ground object.
		///	</summary>
		/// <returns>Returns a ref_ptr to geometry object representing a Ground object.</returns>
		static osg::ref_ptr<osg::Geometry> createGround();

		///<summary>
		///		Applies the texture on the drawables of a Geode. If the texture cannot be loaded, the method returns NULL.
		///</summary>
		///	<param name = "geode">Geode object to apply the texture on</param>
		///	<param name = "type">Type of the object used to check if the texutre has already been loaded in the cache</param>
		///	<param name = "texturePath">File path of the texutreto apply</param>
		///	<returns>Returns the geode</retruns>
		static osg::ref_ptr<osg::Geode> setTexture(osg::ref_ptr<osg::Geode> geode, Type type, std::string& texturePath);
		///	<summary>
		///		Checks whether the passed type represents a GUIButton
		///	<param name = "type">The type to test</param>
		///	<returns>Result of the test</returns>
		///	</summary>
		static bool isAButton(Type type);
	};

}

