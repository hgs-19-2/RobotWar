
#pragma once
#include"Common.h"
#include<vector>
using std::vector;

class Robotdata {
public:
	Robotdata(char* na, int mhp, int nhp, int range, int sp, int de);
	int getmaxhp();
	int getnowhp();
	int getmoverange();
	int getspeed();
	int getdefense();
	int changehp(int change);
	void Move(int m);
	int getcanmove();
	char* getname();
	void setskill(vector<int>skilltype);
	int getskillnum();
	Robotskill&getskillinfo(int num);
private:
	char name[20];
	int maxhp;
	int nowhp;
	int moverange;
	int canmove;
	int speed;
	int defense;
	vector<Robotskill> skill;
};

