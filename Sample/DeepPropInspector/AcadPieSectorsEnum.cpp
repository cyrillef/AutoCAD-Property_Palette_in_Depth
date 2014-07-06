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
// AcadPieSectorsEnum.cpp : Implementation of AcadPieSectorsEnum
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "AcadPieSectorsEnum.h"
#include "AsdkPie.h"

//-----------------------------------------------------------------------------
CAcadPieSectorsEnum::CAcadPieSectorsEnum () : m_objRef(), mnIndex(0) {
}

CAcadPieSectorsEnum::~CAcadPieSectorsEnum () {
	//- This reference object is managed by the root object, not us !
	if ( !m_objRef.isNull () ) {
		AcDbObjectId objId ;
		AcDbObject *pObj ;
		m_objRef.release (objId, pObj) ;
	}
}

//-----------------------------------------------------------------------------
HRESULT CAcadPieSectorsEnum::Init (AcAxObjectRef &objRef) {
	Acad::ErrorStatus es =m_objRef.acquire (objRef.objectId ()) ;
	if ( es != Acad::eOk ) {
		AcAxObjectRefPtr<AsdkPie> pEntity (&objRef, AcDb::kForRead) ;
		AcDbObject *pObj =(AcDbObject *)pEntity.object () ;
		es =m_objRef.acquire (pObj) ;
	}
	mnIndex =0 ;
	return (es == Acad::eOk ? S_OK : E_FAIL) ;
}

//-----------------------------------------------------------------------------
HRESULT CAcadPieSectorsEnum::Next (ULONG celt, VARIANT *pVal, ULONG *pCeltFetched) {
	if ( pVal == NULL )
		return (E_POINTER) ;

	try {
		for ( ULONG l =0 ; l < celt ; l++ )
			VariantInit (&pVal [l]) ;
		if ( pCeltFetched != NULL )
			*pCeltFetched =0 ;

		AXObjectDocLock (m_objRef.objectId ()) ;
		AcAxObjectRefPtr<AsdkPie> pEntity (&m_objRef, AcDb::kForRead) ;
		eOkThrow (pEntity.openStatus ()) ;

		long cElements =static_cast<long>(pEntity->get_SectorCount ()) ;
		//- Retrieve the next celt elements.
		long l1 ;
		ULONG l2 ;
		for ( l1 =mnIndex, l2 =0 ; l1 < cElements && l2 < celt ; l1++, l2++ ) {
			IUnknown *pUnk =AcAxGetOleLinkManager ()->GetIUnknown (pEntity.object ()) ;
			CComQIPtr<IAcadPie> pLinDim (pUnk) ;
			//pUnk->Release () ;
			CComPtr<IAcadPieSectors> pSectors ;
			HRESULT hr =pLinDim->get_Sectors (&pSectors) ;
			if ( FAILED ( hr ) )
				throw hr ;
			pUnk =NULL ;
			hr =pSectors->get_Item (CComVariant (l1), &pUnk) ;
			CComQIPtr<IAcadPieSector> pSector (pUnk) ;
			pUnk->Release () ;
			if ( FAILED ( hr ) )
				throw hr ;
			hr =VariantCopy (&pVal [l2], (VARIANT *)&_variant_t (pSector.p)) ;
			if ( FAILED( hr ) )
				throw hr ;
		}
		//- Set count of elements retrieved.
		if ( pCeltFetched != NULL )
			*pCeltFetched =l2 ;
		mnIndex =l1 ;
		return ((l2 < celt) ? ResultFromScode (S_FALSE) : NOERROR) ;

	} catch (const Acad::ErrorStatus) {
		for ( ULONG l =0 ; l < celt ; l++ )
			VariantClear (&pVal [l]) ;
		return (E_FAIL) ;
	} catch (const HRESULT hr) {
		for ( ULONG l =0 ; l < celt ; l++ )
			VariantClear (&pVal [l]) ;
		return (hr) ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
HRESULT CAcadPieSectorsEnum::Skip (ULONG celt) {
	mnIndex +=celt ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
HRESULT CAcadPieSectorsEnum::Reset () {
	mnIndex =0 ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
HRESULT CAcadPieSectorsEnum::Clone (IEnumVARIANT **ppEnum) {
	CComObject<CAcadPieSectorsEnum> *ppEnumVar ;
	HRESULT hr =CComObject<CAcadPieSectorsEnum>::CreateInstance (&ppEnumVar) ;
	if ( FAILED( hr ) )
		return (E_OUTOFMEMORY) ;
	ppEnumVar->AddRef () ;
	hr =ppEnumVar->Init (m_objRef) ;
	if ( SUCCEEDED( hr ) )
		hr =ppEnumVar->QueryInterface (IID_IUnknown, (void **)ppEnum) ;
	if ( FAILED( hr ) ) {
		ppEnumVar->Release () ;
		hr =E_NOINTERFACE ;
	}
	ppEnumVar->mnIndex =mnIndex ;
	ppEnumVar->Release () ;
	return (S_OK) ;
}

