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

	std::shared_ptr<std::vector<oneRobot>> get_robots()throw();

	std::shared_ptr<ICommandBase> get_QueryCommand() throw();

	Model& GetModel() throw();
	//void SetStopNumber(int number);
	void SetRobots();

	//bool Query(const std::string& ss, const std::string& es);
	bool Query(const int& a, const int&x,const int&y);
	
private:
	std::shared_ptr<Model> m_BusModel;

	//std::shared_ptr<std::string> m_StopNumber;
	std::shared_ptr<std::vector<oneRobot>> robots;

	std::shared_ptr<QueryCommand> m_cmdQuery;
	std::shared_ptr<ViewModelSink> m_sink;
};
