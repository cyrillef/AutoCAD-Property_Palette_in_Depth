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
	//- IAcadSpline : IAcadEntity
	STDMETHOD(get_NumberOfControlPoints) (long *numCtrlPoints) {
		return (mpInnerObject->get_NumberOfControlPoints (numCtrlPoints)) ;
	}

	STDMETHOD(get_ControlPoints) (VARIANT *controlPoint) {
		return (mpInnerObject->get_ControlPoints (controlPoint)) ;
	}

	STDMETHOD(put_ControlPoints) (VARIANT controlPoint) {
		return (mpInnerObject->put_ControlPoints (controlPoint)) ;
	}

	STDMETHOD(get_NumberOfFitPoints) (long *numFitPoints) {
		return (mpInnerObject->get_NumberOfFitPoints (numFitPoints)) ;
	}

	STDMETHOD(get_FitPoints) (VARIANT *fitPoint) {
		return (mpInnerObject->get_FitPoints (fitPoint)) ;
	}

	STDMETHOD(put_FitPoints) (VARIANT fitPoint) {
		return (mpInnerObject->put_FitPoints (fitPoint)) ;
	}

	STDMETHOD(get_Degree) (long *Degree) {
		return (mpInnerObject->get_Degree (Degree)) ;
	}

	STDMETHOD(get_Closed) (VARIANT_BOOL *fClose) {
		return (mpInnerObject->get_Closed (fClose)) ;
	}

	STDMETHOD(get_IsPlanar) (VARIANT_BOOL *fPlanar) {
		return (mpInnerObject->get_IsPlanar (fPlanar)) ;
	}

	STDMETHOD(get_IsRational) (VARIANT_BOOL *fRational) {
		return (mpInnerObject->get_IsRational (fRational)) ;
	}

	STDMETHOD(get_IsPeriodic) (VARIANT_BOOL *fPeriodic) {
		return (mpInnerObject->get_IsPeriodic (fPeriodic)) ;
	}

	STDMETHOD(get_StartTangent) (VARIANT *StartTangent) {
		return (mpInnerObject->get_StartTangent (StartTangent)) ;
	}

	STDMETHOD(put_StartTangent) (VARIANT StartTangent) {
		return (mpInnerObject->put_StartTangent (StartTangent)) ;
	}

	STDMETHOD(get_EndTangent) (VARIANT *EndTangent) {
		return (mpInnerObject->get_EndTangent (EndTangent)) ;
	}

	STDMETHOD(put_EndTangent) (VARIANT EndTangent) {
		return (mpInnerObject->put_EndTangent (EndTangent)) ;
	}

	STDMETHOD(get_FitTolerance) (double *fitTol) {
		return (mpInnerObject->get_FitTolerance (fitTol)) ;
	}

	STDMETHOD(put_FitTolerance) (double fitTol) {
		return (mpInnerObject->put_FitTolerance (fitTol)) ;
	}

	STDMETHOD(get_Area) (double *Area) {
		return (mpInnerObject->get_Area (Area)) ;
	}

	STDMETHOD(SetControlPoint) (int Index, VARIANT controlPoint) {
		return (mpInnerObject->SetControlPoint (controlPoint)) ;
	}

	STDMETHOD(GetControlPoint) (int Index, VARIANT *controlPoint) {
		return (mpInnerObject->GetControlPoint (controlPoint)) ;
	}

	STDMETHOD(SetFitPoint) (int Index, VARIANT fitPoint) {
		return (mpInnerObject->SetFitPoint (fitPoint)) ;
	}

	STDMETHOD(GetFitPoint) (int Index, VARIANT *fitPoint) {
		return (mpInnerObject->GetFitPoint (fitPoint)) ;
	}

	STDMETHOD(SetWeight) (int Index, double weight) {
		return (mpInnerObject->SetWeight (Index, weight)) ;
	}

	STDMETHOD(GetWeight) (int Index, double *weight) {
		return (mpInnerObject->GetWeight (Index, weight)) ;
	}

	STDMETHOD(AddFitPoint) (int Index, VARIANT fitPoint) {
		return (mpInnerObject->AddFitPoint (Index, fitPoint)) ;
	}

	STDMETHOD(DeleteFitPoint) (int Index) {
		return (mpInnerObject->DeleteFitPoint (Index)) ;
	}

	STDMETHOD(ElevateOrder) (int Order) {
		return (mpInnerObject->ElevateOrder (Order)) ;
	}

	STDMETHOD(Offset) (double Distance, VARIANT *pOffsetCurves) {
		return (mpInnerObject->Offset (Distance, pOffsetCurves)) ;
	}

	STDMETHOD(PurgeFitData) () {
		return (mpInnerObject->PurgeFitData ()) ;
	}

	STDMETHOD(Reverse) () {
		return (mpInnerObject->Reverse ()) ;
	}

	STDMETHOD(get_Knots) (VARIANT *KnotValues) {
		return (mpInnerObject->get_Knots (KnotValues)) ;
	}

	STDMETHOD(put_Knots) (VARIANT KnotValues) {
		return (mpInnerObject->put_Knots (KnotValues)) ;
	}

	STDMETHOD(get_Weights) (VARIANT *WeightValues) {
		return (mpInnerObject->get_Weights (WeightValues)) ;
	}

	STDMETHOD(put_Weights) (VARIANT WeightValues) {
		return (mpInnerObject->put_Weights (WeightValues)) ;
	}

} ;
