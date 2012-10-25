#include "AnimationUpdater.h"


Sokoban::AnimationUpdater::AnimationUpdater(Vec3 position, Direction dir)
{
	osg::ref_ptr<osg::AnimationPath> simpleMove = new osg::AnimationPath;
	simpleMove->setLoopMode( osg::AnimationPath::NO_LOOPING );

	osg::AnimationPath::ControlPoint ori(position);
	osg::AnimationPath::ControlPoint dest(position+dir.getVector());

	simpleMove->insert( 0, ori ); // Paramètre 1 = Temps, Paramètre 2 = Checkpoint
	simpleMove->insert( 0.5, dest );
	this->setAnimationPath(simpleMove);
}


Sokoban::AnimationUpdater::~AnimationUpdater(void)
{
}
