#pragma once
#include <string>
#include <vector>
#include <osg/Group>

#include "Case.h"
#include "Player.h"
#include "Target.h"

using namespace osg;
namespace Sokoban
{
	class Board
	{
		friend Movable;
	public:
		static Board& getInstance() {
			// The only instance
			// Guaranteed to be lazy initialized
			// Guaranteed that it will be destroyed correctly
			//Explained : http://stackoverflow.com/questions/86582/singleton-how-should-it-be-used
			static Board instance;
			return instance;
		}
		/// <summary>
		/// Parse the String that represent the level, create the level and instance all the OSG graphical items
		/// </summary>
		/// <seealso cref="getLevel()">
		/// The OSG Graphical Level can be get in that method </seealso>
		void init(std::string);
		///<summary>
		///Get the OSG Level with all the graphical element </summary>
		ref_ptr<osg::Group> getLevel() const {
			return _level;
		}
		///<summary>
		///Get the center of the level, will be used to center the camera </summary>
		Vec3 getCenter() const {
			return center;
		}
		///<summary> Try to move the player in the wanted direction
		bool movePlayer(Direction);
		///
		ref_ptr<Case> getCase(unsigned int, unsigned int) const;

		~Board(void);
	private:
		std::vector<std::vector<ref_ptr<Case>>> _movable;
		std::vector<std::vector<ref_ptr<Case>>> _unMovable;
		std::vector<ref_ptr<Target>> _targets;
		ref_ptr<Group> _level;
		Vec3 center;
		ref_ptr<Player> _player;
		Board(){};
		Board(Board const&);              // Don't Implement
		void operator=(Board const&); // Don't implement
	};
};

