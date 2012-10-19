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
		int getX() const {
			return this->_x;
		}

		int getY() const {
			return this->_y;
		}
		int getZ() const {
			return this->_z;
		}
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
	protected:
		int _x;
		int _y;
		int _z;
	};
};
