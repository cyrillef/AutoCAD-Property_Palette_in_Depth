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
//----- IPieSectorExploded.cpp : Implementation of CPieSectorExploded
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "PieSectorExploded.h"
#include "PieSectorsSpin.h"
#include "../DeepPropInspector/DeepPropInspector.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={ &IID_IPieSectorExploded } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//- IDynamicProperty
STDMETHODIMP CPieSectorExploded::GetGUID (GUID *pPropGUID) {
	CHECKOUTPARAM( pPropGUID ) ;
	memcpy (pPropGUID, &CLSID_PieSectorExploded, sizeof (GUID)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::GetDisplayName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Exploded") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pbEnabled ) ;
	*pbEnabled =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::IsPropertyReadOnly (BOOL *pbReadOnly) {
	CHECKOUTPARAM( pbReadOnly ) ;
	*pbReadOnly =FALSE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::GetDescription (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Exploded") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::GetCurrentValueName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Exploded") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::GetCurrentValueType (VARTYPE *pVarType) {
	CHECKOUTPARAM( pVarType ) ;
	//- Boolean
	*pVarType =VT_BOOL ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pVarData ) ;

	::VariantInit (pVarData) ;
	V_VT(pVarData) =VT_BOOL ;
	V_BOOL(pVarData) =VARIANT_FALSE ;

	CComQIPtr<IAcadPie> pPie (pUnk) ;
	CComPtr<IAcadPieSectors> pSectors ;
	pPie->get_Sectors (&pSectors) ;
	long nb =0 ;
	pSectors->get_Count (&nb) ;
	if ( nb == 0 )
		return (S_OK) ;

	ULONG index =CPieSectorsSpin::GetCounterSpinPosition () ;
	CComPtr<IUnknown> pUnk2 ;
	pSectors->get_Item (CComVariant ((long)index), &pUnk2) ;
	CComQIPtr<IAcadPieSector> pSector (pUnk2) ;
	pSector->get_Exploded (&V_BOOL(pVarData)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;

	CComQIPtr<IAcadPie> pPie (pUnk) ;
	CComPtr<IAcadPieSectors> pSectors ;
	pPie->get_Sectors (&pSectors) ;
	long nb =0 ;
	pSectors->get_Count (&nb) ;
	if ( nb == 0 )
		return (S_OK) ;

	ULONG index =CPieSectorsSpin::GetCounterSpinPosition () ;
	CComPtr<IUnknown> pUnk2 ;
	pSectors->get_Item (CComVariant ((long)index), &pUnk2) ;
	CComQIPtr<IAcadPieSector> pSector (pUnk2) ;
	pSector->put_Exploded (V_BOOL(&varData)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::Connect (IDynamicPropertyNotify2 *pSink) {
	CHECKOUTPARAM( pSink ) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorExploded::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- IPerPropertyDisplay
STDMETHODIMP CPieSectorExploded::GetCustomPropertyCtrl (VARIANT varId, LCID lcid, BSTR *pProgId) {
	CHECKOUTPARAM( pProgId ) ;
	//- We want a Boolean edit
	LPOLESTR lpOleStr ;
	::ProgIDFromCLSID (CLSID_AcPePropertyEditorBool, &lpOleStr) ;
	*pProgId =::SysAllocString (lpOleStr) ;
	return (S_OK) ;
}
