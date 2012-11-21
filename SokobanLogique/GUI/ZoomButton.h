#pragma once
#include "GUIButton.h"
namespace Sokoban {
	class ZoomButton :
		public GUIButton
	{
	public:
		ZoomButton(int x, int y, int z, Type type);
		Type getType();
		bool onClick();
		~ZoomButton(void);
	protected:
		Type _type;
	};
};

