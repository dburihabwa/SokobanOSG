#include <sys/stat.h>

#include "Board.h"
#include "Ground.h"
#include "Wall.h"
#include "Box.h"
#include "Player.h"
#include "Target.h"
#include "../Constants.h"
#include "../dirent.h"
#include "../GUI/View.h"

#include <regex>
#include <osg/Geode>
#include <iostream>


void Sokoban::Board::init(std::string level)
{
	_level = new osg::Group;
	std::regex pattern("([^\\n]+)\\n?");
	std::sregex_iterator end, iter(level.begin(), level.end(), pattern);

	_width = 0;
	std::vector<std::string> data;
	//Get every line of the string, check their 
	//length to find the lenght of the level
	int lvl;
	std::stringstream lvlNbr ((*iter)[1].str());
	lvlNbr >> lvl;
	if(lvlNbr) {
		if(lvl >= 0) {
			_currentLvl = lvl;
		}
		++iter;
	}
	for(; iter != end; ++iter)
	{
		data.push_back((*iter)[1]);
		_width = max(_width, (unsigned int)(*iter)[1].length());
	}
	_height = data.size();
	//Get the center of the level, since we are doing a rotation on every element
	//The rotation need to be applied on the center vector also.
	center = Vec3d(_height/2.,_width/2,0);
	for(unsigned int v = 0; v < _height; ++v)
	{
		std::vector<ref_ptr<Case>> sTemp;
		std::vector<ref_ptr<Case>> dTemp;
		for(unsigned int u = 0; u < _width; ++u)
		{
			if(u > data[v].size())
			{
				ref_ptr<Case> ground = new Ground(v,u,-0.05);
				_level->addChild(ground->createNode());
				sTemp.push_back(ground);
				dTemp.push_back(ground);
			}
			else
			{
				ref_ptr<Case> s, d;
				char c = data[v][u];

				if(c == '#') {
					s = new Wall(v,u,0.6);
					d =  new Ground(v,u,-0.05);
				}
				else if(c == '.') { 
					s = new Target(v,u,0);
					d =  new Ground(v,u,-0.05);
					_win++;
				}
				else if(c == '@' ) {
					_player = new Player(v,u,0.4);
					d = _player.get();					
					s =  new Ground(v,u,-0.05);
				}
				else if(c == '$') {
					d = new Box(v,u,0.45);
					s =  new Ground(v,u,-0.05);
				} else if(c == '=') {
					s = new Target(v,u,0);
					d = new Box(v,u,0.45);
				} else if(c == '%') {
					s = new Target(v,u,0);
					_player = new Player(v,u,0.4);
					d = _player.get();			
				}
				else {
					s =  new Ground(v,u,-0.05);
					d = s.get();
				}
				_level->addChild(s->createNode());
				_level->addChild(d->createNode());
				sTemp.push_back(s);
				dTemp.push_back(d);
			}
		}

		_unMovable.push_back(sTemp);
		_movable.push_back(dTemp);
	}
	_set =true;
}

bool Sokoban::Board::movePlayer(Direction dir) {
	if(_win == 0) {
		return false;
	}
	if(_player->canMove(dir)) {
		if(_player->willMoveBox()) {
			bool wasOnTarget = _player->getMovedBox()->isOnTarget();
			_player->move(dir);
			if(wasOnTarget && !_player->getMovedBox()->isOnTarget()) {
				_win++;
			} else if(!wasOnTarget && _player->getMovedBox()->isOnTarget()) {
				_win--;
			}
			if(_win==0) {
				std::string victoryMessage("Vous avez gagné");
				View::getInstance().addText(victoryMessage, MSG_OK);
			}
		}
		else {
			_player->move(dir);
		}
#if DEBUG == TRUE
		displayLevel();
#endif
		return true;
	}
	std::string victoryMessage("Mouvement Incorrect.");
	View::getInstance().addText(victoryMessage, MSG_WARNING);
	return false;
}
ref_ptr<Sokoban::Case> Sokoban::Board::getCase(unsigned int x, unsigned int y) const{
	if(x>_movable.size())
		throw std::exception("X not in the level");
	if(y>_movable[0].size())
		throw std::exception("Y not in the level");
	ref_ptr<Case> lvlCase = _movable[x][y];
	if(lvlCase->getType() == GROUND)
		return  _unMovable[x][y];
	return lvlCase;
}
void Sokoban::Board::swapMovable(unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2) {
	if(x1>_movable.size())
		throw std::exception("X1 not in the level");
	if(y1>_movable[0].size())
		throw std::exception("Y1 not in the level");
	if(x2>_movable.size())
		throw std::exception("X2 not in the level");
	if(y2>_movable[0].size())
		throw std::exception("Y2 not in the level");
	ref_ptr<Case> movable1 = _movable[x1][y1];
	ref_ptr<Case> movable2 = _movable[x2][y2];
	_movable[x1][y1] = movable2;
	_movable[x2][y2] = movable1;
}

