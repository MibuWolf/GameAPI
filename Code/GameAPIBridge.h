#pragma once
#include "Include\IGameAPI.h"



#ifdef __cplusplus
extern "C" {
#endif

	// ActorManagerœ‡πÿ

	extern unsigned int		TD_EXPORTS			GAMEAPI_ACTORMANANGER_ADDMAINROLE();
	extern unsigned int		TD_EXPORTS			GAMEAPI_ACTORMANANGER_GETMAINROLE();
	extern bool				TD_EXPORTS			GAMEAPI_ACTORMANANGER_ATTACHOBJECT(unsigned int uID, const char* pAttachName, const char* pObjectPath);
	extern bool				TD_EXPORTS			GAMEAPI_ACTORMANANGER_ATTACHOBJECTBYID(unsigned int uID, unsigned int uAttachID);

#ifdef __cplusplus
}
#endif