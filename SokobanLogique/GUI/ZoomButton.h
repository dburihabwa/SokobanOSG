#pragma once
#include "GUIButton.h"
namespace Sokoban {
	class ZoomButton :
		public GUIButton
	{
	public:
		ZoomButton(int x, int y, int z, Type type);
		Type getType();
		~ZoomButton(void);
	protected:
		Type _type;
	};
};

