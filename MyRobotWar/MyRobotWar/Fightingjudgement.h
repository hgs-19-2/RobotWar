#pragma once

class Fightingjudgement {
public:
	bool distancejudge(int distance,int skilldistance);
	bool accuracyjudge(int accuracy,int speed);
	bool ifhit(int distance, int skilldistance, int accuracy, int speed);
};