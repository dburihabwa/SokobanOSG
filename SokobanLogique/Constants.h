#pragma once
#include <osg/Quat>
using namespace osg;
namespace Sokoban
{
	//Camera 
	//setProjectionMatrixAsPerspective
	static const float near = 0.1f; 
	static const float far = 100.0f; 
	static const float fovy = 50.0f; 

	//setViewMatrixAsLookAt
	static const Vec3d UP_AXIS(-1.0, 0.0, 0.0); 
};