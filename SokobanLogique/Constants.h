#pragma once
#include <osg/Quat>
using namespace osg;
#define TRUE 1
#define FALSE 0
#define DEBUG FALSE
namespace Sokoban
{
	//Camera 
	//setProjectionMatrixAsPerspective
	static const float near = 0.1f; 
	static const float far = 100.0f; 
	static const float fovy = 50.0f; 

	//setViewMatrixAsLookAt
	static const Vec3d UP_AXIS(-1.0, 0.0, 0.0); 
	
	//Rotations
	static const Quat DEGREE_180(3.1415,Z_AXIS);
	static const Quat DEGREE_MIN_90(-1.57,Z_AXIS);
	static const Quat DEGREE_90(1.57,Z_AXIS);
	static const Quat DEGREE_0(0,Z_AXIS);
};