#include "Player.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Player::~Player(void)
{
}
ref_ptr<Geode> Sokoban::Player::createGeode() {
	ref_ptr<Geode> geode = new Geode;
	return geode;
}
bool Sokoban::Player::canMove(Direction dir) const {
	return false;
}
bool Sokoban::Player::move(Direction dir) {
	return false;
}