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
	//- IAcadCircle
	STDMETHOD(get_Center) (ACAD_POINT *centerPoint) {
		//CHECKOUTPARAM( centerPoint ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//AcAxPoint3d pt3d =pEntity->center () ;
		//pt3d.setVariant (centerPoint) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Center (centerPoint)) ;
	}

	STDMETHOD(put_Center) (ACAD_POINT centerPoint) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//AcAxPoint3d pt3d (centerPoint) ;
		//pEntity->setCenter (pt3d) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Center (centerPoint)) ;
	}

	STDMETHOD(get_Radius) (double *radius) {
		//CHECKOUTPARAM( radius ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//*radius =pEntity->radius () ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Radius (radius)) ;
	}

	STDMETHOD(put_Radius) (double radius) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//pEntity->setRadius (radius) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Radius (radius)) ;
	}

	STDMETHOD(get_Diameter) (double *diameter) {
		//CHECKOUTPARAM( diameter ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//*diameter =2 * pEntity->radius () ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Diameter (diameter)) ;
	}

	STDMETHOD(put_Diameter) (double diameter) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//pEntity->setRadius (diameter / 2) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Diameter (diameter)) ;
	}

	STDMETHOD(get_Circumference) (double *circumference) {
		//CHECKOUTPARAM( circumference ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//*circumference =2 * kPi * pEntity->radius () ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Circumference (circumference)) ;
	}

	STDMETHOD(put_Circumference) (double circumference) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//pEntity->setRadius (circumference / (2 * kPi)) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Circumference (circumference)) ;
	}

	STDMETHOD(get_Area) (double *area) {
		//CHECKOUTPARAM( area ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//*area =kPi * pow (pEntity->radius (), 2) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Area (area)) ;
	}

	STDMETHOD(put_Area) (double area) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//pEntity->setRadius (sqrt (area / kPi)) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Area (area)) ;
	}

	STDMETHOD(get_Normal) (VARIANT *normal) {
		//CHECKOUTPARAM( normal ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//AcAxPoint3d pt3d =pEntity->normal () ;
		//pt3d.setVariant (normal) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Normal (normal)) ;
	}

	STDMETHOD(put_Normal) (VARIANT normal) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//AcAxPoint3d pt3d (normal) ;
		//pEntity->setNormal (pt3d.asVector ()) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Normal (normal)) ;
	}

	STDMETHOD(get_Thickness) (double *thickness) {
		//CHECKOUTPARAM( thickness ) ;
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForRead) ;
		//*thickness =pEntity->thickness () ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->get_Thickness (thickness)) ;
	}

	STDMETHOD(put_Thickness) (double thickness) {
		//BEGIN_PROP_GETPUT(rxClass, AcDb::kForWrite) ;
		//pEntity->setThickness (thickness) ;
		//xEND_PROP_GETPUT(*piid) ;
		//return (S_OK) ;
		return (mpInnerObject->put_Thickness (thickness)) ;
	}

	STDMETHOD(Offset) (double Distance, VARIANT *pOffsetCurves) {
		//return (E_NOTIMPL) ;
		return (mpInnerObject->Offset (Distance, pOffsetCurves)) ;
	}

} ;
