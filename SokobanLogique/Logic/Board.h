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
#include "IView.h"


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
		osg::Vec3 getCenter() const {
			return center;
		}
		///<summary> Try to move the player in the wanted direction.
		/// If the player moves a box, the moved box will be set.
		///</summary>
		bool movePlayer(Direction, osg::ref_ptr<Box>&);

		///	<summary>Writes the level's current state to the standard ouput.</summary>
		void displayLevel() const;

		~Board(void);

		friend std::ostream& operator<<(std::ostream& out, Board const& board);
		friend std::istream& operator>>(std::istream& in, Board& board);

		///<summary>Loads the next level and notify the view</summary>
		void loadNextLvl();

		///<summary>Reloads the current level to it's first state</summary>
		void reloadLvl();

		void save();
		///<summary> Load the save, return true if there is a save else return false</summary>
		bool loadSave();
		
		///	<summary>Returns the matrix of movable objects</summary>
		///	<returns>matrix of movable objects</returns>
		const std::vector<std::vector<osg::ref_ptr<Movable>>>& getMovable() const {
			return _movable;
		}

		///	<summary>Returns the matrix of unmovable objects</summary>
		///	<returns>matrix of unmovable objects</returns>
		const std::vector<std::vector<osg::ref_ptr<Unmovable>>>& getUnMovable() const {
			return _unMovable;
		}

		///	<summary>Returns the player's score</summary>
		///	<returns>The player's score</returns>
		unsigned int getPlayerScore() const {
			return _playerScore;
		}
		
		///	<summary>Returns the box's score</summary>
		///	<returns>The box's score</returns>
		unsigned int getBoxScore() const {
			return _boxScore;
		}
		///<summary> Revert the move for the player and the box if it was moved </summary>
		void revertMove(Direction dir, osg::ref_ptr<Box>);

		///	<summary>Registers a view to the board.</summary>
		///	<param name = "view">The view to register</param>
		void addView(osg::ref_ptr<IView> view) {
			_views.push_back(view);
		}
		///	<summary>Returns the latest message.</summary>
		///	<returns>The latest message</returns>
		std::string getMessage() const {
			return _message;
		}
	private:
		std::vector<std::vector<osg::ref_ptr<Movable>>> _movable;
		std::vector<std::vector<osg::ref_ptr<Unmovable>>> _unMovable;
		std::vector<std::string> _levelFile;
		std::vector<osg::ref_ptr<IView>> _views;
		int _currentLvl;
		unsigned int _win;
		unsigned int _width;
		unsigned int _height;
		unsigned int _playerScore;
		unsigned int _boxScore;
		bool _set;
		std::string _message;
		osg::Vec3 center;
		osg::ref_ptr<Player> _player;
		Board();
		Board(Board const&);              // Don't Implement
		void operator=(Board const&); // Don't implement
		void swapMovable(unsigned int, unsigned int,unsigned int, unsigned int);
		///<summary>
		///Get the Case on the wanted coordonate </summary>
		osg::ref_ptr<Case> getCase(unsigned int, unsigned int) const;
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
		///<summary>Check what do to with the win counter, increment, decrement or nothing when moving a box</summary>
		void checkWinCond(bool,bool);
		void notifyViews(Event);

	};



};

