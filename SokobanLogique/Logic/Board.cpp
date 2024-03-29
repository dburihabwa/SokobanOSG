#include <sys/stat.h>

#include "Board.h"
#include "Ground.h"
#include "Wall.h"
#include "Box.h"
#include "Player.h"
#include "Target.h"
#include "Empty.h"
#include "../Constants.h"
#include "../dirent.h"
#include "../GUI/View.h"
#include "../Event.h"

#include <regex>
#include <osg/Geode>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while(std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	return split(s, delim, elems);
}

void Sokoban::Board::init(std::string level)
{

	std::vector<std::string> data= this->parseStringLevel(level);
	//Get the center of the level, since we are doing a rotation on every element
	//The rotation need to be applied on the center vector also.
	center = osg::Vec3d(_height/2.,_width/2,0);
	for(unsigned int v = 0; v < _height; ++v)
	{
		std::vector<osg::ref_ptr<Unmovable>> sTemp;
		std::vector<osg::ref_ptr<Movable>> dTemp;
		for(unsigned int u = 0; u < _width; ++u)
		{
			if(u > data[v].size())
			{
				osg::ref_ptr<Unmovable> ground = new Ground(v,u,0);
				osg::ref_ptr<Movable> empty = new Empty(v,u,0);
				sTemp.push_back(ground);
				dTemp.push_back(empty);
			}
			else
			{
				osg::ref_ptr<Unmovable> s;
				osg::ref_ptr<Movable>d;
				char c = data[v][u];

				if(c == '#') {
					s = new Wall(v,u,0);
					d =  new Empty(v,u,0);
				}
				else if(c == '.') { 
					s = new Target(v,u,0);
					d =  new Empty(v,u,0);
					_win++;
				}
				else if(c == '@' ) {
					_player = new Player(v,u,1);
					d = _player.get();					
					s =  new Ground(v,u,0);
				}
				else if(c == '$') {
					d = new Box(v,u,1);
					s =  new Ground(v,u,0);
				} else if(c == '=') {
					s = new Target(v,u,0);
					d = new Box(v,u,1);
				} else if(c == '%') {
					s = new Target(v,u,0);
					_player = new Player(v,u,1);
					d = _player.get();			
				}
				else {
					s = new Ground(v,u,0);
					d = new Empty(v,u,0);
				}
				sTemp.push_back(s);
				dTemp.push_back(d);
			}
		}

		_unMovable.push_back(sTemp);
		_movable.push_back(dTemp);
	}
	_set =true;
}

bool Sokoban::Board::movePlayer(Direction dir, osg::ref_ptr<Box>& movedBox) {
	//If the win counter == 0, the player have finished the level.
	if(_win == 0) {
		return false;
	}
	movedBox.release();
	//Check if the player can move
	if(_player->canMove(dir)) {
		//Check if the player is going to move a box
		//It's set when the player check if he can move
		if(_player->willMoveBox()) {
			//retain the state of the box (on a target or not)
			movedBox = _player->getMovedBox();
			bool wasOnTarget = movedBox->isOnTarget();			
			_player->move(dir);
			//Check the winning condition
			checkWinCond(wasOnTarget,movedBox->isOnTarget());
			_boxScore++;
			notifyViews(BOX_MOVED);
		}
		else {
			_player->move(dir);
		}
#if DEBUG == TRUE
		displayLevel();
#endif
		_playerScore++;
		notifyViews(PLAYER_MOVED);
		return true;
	}
	_message = "Mouvement Incorrect.";
	notifyViews(WARN_MSG);
	return false;
}
osg::ref_ptr<Sokoban::Case> Sokoban::Board::getCase(unsigned int x, unsigned int y) const{
	if(x>_movable.size())
		throw std::exception("X not in the level");
	if(y>_movable[0].size())
		throw std::exception("Y not in the level");
	osg::ref_ptr<Case> lvlCase = _movable[x][y];
	if(lvlCase->getType() == EMPTY)
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
	osg::ref_ptr<Movable> movable1 = _movable[x1][y1];
	osg::ref_ptr<Movable> movable2 = _movable[x2][y2];
	_movable[x1][y1] = movable2;
	_movable[x2][y2] = movable1;
}

