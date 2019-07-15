//#include "precomp.h"
#include "App.h"

App::App()
{
}

App::~App() throw()
{
}

bool App::Init()
{
	//if (m_wndMain.Create(NULL, CWindow::rcDefault, _T("Bus Map")) == NULL) {	return false;}

	//objects
	std::shared_ptr<Model> spModel(std::make_shared<Model>());
	m_spViewModel = std::make_shared<ViewModel>();
	m_spViewModel->SetModel(spModel);
	//binding
	// properties
	//m_wndMain.m_lblStopNumber.set_Name(m_spViewModel->get_StopNumber());
	//m_wndMain.m_lblCityName.set_Name(m_spViewModel->get_CityName());
	m_wndMain.robots = m_spViewModel->get_robots();
	
	// commands
	m_wndMain.set_QueryCommand(m_spViewModel->get_QueryCommand());
	// notifications
	m_spViewModel->AddPropertyNotification(m_wndMain.get_PropertySink());
	m_spViewModel->AddCommandNotification(m_wndMain.get_CommandSink());

	return true;
}

void App::Show()
{
	m_wndMain.RunWindow();
}
