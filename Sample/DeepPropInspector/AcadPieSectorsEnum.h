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
//- AcadPieSectorsEnum.h: Definition of the AcadPieSectorsEnum class
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"
#include "DeepPropInspector.h"

//-----------------------------------------------------------------------------
class CAcadPieSectorsEnum : 
	public IEnumVARIANT,
	public CComObjectRoot
{
protected:
	AcAxObjectRef m_objRef ;
	ULONG mnIndex ;

public:
	CAcadPieSectorsEnum () ;
	virtual ~CAcadPieSectorsEnum () ;

	DECLARE_NOT_AGGREGATABLE(CAcadPieSectorsEnum) 

	BEGIN_COM_MAP(CAcadPieSectorsEnum)
		COM_INTERFACE_ENTRY(IEnumVARIANT)
	END_COM_MAP()

public:
	//- IEnumUnknown
	STDMETHOD(Next) (ULONG celt, VARIANT *pVal, ULONG *pCeltFetched) ;
    STDMETHOD(Skip) (ULONG celt) ;
    STDMETHOD(Reset) () ;
	STDMETHOD(Clone) (IEnumVARIANT **ppEnum) ;

	//- Intialize the enumerator
	HRESULT Init (AcAxObjectRef &objRef) ;
} ;

//-----------------------------------------------------------------------------
//OBJECT_ENTRY_AUTO(__uuidof(AcadPieSectorsEnum), CAcadPieSectorsEnum)
