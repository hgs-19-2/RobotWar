#include <random>
#include"Fightingjudgement.h"

bool Fightingjudgement::distancejudge(int distance, int skilldistance) {
	return (distance <= skilldistance);
}

bool Fightingjudgement::accuracyjudge(int accuracy, int speed) {
	std::random_device rd;
	std::mt19937 mt(rd());
	int probability = mt() % 101;
	return (accuracy >= probability);
}

bool Fightingjudgement::ifhit(int distance, int skilldistance, int accuracy, int speed) {
	return distancejudge(distance, skilldistance) && accuracyjudge(accuracy, speed);
}