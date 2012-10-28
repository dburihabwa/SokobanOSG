#include <osgViewer/Viewer>
#include "View.h"
#include "Constants.h"
int main(void) {
	std::string level;
#if DEBUG == TRUE
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