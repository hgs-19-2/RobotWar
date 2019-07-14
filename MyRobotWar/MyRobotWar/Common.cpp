#include"Common.h"
//#include<cstring>

Robotskill::Robotskill(string na, int dmg, int dis, int acc, int mtimes) {
	//strcpy(name, na);
	name = na;
	damage = dmg;
	distance = dis;
	accuracy = acc;
	maxtimes = mtimes;
	nowtimes = mtimes;
}

string Robotskill::getname() {
	return name;
}

int Robotskill::getdamage() {
	return damage;
}

int Robotskill::getdistance() {
	return distance;
}

int Robotskill::getaccuracy() {
	return accuracy;
}

int Robotskill::getmaxtimes() {
	return maxtimes;
}

int Robotskill::getnowtimes() {
	return nowtimes;
}

bool Robotskill::useskill() {
	if (nowtimes > 0)
	{
		use();
		return true;
	}
	return false;
}

void Robotskill::use() {
	nowtimes--;
}

std::string Robotskill::getskillstring()
{
	string str;
	str = name;
	str = str + " damage:";
	str = str + to_string(damage);
	str = str + " distance:";
	str = str + to_string(distance);
	str = str + " accuracy:";
	str = str + to_string(accuracy);
	str = str + " maxtimes:";
	str = str + to_string(maxtimes);
	str = str + " nowtimes:";
	str = str + to_string(nowtimes);
	return str;
}
void oneRobot::Setchosen(bool c)
{
	chosen = c;
}
void oneRobot::SetoneRobot(int tx, int ty, int tid, string tname, int tcl, int twl,
	std::vector<Robotskill>& tskills, int ts, int tws, bool tdone, bool tchosen)throw()
{
	x = tx;
	y = ty;
	id = tid;
	name = tname;
	currentlife = tcl;
	wholelife = twl;
	skills = tskills;
	steps = ts;
	wholesteps = tws;
	done = tdone;
	chosen = tchosen;
}
void oneRobot::ShowoneRobot()
{
	IMAGE img;
	string str = "picture\\" + to_string(id) + ".jpg";
	loadimage(&img, str.c_str());
	putimage(start_x + x * cell_width, y*cell_width, &img);
	if (done) outtextxy(start_x + x * cell_width, y*cell_width, "done");
	if (chosen)
	{
		//画一个选中的框
		setlinecolor(YELLOW);
		rectangle(start_x + x * cell_width, y*cell_width, start_x + (x + 1)*cell_width, (y + 1)*cell_width);
		//画行动范围
		setlinecolor(YELLOW);
		//row 行，col 列
		int i = x - steps;
		if (i < 0)i = 0;
		for (; i <= x && i < col; i++)
		{
			int j = y - (i-(x-steps));
			if (j < 0)j = 0;
			for (; j <= y + (i-(x-steps)) && j < row; j++)
			{
					rectangle(start_x + i * cell_width, j*cell_width, start_x + (i + 1)*cell_width, (j + 1)*cell_width);
			}
		}
		for (i = x; i <= x + steps && i < col; i++)
		{
			int j = y + (i - (x + steps));
			if (j < 0)j = 0;
			for (; j <= y - (i - (x + steps)) && j < row; j++)
			{
				rectangle(start_x + i * cell_width, j*cell_width, start_x + (i + 1)*cell_width, (j + 1)*cell_width);
			}
		}
		//显示一个机器人的信息
		outtextxy(50, 50, "选中机器人信息：");
		outtextxy(50,80,"名字：");
		outtextxy(100,80,name.c_str());
		outtextxy(50,150,"生命值：");
		outtextxy(100,150,to_string(currentlife).c_str());
		outtextxy(150,150,"/");
		outtextxy(170,150,to_string(wholelife).c_str());
		outtextxy(50,180,"可移动步数：");
		outtextxy(150,180,to_string(steps).c_str());
		outtextxy(180,180,"/");
		outtextxy(200,180,to_string(wholesteps).c_str());
		outtextxy(50, 310, "移动");
		rectangle(50, 310, 100, 325);
		outtextxy(10, 350, "技能：");
		outtextxy(50, 350, "技能1");
		rectangle(50, 350, 100, 390);
		outtextxy(50, 390, "技能2");
		rectangle(50, 390, 100, 430);
		outtextxy(50, 430, "技能3");
		rectangle(50, 430, 100, 470);
		outtextxy(50, 470, "技能4");
		rectangle(50, 470, 100, 510);
		outtextxy(50, 510, "技能5");
		rectangle(50, 510, 100, 550);
		int n = skills.size();
		for(int i=0;i<n;i++)
			outtextxy(100,350+40*i,skills[i].getskillstring().c_str());
		for(int i = n;i<5;i++)
			outtextxy(100, 350 + 40 * i, "无");
		outtextxy(50, 570, "done");
		rectangle(50, 570, 100, 585);
	}
	if (currentlife == 0)outtextxy(start_x + x * cell_width, y*cell_width, "dead");
}