#pragma once
#include "../Event.h"
#include <osg/Referenced>
namespace Sokoban {
	class IView : public osg::Referenced
	{
	public:

		IView()
		{
		}

		virtual ~IView() {
		}
		virtual void notify(Event) = 0;
	};
}

