#pragma once
#include "Managers\ActorManager.h"
using namespace System;

namespace GameAPIBridge {

	public ref class GameAPI
	{
	public:

		static GameAPI^		GetInstance();

	public:
		
		// 初始化
		bool	Initialization();

		// 销毁
		void	Destory();


	public:

		// Actor管理器
		ActorManager ^ GetActorManager();

	private:

		static GameAPI ^		api;

	private:

		GameAPIBridge::ActorManager ^ m_ActorManager;				// Actor管理器
	};
}
