#pragma once
#include<vector>
using std::vector;

class Robotskill {
public:
	Robotskill(char* na,int dmg,int dis,int acc,int mtimes);
	char* getname();
	int getdamage();
	int getdistance();
	int getaccuracy();
	int getmaxtimes();
	int getnowtimes();
	bool useskill();
	void use();
private:
	char name[20];
	int damage;
	int distance;
	int accuracy;
	int maxtimes;
	int nowtimes;
};

