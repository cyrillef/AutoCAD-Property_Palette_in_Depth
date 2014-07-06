// (C) Copyright 2002-2003 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- DeepPropInspector.cpp : Initialization functions
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include <initguid.h>
#include "DeepPropInspector.h"
#include "DeepPropInspector_i.c"
#include "axdb_i.c"
//-----------------------------------------------------------------------------
class CDeepPropInspectorModule : public CAtlDllModuleT<CDeepPropInspectorModule> {

public :
	DECLARE_LIBID(LIBID_AsdkDeepPropInspectorLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DEEPPROPINSPECTOR, "{CFE469DA-2022-4194-8DDA-85A0EF32E9FB}")
} ;

CDeepPropInspectorModule _AtlModule ;

//-----------------------------------------------------------------------------
//----- DLL Entry Point
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	//----- Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved) ;

	if ( dwReason == DLL_PROCESS_ATTACH ) {
        _hdllInstance =hInstance ;
		_AtlBaseModule.SetResourceInstance (hInstance) ;
	} else if ( dwReason == DLL_PROCESS_DETACH ) {
	}
	return (_AtlModule.DllMain (dwReason, lpReserved)) ; 
}

//-----------------------------------------------------------------------------
//----- Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow (void) {
	return ((_AtlModule.GetLockCount () == 0) ? S_OK : S_FALSE) ;
}

//-----------------------------------------------------------------------------
//----- Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
	return (_AtlModule.GetClassObject (rclsid, riid, ppv)) ;
}

//-----------------------------------------------------------------------------
//----- DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer (void) {
	//----- Registers object, typelib and all interfaces in typelib
	return (_AtlModule.RegisterServer (TRUE)) ;
}

//-----------------------------------------------------------------------------
//----- DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer (void) {
	return (_AtlModule.UnregisterServer (TRUE)) ;
}

