#pragma once
#include <string>
#include <vector>
#include <osg/Group>
#include <ostream>
#include <fstream>

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

		void displayLevel() const;


		~Board(void);

		friend std::ostream& operator<<(std::ostream& out, Board const& board){
			//Première ligne doit être le num du niveau + 1 (car ATOI qui sera utilisé dans <<
			// renvoit 0 s'il peut pas convertir, donc on ne peut pas avoir 0 comme num de lvl
			//le reste c'est le format qu'on a décidé
			return out;
		}
		friend std::istream& operator>>(std::istream& in, Board& board) {
			std::string line, level;
			if(!in.eof()) {
				getline(in,line); // Saves the line in STRING.
				int lvl = atoi(line.c_str());
				if(lvl == 0){
					level.append(line);
				}
				else {
					board._currentLvl = lvl-1;
				}
			}
			while(!in.eof()) // To get you all the lines.
			{
				getline(in,line); // Saves the line in STRING.
				level.append(line+"\n");
			}
			board.init(level);
			return in;
		}
		///<summary>Load the next level and return it</summary>
		ref_ptr<Group> loadNextLvl();


	private:
		std::vector<std::vector<ref_ptr<Case>>> _movable;
		std::vector<std::vector<ref_ptr<Case>>> _unMovable;
		std::vector<char*> _levelFile;
		int _currentLvl;
		unsigned int _win;
		unsigned int _width;
		unsigned int _height;
		bool _set;
		ref_ptr<Group> _level;
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

	};



};

