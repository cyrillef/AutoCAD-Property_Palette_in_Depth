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
//----- PieSectorImage.cpp : Implementation of CPieSectorImage
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "PieSectorImage.h"
#include "PieSectorsSpin.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={ &IID_IPieSectorImage } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//- IDynamicProperty
STDMETHODIMP CPieSectorImage::GetGUID (GUID *pPropGUID) {
	CHECKOUTPARAM( pPropGUID ) ;
	memcpy (pPropGUID, &CLSID_PieSectorImage, sizeof(GUID)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::GetDisplayName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Image") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pbEnabled ) ;
	*pbEnabled =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::IsPropertyReadOnly (BOOL *pbReadOnly) {
	CHECKOUTPARAM( pbReadOnly ) ;
	*pbReadOnly =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::GetDescription (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Image") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::GetCurrentValueName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Image") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::GetCurrentValueType (VARTYPE *pVarType) {
	CHECKOUTPARAM( pVarType ) ;
	//- String
	*pVarType =VT_BSTR ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pVarData ) ;
	::VariantInit (pVarData) ;
	V_VT(pVarData) =VT_BSTR ;
	V_BSTR(pVarData) =::SysAllocString(L"") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	//- Nothing to do Read-Only property
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::Connect (IDynamicPropertyNotify2 *pSink) {
	if ( pSink == NULL )
		return (E_POINTER) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorImage::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- IPerPropertyDisplay
STDMETHODIMP CPieSectorImage::GetCustomPropertyCtrl (VARIANT varId, LCID lcid, BSTR *pProgId) {
	try {
		USES_CONVERSION ;
		CHECKOUTPARAM( pProgId ) ;
		if ( !(varId.vt & VT_I4) )
			throw "" ;
		*pProgId =NULL ;
		PROP_DISP_VECTOR arr =GetPerPropDisplayVector () ;
		if ( arr.empty () )
			throw "" ;
		PER_PROP_DISP_ENTRY *pPerPropDispEntry =(PER_PROP_DISP_ENTRY*)(&(*(arr.begin ()))) ;
		if ( pPerPropDispEntry == NULL )
			throw "" ;
		*pProgId =::SysAllocString (A2OLE(pPerPropDispEntry->m_ProgID)) ;
	} catch (...) {
		return (IAcPiPropertyDisplayImpl<CPieSectorImage>::GetCustomPropertyCtrl (varId, lcid, pProgId)) ;
	}
	return (S_OK) ;
	//return (IAcPiPropertyDisplayImpl<CPieSectorsSpin>::GetCustomPropertyCtrl (varId, lcid, pProgId)) ;
}

