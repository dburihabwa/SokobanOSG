#pragma once
#include <osg\MatrixTransform>
#include "../Factories/NodeFactory.h"

namespace Sokoban
{
	class Case : public osg::Referenced
	{
	public:
		Case(int x,int y, int z) : _x(x), _y(y), _z(z){}
		///<summary>
		///Return the type of the case </summary>
		/// <seealso cref="Type">
		/// Use the enum Type defined in GUITypes.h </seealso>
		virtual Type getType()=0;

		osg::Vec3 getPosition() const {
			return osg::Vec3(_x,_y,_z);
		}
		virtual ~Case() {}
	protected:
		int _x;
		int _y;
		int _z;
	};
};
