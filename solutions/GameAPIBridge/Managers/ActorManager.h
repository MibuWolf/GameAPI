#pragma once


namespace GameAPIBridge {

	public ref class ActorManager
	{
	public:

		// ��ʼ��
		virtual bool	Initialization();


		// ����
		virtual void	Destory();


	public:

		// �������
		unsigned int	AddMainRole();

	};
}
