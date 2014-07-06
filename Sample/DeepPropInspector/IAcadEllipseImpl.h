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
class ATL_NO_VTABLE IAcadEllipseImpl : 
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, IAcadEllipse, pclsid, &CLSID_AcadEllipse, piid, plibid>
{
public:
	//- IAcadEllipse
	STDMETHOD(get_StartPoint) (VARIANT *StartPoint) {
		return (mpInnerObject->get_StartPoint (StartPoint)) ;
	}

	STDMETHOD(get_Center) (VARIANT *Center) {
		return (mpInnerObject->get_Center (Center)) ;
	}

	STDMETHOD(put_Center) (VARIANT Center) {
		return (mpInnerObject->put_Center (Center)) ;
	}

	STDMETHOD(get_EndPoint) (VARIANT *EndPoint) {
		return (mpInnerObject->get_EndPoint (visibility)) ;
	}

	STDMETHOD(get_MajorRadius) (double *MajorRadius) {
		return (mpInnerObject->get_MajorRadius (MajorRadius)) ;
	}

	STDMETHOD(put_MajorRadius) (double MajorRadius) {
		return (mpInnerObject->put_MajorRadius (MajorRadius)) ;
	}

	STDMETHOD(get_MinorRadius) (double *MinorRadius) {
		return (mpInnerObject->get_MinorRadius (MinorRadius)) ;
	}

	STDMETHOD(put_MinorRadius) (double MinorRadius) {
		return (mpInnerObject->put_MinorRadius (MinorRadius)) ;
	}

	STDMETHOD(get_RadiusRatio) (double *RadiusRatio) {
		return (mpInnerObject->get_RadiusRatio (RadiusRatio)) ;
	}

	STDMETHOD(put_RadiusRatio) (double RadiusRatio) {
		return (mpInnerObject->put_RadiusRatio (RadiusRatio)) ;
	}

	STDMETHOD(get_StartAngle) (ACAD_ANGLE *StartAngle) {
		return (mpInnerObject->get_StartAngle (StartAngle)) ;
	}

	STDMETHOD(put_StartAngle) (ACAD_ANGLE StartAngle) {
		return (mpInnerObject->put_StartAngle (StartAngle)) ;
	}

	STDMETHOD(get_EndAngle) (ACAD_ANGLE *EndAngle) {
		return (mpInnerObject->get_EndAngle (EndAngle)) ;
	}

	STDMETHOD(put_EndAngle) (ACAD_ANGLE EndAngle) {
		return (mpInnerObject->put_EndAngle (EndAngle)) ;
	}

	STDMETHOD(get_StartParameter) (double *StartParameter) {
		return (mpInnerObject->get_StartParameter (StartParameter)) ;
	}

	STDMETHOD(put_StartParameter) (double StartParameter) {
		return (mpInnerObject->put_StartParameter (StartParameter)) ;
	}

	STDMETHOD(get_EndParameter) (double *EndParameter) {
		return (mpInnerObject->get_EndParameter (EndParameter)) ;
	}

	STDMETHOD(put_EndParameter) (double EndParameter) {
		return (mpInnerObject->put_EndParameter (EndParameter)) ;
	}

	STDMETHOD(get_MajorAxis) (VARIANT *MajorAxis) {
		return (mpInnerObject->get_MajorAxis (MajorAxis)) ;
	}

	STDMETHOD(put_MajorAxis) (VARIANT MajorAxis) {
		return (mpInnerObject->put_MajorAxis (MajorAxis)) ;
	}

	STDMETHOD(get_MinorAxis) (VARIANT *MinorAxis) {
		return (mpInnerObject->get_MinorAxis (MinorAxis)) ;
	}

	STDMETHOD(get_Normal) (VARIANT *Normal) {
		return (mpInnerObject->get_Normal (Normal)) ;
	}

	STDMETHOD(put_Normal) (VARIANT Normal) {
		return (mpInnerObject->put_Normal (Normal)) ;
	}

	STDMETHOD(get_Area) (double *Area) {
		return (mpInnerObject->get_Area (Area)) ;
	}

	STDMETHOD(Offset) (double Distance, VARIANT *pOffsetCurves) {
		return (mpInnerObject->Offset (Distance, pOffsetCurves)) ;
	}

} ;