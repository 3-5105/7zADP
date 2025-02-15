// ShellExt.cpp: implementation of the CShellExt class.
//
//////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <tchar.h>
#include <shlobj.h>

#include "ShellExt.h"
#include "Guid.h"
#include "7zADP.h"


LPCWSTR szText = L"分别压缩为7z压缩包";



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CShellExt::CShellExt()
{
	m_ObjRefCount = 1;
	m_pFiles = NULL;
	m_nFiles = 0;
}

CShellExt::~CShellExt()
{
	if (m_pFiles)
	{
		delete[] m_pFiles;
		m_pFiles = NULL;
	}
	m_nFiles = 0;
}

STDMETHODIMP_(DWORD) CShellExt::Release(void)
{
	if (--m_ObjRefCount == 0)
	{
		delete this;
		return 0;
	}

	return m_ObjRefCount;
}

STDMETHODIMP_(DWORD) CShellExt::AddRef(void)
{
	return ++m_ObjRefCount;
}

STDMETHODIMP CShellExt::QueryInterface(REFIID riid, LPVOID* ppReturn)
{
	*ppReturn = NULL;

	if (IsEqualIID(riid, IID_IUnknown))
		*ppReturn = this;
	else if (IsEqualIID(riid, IID_IClassFactory))
		*ppReturn = (IClassFactory*)this;
	else if (IsEqualIID(riid, IID_IShellExtInit))
		*ppReturn = (IShellExtInit*)this;
	else if (IsEqualIID(riid, IID_IContextMenu))
		*ppReturn = (IContextMenu*)this;


	if (*ppReturn)
	{
		LPUNKNOWN pUnk = (LPUNKNOWN)(*ppReturn);
		pUnk->AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP CShellExt::Initialize(
	LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID)
{
	// 如果没有数据对象，说明是在空白区域点击
	if (pDataObj == NULL)
	{
		// 清理之前的数据
		if (m_pFiles)
		{
			delete[] m_pFiles;
			m_pFiles = NULL;
		}
		m_nFiles = 0;
		return S_OK;
	}

	FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg = { TYMED_HGLOBAL };
	HDROP     hDrop;

	// Look for CF_HDROP data in the data object.
	if (FAILED(pDataObj->GetData(&fmt, &stg)))
	{
		return S_OK;
	}

	// 清理之前的数据
	if (m_pFiles)
	{
		delete[] m_pFiles;
		m_pFiles = NULL;
	}
	m_nFiles = 0;

	// Get a pointer to the actual data.
	hDrop = (HDROP)GlobalLock(stg.hGlobal);

	// Make sure it worked.
	if (NULL == hDrop)
	{
		ReleaseStgMedium(&stg);
		return S_OK;
	}

	// Get the number of files selected
	m_nFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);

	if (0 == m_nFiles)
	{
		GlobalUnlock(stg.hGlobal);
		ReleaseStgMedium(&stg);
		return S_OK;
	}

	// Allocate memory for file paths
	m_pFiles = new WCHAR[m_nFiles][MAX_PATH];

	// Get all file names
	for (UINT i = 0; i < m_nFiles; i++)
	{
		if (0 == DragQueryFileW(hDrop, i, m_pFiles[i], MAX_PATH))
		{
			delete[] m_pFiles;
			m_pFiles = NULL;
			m_nFiles = 0;
			GlobalUnlock(stg.hGlobal);
			ReleaseStgMedium(&stg);
			return S_OK;
		}
	}

	GlobalUnlock(stg.hGlobal);
	ReleaseStgMedium(&stg);

	return S_OK;
}

STDMETHODIMP CShellExt::QueryContextMenu(
	HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,
	UINT uidLastCmd, UINT uFlags)
{
	// 如果是默认菜单或没有选中文件，不显示菜单项
	if ((uFlags & CMF_DEFAULTONLY) || m_nFiles == 0)
		return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0);

	InsertMenuW(hmenu, uMenuIndex, MF_BYPOSITION, uidFirstCmd, szText);

	return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 1);
}

