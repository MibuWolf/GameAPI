#include "StdAfx.h"
#include "ActorManager.h"
#include "../Components/Actor/ActorComponent.h"


ActorManager::ActorManager()
{
}

ActorManager::~ActorManager()
{
}

unsigned int ActorManager::AddMainRole(const char* charaterName)
{
	IEntity* pEntity = this->CreateEntity();
	if (!pEntity)
		return 0;

	ActorComponent* pActor = pEntity->GetOrCreateComponentClass<ActorComponent>();
	pActor->LoadCharacter(charaterName);

	m_mainRole = pEntity->GetId();

	return m_mainRole;
}

unsigned int ActorManager::GetMainRole()
{
	return m_mainRole;
}

bool ActorManager::AttachObject(unsigned int uID, const char * pAttachName, const char * pObjectPath)
{
	return false;
}

bool ActorManager::AttachObjectByID(unsigned int uID, unsigned int uAttachID)
{
	return false;
}

IEntity * ActorManager::CreateEntity()
{
	SEntitySpawnParams spawnParams;
	spawnParams.pClass = gEnv->pEntitySystem->GetClassRegistry()->GetDefaultClass();
	spawnParams.sName = "Player";
	spawnParams.nFlags |= ENTITY_FLAG_NEVER_NETWORK_STATIC;

	// Set local player details
	spawnParams.nFlags |= ENTITY_FLAG_LOCAL_PLAYER;

	return gEnv->pEntitySystem->SpawnEntity(spawnParams);
}
