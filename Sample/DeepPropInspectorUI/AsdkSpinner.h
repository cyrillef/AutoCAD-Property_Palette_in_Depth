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
//- AsdkSpinner.h : Declaration of the CAsdkSpinner
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"

#include "DeepPropInspectorUI.h"
#include "ProxyIAcPi.h"
#include "AsdkSpinnerEvents_CP.h"

#define OPM_MARGIN 2
#define DISPID_SECTORS 103
#define DISPID_COUNT 1

//-----------------------------------------------------------------------------
#ifndef IDC_EDITCTL
#define IDC_EDITCTL 200
#endif
#ifndef IDC_SPINCTL
#define IDC_SPINCTL 201
#endif

//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CAsdkSpinner : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CAsdkSpinner, IAsdkSpinner>,
	public IPersistStreamInitImpl<CAsdkSpinner>,
	public IOleControlImpl<CAsdkSpinner>,
	public IOleObjectImpl<CAsdkSpinner>,
	public IOleInPlaceActiveObjectImpl<CAsdkSpinner>,
	public IViewObjectExImpl<CAsdkSpinner>,
	public IOleInPlaceObjectWindowlessImpl<CAsdkSpinner>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CAsdkSpinner>,
	public CProxy_IAsdkSpinnerEvents<CAsdkSpinner>, 
	public IObjectWithSiteImpl<CAsdkSpinner>,
	public IServiceProviderImpl<CAsdkSpinner>,
	public IPersistStorageImpl<CAsdkSpinner>,
	public ISpecifyPropertyPagesImpl<CAsdkSpinner>,
	public IQuickActivateImpl<CAsdkSpinner>,
	public IDataObjectImpl<CAsdkSpinner>,
	public IProvideClassInfo2Impl<&CLSID_AsdkSpinner, &__uuidof(_IAsdkSpinnerEvents), &LIBID_AsdkDeepPropInspectorUILib>,
	public CComCoClass<CAsdkSpinner, &CLSID_AsdkSpinner>,
	public CComControl<CAsdkSpinner>,
	public CProxyIAcPiPropertyEditEventsSink<CAsdkSpinner>,
	public CProxyIPropertyNotifySink<CAsdkSpinner>,
	public IDispatchImpl<IAcPiPropertyEditControl, &IID_IAcPiPropertyEditControl, &LIBID_ACPILib>
{
protected:
	IDispatch **mppDisp ; //- Pointers to IDispatch to COM wrapper
	IDynamicProperty2 **mppDynProp ;

	UINT mnDisp ; //- Number of IDispatch pointers
	UINT mnDynProp ; //- Number of IDynamicProperty2 pointers

	bool mbReadOnly ; //- Read-Only
	bool mbActivated, mbDeactivating ;

	OLE_COLOR mBackColor, mForeColor ;
	OLE_COLOR mReadOnlyBackColor, mReadOnlyForeColor ;
	CComQIPtr<IFont, &IID_IFont> mpFont ;

	int mnIndex, mnMin, mnMax ;

	CWindow mEditWnd, mSpinWnd ;

public:
	CAsdkSpinner () ;

	DECLARE_REGISTRY_RESOURCEID(IDR_ASDKSPINNER)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	DECLARE_OLEMISC_STATUS(
		OLEMISC_RECOMPOSEONRESIZE | 
		OLEMISC_CANTLINKINSIDE | 
		OLEMISC_INSIDEOUT | 
		OLEMISC_ACTIVATEWHENVISIBLE | 
		OLEMISC_SETCLIENTSITEFIRST
	)

	BEGIN_COM_MAP(CAsdkSpinner)
		COM_INTERFACE_ENTRY(IAsdkSpinner)
		COM_INTERFACE_ENTRY(IViewObjectEx)
		COM_INTERFACE_ENTRY(IViewObject2)
		COM_INTERFACE_ENTRY(IViewObject)
		COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
		COM_INTERFACE_ENTRY(IOleInPlaceObject)
		COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
		COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
		COM_INTERFACE_ENTRY(IOleControl)
		COM_INTERFACE_ENTRY(IOleObject)
		COM_INTERFACE_ENTRY(IPersistStreamInit)
		COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
		COM_INTERFACE_ENTRY(IQuickActivate)
		COM_INTERFACE_ENTRY(IPersistStorage)
		COM_INTERFACE_ENTRY(IDataObject)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
		COM_INTERFACE_ENTRY(IObjectWithSite)
		COM_INTERFACE_ENTRY(IServiceProvider)
		COM_INTERFACE_ENTRY(IAcPiPropertyEditControl)
	END_COM_MAP()

	BEGIN_PROP_MAP(CAsdkSpinner)
		PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
		PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	END_PROP_MAP()

	BEGIN_CONNECTION_POINT_MAP(CAsdkSpinner)
		CONNECTION_POINT_ENTRY(__uuidof(_IAsdkSpinnerEvents))
		CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
		CONNECTION_POINT_ENTRY(IID_IAcPiPropertyEditEventsSink)
	END_CONNECTION_POINT_MAP()

	BEGIN_MSG_MAP(CAsdkSpinner)
		CHAIN_MSG_MAP(CComControl<CAsdkSpinner>)
		DEFAULT_REFLECTION_HANDLER()
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
		NOTIFY_HANDLER(IDC_SPINCTL, UDN_DELTAPOS, OnSpinButtonClicked)
	END_MSG_MAP()

	//- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) ;
	//- IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

public:
	//- IOleControl
	STDMETHOD(OnAmbientPropertyChange) (DISPID dispid) ;

	//- IAcPiPropertyEditControl
	STDMETHOD(InitEditControl) (LPVARIANT pVarObjDispArray, LPVARIANT pVarDynPropArray, LPVARIANT pDispidArray, VARIANT_BOOL bReadOnly) ;
	STDMETHOD(Refresh) (DWORD dwFlags) ;
	STDMETHOD(get_KeepFocus) (VARIANT_BOOL *bKeepFocus) ;
	STDMETHOD(get_ForeColor) (OLE_COLOR *pClr) ;
	STDMETHOD(put_ForeColor) (OLE_COLOR pClr) ;
	STDMETHOD(get_BackColor) (OLE_COLOR *pClr) ;
	STDMETHOD(put_BackColor) (OLE_COLOR pClr) ;
	STDMETHOD(get_ReadOnlyForeColor) (OLE_COLOR *pClr) ;
	STDMETHOD(put_ReadOnlyForeColor) (OLE_COLOR pClr) ;
	STDMETHOD(get_ReadOnlyBackColor) (OLE_COLOR *pClr) ;
	STDMETHOD(put_ReadOnlyBackColor) (OLE_COLOR pClr) ;
	STDMETHOD(get_Font) (IUnknown **pIFont) ;
	STDMETHOD(put_Font) (IUnknown *pIFont) ;

	//- IAsdkSpinner
	HRESULT OnDraw (ATL_DRAWINFO &di) ;
	STDMETHOD(SetObjectRects) (LPCRECT prcPos, LPCRECT prcClip) ;
	STDMETHOD(DoVerbHide) (LPCRECT prcPosRect, HWND hwndParent) ;
	STDMETHOD(DoVerbShow) (LPCRECT prcPosRect, HWND hwndParent) ;
	STDMETHOD(DoVerbUIActivate) (LPCRECT prcPosRect, HWND hwndParent) ;
	STDMETHOD(UIDeactivate) () ;

	STDMETHOD(_InternalQueryService) (REFGUID guidService, REFIID riid, void **ppvObject) ;

	HRESULT FinalConstruct () ;
	void FinalRelease () ;

	//- Message Handlers
	LRESULT OnCreate (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
	LRESULT OnLButtonDown (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;

	//- Custom control methods
	STDMETHOD(OnSpinButtonClicked) (int idCtrl, LPNMHDR pnmh, BOOL &bHandled) ;
	STDMETHOD(OnStockSpinChg) (int delta) ;

	STDMETHOD(BeginEdit) (const RECT &rect) ;
	STDMETHOD(EndEdit) () ;
} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(AsdkSpinner), CAsdkSpinner)
