#pragma once
namespace Sokoban {
	class Command
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

