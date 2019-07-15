#pragma once
#include "..\Common\etlbase.h"
//#include "etlbase.h"

class ViewModel;

class ViewModelSink : public IPropertyNotification
{
public:
	ViewModelSink(ViewModel* p) throw();
	virtual void OnPropertyChanged(const std::string& str);
private:
	ViewModel* m_pVM;
};
