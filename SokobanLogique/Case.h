#pragma once
#include <osg\MatrixTransform>
#include "NodeFactory.h"
using namespace osg;
namespace Sokoban
{
	class Case : public Referenced
	{
	public:
		Case(size_t x,size_t y, size_t z) : _x(x), _y(y), _z(z){}
		size_t getX() const {
			return this->_x;
		}

		size_t getY() const {
			return this->_y;
		}
		size_t getZ() const {
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
	private:
		size_t _x;
		size_t _y;
		size_t _z;
	};
};
