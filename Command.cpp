#include "Command.h"

#include "ViewModel.h"
//location
LocationCommand::LocationCommand(ViewModel* p) throw() : m_pVM(p)
{
}

void LocationCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<location>(param);
}

void LocationCommand::Exec()
{
	bool bResult = m_pVM->Querylocation(m_param.getlocationx(), m_param.getlocationy());
	m_pVM->Fire_OnCommandComplete("query", bResult);
}

//action
ActionCommand::ActionCommand(ViewModel* p) throw() : m_pVM(p)
{
}

void ActionCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<action>(param);
}

void ActionCommand::Exec()
{
	bool bResult = m_pVM->Queryaction(m_param.getaction());
	m_pVM->Fire_OnCommandComplete("query", bResult);
}
