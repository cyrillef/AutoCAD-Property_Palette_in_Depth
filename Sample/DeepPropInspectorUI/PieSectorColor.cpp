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
//----- IPieSectorColor.cpp : Implementation of CPieSectorColor
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "PieSectorColor.h"
#include "PieSectorsSpin.h"
#include "../DeepPropInspector/DeepPropInspector.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={ &IID_IPieSectorColor } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//- IDynamicProperty
STDMETHODIMP CPieSectorColor::GetGUID (GUID *pPropGUID) {
	CHECKOUTPARAM( pPropGUID ) ;
	memcpy (pPropGUID, &CLSID_PieSectorColor, sizeof (GUID)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::GetDisplayName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Color") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pbEnabled ) ;
	*pbEnabled =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::IsPropertyReadOnly (BOOL *pbReadOnly) {
	CHECKOUTPARAM( pbReadOnly ) ;
	*pbReadOnly =FALSE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::GetDescription (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Color") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::GetCurrentValueName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Color") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::GetCurrentValueType (VARTYPE *pVarType) {
	CHECKOUTPARAM( pVarType ) ;
	*pVarType =VT_I4 ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pVarData ) ;

	::VariantInit (pVarData) ;
	V_VT(pVarData) =VT_I4 ;
	V_I4(pVarData) =0 ;

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
	CComPtr<IAcadAcCmColor> pColor ;
	pSector->get_TrueColor (&pColor) ;
	//V_DISPATCH(pVarData) =pColor.Detach () ;
	AcColor color ;
	pColor->get_ColorIndex (&color) ;
	V_I4(pVarData) =(long)color ;

	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
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
	CComPtr<IAcadAcCmColor> pColor ;
	pSector->get_TrueColor (&pColor) ;
	pColor->put_ColorIndex ((AcColor)V_I4(&varData)) ;
	pSector->put_TrueColor (pColor) ;

	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::Connect (IDynamicPropertyNotify2 *pSink) {
	CHECKOUTPARAM( pSink ) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorColor::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- IPerPropertyDisplay
//STDMETHODIMP CPieSectorColor::GetCustomPropertyCtrl (VARIANT varId, LCID lcid, BSTR *pProgId) {
//	CHECKOUTPARAM( pProgId ) ;
//	//- We want a color control
//	LPOLESTR lpOleStr ;
//	//::ProgIDFromCLSID (IID_IAcPeColorCtrl, &lpOleStr) ;
//	*pProgId =::SysAllocString (lpOleStr) ;
//	return (S_OK) ;
//}
