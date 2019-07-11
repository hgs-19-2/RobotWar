#pragma once
//#include "view/BusLabel.h"
#include <graphics.h>
#include <conio.h>
#include <string>
using namespace std;
//#include "sinks/MainWindowPropertySink.h"
//#include "sinks/MainWindowCommandSink.h"
//view
#include "etlbase.h"
#define start_x 100
#define cell_width 50
#define col 10
#define row 10
//定义一个画矩形的函数
void DrawRectangle(int x, int y, int w, int h)
{
	line(x, y, x + w, y);
	line(x + w, y, x + w, y + h);
	line(x + w, y + h, x, y + h);
	line(x, y + h, x, y);
}
class Robot
{
private:
	int x;
	int y;			//机器人在场景中的坐标
	int id;			//机器人编号，即图片编号
	char* name;		//机器人名字
	int currentlife;//当前生命值
	int wholelife;	//原本的生命值
	char* skill;	//技能名字以及描述
	int influence;	//当前技能影响范围
	int steps;		//剩余可移动步数
	int wholesteps; //原本的步数
	bool done;		//是否已经完成了对该机器人的操作，每个回合对一个机器人只能确认操作一次
	bool chosen;	//是否当前被选中

public:
	Robot() { x = 0; y = 0; id = 0; done = false; chosen = false; }
	void ShowRobot();
	void ShowRobotInformation();
	bool IsChosen() { return chosen; }
};
//显示一个机器人
void Robot::ShowRobot()
{
	IMAGE img;
	string str = to_string(id) + ".jpg";
	loadimage(&img,str.c_str());
	putimage(start_x + x * cell_width, y*cell_width, &img);
	if (done) outtextxy(start_x + x * cell_width, y*cell_width, "done");
	if (chosen)
	{
		//画一个选中的框
		setlinecolor(YELLOW);
		DrawRectangle(start_x + x * cell_width, y*cell_width, cell_width, cell_width);
		//画行动范围
		setlinecolor(YELLOW);
		//row 行，col 列
		int i = x - steps;
		if (i < 0)i = 0;
		for (; i <= x + steps && i < col; i++)
		{
			int j = y - steps;
			if (y < 0)y = 0;
			for (; j <= j + steps && j < row; j++);
			{
				if (i + j <= x + y + steps && i + j >= x + y - steps)
				{
					DrawRectangle(start_x + i * cell_width, j*cell_width, cell_width, cell_width);
				}
			}
		}

	}
};
//显示一个机器人的信息
void Robot::ShowRobotInformation()
{
	outtextxy(10, 50, "选中机器人信息：");
	outtext( "\n名字：");
	outtext(name);
	outtext("\n生命值：");
	outtext(currentlife);
	outtext(" / ");
	outtext(wholelife);
	outtext("\n技能：");
	outtext(skill);
	outtext("\n可移动步数：");
	outtext(steps);
	outtext(" / ");
	outtext(wholesteps);
}
class Window;
class WindowPropertySink:public IPropertyNotification
{
private:
	Window* m_pw;
public:
	WindowPropertySink(Window* pw) throw() :m_pw(pw) {}
	virtual void OnPropertyChanged(const std::string& str) {
		/*if (str == "Stop_Number") {
			m_pW->m_lblStopNumber.Update();
		}
		else if (str == "city-name") {
			m_pW->m_lblCityName.Update();
		}*/
	}
};
class WindowCommandSink : public ICommandNotification
{
private:
	Window* m_pw;
public:
	WindowCommandSink(Window* pw) throw() :m_pw(pw) {}
	virtual void OnCommandComplete(const std::string& str, bool bOK) {
		/*if (str == "query") {
			if (!bOK) {
				AtlMessageBox(NULL, _T("error query"), _T("error"), MB_OK);
			}
		}*/
	}
};

class Window
{
private:
	int width;
	int height;
	int robot_num;
	Robot* robots;
	MOUSEMSG m;
	std::shared_ptr<ICommandBase> m_cmdQuery;
	std::shared_ptr<WindowPropertySink> m_sinkProperty;
	std::shared_ptr<WindowCommandSink> m_sinkCommand;

public:
	Window(int x, int y) { width = x; height = y; initgraph(x, y); }
	~Window() { closegraph(); }
	void ShowWindow()
	{
		//initgraph(width, height);
		//background
		IMAGE background;
		loadimage(&background, "picture\\background.jpg");
		putimage(50, 0, &background);
		//robots
		for (int i = 0; i < robot_num; i++)
		{
			robots[i].ShowRobot();
			if (robots[i].IsChosen()) robots[i].ShowRobotInformation();
		}
		//information of players
		outtextxy(20, 20, "玩家");
		outtextxy(600, 20, "电脑");
	}

	void set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw() { m_cmdQuery = cmd; }
	std::shared_ptr<IPropertyNotification> get_PropertySink() throw(){ return std::static_pointer_cast<IPropertyNotification>(m_sinkProperty); }
	std::shared_ptr<ICommandNotification> get_CommandSink() throw(){ return std::static_pointer_cast<ICommandNotification>(m_sinkCommand); }
	
};

//ICommandBase, IPropertyNotification, ICommandNotification?
