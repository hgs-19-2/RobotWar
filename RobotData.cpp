#include"Model.h"
#include<string>

Robotdata::Robotdata(char* na, int mhp, int nhp, int range, int sp, int de) {
	strcpy(name, na);
	maxhp = nhp;
	nowhp = nhp;
	moverange = range;
	canmove = range;
	speed = sp;
	defense = de;
}

int Robotdata::changehp(int change) {
	nowhp = nowhp + change;
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

char* Robotdata::getname() {
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

void Robotdata::setskill(vector<int> skilltype){
	for(int i;skilltype[i]>=0;skilltype[i]++)
		skill.push_back(Robotskilllist[skilltype[i]]);
}