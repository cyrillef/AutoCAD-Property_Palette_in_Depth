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
//----- PieSectorsSpin.cpp : Implementation of CPieSectorsSpin
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "acPexCtl_i.c"
#include "PieSectorsSpin.h"
#include "../DeepPropInspector/DeepPropInspector.h"

//-----------------------------------------------------------------------------
//----- CPieSectorsSpin
STDMETHODIMP CPieSectorsSpin::InterfaceSupportsErrorInfo(REFIID riid) {
	static const IID* arr [] ={ &IID_IPieSectorsSpin } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
/*static*/
IPieSectorsSpin *CPieSectorsSpin::GetCounterSpin (bool bAddRef) {
	CComQIPtr<IPropertyManager2> pPropMan ;
	pPropMan =GET_OPMPROPERTY_MANAGER (AsdkPie::desc ()) ;
	long n =0 ;
	HRESULT hr =pPropMan->GetDynamicPropertyCountEx (&n) ;
	for ( long i =0 ; i < n ; i++ ) {
		CComPtr<IUnknown> pUnk ;
		hr =pPropMan->GetDynamicProperty (i, &pUnk) ;
		CComQIPtr<IDynamicProperty2> pp (pUnk) ;
		if ( pp.p == NULL )
			continue ;

		CComBSTR bstr ;
		hr =pp->GetCurrentValueName (&bstr) ;

		if ( _bstr_t (bstr, TRUE) == _bstr_t (_T("Sector Spin")) ) {
			CComQIPtr<IPieSectorsSpin> pFinal (pp) ;
			if ( bAddRef )
				return (pFinal.Detach ()) ;
			return (pFinal.p) ;
		}
	}
	return (NULL) ;
}

/*static*/
ULONG CPieSectorsSpin::GetCounterSpinPosition () {
	CComPtr<IPieSectorsSpin> pp =CPieSectorsSpin::GetCounterSpin (false) ;
	RXASSERT( pp.p != NULL ) ;
	ULONG index =0 ;
	pp->get_Counter (&index) ;
	return (index) ;
}

//-----------------------------------------------------------------------------
//----- IDynamicProperty
STDMETHODIMP CPieSectorsSpin::GetGUID (GUID *pPropGUID) {
	CHECKOUTPARAM( pPropGUID ) ;
	memcpy (pPropGUID, &CLSID_PieSectorsSpin, sizeof(GUID)) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::GetDisplayName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Sector Spin") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::IsPropertyEnabled (IUnknown *pUnk, BOOL *pbEnabled) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pbEnabled ) ;
	*pbEnabled =TRUE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::IsPropertyReadOnly (BOOL *pbReadOnly) {
	CHECKOUTPARAM( pbReadOnly ) ;
	*pbReadOnly =FALSE ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::GetDescription (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Sector Spin") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::GetCurrentValueName (BSTR *pBstrName) {
	CHECKOUTPARAM( pBstrName ) ;
	*pBstrName =::SysAllocString (L"Sector Spin") ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::GetCurrentValueType (VARTYPE *pVarType) {
	CHECKOUTPARAM( pVarType ) ;
	*pVarType =VT_I4 ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::GetCurrentValueData (IUnknown *pUnk, VARIANT *pVarData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	CHECKOUTPARAM( pVarData ) ;
	//- Return value in a variant
	::VariantInit (pVarData) ;
	V_VT(pVarData) =VT_I4 ;
	V_I4(pVarData) =mnCounter + 1 ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::SetCurrentValueData (IUnknown *pUnk, const VARIANT varData) {
	CHECKOUTPARAMVAL( pUnk, E_INVALIDARG ) ;
	mnCounter =V_I4(&varData) - 1 ;
	CComQIPtr<IAcadPie> pPie (pUnk) ;
	CComPtr<IAcadPieSectors> pSectors ;
	pPie->get_Sectors (&pSectors) ;
	long nb =0 ;
	pSectors->get_Count (&nb) ;
	if ( mnCounter >= nb )
		mnCounter =nb - 1 ;
	if ( mnCounter < 0 )
		mnCounter =0 ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::Connect (IDynamicPropertyNotify2 *pSink) {
	CHECKOUTPARAM( pSink ) ;
	m_pNotify =pSink ;
	m_pNotify->AddRef () ;
	mnCounter =0 ;
	pSink->GetCurrentSelectionSet (&mSset) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CPieSectorsSpin::Disconnect () {
	if ( m_pNotify ) {
		m_pNotify->Release () ;
		m_pNotify= NULL ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//- IPerPropertyDisplay
STDMETHODIMP CPieSectorsSpin::GetCustomPropertyCtrl (VARIANT varId, LCID lcid, BSTR *pProgId) {
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
		return (IAcPiPropertyDisplayImpl<CPieSectorsSpin>::GetCustomPropertyCtrl (varId, lcid, pProgId)) ;
	}
	return (S_OK) ;
	//return (IAcPiPropertyDisplayImpl<CPieSectorsSpin>::GetCustomPropertyCtrl (varId, lcid, pProgId)) ;
}

//-----------------------------------------------------------------------------
//- IPDMSPieSectorsSpin
STDMETHODIMP CPieSectorsSpin::get_Counter (ULONG *pVal) {
	CHECKOUTPARAM( pVal ) ;
	*pVal =static_cast<ULONG>(mnCounter) ;
	return (S_OK) ;
}