#include "Player.h"
#include <osg/Geode>
#include "Board.h"
#include "Box.h"
#include "EventController.h"
using namespace osg;

Sokoban::Player::~Player(void) {
	_lastBox.release();
}
bool Sokoban::Player::canMove(Direction dir) {
	ref_ptr<Case> lvlCase = getCase(dir);
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
ref_ptr<Node> Sokoban::Player::createNode() {
	ref_ptr<Node> matrix = Movable::createNode();
	matrix->setEventCallback(new EventController);
	return matrix;
}

void Sokoban::Player::move(Direction dir) {
	if(_canMoveBox) {
		_lastBox->move(dir);
		_canMoveBox = false;
	}
	Movable::move(dir);
}