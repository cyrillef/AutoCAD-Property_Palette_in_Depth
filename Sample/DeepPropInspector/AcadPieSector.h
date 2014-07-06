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
//- AcadPieSector.h : Declaration of the CAcadPieSector
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"
#include "DeepPropInspector.h"

#include "AsdkPie.h"

//-----------------------------------------------------------------------------
class CAcadPieSector ;
typedef std::map<AsdkPieSector *, CAcadPieSector *> PieSectorMap ;
typedef std::map<AsdkPieSector *, CAcadPieSector *>::iterator PieSectorMapIter ;
extern PieSectorMap pieSectorPointers ;

//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CAcadPieSector : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAcadPieSector, &CLSID_AcadPieSector>,
	public ISupportErrorInfo,
	public IDispatchImpl<IAcadPieSector, &IID_IAcadPieSector, &LIBID_AsdkDeepPropInspectorLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	AcAxObjectRef m_objRef ;
	AsdkPieSector *mpSector ;

public:
	CAcadPieSector () ;
	virtual ~CAcadPieSector () ;

	DECLARE_REGISTRY_RESOURCEID(IDR_ACADPIESECTOR)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CAcadPieSector)
		COM_INTERFACE_ENTRY(IAcadPieSector)
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

	//- Initialize the interface
	STDMETHOD(Init) (AcDbObjectId id, AsdkPie *pPie, AsdkPieSector *pSector) ;
	STDMETHOD(Init) (AcAxObjectRef &objRef, AsdkPieSector *pSector) ;

public:
	//- IAcadPieSector
	STDMETHOD(get_Exploded) (VARIANT_BOOL *pVal) ;
	STDMETHOD(put_Exploded) (VARIANT_BOOL newVal) ;
	STDMETHOD(get_TrueColor) (IAcadAcCmColor **ppColor) ;
	STDMETHOD(put_TrueColor) (IAcadAcCmColor *pColor) ;
	STDMETHOD(get_Color) (enum AcColor *pColor) ;
	STDMETHOD(put_Color) (enum AcColor color) ;
} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(AcadPieSector), CAcadPieSector)
