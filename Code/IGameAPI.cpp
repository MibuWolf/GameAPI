#include "StdAfx.h"
#include "Include\IGameAPI.h"
#include "Actor\ActorManager.h"


IGameAPI::IGameAPI()
{

}

IGameAPI::~IGameAPI()
{
}

bool IGameAPI::Initialize()
{
	return false;
}


IActorManager * IGameAPI::GetActorManager()
{
	return ActorManager::GetInstance();
}

