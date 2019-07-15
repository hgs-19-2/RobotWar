#pragma once
#include "..\View\View.h"
#include "..\ViewModel\ViewModel.h"
//#include "View.h"
//#include "ViewModel.h"

class App
{
public:
	App();
	~App() throw();

	bool Init();
	void Show();

private:
	Window  m_wndMain;
	std::shared_ptr<ViewModel>  m_spViewModel;
};