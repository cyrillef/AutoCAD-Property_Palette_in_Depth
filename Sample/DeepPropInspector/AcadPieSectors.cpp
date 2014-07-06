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
//- AcadPieSectors.cpp : Implementation of CAcadPieSectors
//-----------------------------------------------------------------------------
#include "stdafx.h"

#include "AsdkPie.h"

#include "AcadPieSectors.h"
#include "AcadPieSector.h"
#include "AcadPieSectorsEnum.h"
#include ".\acadpiesectors.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSectors::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID* arr[] ={ &IID_IAcadPieSectors } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
CAcadPieSectors::CAcadPieSectors () : m_objRef() {
}

CAcadPieSectors::~CAcadPieSectors () {
	//- This reference object is managed by the root object, not us !
	if ( !m_objRef.isNull () ) {
		AcDbObjectId objId ;
		AcDbObject *pObj ;
		m_objRef.release (objId, pObj) ;
	}
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSectors::Init (AcDbObjectId id, AsdkPie *pPie) {
	Acad::ErrorStatus es =m_objRef.acquire (id) ;
	if ( es != Acad::eOk ) {
		AcDbObject *pObj =(AcDbObject *)pPie ;
		es =m_objRef.acquire (pObj) ;
	}
	return (es == Acad::eOk ? S_OK : E_FAIL) ;
}

STDMETHODIMP CAcadPieSectors::Init (AcAxObjectRef &objRef) {
	Acad::ErrorStatus es =m_objRef.acquire (objRef.objectId ()) ;
	if ( es != Acad::eOk ) {
		AcAxObjectRefPtr<AsdkPie> pEntity (&objRef, AcDb::kForRead) ;
		AcDbObject *pObj =(AcDbObject *)pEntity.object () ;
		es =m_objRef.acquire (pObj) ;
	}
	return (es == Acad::eOk ? S_OK : E_FAIL) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSectors::get_Count (long *pVal) {
	CHECKOUTPARAM( pVal ) ;
	BEGIN_PROP_GETPUT_OBJREF(m_objRef, AsdkPie, AcDb::kForRead) ;
	*pVal =static_cast<long>(pEntity->get_SectorCount ()) ;
	END_PROP_GETPUT(IID_IAcadPieSectors) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPieSectors::get_Item (VARIANT vIndex, IUnknown **ppUnk) {
	CHECKOUTPARAM( ppUnk ) ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	switch ( V_VT(&vIndex) ) {
		case VT_I4: {
			AsdkPieSector *pSector =pEntity->get_Sector (static_cast<int>(vIndex.lVal)) ;
			CHECKOUTPARAMVAL( pSector, E_FAIL ) ;
			PieSectorMapIter iter =pieSectorPointers.find (pSector) ;
			if ( iter == pieSectorPointers.end () ) {
				CComObject<CAcadPieSector> *ppSector =NULL ;
				CComObject<CAcadPieSector>::CreateInstance (&ppSector) ;
				ppSector->Init (m_objRef, pSector) ;
				ppSector->AddRef () ;
				ppSector->QueryInterface (IID_IUnknown, reinterpret_cast<void **>(ppUnk)) ;
				ppSector->Release () ;
			} else {
				CAcadPieSector *pSector =(*iter).second ;
				pSector->QueryInterface (IID_IUnknown, reinterpret_cast<void **>(ppUnk)) ;
			}
			break ;
		}
		default:
			throw E_INVALIDARG ;
			break ;
	}
	END_PROP_GETPUT(IID_IAcadPieSectors) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPieSectors::get__NewEnum (IUnknown **ppunkEnum) {
	CHECKOUTPARAM( ppunkEnum ) ;
	HRESULT hr =E_NOTIMPL ;
	*ppunkEnum =NULL ;

	//- Create new enumerator for items currently in collection and QI for IUnknown
	CComObject<CAcadPieSectorsEnum> *pEnum =NULL ;
	hr =CComObject<CAcadPieSectorsEnum>::CreateInstance (&pEnum) ;
	if ( FAILED( hr ) )
		hr =E_OUTOFMEMORY ;
	pEnum->AddRef () ;

	//- Initialize the enumerator object 
	hr =pEnum->Init (m_objRef) ;

	if ( SUCCEEDED( hr ) )
		hr =pEnum->QueryInterface (IID_IUnknown, (void **)ppunkEnum) ;
	if ( FAILED( hr ) )
		hr =E_NOINTERFACE ;
	pEnum->Release () ;
	return (hr) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSectors::AddSimpleSector (DOUBLE val, IAcadPieSector **ppVal) {
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForWrite) ;
	AsdkPieSector *pSector =pEntity->AppendData (val, AsdkPieSector::kNumber) ;
	PieSectorMapIter iter =pieSectorPointers.find (pSector) ;
	if ( iter == pieSectorPointers.end () ) {
		CComObject<CAcadPieSector> *ppSector =NULL ;
		CComObject<CAcadPieSector>::CreateInstance (&ppSector) ;
		ppSector->Init (pEntity->objectId (), pEntity.object (), pSector) ;
		ppSector->AddRef () ;
		ppSector->QueryInterface (IID_IAcadPieSector, reinterpret_cast<void **>(ppVal)) ;
		ppSector->Release () ;
	} else {
		CAcadPieSector *ppSector =(*iter).second ;
		//*ppVal =pSector ;
		ppSector->QueryInterface (IID_IAcadPieSector, reinterpret_cast<void **>(ppVal)) ;
	}
	END_PROP_GETPUT(IID_IAcadPieSectors) ;
	return (S_OK) ;
}
