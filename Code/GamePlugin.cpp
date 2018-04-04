#include "StdAfx.h"
#include "GamePlugin.h"
#include <CrySchematyc/Env/IEnvRegistry.h>
#include <CrySchematyc/Env/EnvPackage.h>
#include <CrySchematyc/Utils/SharedString.h>

#include <IGameObjectSystem.h>
#include <IGameObject.h>

// Included only once per DLL module.
#include <CryCore/Platform/platform_impl.inl>

#include "Include\IGameAPI.h"
#include "../Code/Help/ToCSharp.h"

CGamePlugin::~CGamePlugin()
{
	// Remove any registered listeners before 'this' becomes invalid
	gEnv->pGameFramework->RemoveNetworkedClientListener(*this);
	gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);

	if (gEnv->pSchematyc)
	{
		gEnv->pSchematyc->GetEnvRegistry().DeregisterPackage(CGamePlugin::GetCID());
	}
}

bool CGamePlugin::Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams)
{
	// Register for engine system events, in our case we need ESYSTEM_EVENT_GAME_POST_INIT to load the map
	gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this, "CGamePlugin");
	// Listen for client connection events, in order to create the local player
	gEnv->pGameFramework->AddNetworkedClientListener(*this);

	return true;
}

void CGamePlugin::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	switch (event)
	{
	case ESYSTEM_EVENT_REGISTER_SCHEMATYC_ENV:
	{
		// Register all components that belong to this plug-in
		auto staticAutoRegisterLambda = [](Schematyc::IEnvRegistrar& registrar)
		{
			// Call all static callback registered with the CRY_STATIC_AUTO_REGISTER_WITH_PARAM
			Detail::CStaticAutoRegistrar<Schematyc::IEnvRegistrar&>::InvokeStaticCallbacks(registrar);
		};

		if (gEnv->pSchematyc)
		{
			gEnv->pSchematyc->GetEnvRegistry().RegisterPackage(
				stl::make_unique<Schematyc::CEnvPackage>(
					CGamePlugin::GetCID(),
					"EntityComponents",
					"Crytek GmbH",
					"Components",
					staticAutoRegisterLambda
					)
			);
		}
	}break;
		// Called when the game framework has initialized and we are ready for game logic to start
	case ESYSTEM_EVENT_GAME_POST_INIT:
	{
		// Don't need to load the map in editor
		if (!gEnv->IsEditor())
		{
			gEnv->pConsole->ExecuteString("map example", false, true);
		}
	}
	break;

		// shutdown
	case ESYSTEM_EVENT_GAME_FRAMEWORK_ABOUT_TO_SHUTDOWN:
	{
		wchar_t strDLLName[256] = L"bin\\Game.dll";
		wchar_t strClassName[256] = L"Game.Game";
		wchar_t strFunction[256] = L"CloseGame";
		wchar_t strParam[256] = L"Hello World";

		wchar_t strCurDir[256];
		wchar_t strDLLPath[256];
		GetCurrentDirectoryW(256, strCurDir);
		swprintf(strDLLPath, L"%s\\%s", strCurDir, strDLLName);

		ToCSharp::DestoryTheDotNetRuntime(L"v4.0.30319",
			strDLLPath,
			strClassName,
			strFunction,
			strParam
		);
	}
	break;
	}
}

bool CGamePlugin::OnClientConnectionReceived(int channelId, bool bIsReset)
{
	//GAME_API->GetActorManager()->AddMainRole("thirdperson");
	//return true;
	wchar_t strDLLName[256] = L"bin\\Game.dll";
	wchar_t strClassName[256] = L"Game.Game";
	wchar_t strFunction[256] = L"InitGame";
	wchar_t strParam[256] = L"Hello World";

	wchar_t strCurDir[256];
	wchar_t strDLLPath[256];
	GetCurrentDirectoryW(256, strCurDir);
	swprintf(strDLLPath, L"%s\\%s", strCurDir, strDLLName);

	GAME_API->num = 8;

	ToCSharp::StartTheDotNetRuntime(L"v4.0.30319",
		strDLLPath,
		strClassName,
		strFunction,
		strParam
	);

	return true;
}

bool CGamePlugin::OnClientReadyForGameplay(int channelId, bool bIsReset)
{
	// Revive players when the network reports that the client is connected and ready for gameplay
	auto it = m_players.find(channelId);
	if (it != m_players.end())
	{
		/*if (IEntity* pPlayerEntity = gEnv->pEntitySystem->GetEntity(it->second))
		{
			if (CPlayerComponent* pPlayer = pPlayerEntity->GetComponent<CPlayerComponent>())
			{
				pPlayer->Revive();
			}
		}*/
	}

	return true;
}

void CGamePlugin::OnClientDisconnected(int channelId, EDisconnectionCause cause, const char* description, bool bKeepClient)
{
	// Client disconnected, remove the entity and from map
	auto it = m_players.find(channelId);
	if (it != m_players.end())
	{
		gEnv->pEntitySystem->RemoveEntity(it->second);

		m_players.erase(it);
	}
}

CRYREGISTER_SINGLETON_CLASS(CGamePlugin)