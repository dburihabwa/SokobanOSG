#include "Player.h"
#include <osg/Geode>
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