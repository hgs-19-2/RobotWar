#include"Model.h"
vector<Robotskill> Robotskilllist;
vector<Robotdata> Robotdatalist;
void Model::gameinit(){
	/*Robotfile robf;
	Skillfile skif;
	robf.read();
	skif.read();*/
	readskill();
	readrobot();
}

void Model::stageinit(int stagenum){
	//readdata
	readstage(stagenum);
}

void Model::roundinit() {
	playerlist[0].reset();
	playerlist[1].reset();
	selected.setlocation(0, 0);
	Fire_OnPropertyChanged("robots");
}

bool Model::canselect(int x, int y) {
	if (gmap.getrobot(x, y) == -1||gmap.ifhavehumanrobot(x,y)==false)
		return false;
	if (playerlist[0].ifonedone(gmap.getrobot(x, y)))//getrobot
		return false;
	return true;
}

/*Robotdata* Model::select(int x, int y) {
	int temp = gmap.getrobot(x, y);
	//if(playerlist[0].Robotlocation[temp].getlocationx==x&& playerlist[0].Robotlocation[temp].getlocationy == y)留在后面写选中时的敌我判定
	return &playerlist[0].playerrobot[temp];
}*/

/*shared_ptr<Robotdata> Model::select(int x, int y) {
	int temp = gmap.getrobot(x, y);
	shared_ptr<Robotdata> ptr(&playerlist[0].playerrobot[temp]);
	return ptr;
}*/
int Model::get_selectednum()
{
	return gmap.getrobot(selected.getlocationx(), selected.getlocationy());
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

bool Model::playermove(location selected, int x2, int y2) {
	int flag = Movejudge(selected, x2, y2);//?
	if (flag < 0||gmap.getrobot(x2,y2)>-1)
		return false;
	int type = gmap.getrobot(selected.getlocationx(), selected.getlocationy());
	playerlist[0].playerrobot[type].Move(flag);
	playerlist[0].Robotlocation[type].setlocation(x2, y2);
	gmap.move(selected, x2, y2);
	return true;
}

int Model::Movejudge(location selected, int x2, int y2) {
	//int range = Robotdatalist[robottype].getmoverange();
	int dx, dy;
	int x1 = selected.getlocationx();
	int y1 = selected.getlocationy();
	int range = playerlist[0].playerrobot[gmap.getrobot(x1, y1)].getcanmove();
	dx = x1 - x2;
	dy = y1 - y2;
	int distance = abs(dx) + abs(dy);
	return range - distance;
}

bool Model::playerattack(int x1, int y1, int x2, int y2, int skillnum) {
	int attacker = gmap.getrobot(x1, y1);
	int target = gmap.getrobot(x2, y2)-maxrobot;
	if (target < 0)
		return false;
	int distance = abs(x1 - x2) + abs(y1 - y2);
	Fightingjudgement judge;
	if (!playerlist[0].playerrobot[attacker].getskillinfo(skillnum).useskill())
		return false;
	bool ifhit=judge.ifhit(distance, playerlist[0].playerrobot[attacker].getskillinfo(skillnum).getdistance(), playerlist[0].playerrobot[attacker].getskillinfo(skillnum).getaccuracy(), playerlist[1].playerrobot[target].getspeed());
	if (!ifhit)
		return ifhit;
	int damage = playerlist[0].playerrobot[attacker].getskillinfo(skillnum).getdamage() - playerlist[1].playerrobot[target].getdefense();
	if (damage <= 0)
		return false;
	playerlist[1].playerrobot[target].changehp(damage);
	//playerlist[0].done[attacker];//
	
	playerlist[0].done(attacker);
	return true;
}

int Model::winorlose() {
	if (!playerlist[0].ifalldead() && !playerlist[1].ifalldead())
		return 0;
	if (playerlist[0].ifalldead())
		return -1;
	return 1;
}

bool Model::Query(int a, int b, int c) {//1-select,2-move,3~7-attack,8-end
	switch (a) {
	case 0: {
		//gameinit
		if (b == 0) 
		{
			gameinit();
			//Fire_OnPropertyChanged("robots");
			return true;
		}
		else 
		{
			stageinit(b);
			Fire_OnPropertyChanged("robots");
			return true;
		}
	}
	case 1: {
		if (!canselect(b, c))
			return false;
		//shared_ptr<Robotdata> sel = select(b, c);
		selected.setlocation(b, c);
		Fire_OnPropertyChanged("robots");
		return true; }
	case 2: { 
		if (!playermove(selected, b, c))
			return false;
		Fire_OnPropertyChanged("robots");
		return true; }
	case 3:
	case 4:
	case 5:
	case 6:
	case 7: {
		int x = selected.getlocationx();
		int y = selected.getlocationy();
		if (!canselect(x, y))
			return false;

		if ((a - 2) > playerlist[0].playerrobot[gmap.getrobot(x,y)].getskillnum())//?
			return false;
		
		bool flag=playerattack(x, y, b, c, a - 3);
		if (!flag)
			return false;
		string str = "attack" + to_string(b) + "," + to_string(c);
		Fire_OnPropertyChanged(str);
		if (winorlose() == 1) {
			Fire_OnPropertyChanged("win");
			return true;
		}

		if (winorlose() == -1) {
			Fire_OnPropertyChanged("lose");
			return true;
		}
			
		if (playerlist[0].ifalldone()&&!winorlose())
		{
			cpumove();
			if(!winorlose())
			roundinit();
			else if(winorlose() == 1)
			{
				Fire_OnPropertyChanged("win");
				return true;
			}
			else 
			{
				Fire_OnPropertyChanged("lose");
				return true;
			}

		}
		return true;
	}
	case 8: {
		playerlist[0].done(gmap.getrobot(selected.getlocationx(), selected.getlocationy()));//
		Fire_OnPropertyChanged("robots");
		if (playerlist[0].ifalldone() /*&& !playerlist[0].ifalldead() && !playerlist[1].ifalldead()*/)
		{
			cpumove();
			if (!winorlose())
				roundinit();
			else if (winorlose() == 1)
			{
				Fire_OnPropertyChanged("win");
				return true;
			}
			else
			{
				Fire_OnPropertyChanged("lose");
				return true;
			}
		}
		return true; }
	}
	return false;
}

/*shared_ptr<Robotlist> Model::getcpu(){
	shared_ptr<Robotlist> temp(&playerlist[1]);
	return temp;
}

shared_ptr<Robotlist> Model::gethuman() {
	shared_ptr<Robotlist> temp(&playerlist[0]);
	return temp;
}*/
Robotlist& Model::getcpu() {
	//shared_ptr<Robotlist> temp(&playerlist[1]);
	return playerlist[1];
}

Robotlist& Model::gethuman() {
	//shared_ptr<Robotlist> temp(&playerlist[0]);
	return playerlist[0];
}