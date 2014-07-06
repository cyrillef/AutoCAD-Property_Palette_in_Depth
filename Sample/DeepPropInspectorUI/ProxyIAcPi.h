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
//- CProxyIAcPi.h : Declaration of the CPdmsViewControl
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
template <class T>
class CProxyIAcPiPropertyEditEventsSink : public IConnectionPointImpl<T, &IID_IAcPiPropertyEditEventsSink, CComDynamicUnkArray> {
	//- Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_Clicked () {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex ;
		int nConnections = connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnClick () ;
		}
		return (hr) ;
	}

	HRESULT Fire_DblClicked () {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnDblClick () ;
		}
		return (hr) ;
	}

	HRESULT Fire_KeyDown (long nChar, long nKeyData) {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex ;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnKeyDown (nChar, nKeyData) ;
		}
		return (hr) ;
	}

	HRESULT Fire_RButtonDown (WPARAM wParam, LPARAM lParam) {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex ;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnRButtonDown (wParam, lParam) ;
		}
		return (hr) ;
	}

	HRESULT Fire_MButtonDown (WPARAM wParam, LPARAM lParam) {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnMButtonDown (wParam, lParam) ;
		}
		return (hr) ;
	}

	HRESULT Fire_KeyUp (long nChar, long nKeyData) {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnKeyDown (nChar, nKeyData) ;
		}
		return (hr) ;
	}

	HRESULT Fire_BeginPropertyUpdate () {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnBeginPropertyUpdate () ;
		}
		return (hr) ;
	}

	HRESULT Fire_EndPropertyUpdate () {
		HRESULT hr =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComQIPtr<IAcPiPropertyEditEventsSink, &IID_IAcPiPropertyEditEventsSink> sp =connections.GetAt (nConnectionIndex) ;
			if ( sp )
				hr =sp->OnEndPropertyUpdate () ;
		}
		return (hr) ;
	}

protected:
	void CopySinkArray (CComDynamicUnkArray &pCopy) {
		pCopy.clear () ;
		IUnknown **pp =NULL ;
		T *pT =static_cast<T *>(this) ;
		pT->Lock () ;
		for ( pp =m_vec.begin () ; pp < m_vec.end () ; pp++ ) {
			if ( *pp == NULL )
				continue ;
			pCopy.Add (*pp) ;
		}
		pT->Unlock () ;
	}
} ;

//-----------------------------------------------------------------------------
template <class T>
class ATL_NO_VTABLE CProxyIPropertyNotifySink : public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CComDynamicUnkArray> {

public:
	HRESULT Fire_OnChanged (LONG dispID) {
		HRESULT ret =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex ;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections ; nConnectionIndex++ ) {
			CComPtr<IUnknown> sp =connections.GetAt (nConnectionIndex);
			IPropertyNotifySink *pIPropertyNotifySink =reinterpret_cast<IPropertyNotifySink*>(sp.p) ;
			if ( pIPropertyNotifySink != NULL )
				ret =pIPropertyNotifySink->OnChanged (dispID) ;
		}
		return (ret) ;
	}

	HRESULT Fire_OnRequestEdit (LONG dispID) {
		HRESULT ret =S_OK ;
		CComDynamicUnkArray connections ;
		CopySinkArray (connections) ;
		int nConnectionIndex ;
		int nConnections =connections.GetSize () ;
		for ( nConnectionIndex =0 ; nConnectionIndex < nConnections && SUCCEEDED(ret) ; nConnectionIndex++ ) {
			CComPtr<IUnknown> sp =connections.GetAt (nConnectionIndex) ;
			IPropertyNotifySink *pIPropertyNotifySink =reinterpret_cast<IPropertyNotifySink *>(sp.p) ;
			if ( pIPropertyNotifySink != NULL )
				ret =pIPropertyNotifySink->OnRequestEdit (dispID) ;
		}
		return (ret) ;
	}

protected:
	void CopySinkArray (CComDynamicUnkArray &pCopy) {
		pCopy.clear () ;
		IUnknown **pp =NULL ;
		T *pT =static_cast<T *>(this) ;
		pT->Lock () ;
		for ( pp =m_vec.begin () ; pp < m_vec.end () ; pp++ ) {
			if ( *pp == NULL )
				continue ;
			pCopy.Add (*pp) ;
		}
		pT->Unlock () ;
	}
} ;
