#include <osgViewer/Viewer>
#include "View.h"

#define LVL 2
int main(void) {
	std::string level;
#if LVL == 1
	level =
		"#######\n"
		"#     #\n"
		"#$    #\n"
		"#  #  #\n"
		"#  #  #\n"
		"#.$   #\n"
		"# .  @#\n"
		"#######";
#else
	level = 
		"    #####          \n"
		"    #   #          \n"
		"    #$  #          \n"
		"  ###  $##         \n"
		"  #  $ $ #         \n"
		"### # ## #   ######\n"
		"#   # ## #####  ..#\n"
		"# $  $          ..#\n"
		"##### ### #@##  ..#\n"
		"    #     #########\n"
		"    #######        ";
#endif
	Sokoban::View::getInstance().init(level,800,800);
	return Sokoban::View::getInstance().getViewer()->run();
}