﻿////////////////////////////////////////////////////////////////////////////////
#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <any>
#include <memory>
#include <vector>
#include <map>
#include <stack>
#include <array>

//types
typedef unsigned char     uchar;
typedef unsigned short    ushort;
typedef unsigned int      uint;
typedef unsigned __int64  uint64;
typedef __int64           int64;

//command


class ICommandParameter
{
};


class ICommandBase
{
public:
	//virtual void SetParameter(const std::shared_ptr<ICommandParameter>& param) = 0;
	virtual void SetParameter(const std::any& param) = 0;
	virtual void Exec() = 0;
/*
virtual std::shared_ptr<ICommandBase> get_Undo() = 0;
virtual std::shared_ptr<ICommandBase> get_Redo() = 0;
//use make_shared, then the virtual destructor is not necessary. (RAII)
*/
};

class CommandManager
{
public:
/*
...
*/
private:
	std::vector<std::shared_ptr<ICommandBase>> m_vecUndo;
	std::vector<std::shared_ptr<ICommandBase>> m_vecRedo;
};

//Notifications

template <class T>
class NotificationImpl
{
public:
	void Clear() throw()
	{
		m_array.clear();
	}
	void AddNotification(const std::shared_ptr<T>& p)
	{
		m_array.push_back(p);
	}
	void RemoveNotification(const std::shared_ptr<T>& p) throw()
	{
		auto iter(m_array.begin());
		for( ; iter != m_array.end(); ++ iter ) {
			if( (*iter).get() == p.get() ) {
				m_array.erase(iter);
				return ;
			}
		}
	}

protected:
	std::vector<std::shared_ptr<T>> m_array;
};

class IPropertyNotification
{
public:
	virtual void OnPropertyChanged(const std::string& str) = 0;
	//virtual void OnPropertyChanged(unsigned int uPropertyID) = 0;
};

class ICommandNotification
{
public:
	virtual void OnCommandComplete(const std::string& str, bool bOK) = 0;
	//virtual void OnCommandComplete(unsigned int uCommandID, bool bOK) = 0;
};

template <class T>
class Proxy_PropertyNotification : public NotificationImpl<IPropertyNotification>
{
public:
	void AddPropertyNotification(const std::shared_ptr<IPropertyNotification>& p)
	{
		AddNotification(p);
	}
	void RemovePropertyNotification(const std::shared_ptr<IPropertyNotification>& p) throw()
	{
		RemoveNotification(p);
	}
	void Fire_OnPropertyChanged(const std::string& str)
	{
		auto iter(m_array.begin());
		for( ; iter != m_array.end(); ++ iter ) {
			(*iter)->OnPropertyChanged(str);
		}
	}
};
template <class T>
class Proxy_CommandNotification : public NotificationImpl<ICommandNotification>
{
public:
	void AddCommandNotification(const std::shared_ptr<ICommandNotification>& p)
	{
		AddNotification(p);
	}
	void RemoveCommandNotification(const std::shared_ptr<ICommandNotification>& p) throw()
	{
		RemoveNotification(p);
	}
	void Fire_OnCommandComplete(const std::string& str, bool bOK)
	{
		auto iter(m_array.begin());
		for( ; iter != m_array.end(); ++ iter ) {
			(*iter)->OnCommandComplete(str, bOK);
		}
	}
};

//state machine
/*
class IStateBase
{
public:
	virtual int Process(unsigned int uEvent, const std::any& param) = 0;
};

class StateManager
{
public:
	void Add(int iState, const std::shared_ptr<IStateBase>& spState)
	{
		m_map.insert(std::pair<int, std::shared_ptr<IStateBase>>(iState, spState));
	}
	void SetStartState(int iStartState) throw()
	{
		m_iCurrentState = iStartState;
	}
	void Process(unsigned int uEvent, const std::any& param)
	{
		auto iter(m_map.find(m_iCurrentState));
		if( iter != m_map.end() )
			m_iCurrentState = iter->second->Process(uEvent, param);
	}
	int GetCurrentState() const throw()
	{
		return m_iCurrentState;
	}

private:
	int m_iCurrentState;
	std::map<int, std::shared_ptr<IStateBase>> m_map;
};*/

////////////////////////////////////////////////////////////////////////////////
