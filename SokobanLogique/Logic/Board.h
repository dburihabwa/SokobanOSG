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

		friend std::ostream& operator<<(std::ostream& out, Board const& board){
			//Première ligne doit être le num du niveau
			//le reste c'est le format qu'on a décidé
			std::string level;
			out << board._currentLvl << std::endl;

			for (unsigned int i = 0; i < board._height; i++) {
				for (unsigned int j = 0; j < board._width; j++) {
					char symbol;
					ref_ptr<Case> c = board.getCase(i, j);

					switch (c->getType()) {
					case BOX:
						if (board._unMovable[i][j]->getType() == TARGET) 
							symbol = '=';
						else
							symbol = '$';
						break;
					case PLAYER:
						if (board._unMovable[i][j]->getType() == TARGET)
							symbol = '%';
						else
							symbol = '@';
						break;
					case TARGET: 
						symbol = '.';
						break;
					case WALL:
						symbol = '#';
						break;
					default: /* case GROUND : */
						symbol = ' ';
					}
					level.push_back(symbol);
				}
				level.push_back('\n');
			}
			out << level;
			return out;
		}
		friend std::istream& operator>>(std::istream& in, Board& board) {
			std::stringstream buffer;
			buffer << in.rdbuf();
			board.init(buffer.str());
			return in;
		}
		///<summary>Load the next level and return it</summary>
		void loadNextLvl();

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

	};



};

