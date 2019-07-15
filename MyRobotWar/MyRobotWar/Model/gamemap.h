#pragma once
#include<vector>
#include"RobotList.h"
//robotlist ÀïµÄlocation
using std::vector;
#define Maxsize 20
#define maxrobot 10

class gamemap {
public:
	void setmap();
	void setrobotmap(vector<int>&typelist, vector<location>&locations,int iflag);
	void move(location currentlocation, int movetox, int movetoy);
	bool ifhavehumanrobot(int x, int y);
	bool ifhavecpurobot(int x, int y);
	int getrobot(int x, int y);
private:
	int map[Maxsize][Maxsize];
};
