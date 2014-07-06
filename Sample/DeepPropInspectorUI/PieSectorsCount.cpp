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
//----- PieSectorsCount.cpp : Implementation of CPieSectorsCount
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "PieSectorsCount.h"
#include "PieSectorsSpin.h"
#include "../DeepPropInspector/DeepPropInspector.h"

//-----------------------------------------------------------------------------
//----- CDynPropLinearDimensionPointsCount
STDMETHODIMP CPieSectorsCount::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={ &IID_IPieSectorsCount } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//----- IDynamicProperty
STDMETHODIMP CPieSectorsCount::GetGUID (GUID *pPropGUID) {
	CHECKOUTPARAM( pPropGUID ) ;
	memcpy (pPropGUID, &CLSID_PieSectorsCount, sizeof (GUID)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::GetDisplayName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Sector Count") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pbEnabled ) ;
	*pbEnabled =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::IsPropertyReadOnly (BOOL *pbReadOnly) {
	CHECKOUTPARAM( pbReadOnly ) ;
	*pbReadOnly =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::GetDescription (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Sector Count") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::GetCurrentValueName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Sector Count") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::GetCurrentValueType (VARTYPE *pVarType) {
	CHECKOUTPARAM( pVarType ) ;
	*pVarType =VT_I4 ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pVarData ) ;

	CComQIPtr<IAcadPie> pPie (pUnk) ;
	CComPtr<IAcadPieSectors> pSectors ;
	pPie->get_Sectors (&pSectors) ;
	long nb =0 ;
	pSectors->get_Count (&nb) ;
	::VariantInit (pVarData) ;
	V_VT(pVarData) =VT_I4 ;
	V_I4(pVarData) =nb ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	return (E_NOTIMPL) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::Connect (IDynamicPropertyNotify2 *pSink) {
	CHECKOUTPARAM( pSink ) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsCount::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}