STDMETHODIMP CShellExt::GetCommandString(
	UINT_PTR idCmd, UINT uFlags, UINT* pwReserved, LPSTR pszName, UINT cchMax)
{
	if (0 != idCmd)
		return E_INVALIDARG;

	if (uFlags & GCS_HELPTEXT)
	{
		

		if (uFlags & GCS_UNICODE)
		{
			lstrcpynW((LPWSTR)pszName, szText, cchMax);
		}
		else
		{
			WideCharToMultiByte(CP_ACP, 0, szText, -1,
				pszName, cchMax, NULL, NULL);
		}
		return S_OK;
	}
	return E_INVALIDARG;
}

STDMETHODIMP CShellExt::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
	if (0 != HIWORD(pCmdInfo->lpVerb))
		return E_INVALIDARG;

	switch (LOWORD(pCmdInfo->lpVerb))
	{
	case 0:
	{
		// 获取DLL路径
		WCHAR szDllPath[MAX_PATH];
		GetModuleFileNameW(g_hInst, szDllPath, MAX_PATH);

		// 获取DLL所在目录
		WCHAR szDllDir[MAX_PATH];
		lstrcpyW(szDllDir, szDllPath);
		WCHAR* pLastSlash = wcsrchr(szDllDir, L'\\');
		if (pLastSlash)
			*(pLastSlash + 1) = L'\0';

		// 读取config.ini
		WCHAR sz7zPath[MAX_PATH];
		WCHAR szConfigPath[MAX_PATH];
		WCHAR szExtraParams[MAX_PATH];  // 新增：用于存储附加参数
		lstrcpyW(szConfigPath, szDllDir);
		lstrcatW(szConfigPath, L"config.ini");

		// 读取7z路径和附加参数
		GetPrivateProfileStringW(L"Settings", L"7zPath", L"",
			sz7zPath, MAX_PATH, szConfigPath);
		GetPrivateProfileStringW(L"Settings", L"ExtraParams", L"",  // 新增：读取附加参数
			szExtraParams, MAX_PATH, szConfigPath);

		// 如果没有找到7z路径，使用默认路径
		if (lstrlenW(sz7zPath) == 0)
		{
			lstrcpyW(sz7zPath, L"C:\\Program Files\\7-Zip\\7z.exe");
		}

		// 检查7z.exe是否存在
		if (GetFileAttributesW(sz7zPath) == INVALID_FILE_ATTRIBUTES)
		{
			MessageBoxW(pCmdInfo->hwnd,
				L"未找到7z.exe，请在config.ini中配置正确的路径",
				L"错误", MB_ICONERROR);
			return E_FAIL;
		}

		// 为每个文件执行压缩
		for (UINT i = 0; i < m_nFiles; i++)
		{
			WCHAR szCmdLine[MAX_PATH * 3];
			WCHAR szZipPath[MAX_PATH];

			// 构造目标zip文件路径
			lstrcpyW(szZipPath, (WCHAR*)m_pFiles[i]);
			lstrcatW(szZipPath, L".7z");

			// 构造命令行，加入附加参数
			if (lstrlenW(szExtraParams) > 0)
			{
				// 如果有附加参数，将其加入命令行
				wsprintfW(szCmdLine, L"\"%s\" a %s \"%s\" \"%s\"",
					sz7zPath, szExtraParams, szZipPath, m_pFiles[i]);
			}
			else
			{
				// 没有附加参数时使用原来的命令行
				wsprintfW(szCmdLine, L"\"%s\" a \"%s\" \"%s\"",
					sz7zPath, szZipPath, m_pFiles[i]);
			}

			// 设置启动信息以隐藏窗口
			STARTUPINFOW si = { sizeof(si) };
			si.dwFlags = STARTF_USESHOWWINDOW;
			si.wShowWindow = SW_HIDE;
			
			PROCESS_INFORMATION pi;
			if (CreateProcessW(NULL, szCmdLine, NULL, NULL, FALSE,
				CREATE_NO_WINDOW,
				NULL, NULL, &si, &pi))
			{
				// 等待压缩完成
				WaitForSingleObject(pi.hProcess, INFINITE);
				CloseHandle(pi.hProcess);
				CloseHandle(pi.hThread);
			}
		}
		return S_OK;
	}
	break;

	default:
		return E_INVALIDARG;
	}
}