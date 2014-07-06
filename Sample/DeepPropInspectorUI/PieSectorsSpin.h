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
//----- PieSectorsSpin.h : Declaration of the CPieSectorsSpin
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"

#include "DeepPropInspectorUI.h"
#include "DynPropBase.h"
#include "../DeepPropInspector/AsdkPie.h"

//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CPieSectorsSpin : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPieSectorsSpin, &CLSID_PieSectorsSpin>,
	public ISupportErrorInfo,
	public IDispatchImpl<IPieSectorsSpin, &IID_IPieSectorsSpin, &LIBID_AsdkDeepPropInspectorUILib, 1, 0>,
	public DynPropBaseImpl<CPieSectorsSpin>
{
protected:
	IDynamicPropertyNotify2 *m_pNotify ;
	CComVariant mSset ;
	UINT mnCounter ;

public:
	CPieSectorsSpin () : mnCounter(0) {}

	static IPieSectorsSpin *GetCounterSpin (bool bAddRef =true) ;
	static ULONG GetCounterSpinPosition () ;

	DECLARE_REGISTRY_RESOURCEID(IDR_PIESECTORSSPIN)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CPieSectorsSpin)
		COM_INTERFACE_ENTRY(IPieSectorsSpin)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(ICategorizeProperties)
		COM_INTERFACE_ENTRY(IAcPiPropertyDisplay)
		COM_INTERFACE_ENTRY(IDynamicProperty2)
	END_COM_MAP()

	BEGIN_PERPROPDISPLAY_MAP()
		PROP_DISP_ENTRY(0, _T("DeepPropInspectorUI.AsdkSpinner.1"), NULL, NULL, NULL, NULL, RGB(0, 0, 0), false, 1, 0)
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
	STDMETHOD(IsPropertyEnabled) (IUnknown *pUnk, BOOL *pbEnabled) ;
	STDMETHOD(IsPropertyReadOnly) (BOOL *pbReadonly) ;
	STDMETHOD(GetDescription) (BSTR *bstrName) ;
	STDMETHOD(GetCurrentValueName) (BSTR *pbstrName) ;
	STDMETHOD(GetCurrentValueType) (VARTYPE* pVarType) ;
	STDMETHOD(GetCurrentValueData) (IUnknown *pUnk, VARIANT *pvarData) ;
	STDMETHOD(SetCurrentValueData) (IUnknown *pUnk, const VARIANT varData) ;
	STDMETHOD(Connect) (IDynamicPropertyNotify2 *pSink) ;
	STDMETHOD(Disconnect) () ;

	//- IPerPropertyDisplay
	STDMETHOD(GetCustomPropertyCtrl) (VARIANT varId, LCID lcid, BSTR *pProgId) ;

	//- IPieSectorsSpin
	STDMETHOD(get_Counter) (ULONG *pVal) ;

} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(PieSectorsSpin), CPieSectorsSpin)
//- See DynPropOrder.h for details
//OPM_DYNPROP_OBJECT_ENTRY_AUTO(CPieSectorsSpin, AsdkPie)
#include "DynPropOrder.h"
