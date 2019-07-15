#pragma once
#include"Fightingjudgement.h"
#include "..\Common\Common.h"
#include "..\Common\etlbase.h"
#include"RobotData.h"
#include"RobotList.h"
//#include"Common.h"
//#include "etlbase.h"
#include"gamemap.h"
#include<memory>
#include<math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
extern vector<Robotskill> Robotskilllist;
extern vector<Robotdata> Robotdatalist;
class Model :public Proxy_PropertyNotification<Model>
{
public:
	void readrobot();
	void readskill();
	void readstage(int stagenum);
	void gameinit();
	void stageinit(int stagenum);
	void roundinit();
	bool canselect(int x,int y);
	//shared_ptr<Robotdata> select(int x, int y);
	int get_selectednum();
	bool ifendround();
	int ifendstage();
	int Movejudge(location selected, int x2, int y2);
	bool playermove(location selected, int x2, int y2);
	bool playerattack(int x1,int y1,int x2,int y2,int skillnum);
	void cpumove();
	bool Query(int a,int b,int c);
	void attack(Robotskill&skill, Robotdata&target,location&targetlocation);
	void moveto(location&currentlocation, int movetox, int movetoy);
	int winorlose();
	//location getselected();
	//void setselected(int x,int y);
	//shared_ptr<Robotlist> gethuman();
	//shared_ptr<Robotlist> getcpu();
	Robotlist& gethuman();
	Robotlist& getcpu();
private:
	gamemap gmap;
	Robotlist playerlist[2];
	location selected;

};
