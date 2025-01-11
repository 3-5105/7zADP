// ClassFactory.cpp: implementation of the CClassFactory class.
//
//////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <shlobj.h>

#include "ClassFactory.h"

#include "ShellExt.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClassFactory::CClassFactory()
{
	m_ObjRefCount = 1;
	g_DllRefCount++;
}

CClassFactory::~CClassFactory()
{
	g_DllRefCount--;
}

STDMETHODIMP CClassFactory::QueryInterface( REFIID riid, LPVOID *ppReturn )
{
	*ppReturn = NULL;

	if( IsEqualIID(riid, IID_IUnknown) )
		*ppReturn = this;
	else 
		if( IsEqualIID(riid, IID_IClassFactory) )
			*ppReturn = (IClassFactory*)this;


	if( *ppReturn )
	{
		LPUNKNOWN pUnk = (LPUNKNOWN)(*ppReturn);
		pUnk->AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP_(DWORD) CClassFactory::AddRef()
{
	return ++m_ObjRefCount;
}

STDMETHODIMP_(DWORD) CClassFactory::Release()
{
	if(--m_ObjRefCount == 0)
	{
		delete this;
		return 0;
	}

	return m_ObjRefCount;
}

STDMETHODIMP CClassFactory::CreateInstance( LPUNKNOWN pUnknown, REFIID riid, LPVOID *ppObject )
{
	*ppObject = NULL;
	if( pUnknown != NULL )
		return CLASS_E_NOAGGREGATION;

	// creates the namespace's main class
	CShellExt *pShellExt = new CShellExt();
	if( NULL==pShellExt ) 
		return E_OUTOFMEMORY;

	// query interface for the return value
	HRESULT hResult = pShellExt->QueryInterface(riid, ppObject);
	pShellExt->Release();
	return hResult;
}
