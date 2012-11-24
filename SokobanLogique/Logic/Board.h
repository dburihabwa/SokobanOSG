#pragma once
#include <string>
#include <vector>
#include <osg/Group>
#include <ostream>
#include <fstream>
#include <sstream>

#include "Case.h"
#include "Player.h"
#include "Target.h"



namespace Sokoban
{
	class Board
	{
		friend class Movable;
	public:
		static Board& getInstance() {
			// The only instance
			// Guaranteed to be lazy initialized
			// Guaranteed that it will be destroyed correctly
			//Explained : http://stackoverflow.com/questions/86582/singleton-how-should-it-be-used
			static Board instance;
			return instance;
		}
		///<summary>
		///Get the center of the level, will be used to center the camera </summary>
		Vec3 getCenter() const {
			return center;
		}
		///<summary> Try to move the player in the wanted direction
		bool movePlayer(Direction);

		void displayLevel() const;


		~Board(void);

		friend std::ostream& operator<<(std::ostream& out, Board const& board);
		friend std::istream& operator>>(std::istream& in, Board& board);

		///<summary>Load the next level and notify the view</summary>
		void loadNextLvl();

		///<summary>reload the current level to it's first state</summary>
		void reloadLvl();

		void save() const;
		///<summary> Load the save, return true if there is a save else return false</summary>
		bool loadSave();
		const std::vector<std::vector<ref_ptr<Movable>>>& getMovable() const {
			return _movable;
		}
		const std::vector<std::vector<ref_ptr<Unmovable>>>& getUnMovable() const {
			return _unMovable;
		}

	private:
		std::vector<std::vector<ref_ptr<Movable>>> _movable;
		std::vector<std::vector<ref_ptr<Unmovable>>> _unMovable;
		std::vector<std::string> _levelFile;
		int _currentLvl;
		unsigned int _win;
		unsigned int _width;
		unsigned int _height;
		bool _set;
		Vec3 center;
		ref_ptr<Player> _player;
		Board();
		Board(Board const&);              // Don't Implement
		void operator=(Board const&); // Don't implement
		void swapMovable(unsigned int, unsigned int,unsigned int, unsigned int);
		///<summary>
		///Get the Case on the wanted coordonate </summary>
		ref_ptr<Case> getCase(unsigned int, unsigned int) const;
		void resetBoard();
		void loadFile(const char* file);
		/// <summary>
		/// Parse the String that represent the level, create the level and instance all the OSG graphical items
		/// </summary>
		/// <seealso cref="getLevel()">
		/// The OSG Graphical Level can be get in that method </seealso>
		void init(std::string);
		std::vector<std::string> parseStringLevel(std::string);
		///<summary>Load the lvl pointed by the _currentLvl</summary>
		void loadLvl();

	};



};

