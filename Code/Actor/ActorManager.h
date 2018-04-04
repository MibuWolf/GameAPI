// ----------------------------------------------------------------------------
// Desc    : ActorManager ActorManager�ӿ�
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

	// �������
	virtual	unsigned int					AddMainRole(const char* charaterName);

	// ��ȡ����
	unsigned int							GetMainRole();

	// ��Actor�������
	virtual	bool							AttachObject(unsigned int uID, const char* pAttachName, const char* pObjectPath);

	// ��Actor�������
	virtual	bool							AttachObjectByID(unsigned int uID, unsigned int uAttachID);

private:

	// ����һ���յ�ʵ��
	IEntity*								CreateEntity();

	// ��Ϸ����ID
	unsigned int							m_mainRole;
};
