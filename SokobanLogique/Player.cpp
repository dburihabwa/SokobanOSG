#include "Player.h"
#include <osg/Geode>
using namespace osg;

Sokoban::Player::~Player(void)
{
}
Geode* Sokoban::Player::createGeode() {
	ref_ptr<Geode> geode = new Geode;
	return geode.get();
}
bool Sokoban::Player::canMove(Direction dir) const {
	return false;
}
bool Sokoban::Player::move(Direction dir) {
	return false;
}