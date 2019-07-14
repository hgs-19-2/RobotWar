//common
#pragma once
#include"RobotData.h"
//#include<vector>
//using std::vector;

class location
{
public:
	void setlocation(int m, int n);
	int getlocationx();
	int getlocationy();
private:
	int x;
	int y;
};

class Robotlist
{
public:
	void setlist(vector<Robotdata>&Robotdatalist,vector<int>&typelist,vector<location>&locations);
	int getrobotnumber();
	void done(int num);
	void reset();
	vector<Robotdata> playerrobot;
	vector<location> Robotlocation;
	bool ifalldone();
	bool ifonedone(int num);
	bool ifalldead();
private:
	int numofrobot;
	vector<bool> ifdone;
};

