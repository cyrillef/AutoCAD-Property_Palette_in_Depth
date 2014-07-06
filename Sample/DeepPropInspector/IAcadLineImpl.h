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
class ATL_NO_VTABLE IAcadLineImpl : 
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, IAcadLine, pclsid, &CLSID_AcadLine, piid, plibid>
{
public:
	//- IAcadLine
	STDMETHOD(get_StartPoint) (VARIANT *StartPoint) {
		return (mpInnerObject->get_StartPoint (StartPoint)) ;
	}

	STDMETHOD(put_StartPoint) (VARIANT StartPoint) {
		return (mpInnerObject->put_StartPoint (StartPoint)) ;
	}

	STDMETHOD(get_EndPoint) (VARIANT *EndPoint) {
		return (mpInnerObject->get_EndPoint (EndPoint)) ;
	}

	STDMETHOD(put_EndPoint) (VARIANT EndPoint) {
		return (mpInnerObject->put_EndPoint (EndPoint)) ;
	}

	STDMETHOD(get_Normal) (VARIANT *Normal) {
		return (mpInnerObject->get_Normal (Normal)) ;
	}

	STDMETHOD(put_Normal) (VARIANT Normal) {
		return (mpInnerObject->put_Normal (Normal)) ;
	}

	STDMETHOD(get_Thickness) (double *Thickness) {
		return (mpInnerObject->get_Thickness (Thickness)) ;
	}

	STDMETHOD(put_Thickness) (double Thickness) {
		return (mpInnerObject->put_Thickness (Thickness)) ;
	}

	STDMETHOD(Offset) (double Distance, VARIANT *pOffsetCurves) {
		return (mpInnerObject->Offset (Distance, pOffsetCurves)) ;
	}

	STDMETHOD(get_Delta) (VARIANT *Delta) {
		return (mpInnerObject->get_Delta (Delta)) ;
	}

	STDMETHOD(get_Length) (double *Length) {
		return (mpInnerObject->get_Length (Length)) ;
	}

	STDMETHOD(get_Angle) (ACAD_ANGLE *Angle) {
		return (mpInnerObject->get_Angle (Angle)) ;
	}

} ;