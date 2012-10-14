#pragma once
#include <osg\MatrixTransform>
using namespace osg;
namespace Sokoban
{
	class Case : public Referenced
	{
	public:
		Case(size_t x,size_t y, size_t z) : _x(x), _y(y), _z(z), _refCount(0){}
		size_t Case::getX() const {
			return this->_x;
		}

		size_t Case::getY() const {
			return this->_y;
		}
		size_t getZ() const {
			return this->_z;
		}
		virtual ref_ptr<Geode> createGeode() = 0;
		//From Referenced
		void ref() {
			_refCount++;
		}
		void unref() {
			_refCount--;
		}
		int getReferenceCount() {
			return _refCount;
		}
	protected:
		size_t _x;
		size_t _y;
		size_t _z;
	private:
		int _refCount;
	};
};
