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
//----- IAcadCircleImpl.h : Declaration of the IAcadCircleImpl
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#include "resource.h"
#include "DeepPropInspector.h"
#include "IBaseObjectImpl.h"

//-----------------------------------------------------------------------------
template <
	class T, class rxClass, class interfaceClass,
	const CLSID *pclsid, const IID *piid =&__uuidof (interfaceClass),
	const GUID *plibid =&CAtlModule::m_libid
>
class ATL_NO_VTABLE IAcad3DFaceImpl : 
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, IAcad3DFace, pclsid, &CLSID_Acad3DFace, piid, plibid>
{
public:
	//- IAcad3DFace
	STDMETHOD(get_Coordinates) (VARIANT *corners) {
		return (mpInnerObject->get_Coordinates (corners)) ;
	}

	STDMETHOD (put_Coordinates) (VARIANT corners) {
		return (mpInnerObject->put_Coordinates (corners)) ;
	}

	STDMETHOD(get_VisibilityEdge1) (VARIANT_BOOL *visibility) {
		return (mpInnerObject->put_VisibilityEdge1 (visibility)) ;
	}

	STDMETHOD(put_VisibilityEdge1) (VARIANT_BOOL visibility) {
		return (mpInnerObject->put_VisibilityEdge1 (visibility)) ;
	}

	STDMETHOD(get_VisibilityEdge2) (VARIANT_BOOL *visibility) {
		return (mpInnerObject->get_VisibilityEdge2 (visibility)) ;
	}

	STDMETHOD(put_VisibilityEdge2) (VARIANT_BOOL visibility) {
		return (mpInnerObject->get_VisibilityEdge2 (visibility)) ;
	}

	STDMETHOD(get_VisibilityEdge3) (VARIANT_BOOL *visibility ) {
		return (mpInnerObject->put_VisibilityEdge3 (visibility)) ;
	}

	STDMETHOD(put_VisibilityEdge3) (VARIANT_BOOL visibility) {
		return (mpInnerObject->put_VisibilityEdge3 (visibility)) ;
	}

	STDMETHOD(get_VisibilityEdge4) (VARIANT_BOOL *visibility) {
		return (mpInnerObject->put_VisibilityEdge4 (visibility)) ;
	}

	STDMETHOD(put_VisibilityEdge4) (VARIANT_BOOL visibility) {
		return (mpInnerObject->put_VisibilityEdge4 (visibility)) ;
	}

	STDMETHOD(GetInvisibleEdge) (int Index, VARIANT_BOOL *bVisible) {
		return (mpInnerObject->GetInvisibleEdge (Index, bVisible)) ;
	}

	STDMETHOD(SetInvisibleEdge) (int Index, VARIANT_BOOL State) {
		return (mpInnerObject->SetInvisibleEdge (Index, State)) ;
	}

	STDMETHOD(get_Coordinate) (int Index, VARIANT *pVal) {
		return (mpInnerObject->get_Coordinate (Index, pVal)) ;
	}

	STDMETHOD(put_Coordinate) (int Index, VARIANT newVal) {
		return (mpInnerObject->put_Coordinate (Index, newVal)) ;
	}
} ;
