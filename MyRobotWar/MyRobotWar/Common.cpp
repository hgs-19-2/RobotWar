#include"Common.h"
#include<cstring>

Robotskill::Robotskill(char* na, int dmg, int dis, int acc, int mtimes) {
	strcpy(name, na);
	damage = dmg;
	distance = dis;
	accuracy = acc;
	maxtimes = mtimes;
	nowtimes = mtimes;
}

char* Robotskill::getname() {
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
	string str = to_string(id) + ".jpg";
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
		for (; i <= x + steps && i < col; i++)
		{
			int j = y - steps;
			if (j < 0)j = 0;
			for (; j <= y + steps && j < row; j++);
			{
				if (i + j <= x + y + steps && i + j >= x + y - steps)
				{
					rectangle(start_x + i * cell_width, j*cell_width, start_x + (i + 1)*cell_width, (j + 1)*cell_width);
				}
			}
		}
		//显示一个机器人的信息
		outtextxy(10, 50, "选中机器人信息：");
		outtext("\n名字：");
		outtext(name.c_str());
		outtext("\n生命值：");
		outtext(currentlife);
		outtext(" / ");
		outtext(wholelife);
		outtext("\n技能：");
		int n = skills.size();
		for(int i=0;i<n;i++)
			outtext(skills[i].getskillstring().c_str());
		outtext("\n可移动步数：");
		outtext(steps);
		outtext(" / ");
		outtext(wholesteps);

	}
}