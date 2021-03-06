#include "stdafx.h"
#include <Windows.h>
#include "GameAPIBridge.h"
#include "Managers\ActorManager.h"

typedef unsigned int(*GAMEAPI_ACTORMANANGER_ADDMAINROLE)();



GameAPIBridge::GameAPI^		GameAPIBridge::GameAPI::GetInstance()
{
	if (GameAPIBridge::GameAPI::api != nullptr)
		return GameAPIBridge::GameAPI::api;

	GameAPIBridge::GameAPI::api = gcnew GameAPIBridge::GameAPI();

	return GameAPIBridge::GameAPI::api;
}


bool GameAPIBridge::GameAPI::Initialization()
{
	HMODULE hGameAPI = GetModuleHandleA("GameAPI");

	if (SUCCEEDED(hGameAPI))
	{
		if (!m_ActorManager)
			m_ActorManager = gcnew GameAPIBridge::ActorManager();

		m_ActorManager->Initialization();
		return true;
	}
	return false;
}




void GameAPIBridge::GameAPI::Destory()
{

}

GameAPIBridge::ActorManager ^ GameAPIBridge::GameAPI::GetActorManager()
{
	return m_ActorManager;
}
