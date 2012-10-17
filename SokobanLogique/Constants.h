#pragma once
#include "Direction.h"
using namespace osg;
namespace Sokoban
{
	//Directions
	static const Direction UP = Direction(0,1);
	static const Direction DOWN = Direction(0,-1);
	static const Direction RIGHT = Direction(1,0);
	static const Direction LEFT = Direction(-1,0);

	//Camera 
	//setProjectionMatrixAsPerspective
	static const float near = 0.1; 
	static const float far = 0.5; 
	static const float fovy = 45.0; 
	static const float ratio = 1.0; 

	//setViewMatrixAsLookAt
	static const Vec3d oeil(0.0, 0.0, 15.0); 
	static const Vec3d cible(0, 0, 0.0); 
	static const Vec3d normale(0.0, 1.0, 0.0); 
};