#pragma once
#include "Direction.h"
#include <osg/Quat>
using namespace osg;
namespace Sokoban
{
	//Directions
	static const Direction UP(0,1);
	static const Direction DOWN(0,-1);
	static const Direction RIGHT(1,0);
	static const Direction LEFT(-1,0);
	static const Direction NONE();

	//Camera 
	//setProjectionMatrixAsPerspective
	static const float near = 0.1f; 
	static const float far = 0.5f; 
	static const float fovy = 45.0f; 
	static const float ratio = 1.0f; 

	//setViewMatrixAsLookAt
	static const Vec3d oeil(0.0, 0.0, 15.0); 
	static const Vec3d cible(0, 0, 0.0); 
	static const Vec3d normale(0.0, 1.0, 0.0); 

	//Rotation of -90° (-Pi/2) on Z axis
	static const Quat ROTATION(-1.57, Z_AXIS);
};