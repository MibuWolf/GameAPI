#pragma once



namespace GameAPIBridge {

	public ref class IManager
	{
	public:

		// ��ʼ��
		virtual bool	Initialization() = 0;


		// ����
		virtual void	Destory() = 0;

	};
}
