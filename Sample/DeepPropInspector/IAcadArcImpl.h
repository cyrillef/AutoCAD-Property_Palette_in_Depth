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
class ATL_NO_VTABLE IAcadArcImpl : 
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, IAcadArc, pclsid, &CLSID_AcadArc, piid, plibid>
{
public:
	//- IAcadArc
	STDMETHOD(get_StartPoint) (VARIANT *StartPoint) {
		return (mpInnerObject->get_StartPoint (StartPoint)) ;
	}

	STDMETHOD(get_Center) (VARIANT *CenterPoint) {
		return (mpInnerObject->get_Center (CenterPoint)) ;
	}

	STDMETHOD(put_Center) (VARIANT CenterPoint) {
		return (mpInnerObject->put_Center (CenterPoint)) ;
	}

	STDMETHOD(get_EndPoint) (VARIANT *EndPoint) {
		return (mpInnerObject->get_EndPoint (EndPoint)) ;
	}

	STDMETHOD(get_Radius) (double *Radius) {
		return (mpInnerObject->get_Radius (Radius)) ;
	}

	STDMETHOD(put_Radius) (double Radius) {
		return (mpInnerObject->put_Radius (Radius)) ;
	}

	STDMETHOD(get_StartAngle) (ACAD_ANGLE *Angle) {
		return (mpInnerObject->get_StartAngle (Angle)) ;
	}

	STDMETHOD(put_StartAngle) (ACAD_ANGLE Angle) {
		return (mpInnerObject->put_StartAngle (Angle)) ;
	}

	STDMETHOD(get_EndAngle) (ACAD_ANGLE *Angle) {
		return (mpInnerObject->get_EndAngle (Angle)) ;
	}

	STDMETHOD(put_EndAngle) (ACAD_ANGLE Angle) {
		return (mpInnerObject->put_EndAngle (Angle)) ;
	}

	STDMETHOD(get_TotalAngle) (ACAD_ANGLE *TotalAngle) {
		return (mpInnerObject->get_TotalAngle (TotalAngle)) ;
	}

	STDMETHOD(get_ArcLength) (ACAD_DISTANCE *ArcLength) {
		return (mpInnerObject->get_ArcLength (ArcLength)) ;
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

	STDMETHOD(get_Area) (double *Area) {
		return (mpInnerObject->get_Area (Area)) ;
	}

	STDMETHOD(get_Normal) (VARIANT *Normal) {
		return (mpInnerObject->get_Normal (Normal)) ;
	}

	STDMETHOD(put_Normal) (VARIANT Normal) {
		return (mpInnerObject->put_Normal (Normal)) ;
	}
} ;
