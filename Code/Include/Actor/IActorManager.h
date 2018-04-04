// ----------------------------------------------------------------------------
// Desc    : IActorManager ActorManager接口
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
	@breif		添加主角

	@param		[Int]
	charaterName 角色charater名称

	@param		[OUT]
	uint32		主角ID
	*/
	virtual	unsigned int						AddMainRole(const char* charaterName) PURE;


	/**
	@breif		获取主角

	@param		[OUT]
	uint32		主角ID
	*/
	virtual	unsigned int						GetMainRole() PURE;


	/**
	@breif		给Actor挂载物件

	@param		[In]
	uID			Actor索引ID

	@param		[In]
	pAttachName	挂载点

	@param		[In]
	pObjectPath	挂载物资源路径
	*/
	virtual	bool							AttachObject(unsigned int uID, const char* pAttachName, const char* pObjectPath) PURE;


	/**
	@breif		给Actor挂载物件

	@param		[In]
	uID			Actor索引ID

	@param		[In]
	uAttachID	挂载物ID
	*/
	virtual	bool							AttachObjectByID(unsigned int uID, unsigned int uAttachID) PURE;

};