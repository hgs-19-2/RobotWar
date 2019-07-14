#include "ViewModel.h"

ViewModel::ViewModel() : //m_StopNumber(std::make_shared<std::string>()),
m_cmdQuery(std::make_shared<QueryCommand>(this)),
m_sink(std::make_shared<ViewModelSink>(this))
{
}

void ViewModel::SetModel(const std::shared_ptr<Model>& model)
{
	m_BusModel = model;
	m_BusModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}
void ViewModel::SetRobots()
{
	robots->clear();
	oneRobot tmp;
	int n = m_BusModel->gethuman()->getrobotnumber();
	for (int i = 0; i < n; i++)
	{
		int x = m_BusModel->gethuman()->Robotlocation[i].getlocationx();
		int y = m_BusModel->gethuman()->Robotlocation[i].getlocationy();
		int id = 0;//?
		string name = m_BusModel->gethuman()->playerrobot[i].getname();
		int currentlife = m_BusModel->gethuman()->playerrobot[i].getnowhp();
		int wholelife = m_BusModel->gethuman()->playerrobot[i].getmaxhp();
		int numskills = m_BusModel->gethuman()->playerrobot[i].getskillnum();
		vector<Robotskill> skills;
		for (int j = 0; j < numskills; j++)
		{
			skills.push_back(m_BusModel->gethuman()->playerrobot[i].getskillinfo(j));
		}
		int steps = m_BusModel->gethuman()->playerrobot[i].getcanmove();
		int wholesteps = m_BusModel->gethuman()->playerrobot[i].getmoverange();
		bool done = m_BusModel->gethuman()->ifonedone(i);
		bool chosen = false;//?
		tmp.SetoneRobot(x, y, id, name, currentlife, wholelife, skills, steps, wholesteps, done, chosen);
		robots->push_back(tmp);
	}
	int m = m_BusModel->getcpu()->getrobotnumber();
	
	for (int i = 0; i < m; i++)
	{
		int x = m_BusModel->getcpu()->Robotlocation[i].getlocationx();
		int y = m_BusModel->getcpu()->Robotlocation[i].getlocationy();
		int id = 0;//?
		string name = m_BusModel->getcpu()->playerrobot[i].getname();
		int currentlife = m_BusModel->getcpu()->playerrobot[i].getnowhp();
		int wholelife = m_BusModel->getcpu()->playerrobot[i].getmaxhp();
		int numskills = m_BusModel->getcpu()->playerrobot[i].getskillnum();
		vector<Robotskill> skills;
		for (int j = 0; j < numskills; j++)
		{
			skills.push_back(m_BusModel->getcpu()->playerrobot[i].getskillinfo(j));
		}
		int steps = m_BusModel->getcpu()->playerrobot[i].getcanmove();
		int wholesteps = m_BusModel->getcpu()->playerrobot[i].getmoverange();
		bool done = m_BusModel->getcpu()->ifonedone(i);
		bool chosen = false;//?
		tmp.SetoneRobot(x, y, id, name, currentlife, wholelife, skills, steps, wholesteps, done, chosen);
		robots->push_back(tmp);
	}
}
std::shared_ptr<std::vector<oneRobot>> ViewModel::get_robots()throw()
{
	return robots;
}
/*
std::shared_ptr<std::string> ViewModel::get_StopNumber() throw()
{
	return m_StopNumber;
}

std::shared_ptr<std::string> BusViewModel::get_CityName() throw()
{
	return m_BusModel->get_CityName();
}
*/

std::shared_ptr<ICommandBase> ViewModel::get_QueryCommand() throw()
{
	return std::static_pointer_cast<ICommandBase>(m_cmdQuery);
}
Model& ViewModel::GetModel() throw()
{
	return *m_BusModel;
}
/*
void ViewModel::SetStopNumber(int number)
{
	*m_StopNumber = std::to_string(number);
}*/

bool ViewModel::Query(const int & a, const int & x, const int & y)
{
	return m_BusModel->Query(a, x, y);
}