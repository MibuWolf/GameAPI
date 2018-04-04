// ----------------------------------------------------------------------------
// Desc    : ActorManager ActorManager接口
// History : 
// Date    : 03/26/2018		Sam
// Copyright (C) 2018 - All Rights Reserved
// ----------------------------------------------------------------------------

#pragma once
#include "Include\ICryEngine.h"
#include "Include\Actor\IActorManager.h"


class ActorManager : public IActorManager
{
	SINGLETON_IMPLEMENT(ActorManager);

public:

	~ActorManager();

	// 添加主角
	virtual	unsigned int					AddMainRole(const char* charaterName);

	// 获取主角
	unsigned int							GetMainRole();

	// 给Actor挂载物件
	virtual	bool							AttachObject(unsigned int uID, const char* pAttachName, const char* pObjectPath);

	// 给Actor挂载物件
	virtual	bool							AttachObjectByID(unsigned int uID, unsigned int uAttachID);

private:

	// 创建一个空的实体
	IEntity*								CreateEntity();

	// 游戏主角ID
	unsigned int							m_mainRole;
};
