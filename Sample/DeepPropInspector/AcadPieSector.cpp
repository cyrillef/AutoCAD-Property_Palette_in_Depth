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
//- AcadPieSector.cpp : Implementation of CAcadPieSector
//-----------------------------------------------------------------------------
#include "stdafx.h"

#include "AcadPieSector.h"
#include ".\acadpiesector.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSector::InterfaceSupportsErrorInfo (REFIID riid) {
	static const IID* arr[] ={ &IID_IAcadPieSector } ;
	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ ) {
		if (InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}
	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
PieSectorMap pieSectorPointers ;

//-----------------------------------------------------------------------------
CAcadPieSector::CAcadPieSector () : m_objRef(), mpSector(NULL) {
}

CAcadPieSector::~CAcadPieSector () {
	//- Remove ourself from the interface cache list
	PieSectorMapIter iter =pieSectorPointers.find (mpSector) ;
	if ( iter != pieSectorPointers.end () )
		pieSectorPointers.erase (iter) ;

	//- This reference object is managed by the root object, not us !
	if ( !m_objRef.isNull () ) {
		AcDbObjectId objId ;
		AcDbObject *pObj ;
		m_objRef.release (objId, pObj) ;
	}
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSector::Init (AcDbObjectId id, AsdkPie *pPie, AsdkPieSector *pSector) {
	Acad::ErrorStatus es =m_objRef.acquire (id) ;
	if ( es != Acad::eOk ) {
		AcDbObject *pObj =(AcDbObject *)pPie ;
		es =m_objRef.acquire (pObj) ;
	}
	mpSector =pSector ;
	pieSectorPointers [mpSector] =this ;
	return (es == Acad::eOk ? S_OK : E_FAIL) ;
}

STDMETHODIMP CAcadPieSector::Init (AcAxObjectRef &objRef, AsdkPieSector *pSector) {
	Acad::ErrorStatus es =m_objRef.acquire (objRef.objectId ()) ;
	if ( es != Acad::eOk ) {
		AcAxObjectRefPtr<AsdkPie> pEntity (&objRef, AcDb::kForRead) ;
		AcDbObject *pObj =(AcDbObject *)pEntity.object () ;
		es =m_objRef.acquire (pObj) ;
	}
	mpSector =pSector ;
	pieSectorPointers [mpSector] =this ;
	return (es == Acad::eOk ? S_OK : E_FAIL) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSector::get_Exploded (VARIANT_BOOL *pVal) {
	CHECKOUTPARAM( pVal ) ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	*pVal =mpSector->isExploded () ? VARIANT_TRUE : VARIANT_FALSE ;
	END_PROP_GETPUT(IID_IAcadPieSector) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPieSector::put_Exploded (VARIANT_BOOL newVal) {
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForWrite) ;
	mpSector->put_Exploded (newVal == VARIANT_FALSE ? false : true) ;
	END_PROP_GETPUT(IID_IAcadPieSector) ;
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
STDMETHODIMP CAcadPieSector::get_TrueColor (IAcadAcCmColor **ppColor) {
	CHECKOUTPARAM( ppColor ) ;
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForRead) ;
	AcCmEntityColor color =mpSector->get_Color () ;
	CComPtr<IAcadAcCmColor> pColor ;
	pColor.CoCreateInstance (CLSID_AcadAcCmColor, NULL, CLSCTX_ALL) ;
	pColor->put_EntityColor (static_cast<long>(color.color ())) ;
	(*ppColor) =pColor.Detach () ;
	END_PROP_GETPUT(IID_IAcadPieSector) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPieSector::put_TrueColor (IAcadAcCmColor *pColor) {
	BEGIN_PROP_GETPUT(AsdkPie, AcDb::kForWrite) ;
	long lColor =0 ;
	pColor->get_EntityColor (&lColor) ;
	AcCmEntityColor color ;
	color.setColor (static_cast<const Adesk::UInt32>(lColor)) ;
	mpSector->put_Color (color) ;
	END_PROP_GETPUT(IID_IAcadPieSector) ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPieSector::get_Color (enum AcColor *pColor) {
	*pColor =acRed ;
	return (S_OK) ;
}

STDMETHODIMP CAcadPieSector::put_Color (enum AcColor color) {
	return (S_OK) ;
}
