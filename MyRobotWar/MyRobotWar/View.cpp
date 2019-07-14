#include "View.h"

#define move_x1 10
#define move_x2 30
#define move_y1 20
#define move_y2 30
#define skill_x1 10
#define skill_x2 30
#define skill_y1 50
#define skill_y2 100
#define done_x1 10
#define done_x2 30
#define done_y1 110
#define done_y2 120

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

Window::Window() : m_sinkProperty(std::make_shared<WindowPropertySink>(this)),
m_sinkCommand(std::make_shared<WindowCommandSink>(this))
{ 
	//width = x;
	//height = y; 
	//initgraph(x, y); 
	initgraph(1000, 1000);
}
void Window::RunWindow()
{
	//initgraph(width, height);
	//background
	IMAGE background;
	loadimage(&background, "picture\\background.jpg");
	putimage(50, 0, &background);
	//robots
	for (int i = 0; i < robots->size(); i++)
	{
		//robots[i].UpdateRobot();
		(*robots)[i].ShowoneRobot();
	}
	//information of players
	outtextxy(20, 20, "玩家");
	outtextxy(600, 20, "电脑");
	MOUSEMSG m;
	while (true)
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
				std::any param(std::make_any<ThreeInt>());
				ThreeInt& tp = std::any_cast<ThreeInt&>(param);
				tp.setThreeInt(1,x,y);
				m_cmdQuery->SetParameter(param);
				m_cmdQuery->Exec();
				
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					 x = m.x;
					 y = m.y;
					//移动 (2,x,y)
					if (x > move_x1 && x<move_x2 && y>move_y1 && y < move_y2)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
						{
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
					}
					//技能 3-7 (3-7,x,y)
					else if (x > skill_x1 && x<skill_x2 && y>skill_y1 && y < skill_y2)
					{
						int i = (y - skill_y1) / ((skill_y2 - skill_y1) / 5) + 3;
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
						{
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