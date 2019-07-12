#include"Model.h"

void Model::gameinit(){
	//Robotlist playerlist[2];
	//vector<Robotdata> Robotdatalist;
	//vector<Robotskill> Robotskilllist;

	//readdata
	Robotfile robf;
	Skillfile skif;
	robf.read();
	skif.read();
}

void Model::stageinit(int stagenum){
	//readdata
	readstage(stagenum);
	roundinit();
}

void Model::roundinit() {
	playerlist[0].reset();
	playerlist[1].reset();
}

bool Model::canselect(int x, int y) {
	if (playerlist[0].ifonedone(gmap.ifhaverobot(x, y)))
		return false;
	return gmap.ifhaverobot(x, y);
}

Robotdata* Model::select(int x, int y) {
	int temp = gmap.getrobot(x, y);
	//if(playerlist[0].Robotlocation[temp].getlocationx==x&& playerlist[0].Robotlocation[temp].getlocationy == y)留在后面写选中时的敌我判定
	return &playerlist[0].playerrobot[temp];
}

bool Model::ifendround() {
	return (playerlist[0].ifalldone()) && (playerlist[1].ifalldone());
}

int Model::ifendstage() {
	int human = playerlist[0].getrobotnumber();
	int computer = playerlist[1].getrobotnumber();
	bool flagh = true;
	for (int i = 0; i < human; i++) {
		if (playerlist[0].playerrobot[i].getnowhp() > 0) {
			flagh = false;
			break;
		}		
	}
	bool flagc = true;
	for (int i = 0; i < computer; i++) {
		if (playerlist[1].playerrobot[i].getnowhp() > 0) {
			flagh = false;
			break;
		}
	}
	if (flagh || flagc)
		return -1;
	else if (flagc)
		return 0;
	else
		return 1;
}

void Model::playermove(int x1, int y1, int x2, int y2) {
	location nloc;
	nloc.setlocation(x1, y1);
	gmap.move(nloc, x2, y2);
}

bool Model::playerattack(int x1, int y1, int x2, int y2, int skillnum) {
	int attacker = gmap.getrobot(x1, y1);
	int target = gmap.getrobot(x2, y2)-maxrobot;
	int distance = abs(x1 - x2) + abs(y1 - y2);
	Fightingjudgement judge;
	bool ifhit=judge.ifhit(distance, playerlist[0].playerrobot[attacker].getskillinfo(skillnum).getdistance, playerlist[0].playerrobot[attacker].getskillinfo(skillnum).getaccuracy, playerlist[1].playerrobot[target].getspeed);
	if (!ifhit)
		return ifhit;
	int damage = playerlist[0].playerrobot[attacker].getskillinfo(skillnum).getdamage - playerlist[1].playerrobot[target].getdefense;
	if (damage <= 0)
		return false;
	playerlist[0].playerrobot[attacker].changehp(damage);
}