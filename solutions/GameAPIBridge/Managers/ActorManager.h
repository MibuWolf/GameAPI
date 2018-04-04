#pragma once


namespace GameAPIBridge {

	public ref class ActorManager
	{
	public:

		// 初始化
		virtual bool	Initialization();


		// 销毁
		virtual void	Destory();


	public:

		// 添加主角
		unsigned int	AddMainRole();

	};
}
