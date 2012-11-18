#pragma once
#include "GUIButton.h"

namespace Sokoban {
	class SaveButton : public GUIButton
	{
	public:
		SaveButton(int x, int y, int z);
		Type getType();
		osg::ref_ptr<osg::Node> createNode();
	};
};

