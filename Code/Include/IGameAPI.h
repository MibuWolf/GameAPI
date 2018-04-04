// ----------------------------------------------------------------------------
// Desc    : IGameAPI �����ܽӿ�
// History : 
// Date    : 03/26/2018		Sam
// Copyright (C) 2018 - All Rights Reserved
// ----------------------------------------------------------------------------

#pragma once
#include "IMiscellaneous.h"
#include "Actor\IActorManager.h"

class IGameAPI
{
	SINGLETON_IMPLEMENT(IGameAPI);

public:

	~IGameAPI();

public:

	// ��ʼ��
	bool				Initialize();


	// ��ȡActionManager������
	IActorManager*		GetActorManager();

public:

	int num = 0;
};

#define				GAME_API		IGameAPI::GetInstance()