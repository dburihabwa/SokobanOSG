#pragma once
#include "unmovable.h"
namespace Sokoban
{
	class Target :
		public Unmovable
	{
	public:
		Target(size_t x, size_t y, size_t z) : Unmovable(x, y, z), _withBox(false) {}
		Type getType() {
			return TARGET;
		}
		bool isWithBox() {
			return _withBox;
		}
	private:
		bool _withBox;
	};
};