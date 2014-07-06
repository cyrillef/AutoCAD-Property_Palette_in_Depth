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
//- AcadPieSectors.h : Declaration of the CAcadPieSectors
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"

#include "DeepPropInspector.h"

//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CAcadPieSectors : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAcadPieSectors, &CLSID_AcadPieSectors>,
	public ISupportErrorInfo,
	public IDispatchImpl<IAcadPieSectors, &IID_IAcadPieSectors, &LIBID_AsdkDeepPropInspectorLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
protected:
	AcAxObjectRef m_objRef ;

public:
	CAcadPieSectors () ;
	virtual ~CAcadPieSectors () ;

	DECLARE_REGISTRY_RESOURCEID(IDR_ACADPIESECTORS)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CAcadPieSectors)
		COM_INTERFACE_ENTRY(IAcadPieSectors)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
	END_COM_MAP()

	//- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	HRESULT FinalConstruct () {
		return (S_OK) ;
	}
	
	void FinalRelease () {
	}

	//- Initialize the enumerator
	STDMETHOD(Init) (AcDbObjectId id, AsdkPie *pPie =NULL) ;
	STDMETHOD(Init) (AcAxObjectRef &objRef) ;

public:
	//- IAcadPieSectors
	STDMETHOD(get_Count) (long *plNumber) ;
	STDMETHOD(get_Item) (VARIANT vIndex, IUnknown **pvItem) ;
	STDMETHOD(get__NewEnum) (IUnknown **ppUnk) ;

	STDMETHOD(AddSimpleSector) (DOUBLE val, IAcadPieSector **ppVal) ;
} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(AcadPieSectors), CAcadPieSectors)
