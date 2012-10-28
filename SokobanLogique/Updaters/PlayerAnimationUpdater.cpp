#include "PlayerAnimationUpdater.h"
#include "../Constants.h"


Sokoban::PlayerAnimationUpdater::~PlayerAnimationUpdater(void)
{
}
void Sokoban::PlayerAnimationUpdater::setMovement(Vec3 position, Vec3 newPosition) {
	osg::ref_ptr<osg::AnimationPath> simpleMove = new osg::AnimationPath;
	simpleMove->setLoopMode( osg::AnimationPath::NO_LOOPING );

	osg::AnimationPath::ControlPoint orign(position,_lastRot);
	osg::AnimationPath::ControlPoint destination;
	if(_nextDir == UP) {
		_lastRot = DEGREE_0;
	}else if(_nextDir==DOWN) {
		_lastRot = DEGREE_180;
	} else if(_nextDir == RIGHT) {
		_lastRot = DEGREE_MIN_90;
	} else if(_nextDir == LEFT) {
		_lastRot = DEGREE_90;
	}


	destination = osg::AnimationPath::ControlPoint(newPosition,_lastRot);

	simpleMove->insert( 0, orign ); 
	simpleMove->insert( 0.25, destination );
	this->reset();
	this->setAnimationPath(simpleMove);
}
