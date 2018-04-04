#pragma once
struct ToCSharp
{
	static void StartTheDotNetRuntime(wchar_t* runtimeVersion, wchar_t* dllPath, wchar_t* startClass, wchar_t* startMethod, wchar_t* startArgument);

	static void DestoryTheDotNetRuntime(wchar_t* runtimeVersion, wchar_t* dllPath, wchar_t* startClass, wchar_t* startMethod, wchar_t* startArgument);

};

