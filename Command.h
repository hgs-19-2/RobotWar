#pragma once
#include "etlbase.h"

//#include "common/parameters.h"
#include "Common.h"
class ViewModel;
class LocationCommand :public ICommandBase
{
public:
	LocationCommand(ViewModel*p)throw();
	virtual void SetParameter(const std::any& param);
	virtual void Exec();
private:
	ViewModel* m_pVM;
	location m_param;
};
class ActionCommand :public ICommandBase
{
public:
	ActionCommand(ViewModel*p)throw();
	virtual void SetParameter(const std::any& param);
	virtual void Exec();
private:
	ViewModel* m_pVM;
	action m_param;
};
/*class BusViewModel;
class QueryCommand : public ICommandBase
{
public:
	QueryCommand(BusViewModel* p) throw();

	virtual void SetParameter(const std::any& param);
	virtual void Exec();

private:
	BusViewModel* m_pVM;

	TwoStrings m_param;
};*/