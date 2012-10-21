#pragma once
#include <osg/Quat>
using namespace osg;
namespace Sokoban
{
	//Camera 
	//setProjectionMatrixAsPerspective
	static const float near = 0.1f; 
	static const float far = 0.5f; 
	static const float fovy = 45.0f; 
	static const float ratio = 1.0f; 

	//setViewMatrixAsLookAt
	static const Vec3d HAUT(-1.0, 0.0, 0.0); 
};