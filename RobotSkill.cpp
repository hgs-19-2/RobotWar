#include"RobotData.h"
#include<cstring>

Robotskill::Robotskill(char* na, int dmg,int dis, int acc,int mtimes) {
	strcpy(name, na);
	damage = dmg;
	distance=dis;
	accuracy = acc;
	maxtimes = mtimes;
	nowtimes = mtimes;
}

char* Robotskill::getname() {
	return name;
}

int Robotskill::getdamage(){
	return damage;
}

int Robotskill::getdistance() {
	return distance;
}

int Robotskill::getaccuracy() {
	return accuracy;
}

int Robotskill::getmaxtimes() {
	return maxtimes;
}

int Robotskill::getnowtimes() {
	return nowtimes;
}

bool Robotskill::useskill() {
	if (nowtimes > 0)
	{
		use();
		return true;
	}
	return false;
}

void Robotskill::use() {
	nowtimes--;
}