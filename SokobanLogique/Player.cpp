#include "Player.h"
#include <osg/Geode>
#include "Board.h"
#include "Box.h"
#include "KeyboardHandler.h"
#include "PlayerAnimationUpdater.h"
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
void Sokoban::Player::move(Direction dir) {
	if(_canMoveBox) {
		_lastBox->move(dir);
		_canMoveBox = false;
	}
	dynamic_cast<PlayerAnimationUpdater*>(_aniUpdater.get())->setDirection(dir);
	Movable::move(dir);
}

ref_ptr<Node> Sokoban::Player::createNode() {
	_graphNode = Case::createNode();
	_aniUpdater = new PlayerAnimationUpdater();
	_graphNode->setUpdateCallback(_aniUpdater);
	return _graphNode;
}