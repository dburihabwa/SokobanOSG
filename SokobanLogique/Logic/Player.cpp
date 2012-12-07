#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "../Updaters/PlayerAnimationUpdater.h"

Sokoban::Player::~Player(void) {
	_lastBox.release();
}
bool Sokoban::Player::canMove(Direction dir) {
	osg::ref_ptr<Case> lvlCase = getCase(dir);
	osg::ref_ptr<Box> box;
	if(dynamic_cast<Wall*> (lvlCase.get()))
		return false;
	if(box = dynamic_cast<Box*> (lvlCase.get())) {
		_lastBox.release();
		_lastBox =  box.get();
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