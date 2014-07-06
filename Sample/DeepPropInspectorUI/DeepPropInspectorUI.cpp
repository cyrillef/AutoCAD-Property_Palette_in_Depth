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
//----- DeepPropInspectorUI.cpp : Initialization functions
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "resource.h"

#include <initguid.h>
#include "DeepPropInspectorUI.h"
#include <afxdllx.h>
#include "DeepPropInspectorUI_i.c"
#include "acadi_i.c"
#include "acpi_i.c" //- Include once

//-----------------------------------------------------------------------------
class CDeepPropInspectorUIModule : public CAtlDllModuleT<CDeepPropInspectorUIModule> {

public :
	DECLARE_LIBID(LIBID_AsdkDeepPropInspectorUILib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DEEPPROPINSPECTORUI, "{25CD408A-6A08-48A9-B2D2-025AE07879FB}")
} ;

CDeepPropInspectorUIModule _AtlModule ;

//-----------------------------------------------------------------------------
//----- Define the sole extension module object.
AC_IMPLEMENT_EXTENSION_MODULE(DeepPropInspectorUIDLL)
//- Please do not remove the 3 following lines. These are here to make .NET MFC Wizards
//- running properly. The object will not compile but is require by .NET to recognize
//- this project as being an MFC project
#ifdef NEVER
AFX_EXTENSION_MODULE DeepPropInspectorUIExtDLL ={ NULL, NULL } ;
#endif

//----- Now you can use the CAcModuleResourceOverride class in
//----- your application to switch to the correct resource instance.
//----- Please see the ObjectARX Documentation for more details

//-----------------------------------------------------------------------------
//----- DLL Entry Point
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	//----- Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved) ;

	if ( dwReason == DLL_PROCESS_ATTACH ) {
        _hdllInstance =hInstance ;
		DeepPropInspectorUIDLL.AttachInstance (hInstance) ;
		InitAcUiDLL () ;
	} else if ( dwReason == DLL_PROCESS_DETACH ) {
		DeepPropInspectorUIDLL.DetachInstance () ;
#ifdef _DEBUG
		//- Since ATL was compiled with _DEBUG undefined the following line
		//- was never called. Therefore the default _DEBUg implementation is
		//- not doing its work.

		//- Prevent false memory leak reporting. ~CAtlWinModule may be too late.
		_AtlWinModule.Term () ;
#endif
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

