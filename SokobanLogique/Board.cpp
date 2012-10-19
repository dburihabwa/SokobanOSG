#include "Board.h"
#include "Ground.h"
#include "Wall.h"
#include "Box.h"
#include "Player.h"
#include "Target.h"
#include <regex>
#include <osg/Geode>
#include "Constants.h"
using namespace std;


void Sokoban::Board::init(string level)
{
	_level = new osg::Group;
	regex pattern("([^\\n]+)\\n?");
	sregex_iterator end, iter(level.begin(), level.end(), pattern);

	int w = 0;
	vector<string> data;
	//Get every line of the string, check their 
	//length to find the lenght of the level
	for(; iter != end; ++iter)
	{
		data.push_back((*iter)[1]);
		w = max(w, (*iter)[1].length());
	}
	int height = data.size();
	//Get the center of the level, since we are doing a rotation on every element
	//The rotation need to be applied on the center vector also.
	center = ROTATION * Vec3d(height/2.,w/2,0);
	for(size_t v = 0; v < height; ++v)
	{
		vector<ref_ptr<Case>> sTemp;
		vector<ref_ptr<Case>> dTemp;
		for(size_t u = 0; u < w; ++u)
		{
			if(u > data[v].size())
			{
				ref_ptr<Case> ground = new Ground(v,u,0);
				_level->addChild(ground->createNode());
				sTemp.push_back(ground);
				dTemp.push_back(ground);
			}
			else
			{
				ref_ptr<Case> s, d;
				char c = data[v][u];

				if(c == '#') {
					s = new Wall(v,u,0);
					d =  new Ground(v,u,0);
				}
				else if(c == '.' || c == '*' || c == '+') {
					ref_ptr<Target> target = new Target(v,u,0);
					_targets.push_back(target);
					s = target.get();
					d =  new Ground(v,u,0);
				}
				else if(c == '@' || c == '+') {
					_player = new Player(v,u,1);
					d = _player.get();					
					s =  new Ground(v,u,0);
				}
				else if(c == '$' || c == '*') {
					d = new Box(v,u,1);
					s =  new Ground(v,u,0);
				}
				else {
					s =  new Ground(v,u,0);
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

}
Sokoban::Type Sokoban::Board::getCase(unsigned int x, unsigned int y) const{
	if(x>_movable.size())
		throw exception("X not in the level");
	if(y>_movable[0].size())
		throw exception("Y not in the level");
	ref_ptr<Case> lvlCase = _unMovable[x][y];
	if(lvlCase->getType() == GROUND)
		return  _movable[x][y]->getType();
}

Sokoban::Board::~Board(void)
{
}
