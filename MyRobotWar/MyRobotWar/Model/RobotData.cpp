#include"Model.h"
//#include"RobotData.h"
//#include<string>

Robotdata::Robotdata(string na, int mhp, int nhp, int range, int sp, int de) {
	//strcpy(name, na);
	name = na;
	maxhp = nhp;
	nowhp = nhp;
	moverange = range;
	canmove = range;
	speed = sp;
	defense = de;
}

int Robotdata::changehp(int change) {
	nowhp = nowhp - change;
	if (nowhp < 0)
		nowhp = 0;
	else if (nowhp > maxhp)
		nowhp = maxhp;
	return nowhp;
}
void Robotdata::Move(int m) {
	canmove = m;
}

int Robotdata::getcanmove() {
	return canmove;
}

string Robotdata::getname() {
	return name;
}

int Robotdata::getdefense() {
	return defense;
}

int Robotdata::getmaxhp() {
	return maxhp;
}

int Robotdata::getmoverange() {
	return moverange;
}

int Robotdata::getnowhp() {
	return nowhp;
}

int Robotdata::getspeed() {
	return speed;
}

int Robotdata::getskillnum() {
	return skill.size();
}

Robotskill&Robotdata::getskillinfo(int num) {
	
	return skill[num];
}
//
void Robotdata::setskill(vector<int> skilltype){
	int size = skilltype.size();
	for(int i=0;i<size;i++)
		skill.push_back(Robotskilllist[skilltype[i]]);
}

void Robotdata::reset() {
	canmove = moverange;
}