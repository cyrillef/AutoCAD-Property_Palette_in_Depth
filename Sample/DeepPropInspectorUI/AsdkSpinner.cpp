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
//- AsdkSpinner.cpp : Implementation of CAsdkSpinner
//-----------------------------------------------------------------------------
#include "stdafx.h"

//-----------------------------------------------------------------------------
#include "acpi.h"
#include "AsdkSpinner.h"

//-----------------------------------------------------------------------------
CAsdkSpinner::CAsdkSpinner () :
	mppDisp(NULL), mnDisp(0), mbReadOnly(false), mbActivated(false), mbDeactivating(false),
	mBackColor(RGB(255, 255, 255)), mForeColor(0), mReadOnlyBackColor(RGB(192, 192, 192)), mReadOnlyForeColor(0),
	mpFont(),
	mnIndex(1), mnMin(1), mnMax(1)
{
	AtlAxWinInit () ;
	m_bWindowOnly =true ;
}

//-----------------------------------------------------------------------------
//- ISupportsErrorInfo
STDMETHODIMP CAsdkSpinner::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID *arr [] ={ &IID_IAsdkSpinner, } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
HRESULT CAsdkSpinner::FinalConstruct () {
	m_bWindowOnly =true ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
void CAsdkSpinner::FinalRelease () {
	ATLASSERT( mppDisp != NULL ) ;
	for ( UINT i =0 ; i < mnDisp ; i++ ) {
		if ( mppDisp [i] != NULL )
			mppDisp [i]->Release () ;
	}
	delete [] mppDisp ;
	mnDisp =0 ;

	ATLASSERT( mppDynProp != NULL ) ;
	for ( UINT i =0 ; i < mnDynProp ; i++ ) {
		if ( mppDynProp [i] != NULL )
			mppDynProp [i]->Release () ;
	}
	delete [] mppDynProp ;
	mnDynProp =0 ;
}


//-----------------------------------------------------------------------------
HRESULT CAsdkSpinner::OnDraw (ATL_DRAWINFO &di) {
	RECT &rc =*(RECT *)di.prcBounds ;
	//- Set Clip region to the rectangle specified by di.prcBounds
	HRGN hRgnOld =NULL ;
	if ( GetClipRgn (di.hdcDraw, hRgnOld) != 1 )
		hRgnOld =NULL ;
	bool bSelectOldRgn =false ;
	HRGN hRgnNew =CreateRectRgn (rc.left, rc.top, rc.right, rc.bottom) ;
	if ( hRgnNew != NULL )
		bSelectOldRgn =(SelectClipRgn (di.hdcDraw, hRgnNew) != ERROR) ;

	COLORREF fgColor =static_cast<COLORREF>(mForeColor) ;
	COLORREF bgColor =static_cast<COLORREF>(mBackColor) ;
	if ( mbReadOnly == true ) {
		fgColor =static_cast<COLORREF>(mReadOnlyForeColor) ;
		bgColor =static_cast<COLORREF>(mReadOnlyBackColor) ;
	}
	::SetTextColor (di.hdcDraw, fgColor) ;
	::SetBkColor (di.hdcDraw, bgColor) ;
	::SetBkMode (di.hdcDraw, TRANSPARENT) ;

	HBRUSH hbrBk =::CreateSolidBrush (bgColor) ;
	::FillRect (di.hdcDraw, &rc, hbrBk) ;
	::DeleteObject (hbrBk) ;

	HFONT hFont ;
	mpFont->get_hFont (&hFont) ;
	HFONT hOldFont =(HFONT)SelectObject (di.hdcDraw, hFont) ;
	SetTextAlign (di.hdcDraw, TA_LEFT | TA_TOP | TA_NOUPDATECP) ;
	CString st ;
	st.Format (_T("%d"), mnIndex) ;
	rc.left +=OPM_MARGIN ;
	DrawText (di.hdcDraw, (LPCTSTR)st, st.GetLength (), &rc, DT_SINGLELINE | DT_LEFT | DT_VCENTER) ;
	SelectObject (di.hdcDraw, hOldFont) ;

	if ( bSelectOldRgn )
		SelectClipRgn (di.hdcDraw, hRgnOld) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAsdkSpinner::InitEditControl (LPVARIANT pVarObjDispArray, LPVARIANT pVarDynPropArray, LPVARIANT pDispidArray, VARIANT_BOOL bReadOnly) {
	//- Load ambient properties - This will ensure the current fonts, colors are loaded
	OnAmbientPropertyChange (DISPID_UNKNOWN) ;
	//- Cache the IDispatch pointers
	LONG lb =0, ub =0 ;
	SafeArrayGetLBound (pVarObjDispArray->parray, 1, &lb) ;
	SafeArrayGetUBound (pVarObjDispArray->parray, 1, &ub) ;
	mnDisp =(UINT)((ub - lb) + 1) ;
	mppDisp =new IDispatch* [mnDisp] ;
	memset (mppDisp, 0, mnDisp * sizeof (IDispatch *)) ;
	for ( LONG i =lb, j =0 ; i <= ub ; i++, j++ ) {
		CComPtr<IDispatch> pDisp ;
		SafeArrayGetElement (pVarObjDispArray->parray, &i, reinterpret_cast<IDispatch *>(&pDisp)) ;
		mppDisp [j] =pDisp ;
		if ( pDisp != NULL )
			mppDisp [i]->AddRef () ;
	}

	//- Cache the IDynamicProperty2 pointers
	lb =0, ub =0 ;
	SafeArrayGetLBound (pVarDynPropArray->parray, 1, &lb) ;
	SafeArrayGetUBound (pVarDynPropArray->parray, 1, &ub) ;
	mnDynProp =(UINT)((ub - lb) + 1) ;
	mppDynProp =new IDynamicProperty2* [mnDynProp] ;
	memset (mppDynProp, 0, mnDynProp * sizeof (IDynamicProperty2 *)) ;
	for ( LONG i =lb, j =0 ; i <= ub ; i++, j++ ) {
		CComPtr<IDispatch> pDisp ;
		SafeArrayGetElement (pVarDynPropArray->parray, &i, reinterpret_cast<IDispatch *>(&pDisp)) ;
		CComQIPtr<IDynamicProperty2> pDyn2 (pDisp) ;
		mppDynProp [j] =pDyn2 ;
		if ( pDisp != NULL )
			mppDynProp [i]->AddRef () ;
	}

	mbReadOnly =(bReadOnly != VARIANT_FALSE) ;
	Refresh (0) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAsdkSpinner::Refresh (DWORD dwFlags) {
	ATLASSERT( mppDisp != NULL ) ;
	//- Get the property value for the first object
	ATLASSERT ( mppDisp [0] != NULL ) ;
	CComPtr<IDispatch> pDisp =mppDisp [0] ;
	VARIANT varResult ;
	DISPPARAMS dispparamsNoArgs ={ NULL, NULL, 0, 0 } ;
	pDisp->Invoke (DISPID_SECTORS, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispparamsNoArgs, &varResult, NULL, NULL) ;
//	CComQIPtr<PDMSGGLib::IPDMSLinearDimensionPoints> pPoints (varResult.pdispVal) ;
	CComQIPtr<IDispatch> pSectors (varResult.pdispVal) ;
	varResult.pdispVal->Release () ;
	long nb =0 ;
//	pPoints->get_Count (&nb) ;
//	mnMax =nb ;
	pSectors->Invoke (DISPID_COUNT, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispparamsNoArgs, &varResult, NULL, NULL) ;
	nb =mnMax =varResult.lVal ;

	//- Is there more than one object selected
	for ( UINT i =1 ; i < mnDisp ; i++ ) {
		pDisp =mppDisp [i] ;
		VARIANT varResult2 ;
		pDisp->Invoke (DISPID_SECTORS, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispparamsNoArgs, &varResult2, NULL, NULL) ;

//		CComQIPtr<PDMSGGLib::IPDMSLinearDimensionPoints> pPoints2 (varResult2.pdispVal) ;
		CComQIPtr<IDispatch> pSectors2 (varResult2.pdispVal) ;
		varResult2.pdispVal->Release () ;
//		pPoints2->get_Count (&nb) ;
		pSectors2->Invoke (DISPID_COUNT, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispparamsNoArgs, &varResult2, NULL, NULL) ;
		nb =varResult2.lVal ;

		if ( nb != mnMax ) {
			mnMax =-1 ;
			break ;
		}
	}
	Invalidate () ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAsdkSpinner::get_KeepFocus (VARIANT_BOOL *bKeepFocus) {
	if ( bKeepFocus == NULL )
		return (E_POINTER) ;
	*bKeepFocus =VARIANT_FALSE ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::get_ForeColor (OLE_COLOR *pClr) {
	if ( pClr == NULL )
		return (E_POINTER) ;
	*pClr =mForeColor ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::put_ForeColor (OLE_COLOR pClr) {
	if ( FAILED(Fire_OnRequestEdit (DISPID_FORECOLOR)) )
		return (E_ACCESSDENIED) ;
	mForeColor =pClr ;
	Fire_OnChanged (DISPID_FORECOLOR) ;
	if ( IsWindow () )
		Invalidate () ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::get_BackColor (OLE_COLOR *pClr) {
	if ( pClr == NULL )
		return (E_POINTER) ;
	*pClr =mBackColor ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::put_BackColor (OLE_COLOR pClr) {
	if ( FAILED(Fire_OnRequestEdit (DISPID_BACKCOLOR)) )
		return (E_ACCESSDENIED) ;
	mBackColor =pClr ;
	//if ( mhBackgroundBrush )
	//	::DeleteObject (mhBackgroundBrush) ;
	//mhBackgroundBrush =::CreateSolidBrush (static_cast<COLORREF>(mBackColor)) ;
	Fire_OnChanged (DISPID_BACKCOLOR) ;
	if ( IsWindow () )
		Invalidate () ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::get_ReadOnlyForeColor (OLE_COLOR *pClr) {
	if ( pClr == NULL )
		return (E_POINTER) ;
	*pClr =mReadOnlyForeColor ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::put_ReadOnlyForeColor (OLE_COLOR pClr) {
	if ( FAILED(Fire_OnRequestEdit (DISPID_READONLYFORECOLOR)) )
		return (E_ACCESSDENIED) ;
	mReadOnlyForeColor =pClr ;
	Fire_OnChanged (DISPID_READONLYFORECOLOR) ;
	if ( IsWindow () )
		Invalidate () ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::get_ReadOnlyBackColor (OLE_COLOR *pClr) {
	if ( pClr == NULL )
		return (E_POINTER) ;
	*pClr =mReadOnlyBackColor ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::put_ReadOnlyBackColor (OLE_COLOR pClr) {
	if ( FAILED(Fire_OnRequestEdit (DISPID_READONLYBACKCOLOR)) )
		return (E_ACCESSDENIED) ;
	mReadOnlyBackColor =pClr ;
	//if ( mhReadOnlyBackgroundBrush )
	//	::DeleteObject (mhReadOnlyBackgroundBrush) ;
	//mhReadOnlyBackgroundBrush =::CreateSolidBrush (static_cast<COLORREF>(mReadOnlyBackColor)) ;
	//- To get rid of the old 'warning C4702: unreachable code' warning - got too annoying
	Fire_OnChanged (DISPID_READONLYBACKCOLOR) ;
	if ( IsWindow () )
	    Invalidate () ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::get_Font (IUnknown **pIFont) {
	if ( pIFont == NULL )
		return (E_POINTER) ;
	*pIFont =reinterpret_cast<IUnknown *>(mpFont.p) ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::put_Font (IUnknown *pIFont) {
	if ( FAILED(Fire_OnRequestEdit (DISPID_FONT)) )
		return (E_ACCESSDENIED) ;
	mpFont =pIFont ;
	Fire_OnChanged (DISPID_FONT) ;
	if ( IsWindow () )
		Invalidate () ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAsdkSpinner::_InternalQueryService (REFGUID guidService, REFIID riid, void **ppvObject) {
	return (E_NOTIMPL) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAsdkSpinner::OnAmbientPropertyChange (DISPID dispid) {
	if ( dispid == DISPID_FONT || dispid == DISPID_UNKNOWN ) {
		CComPtr<IFont> pIFont ;
		if ( SUCCEEDED(GetAmbientFont (&pIFont)) )
			put_Font (pIFont) ;
	}
	if ( dispid == DISPID_FORECOLOR || dispid == DISPID_UNKNOWN ) {
		OLE_COLOR foreColor ;
		if ( SUCCEEDED(GetAmbientForeColor (foreColor)) )
			put_ForeColor (foreColor) ;
	}
	if ( dispid == DISPID_BACKCOLOR || dispid == DISPID_UNKNOWN ) {
		OLE_COLOR backColor ;
		if ( SUCCEEDED(GetAmbientBackColor (backColor)) )
			put_BackColor (backColor) ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
LRESULT CAsdkSpinner::OnCreate (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) {
	CComVariant tmp ;
	//- Background colors
	COLORREF clr ;
	GetAmbientBackColor (clr) ;
	put_BackColor (clr) ;
	if ( SUCCEEDED(GetAmbientProperty (DISPID_READONLYBACKCOLOR, tmp) && V_VT(&tmp) == VT_I4) )
		put_ReadOnlyBackColor (tmp.lVal) ;
	else
		put_ReadOnlyBackColor (clr) ;
	//- Foreground colors
	GetAmbientForeColor (clr) ;
	if ( SUCCEEDED(GetAmbientProperty (DISPID_READONLYFORECOLOR, tmp) && V_VT(&tmp) == VT_I4) )
		put_ReadOnlyForeColor (tmp.lVal) ;
	else
		put_ReadOnlyForeColor (clr) ;
	//- Font
	CComPtr<IFont> pFont ;
	GetAmbientFont (&pFont) ;
	put_Font (pFont) ;

	//- Create internal controls
	RECT rect ;
	::GetClientRect (m_hWnd, &rect) ;

	RECT rect1 ={ rect.left, rect.top, rect.right - 2 * (rect.bottom - rect.top), rect.bottom } ;
	mEditWnd.Create (
		_T("EDIT"), m_hWnd, rect1, NULL,
		WS_CHILD /*| WS_VISIBLE*/ | ES_NUMBER | ES_LEFT | ES_AUTOHSCROLL | ES_READONLY,
		0,
		IDC_EDITCTL, NULL
	) ;
	HFONT hFont ;
	mpFont->get_hFont (&hFont) ;
	mEditWnd.SetFont (hFont, TRUE) ;
	mEditWnd.SetWindowText (_T("")) ;

	RECT rect2 ={ rect.right - 2 * (rect.bottom - rect.top), rect.top, rect.right, rect.bottom } ;
	mSpinWnd.Create (
		UPDOWN_CLASS, m_hWnd, rect2, NULL,
		WS_CHILD /*| WS_VISIBLE*/ | UDS_HORZ | UDS_ALIGNRIGHT | UDS_NOTHOUSANDS | UDS_ARROWKEYS /*| UDS_WRAP | UDS_SETBUDDYINT | UDS_AUTOBUDDY | UDS_HOTTRACK*/,
		0,
		IDC_SPINCTL, NULL
	) ;
	::SendMessage (mSpinWnd.m_hWnd, UDM_SETRANGE, 0, MAKELPARAM (mnMax, mnMin)) ;
	::SendMessage (mSpinWnd.m_hWnd, UDM_SETPOS, 0, MAKELPARAM (mnIndex, 0)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- The window position has changed, set the rectangle of the ActiveX control
//- to match the new rects and call the SetObjectRects() helper method to set
//- the rects of any child windows. 
STDMETHODIMP CAsdkSpinner::SetObjectRects (LPCRECT prcPos, LPCRECT prcClip) {
	if ( !IsWindow () )
		return (S_OK) ;
	IOleInPlaceObjectWindowlessImpl<CAsdkSpinner>::SetObjectRects (prcPos, prcClip) ;
	int cx =prcPos->right - prcPos->left ;
	int cy =prcPos->bottom - prcPos->top ;
	SetWindowPos (NULL, prcPos->left, prcPos->top, cx, cy, SWP_NOZORDER) ;

	//- Do not forget internal controls
	RECT rect ;
	::GetClientRect (m_hWnd, &rect) ;
	RECT rect1 ={ rect.left, rect.top, rect.right - 2 * (rect.bottom - rect.top), rect.bottom } ;
	mEditWnd.MoveWindow (&rect1, TRUE) ;
	RECT rect2 ={ rect.right - 2 * (rect.bottom - rect.top), rect.top, rect.right, rect.bottom } ;
	mSpinWnd.MoveWindow (&rect2, TRUE) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- Handle requests to hide ourself. Hide the edit control, the ActiveX window.
STDMETHODIMP CAsdkSpinner::DoVerbHide (LPCRECT prcPosRect, HWND hwndParent) {
	if ( IsWindow () )
		ShowWindow (SW_HIDE) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- Handle requests to show ourself. If we are in editing mode, show the child
//- edit window. Show the ATL window.
STDMETHODIMP CAsdkSpinner::DoVerbShow (LPCRECT prcPosRect, HWND hwndParent) {
	if ( IsWindow () )
		ShowWindow (SW_SHOW) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAsdkSpinner::OnSpinButtonClicked (int idCtrl, LPNMHDR pnmh, BOOL &bHandled) {
	bHandled =FALSE ;
	if ( pnmh->idFrom == IDC_SPINCTL && pnmh->code == UDN_DELTAPOS ) {
		NM_UPDOWN *pNMUpDown =(NM_UPDOWN *)pnmh ;
		if ( OnStockSpinChg (pNMUpDown->iDelta) )
			bHandled =TRUE ;
	}         
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::OnStockSpinChg (int delta) {
	int pos =(int)((short)(::SendMessage (mSpinWnd.m_hWnd, UDM_GETPOS, 0, 0l) & 0xffff)) ;
	BOOL bRet =FALSE ;
	pos +=delta ; //- Increment to actual position after scroll
	if ( pos > mnMax ) {
		pos =mnMin ;
		::SendMessage (mSpinWnd.m_hWnd, UDM_SETPOS, 0, MAKELPARAM (pos, 0)) ;
	} else if ( pos < mnMin ) {
		pos =mnMax ;
		::SendMessage (mSpinWnd.m_hWnd, UDM_SETPOS, 0, MAKELPARAM (pos, 0)) ;
	}
	bRet =TRUE ;

	if ( pos != mnIndex ) {
		mnIndex =pos ;
		//- New spin value
		CString st ;
		st.Format (_T("%d"), mnIndex) ;
		mEditWnd.SetWindowText (st) ;
		//- Update the IDynamicProperty2 interface, so other dynprops get updated too
		for ( UINT i =0 ; i < mnDynProp ; i++ ) {
			if ( mppDisp [i] != NULL && mppDynProp [i] != NULL ) {
				Fire_BeginPropertyUpdate () ;
				mppDynProp [i]->SetCurrentValueData (reinterpret_cast<IUnknown *>(mppDisp [i]), CComVariant ((long)mnIndex)) ;
				Fire_EndPropertyUpdate () ;
			}
		}
	}
	return (bRet) ;
}

//-----------------------------------------------------------------------------
LRESULT CAsdkSpinner::OnLButtonDown (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) {
	return (Fire_Clicked ()) ;
}

STDMETHODIMP CAsdkSpinner::DoVerbUIActivate (LPCRECT prcPosRect, HWND hwndParent) {
	if ( /*mbActivated == false &&*/ mbDeactivating == false && mnMax != -1 ) {
		//- Workaround. DoVerbUIActivate is always passed the original rect of the
		//- control, so get the ATL windows actual rect here and pass it to BeginEdit.
		RECT rc ;
		GetClientRect (&rc) ;
		BeginEdit (rc) ;
		//HRESULT hr =IOleObjectImpl<CAsdkSpinner>::DoVerbUIActivate (prcPosRect, hwndParent) ;
	}
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::UIDeactivate () {
	HRESULT hr =S_OK ;
	if ( mbActivated == true ) {
		mbDeactivating =true ;
		EndEdit () ;
		hr =IOleInPlaceObjectWindowlessImpl<CAsdkSpinner>::UIDeactivate () ;
		mbDeactivating =false ;
	} else {
		hr =IOleInPlaceObjectWindowlessImpl<CAsdkSpinner>::UIDeactivate () ;
	}
	return (hr) ;
}

STDMETHODIMP CAsdkSpinner::BeginEdit (const RECT &rect) {
	mbActivated =true ;

	CString st ;
	st.Format (_T("%d"), mnIndex) ;
	mEditWnd.SetWindowText (st) ;
	mEditWnd.ShowWindow (SW_SHOW) ;
	mEditWnd.BringWindowToTop () ;
	mEditWnd.Invalidate () ;

	::SendMessage (mSpinWnd.m_hWnd, UDM_SETRANGE, 0, MAKELPARAM(mnMax, mnMin)) ;
	::SendMessage (mSpinWnd.m_hWnd, UDM_SETPOS, 0, MAKELPARAM(mnIndex, 0)) ;
	mSpinWnd.ShowWindow (SW_SHOW) ;
	mSpinWnd.BringWindowToTop () ;
	mSpinWnd.Invalidate () ;

	::SendMessage (mEditWnd.m_hWnd, EM_SETSEL, 0, -1) ;
	mEditWnd.SetFocus () ;
	return (S_OK) ;
}

STDMETHODIMP CAsdkSpinner::EndEdit () {
	mbActivated =false ;
	mEditWnd.ShowWindow (SW_HIDE) ;
	mSpinWnd.ShowWindow (SW_HIDE) ;
	Invalidate () ;
	Refresh (0) ;
	return (S_OK) ;
}
