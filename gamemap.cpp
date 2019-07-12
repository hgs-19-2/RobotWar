#include"gamemap.h"


void gamemap::setrobotmap(vector<int>&typelist, vector<location>&locations,int flag) {
	int temp = typelist.size;
	for (int i = 0; i < temp; i++)
	{
		int x = locations[i].getlocationx();
		int y = locations[i].getlocationy();
		map[x][y] = i+flag*maxrobot;
	}
}

void gamemap::setmap(){
	for (int i = 0; i < Maxsize; i++)
		for (int j = 0; j < Maxsize; j++)
			map[i][j] = -1;
}

void gamemap::move(location currentlocation, int movetox, int movetoy) {
	int temp = map[currentlocation.getlocationx][currentlocation.getlocationy];
	map[currentlocation.getlocationx][currentlocation.getlocationy] = -1;
	map[movetox][movetoy] = temp;
}

bool gamemap::ifhaverobot(int x, int y) {
	if (map[x][y] == -1)
		return false;
	return true;
}

int gamemap::getrobot(int x, int y) {
	return map[x][y];
}