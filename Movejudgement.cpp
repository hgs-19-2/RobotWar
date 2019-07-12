#include <math.h>
#include"Movejudgement.h"
#include"RobotData.h"

int Movejudgement::Movejudge(int x1, int y1, int x2, int y2, int robottype) {
	int range = Robotdatalist[robottype].getmoverange();
	int dx,dy;
	dx = x1 - x2;
	dy = y1 - y2;
	int distance = abs(dx) + abs(dy);
	return range - distance;
}