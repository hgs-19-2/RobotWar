#include "Command.h"

#include "ViewModel.h"
QueryCommand::QueryCommand(ViewModel* p) throw() : m_pVM(p)
{
}

void QueryCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<ThreeInt>(param);
}

void QueryCommand::Exec()
{
	bool bResult = m_pVM->Query(m_param.get_a(), m_param.get_b(), m_param.get_c());
	m_pVM->Fire_OnCommandComplete("query", bResult);
}

