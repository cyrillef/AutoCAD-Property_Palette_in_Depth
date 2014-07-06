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
//----- IAcadMTextImpl.h : Declaration of the IAcadCircleImpl
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
class ATL_NO_VTABLE IAcadMTextImpl : 
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, IAcadMText, pclsid, &CLSID_AcadMText, piid, plibid>
{
public:
	//- IAcadMText
	STDMETHOD(get_TextString) (BSTR *bstrText) {
		return (mpInnerObject->get_TextString (bstrText)) ;
	}

	STDMETHOD(put_TextString) (BSTR bstrText) {
		return (mpInnerObject->put_TextString (bstrText)) ;
	}

	STDMETHOD(get_StyleName) (BSTR *bstrName) {
		return (mpInnerObject->get_StyleName (bstrName)) ;
	}

	STDMETHOD(put_StyleName) (BSTR bstrName) {
		return (mpInnerObject->put_StyleName (bstrName)) ;
	}

	STDMETHOD(get_AttachmentPoint) (AcAttachmentPoint *attPoint) {
		return (mpInnerObject->get_AttachmentPoint (attPoint)) ;
	}

	STDMETHOD(put_AttachmentPoint) (AcAttachmentPoint attPoint) {
		return (mpInnerObject->put_AttachmentPoint (attPoint)) ;
	}

	STDMETHOD(get_DrawingDirection) (AcDrawingDirection *drawDir) {
		return (mpInnerObject->get_DrawingDirection (drawDir)) ;
	}

	STDMETHOD(put_DrawingDirection) (AcDrawingDirection drawDir) {
		return (mpInnerObject->put_DrawingDirection (drawDir)) ;
	}

	STDMETHOD(get_Width) (double *width) {
		return (mpInnerObject->get_Width (width)) ;
	}

	STDMETHOD(put_Width) (double width) {
		return (mpInnerObject->put_Width (width)) ;
	}

	STDMETHOD(get_Height) (double *height) {
		return (mpInnerObject->get_Height (height)) ;
	}

	STDMETHOD(put_Height) (double height) {
		return (mpInnerObject->put_Height (height)) ;
	}

	STDMETHOD(get_Rotation) (ACAD_ANGLE *rotAngle) {
		return (mpInnerObject->get_Rotation (rotAngle)) ;
	}

	STDMETHOD(put_Rotation) (ACAD_ANGLE rotAngle) {
		return (mpInnerObject->put_Rotation (rotAngle)) ;
	}

	STDMETHOD(get_InsertionPoint) (VARIANT *insPoint) {
		return (mpInnerObject->get_InsertionPoint (insPoint)) ;
	}

	STDMETHOD(put_InsertionPoint) (VARIANT insPoint) {
		return (mpInnerObject->put_InsertionPoint (insPoint)) ;
	}

	STDMETHOD(get_Normal) (VARIANT *normal) {
		return (mpInnerObject->get_Normal (normal)) ;
	}

	STDMETHOD(put_Normal) (VARIANT normal) {
		return (mpInnerObject->put_Normal (normal)) ;
	}

	STDMETHOD(get_LineSpacingFactor) (double *Factor) {
		return (mpInnerObject->get_LineSpacingFactor (Factor)) ;
	}

	STDMETHOD(put_LineSpacingFactor) (double Factor) {
		return (mpInnerObject->put_LineSpacingFactor (Factor)) ;
	}

	STDMETHOD(get_LineSpacingStyle) (AcLineSpacingStyle *Style) {
		return (mpInnerObject->get_LineSpacingStyle (Style)) ;
	}

	STDMETHOD(put_LineSpacingStyle) (AcLineSpacingStyle Style) {
		return (mpInnerObject->put_LineSpacingStyle (Style)) ;
	}

	STDMETHOD(get_LineSpacingDistance) (double *Value) {
		return (mpInnerObject->get_LineSpacingDistance (Value)) ;
	}

	STDMETHOD(put_LineSpacingDistance) (double Value) {
		return (mpInnerObject->put_LineSpacingDistance (Value)) ;
	}

} ;
