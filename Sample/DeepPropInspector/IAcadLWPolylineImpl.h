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
class ATL_NO_VTABLE IAcadCircleImpl : 
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, IAcadCircle, pclsid, &CLSID_AcadCircle, piid, plibid>
{
public:
	//- IAcadLWPolyline
	STDMETHOD(get_Coordinates) (VARIANT *Coordinates) {
		return (mpInnerObject->get_Coordinates (Coordinates)) ;
	}

	STDMETHOD(put_Coordinates) (VARIANT Coordinates) {
		return (mpInnerObject->get_Coordinates (Coordinates)) ;
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

	STDMETHOD(AddVertex) (int Index, VARIANT vertex) {
		return (mpInnerObject->AddVertex (Index, vertex)) ;
	}

	STDMETHOD(Explode) (VARIANT *pArrayObjs) {
		return (mpInnerObject->Explode (pArrayObjs)) ;
	}

	STDMETHOD(GetBulge) (int Index, double *bulge) {
		return (mpInnerObject->GetBulge (Index, bulge)) ;
	}

	STDMETHOD(SetBulge) (int Index, double bulge) {
		return (mpInnerObject->SetBulge (Index, bulge)) ;
	}

	STDMETHOD(GetWidth) (int Index, double *StartWidth, double *EndWidth) {
		return (mpInnerObject->GetWidth (Index, EndWidth)) ;
	}

	STDMETHOD(SetWidth) (int Index, double StartWidth, double EndWidth) {
		return (mpInnerObject->SetWidth (Index, EndWidth)) ;
	}

	STDMETHOD(get_ConstantWidth) (double *Width) {
		return (mpInnerObject->get_ConstantWidth (Width)) ;
	}

	STDMETHOD(put_ConstantWidth) (double Width) {
		return (mpInnerObject->put_ConstantWidth (Width)) ;
	}

	STDMETHOD(Offset) (double Distance, VARIANT *pOffsetCurves) {
		return (mpInnerObject->Offset (Distance, pOffsetCurves)) ;
	}

	STDMETHOD(get_Elevation) (double *Elevation) {
		return (mpInnerObject->get_Elevation (Elevation)) ;
	}

	STDMETHOD(put_Elevation) (double Elevation) {
		return (mpInnerObject->put_Elevation (Elevation)) ;
	}

	STDMETHOD(get_Area) (double *Area) {
		return (mpInnerObject->get_Area (Area)) ;
	}

	STDMETHOD(get_Coordinate) (int Index, VARIANT *pVal) {
		return (mpInnerObject->get_Coordinate (Index, pVal)) ;
	}

	STDMETHOD(put_Coordinate) (int Index, VARIANT pVal) {
		return (mpInnerObject->put_Coordinate (Index, pVal)) ;
	}

	STDMETHOD(get_Closed) (VARIANT_BOOL *fClose) {
		return (mpInnerObject->get_Closed (fClose)) ;
	}

	STDMETHOD(put_Closed) (VARIANT_BOOL fClose) {
		return (mpInnerObject->put_Closed (fClose)) ;
	}

	STDMETHOD(get_LinetypeGeneration) (VARIANT_BOOL *bLinetypeGen) {
		return (mpInnerObject->get_LinetypeGeneration (bLinetypeGen)) ;
	}

	STDMETHOD(put_LinetypeGeneration) (VARIANT_BOOL bLinetypeGen) {
		return (mpInnerObject->put_LinetypeGeneration (bLinetypeGen)) ;
	}

	STDMETHOD(get_Length) (double *Length) {
		return (mpInnerObject->get_Length (Length)) ;
	}

} ;