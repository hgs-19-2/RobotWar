#include"RobotList.h"

void Robotlist::setlist(vector<Robotdata>&Robotdatalist, vector<int>&typelist, vector<location>&locations) {
	numofrobot = typelist.size();
	for (int j = 0; j < numofrobot; j++) {
		playerrobot.push_back(Robotdatalist[typelist[j]]);
		Robotlocation.push_back(locations[j]);
		ifdone.push_back(false);
	}
}

int Robotlist::getrobotnumber() {
	return numofrobot;
}

void Robotlist::done(int num) {
	ifdone[num] = true;
}

void Robotlist::reset() {
	int i = getrobotnumber();
	for (int j = 0; j < i; j++)
		if (playerrobot[j].getnowhp())
		{
			ifdone[j] = false;
			playerrobot[j].reset();
		}
}

int location::getlocationx(){
	return x;
}

int location::getlocationy() {
	return y;
}

void location::setlocation(int m, int n) {
	x = m; y = n;
}

bool Robotlist::ifalldone() {
	int i = getrobotnumber();
	for (int j = 0; j < i; j++)
	{
		if (!ifdone[j])
			return false;
	}
	return true;
}

bool Robotlist::ifonedone(int num) {
	return ifdone[num];
}

bool Robotlist::ifalldead() {
	int i = getrobotnumber();
	for (int j = 0; j < i; j++) {
		if (playerrobot[j].getnowhp() != 0)
			return false;
	}
	return true;
}