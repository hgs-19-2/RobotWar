#pragma once
#include"Fightingjudgement.h"
#include"FileIO.h"
#include"RobotData.h"
#include"RobotList.h"
#include"Common.h"
#include "etlbase.h"
#include"gamemap.h"
#include<memory>
#include<math.h>

class Model :public Proxy_PropertyNotification<Model>
{
public:
	void readstage(int stagenum);
	void gameinit();
	void stageinit(int stagenum);
	void roundinit();
	bool canselect(int x,int y);
	shared_ptr<Robotdata> select(int x, int y);
	bool ifendround();
	int ifendstage();
	int Movejudge(location selected, int x2, int y2, int robottype);
	bool playermove(location selected, int x2, int y2);
	bool playerattack(int x1,int y1,int x2,int y2,int skillnum);
	void cpumove();
	bool Query(int a,int b,int c);
	//location getselected();
	//void setselected(int x,int y);
	shared_ptr<Robotlist> gethuman();
	shared_ptr<Robotlist> getcpu();
private:
	gamemap gmap;
	Robotlist playerlist[2];
	location selected;
};

vector<Robotskill> Robotskilllist;
vector<Robotdata> Robotdatalist;