#pragma once

#include "Model.h"
#include "Command.h"
#include "ViewModelSink.h"
class ViewModel : public Proxy_PropertyNotification<ViewModel>,
	public Proxy_CommandNotification<ViewModel>
{
public:
	ViewModel();

	void SetModel(const std::shared_ptr<Model>& model);

	//std::shared_ptr<std::string> get_StopNumber() throw();
	//std::shared_ptr<std::string> get_CityName() throw();
	/*std::shared_ptr<int> get_x()throw();
	std::shared_ptr<int> get_y()throw();
	std::shared_ptr<int> get_id()throw();
	std::shared_ptr<std::string> get_name()throw();
	std::shared_ptr<int> get_currentlife()throw();
	std::shared_ptr<int> get_wholelife()throw();
	std::shared_ptr<std::string> get_skill()throw();
	std::shared_ptr<int> get_steps()throw();
	std::shared_ptr<int> get_wholesteps()throw();
	std::shared_ptr<int> get_done()throw();
	std::shared_ptr<int> get_chosen()throw();*/

	std::shared_ptr<ICommandBase> get_LocationCommand() throw();
	std::shared_ptr<ICommandBase> get_ActionCommand() throw();


	Model& GetModel() throw();
	//void SetStopNumber(int number);

	//bool Query(const std::string& ss, const std::string& es);
	bool Querylocation(const int & x, const int & y);
	bool Queryaction(const int & a);
private:
	std::shared_ptr<Model> m_BusModel;

	//std::shared_ptr<std::string> m_StopNumber;
	/*std::shared_ptr<int> x;
	std::shared_ptr<int> y;			//�������ڳ����е�����
	std::shared_ptr<int> id;			//�����˱�ţ���ͼƬ���
	std::shared_ptr<std::string> name;	//����������
	std::shared_ptr<int> currentlife;//��ǰ����ֵ
	std::shared_ptr<int> wholelife;	//ԭ��������ֵ
	std::shared_ptr<std::string> skill;	//���������Լ�����
	std::shared_ptr<int> steps;		//ʣ����ƶ�����
	std::shared_ptr<int> wholesteps; //ԭ���Ĳ���
	std::shared_ptr<bool> done;		//�Ƿ��Ѿ�����˶Ըû����˵Ĳ�����ÿ���غ϶�һ��������ֻ��ȷ�ϲ���һ��
	std::shared_ptr<bool> chosen;	//�Ƿ�ǰ��ѡ��*/

	std::shared_ptr<LocationCommand> m_cmdlocation;
	std::shared_ptr<ActionCommand> m_cmdaction;

	std::shared_ptr<ViewModelSink> m_sink;
};
