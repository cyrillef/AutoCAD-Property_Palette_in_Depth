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
//----- AcadPie.cpp : Implementation of CAcadPie
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "AsdkPie.h"

#include "AcadPie.h"
#include "AcadPieSectors.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPie::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID * arr [] ={ &IID_IAcadPie } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPie::ShowProperty (DISPID dispID, BOOL *pShow) {
	CHECKOUTPARAM( pShow ) ;
	switch ( dispID ) {
		case 103:
			*pShow =FALSE ;
			return (S_OK);
	}
	return (IAcadCircleImpl<CAcadPie, AsdkPie, IAcadPie, &CLSID_AcadPie>::ShowProperty (dispID, pShow)) ;
}

//-----------------------------------------------------------------------------
//- IAcadPie
STDMETHODIMP CAcadPie::get_Title (BSTR *pVal) {
	USES_CONVERSION ;
	CHECKOUTPARAM( pVal ) ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	*pVal =::SysAllocString (A2W (pEntity->get_Title ())) ;
	END_PROP_GETPUT(IID_IAcadPie) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPie::put_Title (BSTR newVal) {
	USES_CONVERSION ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForWrite) ;
	pEntity->put_Title (W2A (newVal)) ;
	END_PROP_GETPUT(IID_IAcadPie) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPie::get_AllExploded (VARIANT_BOOL *pVal) {
	CHECKOUTPARAM( pVal ) ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	*pVal =pEntity->isAllExploded () ? VARIANT_TRUE : VARIANT_FALSE ;
	END_PROP_GETPUT(IID_IAcadPie) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPie::put_AllExploded (VARIANT_BOOL newVal) {
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForWrite) ;
	pEntity->put_AllExploded (newVal == VARIANT_FALSE ? false : true) ;
	END_PROP_GETPUT(IID_IAcadPie) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPie::get_Sectors (IAcadPieSectors **ppVal) {
	CHECKOUTPARAM( ppVal ) ;
	//BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	CComObject<CAcadPieSectors> *ppSectors =NULL ;
	CComObject<CAcadPieSectors>::CreateInstance (&ppSectors) ;
	ppSectors->AddRef () ;
	ppSectors->Init (m_objRef) ; //- Ok since no BEGIN_PROP_GETPUT
	ppSectors->QueryInterface (IID_IAcadPieSectors, reinterpret_cast<void **>(ppVal)) ;
	//END_PROP_GETPUT(IID_IAcadPie) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPie::get_Clockwise (VARIANT_BOOL *pVal) {
	CHECKOUTPARAM( pVal ) ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	*pVal =pEntity->isClockwise () ? VARIANT_TRUE : VARIANT_FALSE ;
	END_PROP_GETPUT(IID_IAcadPieSector) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPie::put_Clockwise (VARIANT_BOOL newVal) {
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForWrite) ;
	pEntity->put_Clockwise (newVal == VARIANT_FALSE ? false : true) ;
	END_PROP_GETPUT(IID_IAcadPie) ;
	return (S_OK) ;
}
