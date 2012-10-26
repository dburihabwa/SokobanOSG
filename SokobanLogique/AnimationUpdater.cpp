#include "AnimationUpdater.h"


Sokoban::AnimationUpdater::AnimationUpdater(void)
{
}


Sokoban::AnimationUpdater::~AnimationUpdater(void)
{
}
void Sokoban::AnimationUpdater::setMovement(Vec3 position, Vec3 newPosition) {
	osg::ref_ptr<osg::AnimationPath> simpleMove = new osg::AnimationPath;
	simpleMove->setLoopMode( osg::AnimationPath::NO_LOOPING );

	osg::AnimationPath::ControlPoint ori(position);
	osg::AnimationPath::ControlPoint dest(newPosition);

	simpleMove->insert( 0, ori ); // Paramètre 1 = Temps, Paramètre 2 = Checkpoint
	simpleMove->insert( 0.5, dest );
	this->reset();
	this->setAnimationPath(simpleMove);
}
