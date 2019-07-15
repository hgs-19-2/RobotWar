#include "View.h"
#define play_x1 560
#define play_x2 930
#define play_y1 130
#define play_y2 230
#define exit_x1 560
#define exit_x2 930
#define exit_y1 290
#define exit_y2 390
#define move_x1 50
#define move_x2 200
#define move_y1 300
#define move_y2 330
#define skill_x1 50
#define skill_x2 120
#define skill_y1 350
#define skill_y2 550
#define done_x1 50
#define done_x2 200
#define done_y1 565
#define done_y2 595
#define cpu_start 5
bool continueplay = true;

//一个机器人的信息设置
/*void Robot::SetRobot(const shared_ptr<int>&tx, const shared_ptr<int>&ty, const shared_ptr<int>&tid, const shared_ptr<string>&tname,
	const shared_ptr<int>&tcurrentlife, const shared_ptr<int>&twholelife, const shared_ptr<string>&tskill,
	const shared_ptr<int>&tsteps, const shared_ptr<int>&twholesteps, const shared_ptr<bool>&tdone,
	const shared_ptr<bool>&tchosen)throw()
{
	x = tx;
	y = ty;
	id = tid;			//机器人编号，即图片编号
	name = tname;		//机器人名字
	currentlife = tcurrentlife;//当前生命值
	wholelife = twholelife;	//原本的生命值
	skill = tskill;	//技能名字以及描述
	steps = tsteps;		//剩余可移动步数
	wholesteps = twholesteps; //原本的步数
	done = tdone;		//是否已经完成了对该机器人的操作，每个回合对一个机器人只能确认操作一次
	chosen = tchosen;	//是否当前被选中
}
//显示一个机器人
void Robot::UpdateRobot()
{
	IMAGE img;
	string str = to_string(*id) + ".jpg";
	loadimage(&img, str.c_str());
	putimage(start_x + (*x) * cell_width, (*y)*cell_width, &img);
	if (done) outtextxy(start_x + (*x) * cell_width, (*y)*cell_width, "done");
	if (chosen)
	{
		//画一个选中的框
		setlinecolor(YELLOW);
		rectangle(start_x + (*x) * cell_width, (*y)*cell_width, start_x + (*x + 1)*cell_width, (*y + 1)*cell_width);
		//画行动范围
		setlinecolor(YELLOW);
		//row 行，col 列
		int i = *x - *steps;
		if (i < 0)i = 0;
		for (; i <= *x + *steps && i < col; i++)
		{
			int j = *y - *steps;
			if (j < 0)j = 0;
			for (; j <= *y + *steps && j < row; j++);
			{
				if (i + j <= *x + *y + *steps && i + j >= *x + *y - *steps)
				{
					rectangle(start_x + i * cell_width, j*cell_width, start_x + (i + 1)*cell_width, (j + 1)*cell_width);
				}
			}
		}
		//显示一个机器人的信息
		outtextxy(10, 50, "选中机器人信息：");
		outtext("\n名字：");
		outtext(name->c_str());
		outtext("\n生命值：");
		outtext(*currentlife);
		outtext(" / ");
		outtext(*wholelife);
		outtext("\n技能：");
		outtext(skill->c_str());
		outtext("\n可移动步数：");
		outtext(*steps);
		outtext(" / ");
		outtext(*wholesteps);

	}
};*/
WindowPropertySink::WindowPropertySink(Window* pw) throw() :m_pw(pw) {}
void WindowPropertySink::OnPropertyChanged(const std::string& str)
{
	string s = str.substr(0, 6);

	if (str == "robots" || str.substr(0,6)=="attack")
	{
		IMAGE background;
		loadimage(&background, "picture\\background1.jpg");
		putimage(0, 0, &background);
		//robots
		int count = 0;
		for (int i = 0; i < (*(m_pw->robots)).size(); i++)
		{
			(*(m_pw->robots))[i].ShowoneRobot();
			if ((*(m_pw->robots))[i].getid() >= cpu_start)
			{
				(*(m_pw->robots))[i].ShowOneCpuInfo(count);
				count++;
			}
		}
		//information of players
		//outtextxy(180, 20, "玩家");
		//outtextxy(1180, 20, "电脑");
		if (str.substr(0, 6) == "attack")
		{
			int x = atoi(str.substr(6, 2).c_str());
			int y;
			if (str[8] == ',')y = atoi(str.substr(9).c_str());
			else y = atoi(str.substr(8).c_str());
			outtextxy(start_x + x * cell_width, y*cell_width, "attacked!");
		}
		
	}
	else if (str == "win")
	{
		IMAGE win;
		loadimage(&win, "picture\\win.jpg");
		putimage(1050, 400, &win);
		_getch();
		continueplay = false;
	}
	else if (str == "lose")
	{
		IMAGE lose;
		loadimage(&lose, "picture\\lose.jpg");
		putimage(1050, 400, &lose);
		_getch();
		continueplay = false;

	}
}
WindowCommandSink::WindowCommandSink(Window* pw) throw():m_pw(pw)
{
}
void WindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
	/*if (str == "query") {
		if (!bOK) {
			AtlMessageBox(NULL, _T("error query"), _T("error"), MB_OK);
		}
	}*/
}
Window::Window() : m_sinkProperty(std::make_shared<WindowPropertySink>(this)),
m_sinkCommand(std::make_shared<WindowCommandSink>(this))
{ 
	//width = x;
	//height = y; 
	//initgraph(x, y); 
	initgraph(1400, 600);
}
void Window::RunWindow()
{
	//initgraph(width, height);
	//start play
	IMAGE start;
	loadimage(&start, "picture\\start.jpg");
	putimage(0, 0, &start);
	//rectangle(play_x1, play_y1, play_x2, play_y2);
	//rectangle(exit_x1, exit_y1, exit_x2, exit_y2);
	MOUSEMSG m;
	m = GetMouseMsg();
	while (m.uMsg != WM_LBUTTONDOWN || 
		!((m.x>play_x1&&m.x<play_x2&&m.y>play_y1&&m.y<play_y2)||(m.x>exit_x1&&m.x<exit_x2&&m.y>exit_y1&&m.y<exit_y2)))
		m = GetMouseMsg();
	if (m.x > exit_x1&&m.x<exit_x2&&m.y>exit_y1&&m.y < exit_y2) return;//退出游戏
	//init background
	IMAGE background;
	loadimage(&background, "picture\\background1.jpg");
	putimage(0, 0, &background);
	//gameinit
	std::any param(std::make_any<ThreeInt>());
	ThreeInt& tp = std::any_cast<ThreeInt&>(param);
	tp.setThreeInt(0, 0, 0);
	m_cmdQuery->SetParameter(param);
	m_cmdQuery->Exec();
	//stageinit
	//std::any param(std::make_any<ThreeInt>());
	//ThreeInt& tp = std::any_cast<ThreeInt&>(param);
	tp.setThreeInt(0, 1, 0);
	m_cmdQuery->SetParameter(param);
	m_cmdQuery->Exec();
	//robots
	int count = 0;
	for (int i = 0; i < robots->size(); i++)
	{
		//robots[i].UpdateRobot();
		(*robots)[i].ShowoneRobot();
		if ((*robots)[i].getid() >= cpu_start)//0,1player,2,3computer
		{
			(*robots)[i].ShowOneCpuInfo(count);
			count++;
		}
			
	}
	//information of players
	//outtextxy(180, 20, "玩家");
	//outtextxy(1180, 20, "电脑");
	
	while (continueplay)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			int x = m.x;
			int y = m.y;
			//选择 (1,x,y)
			if (x > start_x&& x < start_x + col * cell_width && y < row * cell_width)
			{
				
				x = (x - start_x) / cell_width;
				y = y / cell_width;
				//std::any param(std::make_any<ThreeInt>());
				//ThreeInt& tp = std::any_cast<ThreeInt&>(param);
				tp.setThreeInt(1,x,y);
				m_cmdQuery->SetParameter(param);
				m_cmdQuery->Exec();
				
				m = GetMouseMsg();
				while (m.uMsg != WM_LBUTTONDOWN)m = GetMouseMsg();
				x = m.x;
				y = m.y;
				//移动 (2,x,y)
				if (x > move_x1 && x<move_x2 && y>move_y1 && y < move_y2)
				{
					m = GetMouseMsg();
					while (m.uMsg != WM_LBUTTONDOWN)m = GetMouseMsg();
					x = m.x;
					y = m.y;
					if (x > start_x&& x < start_x + col * cell_width && y < row * cell_width)
					{
						x = (x - start_x) / cell_width;
						y = y / cell_width;
						std::any param(std::make_any<ThreeInt>());
						ThreeInt& tp = std::any_cast<ThreeInt&>(param);
						tp.setThreeInt(2, x, y);
						m_cmdQuery->SetParameter(param);
						m_cmdQuery->Exec();
					}
				}
				//技能 3-7 (3-7,x,y)
				else if (x > skill_x1 && x<skill_x2 && y>skill_y1 && y < skill_y2)
				{
					//int x1 = x-(*robots)
					int i = (y - skill_y1) / ((skill_y2 - skill_y1) / 5) + 3;
					m = GetMouseMsg();
					while (m.uMsg != WM_LBUTTONDOWN)m = GetMouseMsg();
					x = m.x;
					y = m.y;
					if (x > start_x&& x < start_x + col * cell_width && y < row * cell_width)
					{
						x = (x - start_x) / cell_width;
						y = y / cell_width;
						std::any param(std::make_any<ThreeInt>());
						ThreeInt& tp = std::any_cast<ThreeInt&>(param);
						tp.setThreeInt(i, x, y);
						m_cmdQuery->SetParameter(param);
						m_cmdQuery->Exec();
					}
				}
				//结束对当前机器人的操作 (8,0,0)
				else if (x > done_x1 && x<done_x2 && y>done_y1 && y < done_y2)
				{
					std::any param(std::make_any<ThreeInt>());
					ThreeInt& tp = std::any_cast<ThreeInt&>(param);
					tp.setThreeInt(8, 0, 0);
					m_cmdQuery->SetParameter(param);
					m_cmdQuery->Exec();
				}
			}
		}
	}
}

void Window::set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdQuery = cmd;
}
std::shared_ptr<IPropertyNotification> Window::get_PropertySink() throw() 
{ 
	return std::static_pointer_cast<IPropertyNotification>(m_sinkProperty); 
}
std::shared_ptr<ICommandNotification> Window::get_CommandSink() throw() 
{ 
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommand); 
}