void Sokoban::Board::displayLevel() const {

	for(unsigned int i = 0; i < _movable.size();i++)
	{
		std::vector<ref_ptr<Case>> vect = _movable[i];
		std::vector<ref_ptr<Case>> vect2 = _unMovable[i];
		for(unsigned int j =0; j < vect.size(); j++) {
			std::cout<<vect[j]->getType() + vect2[j]->getType();
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<"Win : "<<_win<<std::endl;


}
Sokoban::Board::~Board(void) {
	this->resetBoard();
}
Sokoban::Board::Board(void): _win(0), _height(0), _width(0), _set(false),_currentLvl(-1) {
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(LVL_DIR)) == NULL) {
		std::cout << "Error(" << errno << ") opening " << LVL_DIR << std::endl;
		std::string victoryMessage("Problème lors du chargement des niveaux.");
		View::getInstance().addText(victoryMessage, MSG_WARNING);
		return;
	}
#if DEBUG==TRUE
	std::cout<<"Loading Lvl files :"<<std::endl;
#endif
	while ((dirp = readdir(dp)) != NULL) {
		char* level = dirp->d_name;
		if(std::strcmp(level,"..") == 0|| std::strcmp(level,".") == 0)
			continue;
		_levelFile.push_back(std::string(level));
#if DEBUG==TRUE
		std::cout<<level<<std::endl;
#endif
	}
	closedir(dp);
	if(_levelFile.size() == 0) {
		std::cout<<"NO LEVELS in the level directory !"<<std::endl;
		std::string victoryMessage("Aucun niveau trouvé.");
		View::getInstance().addText(victoryMessage, MSG_WARNING);
	} 
}
void Sokoban::Board::resetBoard() {
	if(_set) {
		for(unsigned int i = 0; i < _movable.size();i++)
		{
			std::vector<ref_ptr<Case>> vect = _movable[i];
			std::vector<ref_ptr<Case>> vect2 = _unMovable[i];
			for(unsigned int j =0; j < vect.size(); j++) {
				vect[j].release();
				vect2[j].release();
			}
		}
		_player.release();
		const std::vector<osg::Group*>& parents = _level->getParents();
		for(unsigned int i = 0; i < parents.size(); ++i){
			osg::Group& parent = *parents[i];
			parent.removeChild(_level.get());
		}
		_level.release();
		_set = false;
	}
}
void Sokoban::Board::loadFile(const char* file) {
	std::ifstream levelFile;
	levelFile.open(file);
	levelFile >> *this;
	levelFile.close();
}
void Sokoban::Board::loadNextLvl() {
	this->resetBoard();
	_currentLvl++;
	if(_currentLvl == _levelFile.size()) {
		std::string message("Vous avez fini le jeu.");
		View::getInstance().addText(message);
		return;
	}
	std::string level = LVL_DIR;
	level.append(_levelFile[_currentLvl]);

	this->loadFile(level.c_str());
}


void Sokoban::Board::save() const {
	std::ofstream out;
	std::string filePath(SAVE_DIR);
	filePath.append(SAVE_FILE);
	out.open(filePath.c_str());
	out << *this;
	out.close();
	std::string victoryMessage("Jeu sauvé.");
	View::getInstance().addText(victoryMessage, MSG_OK);
}


bool Sokoban::Board::loadSave() {
	this->resetBoard();
	struct stat buf;
	std::string fileName(SAVE_DIR);
	fileName.append("/");
	fileName.append(SAVE_FILE);
	// Tests if the save file does exist
	if (stat(fileName.c_str(), &buf) != -1)
	{
		loadFile(fileName.c_str());
		std::string victoryMessage("Sauvergarde chargée.");
		View::getInstance().addText(victoryMessage, MSG_OK);
		return true;
	}
	std::string victoryMessage("Aucune sauvergarde à charger");
	View::getInstance().addText(victoryMessage, MSG_WARNING);
	return false;
}