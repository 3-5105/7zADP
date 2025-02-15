// 7zADP.cpp: implementation of the C7zADP class.
//
//////////////////////////////////////////////////////////////////////
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <shlobj.h>

#include "7zADP.h"

#include "ClassFactory.h"
#include "Utility.h"

#include <olectl.h>

// data
HINSTANCE   g_hInst;
UINT        g_DllRefCount;

#pragma data_seg(".text")
#define INITGUID
#include <initguid.h>
#include <shlguid.h>
#include "Guid.h"
#pragma data_seg()

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			g_hInst = (HINSTANCE)hModule;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

/*---------------------------------------------------------------*/
// DllCanUnloadNow()
/*---------------------------------------------------------------*/
STDAPI DllCanUnloadNow( VOID )
{
	return (g_DllRefCount ? S_FALSE : S_OK);
}


/*---------------------------------------------------------------*/
// DllGetClassObject()
/*---------------------------------------------------------------*/
STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, LPVOID *ppReturn )
{
	*ppReturn = NULL;

	// do we support the CLSID?
	if( !IsEqualCLSID(rclsid, CLSID_7zADP) )
	   return CLASS_E_CLASSNOTAVAILABLE;
   
	// call the factory
	CClassFactory *pClassFactory = new CClassFactory();
	if( pClassFactory==NULL )
	   return E_OUTOFMEMORY;
   
	// query interface for the a pointer
	HRESULT hResult = pClassFactory->QueryInterface(riid, ppReturn);
	pClassFactory->Release();
	return hResult;
}


/*---------------------------------------------------------------*/
// DllGetRegisterServer()
/*---------------------------------------------------------------*/

typedef struct{
   HKEY  hRootKey;
   LPTSTR lpszSubKey;
   LPTSTR lpszValueName;
   LPTSTR lpszData;
}REGSTRUCT, *LPREGSTRUCT;

STDAPI DllRegisterServer( VOID )
{
	INT i;
	HKEY hKey;
	LRESULT lResult;
	DWORD dwDisp;
	WCHAR szSubKey[MAX_PATH];
	WCHAR szCLSID[MAX_PATH];
	WCHAR szModule[MAX_PATH];
	LPWSTR pwsz;

	// get the CLSID in string form
	StringFromIID(CLSID_7zADP, &pwsz);

	if (pwsz)
	{
		// 直接复制宽字符串
		lstrcpynW(szCLSID, pwsz, MAX_PATH);

		LPMALLOC pMalloc;
		CoGetMalloc(1, &pMalloc);
		if (pMalloc)
		{
			pMalloc->Free(pwsz);
			pMalloc->Release();
		}
	}

	// get this DLL's path and file name
	GetModuleFileNameW(g_hInst, szModule, MAX_PATH);

	// CLSID entries - 使用宽字符串字面量
	struct {
		HKEY  hRootKey;
		LPCWSTR lpszSubKey;
		LPCWSTR lpszValueName;
		LPCWSTR lpszData;
	} ClsidEntries[] = {
		HKEY_CLASSES_ROOT, L"CLSID\\%s",                  NULL,                   L"7zADP",
		HKEY_CLASSES_ROOT, L"CLSID\\%s",                  L"InfoTip",            L"7zADP.",
		HKEY_CLASSES_ROOT, L"CLSID\\%s\\InprocServer32",  NULL,                  L"%s",
		HKEY_CLASSES_ROOT, L"CLSID\\%s\\InprocServer32",  L"ThreadingModel",     L"Apartment",
		HKEY_CLASSES_ROOT, L"CLSID\\%s\\DefaultIcon",     NULL,                  L"%s,0",
		NULL,             NULL,                           NULL,                   NULL
	};

	for (i = 0; ClsidEntries[i].hRootKey; i++)
	{
		// create the sub key string
		wsprintfW(szSubKey, ClsidEntries[i].lpszSubKey, szCLSID);
		lResult = RegCreateKeyExW(ClsidEntries[i].hRootKey,
			szSubKey,
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_WRITE,
			NULL,
			&hKey,
			&dwDisp);

		if (lResult == NOERROR)
		{
			WCHAR szData[MAX_PATH];
			wsprintfW(szData, ClsidEntries[i].lpszData, szModule);
			lResult = RegSetValueExW(hKey,
				ClsidEntries[i].lpszValueName,
				0,
				REG_SZ,
				(LPBYTE)szData,
				(lstrlenW(szData) + 1) * sizeof(WCHAR));

			RegCloseKey(hKey);
		}
		else
			return SELFREG_E_CLASS;
	}

	// 为所有文件和文件夹注册右键菜单
	struct {
		LPCWSTR lpszSubKey;
	} MenuEntries[] = {
		L"*\\ShellEx\\ContextMenuHandlers\\7zADP",        // 所有文件
		L"Directory\\ShellEx\\ContextMenuHandlers\\7zADP", // 文件夹
		L"Folder\\ShellEx\\ContextMenuHandlers\\7zADP",    // 文件夹
		L"Directory\\Background\\ShellEx\\ContextMenuHandlers\\7zADP", // 文件夹背景
		NULL
	};

	// 注册所有菜单项
	for (int i = 0; MenuEntries[i].lpszSubKey != NULL; i++)
	{
		lstrcpyW(szSubKey, MenuEntries[i].lpszSubKey);
		lResult = RegCreateKeyExW(HKEY_CLASSES_ROOT,
			szSubKey,
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_WRITE,
			NULL,
			&hKey,
			&dwDisp);

		if (lResult == NOERROR)
		{
			WCHAR szData[MAX_PATH];
			lstrcpyW(szData, szCLSID);
			lResult = RegSetValueExW(hKey,
				NULL,
				0,
				REG_SZ,
				(LPBYTE)szData,
				(lstrlenW(szData) + 1) * sizeof(WCHAR));

			RegCloseKey(hKey);
		}
		else
			return SELFREG_E_CLASS;
	}

	// register the extension as approved by NT
	OSVERSIONINFO  osvi;
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	GetVersionEx(&osvi);

	if (VER_PLATFORM_WIN32_NT == osvi.dwPlatformId)
	{
		lstrcpyW(szSubKey, L"Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved");
		lResult = RegCreateKeyExW(HKEY_LOCAL_MACHINE,
			szSubKey,
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_WRITE,
			NULL,
			&hKey,
			&dwDisp);

		if (lResult == NOERROR)
		{
			WCHAR szData[MAX_PATH];
			lstrcpyW(szData, L"7zADP");
			lResult = RegSetValueExW(hKey,
				szCLSID,
				0,
				REG_SZ,
				(LPBYTE)szData,
				(lstrlenW(szData) + 1) * sizeof(WCHAR));

			RegCloseKey(hKey);
		}
		else
			return SELFREG_E_CLASS;
	}

	return S_OK;
}

