#pragma once
#include"Fightingjudgement.h"
#include"FileIO.h"
#include"Movejudgement.h"
#include"RobotData.h"
#include"RobotList.h"
#include"RobotSkill.h"
#include"gamemap.h"

class Model :public Proxy_PropertyNotification<Model>
{
public:
	void readstage(int stagenum);
	void gameinit();
	void stageinit(int stagenum);
	void roundinit();
	bool canselect(int x,int y);
	Robotdata* select(int x,int y);
	bool ifendround();
	int ifendstage();
	void playermove(int x1,int y1,int x2,int y2);
	bool playerattack(int x1,int y1,int x2,int y2,int skillnum);
	void cpumove();
private:
	gamemap gmap;
	Robotlist playerlist[2];
};

vector<Robotskill> Robotskilllist;
vector<Robotdata> Robotdatalist;