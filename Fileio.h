#pragma once
#include<fstream>
#include<stdlib.h>
#include<iostream>
#include"RobotData.h"
#include"RobotSkill.h"
#include"RobotList.h"
using namespace std;

class Robotfile {
public:
	void read();
};

class Skillfile {
public:
	void read();
};

class Stagefile {
public:
	void read(int stagenum);
};