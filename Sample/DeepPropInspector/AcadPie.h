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
//----- AcadPie.h : Declaration of the CAcadPie
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#include "resource.h"
#include "DeepPropInspector.h"
#include "IAcadCircleImpl.h"
#include <tchar.h>

//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CAcadPie : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAcadPie, &CLSID_AcadPie>,
	public ISupportErrorInfo,
	public IAcadCircleImpl<CAcadPie, AsdkPie, IAcadPie, &CLSID_AcadPie>
{
public:

	CAcadPie () {
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_ACADPIE)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CAcadPie)
		COM_INTERFACE_ENTRY(IAcadPie)
		COM_INTERFACE_ENTRY(IAcadCircle)
		COM_INTERFACE_ENTRY(IAcadEntity)
		COM_INTERFACE_ENTRY(IAcadObject)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IAcadBaseObject)
		COM_INTERFACE_ENTRY(IAcadBaseObject2)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IRetrieveApplication)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IOPMPropertyExtension)
		COM_INTERFACE_ENTRY(IOPMPropertyExpander)
		COM_INTERFACE_ENTRY(IAcPiCategorizeProperties)
		COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
	END_COM_MAP()

	//- IOPMPropertyExtension
	BEGIN_OPMPROP_MAP()
		//OPMPROP_ENTRY(0, 100, 1, IDS_CATEGORY_PIE, 0, 0, "", 0, 1, IID_NULL, IID_NULL, "") //- Title
		//OPMPROP_ENTRY(0, 101, 1, IDS_CATEGORY_PIE, 0, 0, "", 0, 1, IID_NULL, IID_NULL, "") //- AllExploded
		//OPMPROP_ENTRY(0, 102, 1, IDS_CATEGORY_PIE, 0, 0, "", 0, 1, IID_NULL, IID_NULL, "") //- Clockwise
		//OPMPROP_ENTRY(0, 103, 1, IDS_CATEGORY_PIE, 0, 0, "", 0, 1, IID_NULL, IID_NULL, "") //- Sectors
		OPMPROP_CAT_ENTRY(0, 100, 1, IDS_CATEGORY_PIE)//- Title
		OPMPROP_CAT_ENTRY(0, 101, 1, IDS_CATEGORY_PIE)//- AllExploded
		OPMPROP_CAT_ENTRY(0, 102, 1, IDS_CATEGORY_PIE)//- Clockwise
		OPMPROP_CAT_ENTRY(0, 103, 1, IDS_CATEGORY_PIE)//- Sectors
	END_OPMPROP_MAP()

	//- IAcPiCategorizeProperties
	BEGIN_CATCMDBTN_MAP()
	END_CATCMDBTN_MAP()

	BEGIN_CAT_MAP()
	END_CAT_MAP()

	//- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo) (REFIID riid) ;

	HRESULT FinalConstruct () {
		return (S_OK) ;
	}
	
	void FinalRelease () {
	}

	//- IOPMPropertyExtensionImpl
	virtual HINSTANCE GetResourceInstance () { return (_AtlBaseModule.GetResourceInstance ()) ; }

	//- IOPMPropertyExtension
	STDMETHOD(ShowProperty) (DISPID dispID, BOOL *pShow) ;

public:
	//- IAcadPie
	STDMETHOD(get_Title) (BSTR *pVal) ;
	STDMETHOD(put_Title) (BSTR newVal) ;
	STDMETHOD(get_AllExploded) (VARIANT_BOOL *pVal) ;
	STDMETHOD(put_AllExploded) (VARIANT_BOOL newVal) ;
	STDMETHOD(get_Clockwise) (VARIANT_BOOL *pVal) ;
	STDMETHOD(put_Clockwise) (VARIANT_BOOL newVal) ;
	STDMETHOD(get_Sectors) (IAcadPieSectors **ppVal) ;
} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(AcadPie), CAcadPie)
