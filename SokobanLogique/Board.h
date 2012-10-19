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
		/// <summary>
		/// Parse the String that represent the level, create the level and instance all the OSG graphical items
		/// </summary>
		/// <seealso cref="getLevel()">
		/// The OSG Graphical Level can be get in that method </seealso>
		Board(std::string);
		///<summary>
		///Get the OSG Level with all the graphical element </summary>
		ref_ptr<osg::Group> getLevel() const {
			return _level;
		}
		///<summary>
		///Get the center of the level, will be used to center the camera </summary>
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

