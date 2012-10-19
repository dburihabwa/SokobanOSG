#include "Player.h"
#include <osg/Geode>
#include "PlayerPositionUpdater.h"
#include "Board.h"
#include "Box.h"
using namespace osg;

Sokoban::Player::~Player(void)
{
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
	ref_ptr<Node> matrix = Case::createNode();
	ref_ptr<NodeCallback> posUpdater = new PlayerPositionUpdater(ref_ptr<Player>(this));
	matrix->setUpdateCallback(posUpdater);
	return matrix;
}

void Sokoban::Player::move(Direction dir) {
	Movable::move(dir);
	if(_canMoveBox) {
		_lastBox->move(dir);
		_canMoveBox = false;
	}
}