#pragma once
#include <osg/Quat>
#include <osg/Vec4>
#include <map>
#include "Logic\GUITypes.h"

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

	//Graphical object dimensions	
	static const float DEFAULT_WIDTH = 1.0f;
	static const float DEFAULT_LENGTH_X = 1.0f;
	static const float DEFAULT_LENGTH_Y = 1.0f;
	static const float PLAYER_RADIUS = 0.4f;

	static const float BOX_WIDTH = 0.9f;

	static const float GROUND_LENGTH_Z = 0.1f;
	static const float WALL_LENGTH_Z = 1.4f;
	static const float TARGET_LENGTH_Z = 0.0f;

	static const float BUTTON_LENGTH_X = 1.5f;
	static const float BUTTON_LENGTH_Y = 1.5f;
	static const float BUTTON_LENGTH_Z = 0.0f;

	static const float BOX_CENTER_Z = -0.4f;
	static const float PLAYER_CENTER_Z = -0.5f;
	static const float WALL_CENTER_Z = 0.55f;
	static const float TARGET_CENTER_Z = -0.0f;
	
	//LIGHT EMISSIONS
	static const osg::Vec4f BUTTON_EMISSION(1.0f, 1.0f, 1.0f, 1.0f);
	static const osg::Vec4f OBJECT_EMISSION(0.2f, 0.2f, 0.2f, 0.5f);
};