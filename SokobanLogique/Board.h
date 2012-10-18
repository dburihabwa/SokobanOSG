#pragma once
#include <string>
#include <vector>
#include <osg/Group>

#include "Case.h"

using namespace osg;
namespace Sokoban
{
	class Board
	{
	public:
		Board(std::string);
		ref_ptr<osg::Group> getLevel() const {
			return _level;
		}
		Vec3 getCenter() {
			return center;
		}
		~Board(void);
	private:
		std::vector<std::vector<ref_ptr<Case>>> _movable;
		std::vector<std::vector<ref_ptr<Case>>> _unMovable;
		ref_ptr<Group> _level;
		Vec3 center;
	};
};

