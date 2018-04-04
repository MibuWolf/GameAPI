#include "ToCSharp.h"
#include <metahost.h>
#include <assert.h>

#pragma comment(lib, "mscoree.lib")

static 	ICLRMetaHost *pMetaHost = NULL;
static ICLRMetaHostPolicy *pMetaHostPolicy = NULL;
static ICLRDebugging *pCLRDebugging = NULL;
static ICLRRuntimeHost * pRuntimeHost = NULL;
static 	ICLRRuntimeInfo *pRuntimeInfo = NULL;

void ToCSharp::StartTheDotNetRuntime(wchar_t* runtimeVersion, wchar_t* dllPath, wchar_t* startClass, wchar_t* startMethod, wchar_t* startArgument)
{
	CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pMetaHost);
	CLRCreateInstance(CLSID_CLRMetaHostPolicy, IID_ICLRMetaHostPolicy, (LPVOID*)&pMetaHostPolicy);
	CLRCreateInstance(CLSID_CLRDebugging, IID_ICLRDebugging, (LPVOID*)&pCLRDebugging);

	DWORD dwVersion = 0;
	DWORD dwImageVersion = 0;

	HRESULT result;
	result = pMetaHost->GetRuntime(runtimeVersion, IID_ICLRRuntimeInfo, (LPVOID*)&pRuntimeInfo);
	assert(SUCCEEDED(result));


	result = pRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&pRuntimeHost);
	assert(SUCCEEDED(result));

	result = pRuntimeHost->Start();
	assert(SUCCEEDED(result));

	DWORD dwRetCode = 0;
	result = pRuntimeHost->ExecuteInDefaultAppDomain(dllPath, startClass, startMethod, startArgument, &dwRetCode);
	assert(SUCCEEDED(result));

}



void ToCSharp::DestoryTheDotNetRuntime(wchar_t* runtimeVersion, wchar_t* dllPath, wchar_t* startClass, wchar_t* startMethod, wchar_t* startArgument)
{
	CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pMetaHost);
	CLRCreateInstance(CLSID_CLRMetaHostPolicy, IID_ICLRMetaHostPolicy, (LPVOID*)&pMetaHostPolicy);
	CLRCreateInstance(CLSID_CLRDebugging, IID_ICLRDebugging, (LPVOID*)&pCLRDebugging);

	DWORD dwVersion = 0;
	DWORD dwImageVersion = 0;

	HRESULT result;
	result = pMetaHost->GetRuntime(runtimeVersion, IID_ICLRRuntimeInfo, (LPVOID*)&pRuntimeInfo);
	assert(SUCCEEDED(result));


	result = pRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&pRuntimeHost);
	assert(SUCCEEDED(result));

	result = pRuntimeHost->Start();
	assert(SUCCEEDED(result));

	DWORD dwRetCode = 0;
	result = pRuntimeHost->ExecuteInDefaultAppDomain(dllPath, startClass, startMethod, startArgument, &dwRetCode);
	assert(SUCCEEDED(result));

	pRuntimeHost->Stop();
	pRuntimeHost->Release();
	pRuntimeInfo->Release();
	pCLRDebugging->Release();
	pMetaHostPolicy->Release();
	pMetaHost->Release();
}