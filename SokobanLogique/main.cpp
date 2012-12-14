#include <osgViewer/Viewer>
#include "GUI\View.h"
#include "Logic\Board.h"
#include "Constants.h"
int main(void) {
	std::string level;
	Sokoban::View::getInstance()->init(800,1024);
	Sokoban::Board::getInstance().loadNextLvl();
	return Sokoban::View::getInstance()->getViewer()->run();
}