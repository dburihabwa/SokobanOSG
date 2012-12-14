#pragma once
#include <osg/Referenced>
namespace Sokoban {
	class Command : public osg::Referenced
	{
	public:

		Command(void)
		{
		}

		~Command(void)
		{
		}
		
		virtual bool execute() const = 0;
	};
}

