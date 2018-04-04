cmake_minimum_required (VERSION 3.6.2)
set(CRYENGINE_DIR "D:/Program Files (x86)/Crytek/CRYENGINE Launcher/Crytek/CRYENGINE_5.4")
set(TOOLS_CMAKE_DIR "${CRYENGINE_DIR}/Tools/CMake")

set(PROJECT_BUILD 1)
set(PROJECT_DIR "E:/Code/GameAPI")

include("${TOOLS_CMAKE_DIR}/CommonOptions.cmake")

add_subdirectory("${CRYENGINE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/CRYENGINE")

include("${TOOLS_CMAKE_DIR}/Configure.cmake")
start_sources()

sources_platform(ALL)
add_sources("Code_uber.cpp"
    PROJECTS GameAPI
    SOURCE_GROUP "Root"
		"GamePlugin.cpp"
		"StdAfx.cpp"
		"IGameAPI.cpp"
		"GameAPIBridge.cpp"
		"GameAPIBridge.h"
		"GamePlugin.h"
		"StdAfx.h"
)
add_sources("Components_uber.cpp"
    PROJECTS GameAPI
	SOURCE_GROUP "Include"
		"Include/IGameAPI.h"
		"Include/ICryEngine.h"
		"Include/IMiscellaneous.h"
	SOURCE_GROUP "Include\\\\Actor"
		"Include/Actor/IActorManager.h"
	SOURCE_GROUP "Help"
		"Help/ToCSharp.cpp"
		"Help/ToCSharp.h"
	SOURCE_GROUP "Actor"
		"Actor/ActorManager.cpp"
		"Actor/ActorManager.h"
	SOURCE_GROUP "Components"
    SOURCE_GROUP "Components\\\\Properties"
		"Components/Properties/Properties.h"
		"Components/Properties/WeaponProperties.h"
	SOURCE_GROUP "Components\\\\SpawnPoint"
		"Components/SpawnPoint/SpawnPoint.cpp"
		"Components/SpawnPoint/SpawnPoint.h"
	SOURCE_GROUP "Components\\\\Actor"
		"Components/Actor/ActorComponent.cpp"
		"Components/Actor/ActorComponent.h"
	SOURCE_GROUP "Components\\\\Item"
		"Components/Item/ItemComponent.h"
		"Components/Item/ItemComponent.cpp"
		"Components/Item/WeaponComponent.h"
		"Components/Item/WeaponComponent.cpp"
)

end_sources()
CryEngineModule(GameAPI PCH "StdAfx.cpp" SOLUTION_FOLDER "Project")

target_include_directories(${THIS_PROJECT}
PRIVATE 
    "${CRYENGINE_DIR}/Code/CryEngine/CryCommon"
    "${CRYENGINE_DIR}/Code/CryEngine/CryAction"
	"${CRYENGINE_DIR}/Code/CryEngine/CrySchematyc/Core/Interface"
	"${CRYENGINE_DIR}/Code/CryPlugins/CryDefaultEntities/Module"
)

# Set StartUp project in Visual Studio

add_library(GameLauncher STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
set_target_properties(GameLauncher PROPERTIES LINKER_LANGUAGE CXX)
if (WIN32)
    set_visual_studio_debugger_command(GameLauncher "${CRYENGINE_DIR}/bin/win_x64/GameLauncher.exe" "-project \"E:/Code/GameAPI/GameAPI.cryproject\"")
endif()

add_library(Sandbox STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
set_target_properties(Sandbox PROPERTIES LINKER_LANGUAGE CXX)
if (WIN32)
    set_visual_studio_debugger_command(Sandbox "${CRYENGINE_DIR}/bin/win_x64/Sandbox.exe" "-project \"E:/Code/GameAPI/GameAPI.cryproject\"")
endif()

add_library(GameServer STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
set_target_properties(GameServer PROPERTIES LINKER_LANGUAGE CXX)
if (WIN32)
    set_visual_studio_debugger_command(GameServer "${CRYENGINE_DIR}/bin/win_x64/Game_Server.exe" "-project \"E:/Code/GameAPI/GameAPI.cryproject\"")
endif()

set_solution_startup_target(GameLauncher)

if (WIN32)
    set_visual_studio_debugger_command( ${THIS_PROJECT} "${CRYENGINE_DIR}/bin/win_x64/GameLauncher.exe" "-project \"E:/Code/GameAPI/GameAPI.cryproject\"" )
endif()

#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
#END-CUSTOM