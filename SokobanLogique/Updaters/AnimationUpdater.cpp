#include "AnimationUpdater.h"


Sokoban::AnimationUpdater::AnimationUpdater(void)
{
}


Sokoban::AnimationUpdater::~AnimationUpdater(void)
{
}
void Sokoban::AnimationUpdater::setMovement(osg::Vec3 position, osg::Vec3 newPosition, Direction dir) {
	this->getRefMutex()->lock();
	osg::ref_ptr<osg::AnimationPath> simpleMove = new osg::AnimationPath;
	simpleMove->setLoopMode( osg::AnimationPath::NO_LOOPING );

	osg::AnimationPath::ControlPoint orign(position);
	osg::AnimationPath::ControlPoint destination(newPosition);

	simpleMove->insert( 0, orign ); 
	simpleMove->insert( 0.25, destination );
	this->reset();
	this->setAnimationPath(simpleMove);
	this->getRefMutex()->unlock();
}