void Sokoban::Board::displayLevel() const {

	for(unsigned int i = 0; i < _movable.size();i++)
	{
		std::vector<osg::ref_ptr<Movable>> vect = _movable[i];
		std::vector<osg::ref_ptr<Unmovable>> vect2 = _unMovable[i];
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
Sokoban::Board::Board(void): _win(0), _height(0), _width(0), _set(false),_currentLvl(-1),_boxScore(0),_playerScore(0) {
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(LVL_DIR)) == NULL) {
		std::cout << "Error(" << errno << ") opening " << LVL_DIR << std::endl;
		_message = "Probl�me lors du chargement des niveaux.";
		notifyViews(WARN_MSG);
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
		_message = "Aucun niveau trouv�.";
		notifyViews(WARN_MSG);
	} 
}
void Sokoban::Board::resetBoard() {
	if(_set) {
		for(unsigned int i = 0; i < _movable.size();i++)
		{
			std::vector<osg::ref_ptr<Movable>> vect = _movable[i];
			std::vector<osg::ref_ptr<Unmovable>> vect2 = _unMovable[i];
			for(unsigned int j =0; j < vect.size(); j++) {
				vect[j].release();
				vect2[j].release();
			}
		}
		_player.release();
		_movable.clear();
		_unMovable.clear();
		_win = 0;
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
	if(_win !=0) {
		_message = "pr�c�dant !";
		notifyViews(WARN_MSG);
		_message = "suivant sans savoir terminer le ";
		notifyViews(WARN_MSG);
		_message = "Vous ne pouvez pas charger le niveau";
		notifyViews(WARN_MSG);

		return;
	}
	this->resetBoard();
	if(_currentLvl == _levelFile.size() - 1) {
		_message="Vous avez fini le jeu.";
		notifyViews(NORM_MSG);
		return;
	}
	_currentLvl++;
	this->loadLvl();
}


void Sokoban::Board::save() {
	std::ofstream out;
	std::string filePath(SAVE_DIR);
	filePath.append(SAVE_FILE);
	out.open(filePath.c_str());
	out << *this;
	out.close();
	_message =  "Jeu sauv�.";
	notifyViews(OK_MSG);
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
		_message ="Sauvergarde charg�e.";
		notifyViews(OK_MSG);
		notifyViews(LOAD_SAVE);
		return true;
	}
	std::string victoryMessage("Aucune sauvergarde � charger");
	_message ="Aucune sauvergarde � charger";
	notifyViews(WARN_MSG);
	return false;
}

std::vector<std::string> Sokoban::Board::parseStringLevel(std::string level) {
	std::regex pattern("([^\\n]+)\\n?");
	std::sregex_iterator end, iter(level.begin(), level.end(), pattern);

	_width = 0;
	std::vector<std::string> data;
	//Get every line of the string, check their 
	//length to find the lenght of the level
	std::vector<std::string> levelData = split((*iter)[1].str(),'-');
	if(!levelData.empty() && levelData.size() ==3) {
		std::stringstream level (levelData[0]);
		unsigned int lvl;
		level>>lvl;
		if(level)
			_currentLvl=lvl;

		std::stringstream playerScore (levelData[1]);
		unsigned int pScore;
		playerScore>>pScore;
		if(playerScore)
			_playerScore=pScore;

		std::stringstream boxScore (levelData[1]);
		unsigned int bScore;
		boxScore>>bScore;
		if(boxScore)
			_boxScore=bScore;
		++iter;
	}
	for(; iter != end; ++iter)
	{
		data.push_back((*iter)[1]);
		_width = max(_width, (unsigned int)(*iter)[1].length());
	}
	_height = data.size();
	return data;
}
//Operators
std::istream& Sokoban::operator>>(std::istream& in, Sokoban::Board& board) {
	std::stringstream buffer;
	buffer << in.rdbuf();
	board.init(buffer.str());
	return in;
}

