#pragma once
#include <osg/Quat>
#include <osg/Vec4>
#define TRUE 1
#define FALSE 0
#define DEBUG TRUE
#if DEBUG==TRUE
#include <iostream>
#endif
namespace Sokoban
{
	//Camera 
	//setProjectionMatrixAsPerspective
	static const float NEAR = 0.1f; 
	static const float FAR = 100.0f; 
	static const float FOVY = 58.0f; 

	//setViewMatrixAsLookAt
	static const osg::Vec3d UP_AXIS(-1.0, 0.0, 0.0); 
	
	//Rotations
	static const osg::Quat DEGREE_180(3.1415, osg::Z_AXIS);
	static const osg::Quat DEGREE_MIN_90(-1.57, osg::Z_AXIS);
	static const osg::Quat DEGREE_90(1.57, osg::Z_AXIS);
	static const osg::Quat DEGREE_0(0, osg::Z_AXIS);

	//Directories
	static const char* LVL_DIR = "Ressources/Levels/";
	static const char* TEXTURE_DIR = "Ressources/Textures/";
	static const char* SAVE_DIR = "Ressources/Saves/";
	static const char* SAVE_FILE = "save.sav";

	//Messages
	static const osg::Vec4 MSG_NORMAL(1,1,1,1);
	static const osg::Vec4 MSG_WARNING(1.0, 0.0, 0.0, 1.0);
	static const osg::Vec4 MSG_OK(0,1,0,1);

	//Animation
	static const float ANIM_TIME(0.25);
};