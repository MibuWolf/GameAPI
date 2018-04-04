#include "stdafx.h"
#include <Windows.h>
#include "ActorManager.h"


typedef unsigned int(*GAMEAPI_ACTORMANANGER_ADDMAINROLE)();



GAMEAPI_ACTORMANANGER_ADDMAINROLE  GAMEAPI_ACTORMANANGER_ADDMAINROLE_FUC = nullptr;


bool GameAPIBridge::ActorManager::Initialization()
{
	HMODULE hGameAPI = GetModuleHandleA("GameAPI");

	if (SUCCEEDED(hGameAPI))
	{
		GAMEAPI_ACTORMANANGER_ADDMAINROLE_FUC = (GAMEAPI_ACTORMANANGER_ADDMAINROLE)GetProcAddress(hGameAPI, "GAMEAPI_ACTORMANANGER_ADDMAINROLE");
	}
	return false;
}


void GameAPIBridge::ActorManager::Destory()
{
	GAMEAPI_ACTORMANANGER_ADDMAINROLE_FUC = nullptr;
}


unsigned int	GameAPIBridge::ActorManager::AddMainRole()
{

	return GAMEAPI_ACTORMANANGER_ADDMAINROLE_FUC();
}