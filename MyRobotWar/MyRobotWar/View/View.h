#pragma once
//#include "view/BusLabel.h"
//#include <graphics.h>
//#include <conio.h>
//#include <string>
//using namespace std;
//#include "sinks/MainWindowPropertySink.h"
//#include "sinks/MainWindowCommandSink.h"
//view
#include "..\Common\Common.h"
#include "..\Common\etlbase.h"
//#include "etlbase.h"
//#include "Common.h"
/*class Robot
{
private:
	shared_ptr<int> x;//shared_ptr<int> x?
	shared_ptr<int> y;			//机器人在场景中的坐标
	shared_ptr<int> id;			//机器人编号，即图片编号
	shared_ptr<string> name;	//机器人名字
	shared_ptr<int> currentlife;//当前生命值
	shared_ptr<int> wholelife;	//原本的生命值
	shared_ptr<string> skill;	//技能名字以及描述
	//shared_ptr<int> influence;//当前技能影响范围
	shared_ptr<int> steps;		//剩余可移动步数
	shared_ptr<int> wholesteps; //原本的步数
	shared_ptr<bool> done;		//是否已经完成了对该机器人的操作，每个回合对一个机器人只能确认操作一次
	shared_ptr<bool> chosen;	//是否当前被选中

public:
	//Robot() { x = 0; y = 0; id = 0; done = false; chosen = false; }
	void SetRobot(const shared_ptr<int>&tx, const shared_ptr<int>&ty,const shared_ptr<int>&tid,const shared_ptr<string>&tname,
		const shared_ptr<int>&tcurrentlife,const shared_ptr<int>&twholelife,const shared_ptr<string>&tskill,
		const shared_ptr<int>&tsteps,const shared_ptr<int>&twholesteps,const shared_ptr<bool>&tdone,
		const shared_ptr<bool>&tchosen)throw();
	void UpdateRobot();
	
	bool IsChosen() { return *chosen; }
};*/

class Window;
class WindowPropertySink:public IPropertyNotification
{
private:
	Window* m_pw;
public:
	WindowPropertySink(Window* pw) throw();
	virtual void OnPropertyChanged(const std::string& str);
};
class WindowCommandSink : public ICommandNotification
{
private:
	Window* m_pw;
public:
	WindowCommandSink(Window* pw) throw();
	virtual void OnCommandComplete(const std::string& str, bool bOK);
};

class Window
{
public:
	//int robot_num;?好像没用到
	//Robot* robots;
	std::shared_ptr<std::vector<oneRobot>> robots;
	//MOUSEMSG m;
private:
	//std::shared_ptr<ICommandBase> m_cmdlocation;
	//std::shared_ptr<ICommandBase> m_cmdaction;
	std::shared_ptr<ICommandBase> m_cmdQuery;
	std::shared_ptr<WindowPropertySink> m_sinkProperty;
	std::shared_ptr<WindowCommandSink> m_sinkCommand;
	//int width;
	//int height;
public:
	Window();
	~Window() { closegraph(); }
	void RunWindow();
	//void set_locationCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
	//void set_actionCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
	void set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
	std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
	std::shared_ptr<ICommandNotification> get_CommandSink() throw();
};

//ICommandBase, IPropertyNotification, ICommandNotification?
