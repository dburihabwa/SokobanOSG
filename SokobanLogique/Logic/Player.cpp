#include "Player.h"
#include "Box.h"
#include "../Updaters/PlayerAnimationUpdater.h"

Sokoban::Player::~Player(void) {
	_lastBox.release();
}
bool Sokoban::Player::canMove(Direction dir) {
	osg::ref_ptr<Case> lvlCase = getCase(dir);
	if(lvlCase->getType() == WALL)
		return false;
	if(lvlCase->getType() == BOX) {
		_lastBox.release();
		_lastBox =  static_cast<Box*>(lvlCase.get());
		_canMoveBox = _lastBox->canMove(dir);
		return _canMoveBox;
	}
	return true;
}
void Sokoban::Player::move(Direction dir) {
	if(_canMoveBox) {
		_lastBox->move(dir);
		_canMoveBox = false;
	}
	Movable::move(dir);
}