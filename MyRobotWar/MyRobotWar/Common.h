#pragma once
#include <vector>
#include <string>
#include <graphics.h>
#include <conio.h>
#define start_x 400
#define cell_width 30
#define col 20
#define row 20
using namespace std;
class ThreeInt
{
private:
	int a;
	int b;
	int c;
public:
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	void setThreeInt(int ta, int tb, int tc) { a = ta; b = tb; c = tc; }
	void set_a(int ta) { a = ta; }
	void set_b(int tb) { b = tb; }
	void set_c(int tc) { c = tc; }
};

class Robotskill
{
public:
	Robotskill(string na, int dmg, int dis, int acc, int mtimes);
	string getname();
	int getdamage();
	int getdistance();
	int getaccuracy();
	int getmaxtimes();
	int getnowtimes();
	string getskillstring();
	bool useskill();
	void use();
private:
	string name;
	int damage;
	int distance;
	int accuracy;
	int maxtimes;
	int nowtimes;
};
class oneRobot
{
private:
	int x;
	int y;			//�������ڳ����е�����
	int id;			//�����˱�ţ���ͼƬ���
	string name;		//����������
	int currentlife;//��ǰ����ֵ
	int wholelife;	//ԭ��������ֵ
	vector<Robotskill> skills;	//���������Լ�����
	int steps;		//ʣ����ƶ�����
	int wholesteps; //ԭ���Ĳ���
	bool done;		//�Ƿ��Ѿ�����˶Ըû����˵Ĳ�����ÿ���غ϶�һ��������ֻ��ȷ�ϲ���һ��
	bool chosen;	//�Ƿ�ǰ��ѡ��
public:
	//Robot() { x = 0; y = 0; id = 0; done = false; chosen = false; }
	void Setchosen(bool c);
	void SetoneRobot(int tx, int ty, int id, string tname, int tcl, int twl, 
		vector<Robotskill>& tskills, int ts,int tws, bool tdone, bool tchosen)throw();
	void ShowoneRobot();
	//bool IsChosen() { return chosen; }
};
