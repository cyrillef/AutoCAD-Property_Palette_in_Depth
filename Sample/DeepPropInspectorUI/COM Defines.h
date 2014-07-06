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
//----- COM Defines.h :
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#define CHECKOUTPARAMVAL(x,b) \
	if ( x == NULL ) \
		return (b)

#define CHECKOUTPARAM(x) \
	CHECKOUTPARAMVAL(x, E_FAIL)

#define RETURNONFAILED(x) \
	{ \
		HRESULT hr =x ; \
		if ( FAILED( hr ) ) \
			return (hr) ; \
	}

#define RETURNVALONFAILED(x,b) \
	if ( FAILED( x ) ) \
		return (b) ;

#define THROWFAILED(x) \
	{ \
		HRESULT hr =x ; \
		if ( FAILED( hr ) ) \
			throw hr ; \
	}

#define CHECKPOINTER(x) \
	if ( x.p == NULL ) \
		return (E_FAIL) ;

#define CHECKPOINTERRETURNVAL(x,b) \
	if ( x.p == NULL ) \
		return (b) ;

//-----------------------------------------------------------------------------
#define AXObjectDocLock(objId) \
	AcAxDocLock docLock (objId, AcAxDocLock::kNormal) ; \
	if ( (!objId.isNull () && docLock.lockStatus () != Acad::eOk) || (objId.isNull () && docLock.lockStatus () != Acad::eNoDatabase) ) \
		throw docLock.lockStatus ()

#define AXDatabaseDocLock(pDb) \
	AcAxDocLock docLock (pDb, AcAxDocLock::kNormal) ; \
	if ( docLock.lockStatus () != Acad::eOk ) \
		throw docLock.lockStatus ()

//-----------------------------------------------------------------------------
#define BEGIN_PROP_GETPUT_OBJREF(REF,CLASS,OPENMODE) \
	try { \
		AXObjectDocLock (REF.objectId ()) ; \
		AcAxObjectRefPtr<CLASS> pEntity (&REF, OPENMODE) ; \
		eOkThrow (pEntity.openStatus ())

#define BEGIN_PROP_GETPUT(CLASS,OPENMODE) \
	BEGIN_PROP_GETPUT_OBJREF(m_objRef,CLASS,OPENMODE)

#define END_PROP_GETPUT(INTERFACEID) \
	} catch (const Acad::ErrorStatus) { \
		return (Error (L"Failed to set Entity Property", INTERFACEID, E_FAIL)) ; \
	} catch (const HRESULT hr) { \
		return (Error (L"Invalid argument.", INTERFACEID, hr)) ; \
	}

//-----------------------------------------------------------------------------
#define BEGIN_DYNPROP_GETPUT(CLASS,idObj,OPENMODE) \
	try { \
		AXObjectDocLock (idObj) ; \
		AcDbObjectPointer<CLASS> pEntity (idObj, OPENMODE) ; \
		eOkThrow (pEntity.openStatus ()) ;

#define END_DYNPROP_GETPUT(INTERFACEID) \
	END_PROP_GETPUT(INTERFACEID)
