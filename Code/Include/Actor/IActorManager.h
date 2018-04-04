// ----------------------------------------------------------------------------
// Desc    : IActorManager ActorManager�ӿ�
// History : 
// Date    : 03/26/2018		Sam
// Copyright (C) 2018 - All Rights Reserved
// ----------------------------------------------------------------------------
#pragma once
#include "../IMiscellaneous.h"


class IActorManager
{
public:

	/**
	@breif		�������

	@param		[Int]
	charaterName ��ɫcharater����

	@param		[OUT]
	uint32		����ID
	*/
	virtual	unsigned int						AddMainRole(const char* charaterName) PURE;


	/**
	@breif		��ȡ����

	@param		[OUT]
	uint32		����ID
	*/
	virtual	unsigned int						GetMainRole() PURE;


	/**
	@breif		��Actor�������

	@param		[In]
	uID			Actor����ID

	@param		[In]
	pAttachName	���ص�

	@param		[In]
	pObjectPath	��������Դ·��
	*/
	virtual	bool							AttachObject(unsigned int uID, const char* pAttachName, const char* pObjectPath) PURE;


	/**
	@breif		��Actor�������

	@param		[In]
	uID			Actor����ID

	@param		[In]
	uAttachID	������ID
	*/
	virtual	bool							AttachObjectByID(unsigned int uID, unsigned int uAttachID) PURE;

};