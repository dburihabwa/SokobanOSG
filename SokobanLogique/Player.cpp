#include "Player.h"
#include <osg/Geode>
#include "PlayerPositionUpdater.h"
using namespace osg;

Sokoban::Player::~Player(void)
{
}
bool Sokoban::Player::canMove(Direction dir) const {
	return false;
}
bool Sokoban::Player::move(Direction dir) {
	return false;
}
ref_ptr<Node> Sokoban::Player::createNode() {
	ref_ptr<Node> matrix = Case::createNode();
	ref_ptr<NodeCallback> posUpdater = new PlayerPositionUpdater(ref_ptr<Player>(this));
	matrix->setUpdateCallback(posUpdater);
	return matrix;
}