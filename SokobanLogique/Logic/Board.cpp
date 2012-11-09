#include "Board.h"
#include "Ground.h"
#include "Wall.h"
#include "Box.h"
#include "Player.h"
#include "Target.h"
#include "../Constants.h"

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
	for(; iter != end; ++iter)
	{
		data.push_back((*iter)[1]);
		_width = std::max(_width, (unsigned int)(*iter)[1].length());
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
				else if(c == '.' || c == '*' || c == '+') { 
					s = new Target(v,u,0);
					d =  new Ground(v,u,-0.05);
					_win++;
				}
				else if(c == '@' || c == '+') {
					_player = new Player(v,u,0.4);
					d = _player.get();					
					s =  new Ground(v,u,-0.05);
				}
				else if(c == '$' || c == '*') {
					d = new Box(v,u,0.45);
					s =  new Ground(v,u,-0.05);
				} else if(c == '=') {
					s = new Target(v,u,0);
					d = new Box(v,u,0.45);
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
				std::cout<<"Vous avez Gagné !"<<std::endl;
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
	_level.release();
}
