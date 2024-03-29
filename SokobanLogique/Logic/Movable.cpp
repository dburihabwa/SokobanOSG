#include "Movable.h"
#include "Board.h"
void Sokoban::Movable::move(Direction dir) {
	this->getRefMutex()->lock();
	int newX = _x+dir.getX();
	int newY = _y+dir.getY();
	Board::getInstance().swapMovable(_x,_y,newX,newY);
	_moveAdapter->move(getPosition(),osg::Vec3(newX,newY,getPosition().z()), dir);
	this->_x = newX;
	this->_y = newY;
	this->getRefMutex()->unlock();
}

osg::ref_ptr<Sokoban::Case> Sokoban::Movable::getCase(Direction dir) const {
	return Board::getInstance().getCase(this->_x+dir.getX(),this->_y+dir.getY());
}
