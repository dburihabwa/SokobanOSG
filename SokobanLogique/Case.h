#pragma once
#include <osg\MatrixTransform>
#include "NodeFactory.h"
using namespace osg;
namespace Sokoban
{
	class Case : public Referenced
	{
	public:
		Case(int x,int y, int z) : _x(x), _y(y), _z(z){}
		///<summary>
		///Create the OSG Graphical element.</summary>
		virtual ref_ptr<Node> createNode() {
			return NodeFactory::createNode(_x,_y,_z,getType());
		}
		///<summary>
		///Return the type of the case </summary>
		/// <seealso cref="Type">
		/// Use the enum Type defined in GUITypes.h </seealso>
		virtual Type getType()=0;

		Vec3 getPosition() const {
			return Vec3(_x,_y,_z);
		}
		virtual ~Case() {}
	protected:
		int _x;
		int _y;
		int _z;
	};
};
