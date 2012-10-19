#pragma once
#include "Direction.h"
#include <osg/Quat>
using namespace osg;
namespace Sokoban
{
	//Directions
	static const Direction RIGHT(0,1);
	static const Direction LEFT(0,-1);
	static const Direction DOWN(1,0);
	static const Direction UP(-1,0);
	static const Direction NONE;

	//Camera 
	//setProjectionMatrixAsPerspective
	static const float near = 0.1f; 
	static const float far = 0.5f; 
	static const float fovy = 45.0f; 
	static const float ratio = 1.0f; 

	//setViewMatrixAsLookAt
	static const Vec3d HAUT(0.0, 1.0, 0.0); 

	//Rotation of -90° (-Pi/2) on Z axis
	static const Quat ROTATION(-1.57, Z_AXIS);
};