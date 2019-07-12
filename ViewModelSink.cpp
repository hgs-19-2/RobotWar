#include "ViewModelSink.h"

#include "ViewModel.h"

ViewModelSink::ViewModelSink(ViewModel* p) throw() : m_pVM(p)
{
}

void ViewModelSink::OnPropertyChanged(const std::string& str)
{
	/*if (str == "Stop_Number") {
		m_pVM->SetStopNumber(m_pVM->GetModel().GetStopNumber());
		m_pVM->Fire_OnPropertyChanged(str);//?
	}
	else if (str == "city-name") {
		m_pVM->Fire_OnPropertyChanged(str);//?
	}*/
}
