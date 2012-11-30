#pragma once
#include "GUIButton.h"

namespace Sokoban {
	class RotateButton :
		public GUIButton
	{
	public:
		RotateButton(int x, int y, int z, Type type);
		Type getType() const;
		bool onClick();
		~RotateButton(void);
	protected:
		Type _type;
	};
};

