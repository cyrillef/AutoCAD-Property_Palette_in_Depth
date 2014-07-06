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
//----- PieSectorImage.h : Declaration of the CPieSectorImage
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"

#include "DeepPropInspectorUI.h"
#include "DynPropBase.h"
#include "../DeepPropInspector/AsdkPie.h"

//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CPieSectorImage : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPieSectorImage, &CLSID_PieSectorImage>,
	public ISupportErrorInfo,
	public IDispatchImpl<IPieSectorImage, &IID_IPieSectorImage, &LIBID_AsdkDeepPropInspectorUILib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public DynPropBaseImpl<CPieSectorImage>
{
protected:
	IDynamicPropertyNotify2 *m_pNotify ;

public:
	CPieSectorImage () {}

	DECLARE_REGISTRY_RESOURCEID(IDR_PIESECTORIMAGE)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CPieSectorImage)
		COM_INTERFACE_ENTRY(IPieSectorImage)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(ICategorizeProperties)
		COM_INTERFACE_ENTRY(IAcPiPropertyDisplay)
		COM_INTERFACE_ENTRY(IDynamicProperty2)
	END_COM_MAP()

	BEGIN_PERPROPDISPLAY_MAP()
		PROP_DISP_ENTRY(0, _T("DeepPropInspectorUI.AsdkSpinner.1"), NULL, IDB_I_BMP, NULL, IDB_E_BMP, RGB(0, 0, 0), true, 4, 0)
	END_PERPROPDISPLAY_MAP()

	//- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo) (REFIID riid) ;

	HRESULT FinalConstruct () {
		return (S_OK) ;
	}
	
	void FinalRelease () {
	}

public:
	//- IDynamicProperty2
	STDMETHOD(GetGUID) (GUID *propGUID) ;
	STDMETHOD(GetDisplayName) (BSTR *bstrName) ;
	STDMETHOD(IsPropertyEnabled)(IUnknown *pUnk, BOOL *pbEnabled) ;
	STDMETHOD(IsPropertyReadOnly) (BOOL *pbReadonly) ;
	STDMETHOD(GetDescription) (BSTR *bstrName) ;
	STDMETHOD(GetCurrentValueName) (BSTR *pbstrName) ;
	STDMETHOD(GetCurrentValueType) (VARTYPE *pVarType) ;
	STDMETHOD(GetCurrentValueData) (IUnknown *pUnk, VARIANT *pvarData) ;
	STDMETHOD(SetCurrentValueData) (IUnknown *pUnk, const VARIANT varData) ;
	STDMETHOD(Connect) (IDynamicPropertyNotify2 *pSink) ;
	STDMETHOD(Disconnect) () ;

	//- IPerPropertyDisplay
	STDMETHOD(GetCustomPropertyCtrl) (VARIANT varId, LCID lcid, BSTR *pProgId) ;

	//- IPieSectorImage

} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(PieSectorImage), CPieSectorImage)
//- See DynPropOrder.h for details
//OPM_DYNPROP_OBJECT_ENTRY_AUTO(CPieSectorImage, AsdkPie)
#include "DynPropOrder.h"
