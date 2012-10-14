#include "Board.h"
#include "Ground.h"
#include <regex>
using namespace std;


Board::Board(string level)
{
	regex pattern("([^\\n]+)\\n?");
	sregex_iterator end, iter(level.begin(), level.end(), pattern);

	int w = 0;
	vector<string> data;
	for(; iter != end; ++iter)
	{
		data.push_back((*iter)[1]);
		w = max(w, (*iter)[1].length());
	}

}


Board::~Board(void)
{
}
