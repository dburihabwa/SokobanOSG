#include "Board.h"
#include "Ground.h"
#include "Wall.h"
#include "Box.h"
#include "Player.h"
#include "Target.h"
#include <regex>
#include <osg/Geode>
using namespace std;


Sokoban::Board::Board(string level)
{
	_level = new osg::Group;
	regex pattern("([^\\n]+)\\n?");
	sregex_iterator end, iter(level.begin(), level.end(), pattern);

	int w = 0;
	vector<string> data;
	for(; iter != end; ++iter)
	{
		data.push_back((*iter)[1]);
		w = max(w, (*iter)[1].length());
	}
	for(size_t v = 0; v < data.size(); ++v)
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
					s = new Target(v,u,0);
					d =  new Ground(v,u,0);
				}
				else if(c == '@' || c == '+') {
					d = new Player(v,u,1);
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


Sokoban::Board::~Board(void)
{
}
