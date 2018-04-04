// ----------------------------------------------------------------------------
// Desc    : IMiscellaneous 杂项
// History : 
// Date    : 03/26/2018		Sam
// Copyright (C) 2018 - All Rights Reserved
// ----------------------------------------------------------------------------

#pragma once

#define TDCORE_EXPORTS
#ifdef TDCORE_EXPORTS
#define TD_EXPORTS __declspec(dllexport)
#else
#define TD_EXPORTS __declspec(dllimport)
#endif

#define PURE                    = 0
#define EXTENRNC	extern "C"


// 定义单键提供接口的函数
#define		SINGLETON_IMPLEMENT( ClassName )			\
	private:											\
	ClassName();								\
	public:												\
	static ClassName* GetInstance(void)					\
{													\
	static ClassName instance;							\
	return &instance;									\
}