/*---------------------------------------------------------------*/
// DllUnregisterServer()
/*---------------------------------------------------------------*/
STDAPI DllUnregisterServer(VOID)
{
    INT i;
    LRESULT lResult;
    WCHAR szSubKey[MAX_PATH];
    WCHAR szCLSID[MAX_PATH];
    WCHAR szModule[MAX_PATH];
    LPWSTR pwsz;

    // get the CLSID in string form
    StringFromIID(CLSID_7zADP, &pwsz);

    if (pwsz)
    {
        // 直接复制宽字符串
        lstrcpynW(szCLSID, pwsz, MAX_PATH);
        
        LPMALLOC pMalloc;
        CoGetMalloc(1, &pMalloc);
        if (pMalloc)
        {
            pMalloc->Free(pwsz);
            pMalloc->Release();
        }
    }

    // get this DLL's path and file name
    GetModuleFileNameW(g_hInst, szModule, MAX_PATH);

    // CLSID entries - 使用宽字符串字面量
    struct {
        HKEY  hRootKey;
        LPCWSTR lpszSubKey;
        LPCWSTR lpszValueName;
        LPCWSTR lpszData;
    } ClsidEntries[] = {
        HKEY_CLASSES_ROOT, L"CLSID\\%s",                  NULL,                   L"7zADP",
        HKEY_CLASSES_ROOT, L"CLSID\\%s",                  L"InfoTip",            L"7zADP.",
        HKEY_CLASSES_ROOT, L"CLSID\\%s\\InprocServer32",  NULL,                  L"%s",
        HKEY_CLASSES_ROOT, L"CLSID\\%s\\InprocServer32",  L"ThreadingModel",     L"Apartment",
        HKEY_CLASSES_ROOT, L"CLSID\\%s\\DefaultIcon",     NULL,                  L"%s,0",
        NULL,             NULL,                           NULL,                   NULL
    };

    for (i = 0; ClsidEntries[i].hRootKey; i++)
    {
        // create the sub key string
        wsprintfW(szSubKey, ClsidEntries[i].lpszSubKey, szCLSID);
        lResult = RegDeleteKeyW(ClsidEntries[i].hRootKey, szSubKey);
    }

    // 删除所有菜单注册项
    struct {
        LPCWSTR lpszSubKey;
    } MenuEntries[] = {
        L"*\\ShellEx\\ContextMenuHandlers\\7zADP",
        L"Directory\\ShellEx\\ContextMenuHandlers\\7zADP",
        L"Folder\\ShellEx\\ContextMenuHandlers\\7zADP",
        L"Directory\\Background\\ShellEx\\ContextMenuHandlers\\7zADP",
        NULL
    };

    // 删除所有菜单项
    for (int i = 0; MenuEntries[i].lpszSubKey != NULL; i++)
    {
        lstrcpyW(szSubKey, MenuEntries[i].lpszSubKey);
        RegDeleteKeyW(HKEY_CLASSES_ROOT, szSubKey);
    }

    // register the extension as approved by NT
    OSVERSIONINFO  osvi;
    osvi.dwOSVersionInfoSize = sizeof(osvi);
    GetVersionEx(&osvi);

    if (VER_PLATFORM_WIN32_NT == osvi.dwPlatformId)
    {
        lstrcpyW(szSubKey, L"Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved");
        lResult = RegDeleteKeyW(HKEY_LOCAL_MACHINE, szSubKey);
    }

    return S_OK;
}