#include "ViewModel.h"

ViewModel::ViewModel() : //m_StopNumber(std::make_shared<std::string>()),
m_cmdlocation(std::make_shared<LocationCommand>(this)),
m_cmdaction(std::make_shared<ActionCommand>(this)),
m_sink(std::make_shared<ViewModelSink>(this))
{
}

void ViewModel::SetModel(const std::shared_ptr<Model>& model)
{
	m_BusModel = model;
	m_BusModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
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
std::shared_ptr<ICommandBase> ViewModel::get_LocationCommand() throw()
{
	return std::static_pointer_cast<ICommandBase>(m_cmdlocation);
}
std::shared_ptr<ICommandBase> ViewModel::get_ActionCommand() throw()
{
	return std::static_pointer_cast<ICommandBase>(m_cmdaction);
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
bool ViewModel::Querylocation(const int & x, const int & y)
{
	return m_BusModel->Querylocation(x, y);
}
bool ViewModel::Queryaction(const int & a)
{
	return m_BusModel->Querylocation(a);
}