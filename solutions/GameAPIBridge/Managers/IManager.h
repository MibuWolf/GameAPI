#pragma once



namespace GameAPIBridge {

	public ref class IManager
	{
	public:

		// ³õÊ¼»¯
		virtual bool	Initialization() = 0;


		// Ïú»Ù
		virtual void	Destory() = 0;

	};
}
