#pragma once

#include "Model.h"
#include "Command.h"
#include "ViewModelSink.h"
class ViewModel : public Proxy_PropertyNotification<ViewModel>,
	public Proxy_CommandNotification<ViewModel>
{
public:
	ViewModel();

	void SetModel(const std::shared_ptr<Model>& model);

	//std::shared_ptr<std::string> get_StopNumber() throw();
	//std::shared_ptr<std::string> get_CityName() throw();
	/*std::shared_ptr<int> get_x()throw();
	std::shared_ptr<int> get_y()throw();
	std::shared_ptr<int> get_id()throw();
	std::shared_ptr<std::string> get_name()throw();
	std::shared_ptr<int> get_currentlife()throw();
	std::shared_ptr<int> get_wholelife()throw();
	std::shared_ptr<std::string> get_skill()throw();
	std::shared_ptr<int> get_steps()throw();
	std::shared_ptr<int> get_wholesteps()throw();
	std::shared_ptr<int> get_done()throw();
	std::shared_ptr<int> get_chosen()throw();*/

	std::shared_ptr<ICommandBase> get_LocationCommand() throw();
	std::shared_ptr<ICommandBase> get_ActionCommand() throw();


	Model& GetModel() throw();
	//void SetStopNumber(int number);

	//bool Query(const std::string& ss, const std::string& es);
	bool Querylocation(const int & x, const int & y);
	bool Queryaction(const int & a);
private:
	std::shared_ptr<Model> m_BusModel;

	//std::shared_ptr<std::string> m_StopNumber;
	/*std::shared_ptr<int> x;
	std::shared_ptr<int> y;			//机器人在场景中的坐标
	std::shared_ptr<int> id;			//机器人编号，即图片编号
	std::shared_ptr<std::string> name;	//机器人名字
	std::shared_ptr<int> currentlife;//当前生命值
	std::shared_ptr<int> wholelife;	//原本的生命值
	std::shared_ptr<std::string> skill;	//技能名字以及描述
	std::shared_ptr<int> steps;		//剩余可移动步数
	std::shared_ptr<int> wholesteps; //原本的步数
	std::shared_ptr<bool> done;		//是否已经完成了对该机器人的操作，每个回合对一个机器人只能确认操作一次
	std::shared_ptr<bool> chosen;	//是否当前被选中*/

	std::shared_ptr<LocationCommand> m_cmdlocation;
	std::shared_ptr<ActionCommand> m_cmdaction;

	std::shared_ptr<ViewModelSink> m_sink;
};
