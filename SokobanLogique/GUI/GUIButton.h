#pragma once
#include "../Logic/Case.h"


namespace Sokoban {
	class GUIButton :
		public Sokoban::Case
	{
	public:
		/// GUIButton default constructor
		GUIButton(int x, int y, int z);
		/// Preforms the expected behaviour on a click event
		virtual bool onClick() = 0;
	};
};