std::ostream&  Sokoban::operator<<(std::ostream& out,Sokoban::Board const& board) {
	//Premi�re ligne doit �tre le num du niveau
	//le reste c'est le format qu'on a d�cid�
	std::string level;
	out << board._currentLvl <<"-"<<board._playerScore<<"-"<<board._boxScore<<std::endl;

	for (unsigned int i = 0; i < board._height; i++) {
		for (unsigned int j = 0; j < board._width; j++) {
			char symbol;
			osg::ref_ptr<Sokoban::Case> c = board.getCase(i, j);

			switch (c->getType()) {
			case Sokoban::BOX:
				if (board._unMovable[i][j]->getType() == TARGET) 
					symbol = '=';
				else
					symbol = '$';
				break;
			case Sokoban::PLAYER:
				if (board._unMovable[i][j]->getType() == TARGET)
					symbol = '%';
				else
					symbol = '@';
				break;
			case Sokoban::TARGET: 
				symbol = '.';
				break;
			case Sokoban::WALL:
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

void Sokoban::Board::loadLvl() {
	std::string level = LVL_DIR;
	level.append(_levelFile[_currentLvl]);
	this->loadFile(level.c_str());
	notifyViews(LOAD_LVL);
	std::stringstream message;
	message<<"Niveau "<<_currentLvl<<" charg�.";
	_message = message.str();
	notifyViews(NORM_MSG);
}

void Sokoban::Board::reloadLvl() {
	this->resetBoard();
	this->loadLvl();
}
void Sokoban::Board::checkWinCond(bool wasOnTarget, bool isOnTarget) {
	//check if the box was on a target and is not on a target anymore
	//if it's the case, increment the win counter.
	if(wasOnTarget && !isOnTarget) {
		_win++;
		//if the box wasn't on a target and is a on a target now
		//Decrement the win counter.
	} else if(!wasOnTarget && isOnTarget) {
		_win--;
	}
	//If the win counter == 0, the player have finished the level.
	if(_win==0) {
		std::string victoryMessage("Vous avez gagn� !");
		_message ="Appuyez sur N pour le niveau suivant.";
		notifyViews(NORM_MSG);
		_message ="Vous avez gagn� !";
		notifyViews(OK_MSG);			
	}
}

void Sokoban::Board::revertMove(Direction dir, osg::ref_ptr<Box> movedBox) {
	if(_win==0) {
		return;
	}
	_player->getRefMutex()->lock();
	osg::Vec3 pPos = _player->getPosition();
	_player->move(dir);	
	_player->getRefMutex()->unlock();
	_playerScore--;
	notifyViews(PLAYER_MOVED);	
	if(movedBox) {
		movedBox->getRefMutex()->lock();
		osg::Vec3 oldPos = movedBox->getPosition();
		osg::Vec3 newPos = oldPos + dir.getVector();
		bool wasOnTarget = dynamic_cast<Target*>(_unMovable[oldPos.x()][oldPos.y()].get())?true:false;
		bool willBeOnTarget = dynamic_cast<Target*>(_unMovable[newPos.x()][newPos.y()].get())?true:false;
		movedBox->move(dir);
		movedBox->getRefMutex()->unlock();
		checkWinCond(wasOnTarget,willBeOnTarget);
		_boxScore--;
		notifyViews(BOX_MOVED);
	}
#if DEBUG==TRUE
	std::cout<<"Win : "<<_win<<std::endl;
#endif
}

void Sokoban::Board::notifyViews(Event sokoEvent) {
	for(unsigned int i=0; i < _views.size(); ++i) {
		_views[i]->notify(sokoEvent);
	}
}