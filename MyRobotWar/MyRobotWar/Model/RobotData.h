
#pragma once
#include "..\Common\Common.h"
//#include"Common.h"
//#include<vector>
//using std::vector;

class Robotdata {
public:
	Robotdata(string na, int mhp, int nhp, int range, int sp, int de);
	int getmaxhp();
	int getnowhp();
	int getmoverange();
	int getspeed();
	int getdefense();
	int changehp(int change);
	void Move(int m);
	int getcanmove();
	string getname();
	void setskill(vector<int>skilltype);
	int getskillnum();
	Robotskill&getskillinfo(int num);
	void reset();
private:
	string name;
	int maxhp;
	int nowhp;
	int moverange;
	int canmove;
	int speed;
	int defense;
	vector<Robotskill> skill;
};

