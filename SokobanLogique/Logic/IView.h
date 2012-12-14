#pragma once
#include "../Event.h"
namespace Sokoban {
	class IView
	{
	public:

		IView(void)
		{
		}

		~IView(void)
		{
		}
		virtual void notify(Event) = 0;
	};
}

