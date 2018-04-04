#include "StdAfx.h"
#include "GameAPIBridge.h"


// ActormanagerÏà¹Ø

unsigned int TD_EXPORTS GAMEAPI_ACTORMANANGER_ADDMAINROLE()
{
	int a = GAME_API->num;
	return GAME_API->GetActorManager()->AddMainRole("thirdperson");
}

unsigned int TD_EXPORTS GAMEAPI_ACTORMANANGER_GETMAINROLE()
{
	return GAME_API->GetActorManager()->GetMainRole();
}

bool TD_EXPORTS GAMEAPI_ACTORMANANGER_ATTACHOBJECT(unsigned int uID, const char * pAttachName, const char * pObjectPath)
{
	return GAME_API->GetActorManager()->AttachObject(uID,pAttachName, pObjectPath);
}

bool TD_EXPORTS GAMEAPI_ACTORMANANGER_ATTACHOBJECTBYID(unsigned int uID, unsigned int uAttachID)
{
	return GAME_API->GetActorManager()->AttachObjectByID(uID,uAttachID);
}
