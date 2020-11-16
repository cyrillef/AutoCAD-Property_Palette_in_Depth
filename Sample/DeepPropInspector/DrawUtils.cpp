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
//----- DrawUtils.cpp : 
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "DrawUtils.h"

//-----------------------------------------------------------------------------
SubEntityTraitsSaveContext::SubEntityTraitsSaveContext (AcGiWorldDraw *pWd) : mpWd(pWd) {
	assert( mpWd != NULL ) ;
	mColor =mpWd->subEntityTraits ().trueColor () ;
	mLw =mpWd->subEntityTraits ().lineWeight () ;
	mLt =mpWd->subEntityTraits ().lineTypeId () ;
	mLtScale =mpWd->subEntityTraits ().lineTypeScale () ;
	mThickness =mpWd->subEntityTraits ().thickness () ;
	mFillType =mpWd->subEntityTraits ().fillType () ;
	mLayer =mpWd->subEntityTraits ().layerId () ;
	mMaterial =mpWd->subEntityTraits ().materialId () ;
	AcDbObjectId tempId ;
	mPlotStyle =mpWd->subEntityTraits ().getPlotStyleNameId (tempId) ;
	mpMapper =mpWd->subEntityTraits ().mapper () ;
}

SubEntityTraitsSaveContext::~SubEntityTraitsSaveContext () {
	mpWd->subEntityTraits ().setTrueColor (mColor) ;
	mpWd->subEntityTraits ().setLineWeight (mLw) ;
	mpWd->subEntityTraits ().setLineType (mLt) ;
	mpWd->subEntityTraits ().setLineTypeScale (mLtScale) ;
	mpWd->subEntityTraits ().setThickness (mThickness) ;
	mpWd->subEntityTraits ().setFillType (mFillType) ;
	mpWd->subEntityTraits ().setLayer (mLayer) ;
	mpWd->subEntityTraits ().setMaterial (mMaterial) ;
	mpWd->subEntityTraits ().setPlotStyleName (mPlotStyle, AcDbObjectId::kNull) ;
	mpWd->subEntityTraits ().setMapper (mpMapper) ;
}

//-----------------------------------------------------------------------------
/*static*/
void DrawUtils::buildTextStyle (AcGiTextStyle &txtStyle, AcDbObjectId txtStyleId, AcDbObjectId dimStyleId) {
	AcDbDimStyleTableRecordPointer pDimStyle (dimStyleId, AcDb::kForRead) ;
	if ( !dimStyleId.isNull () && pDimStyle.openStatus () != Acad::eOk )
		return ;
	AcDbObjectId id =txtStyleId ;
	if ( id.isNull () && !dimStyleId.isNull () )
		id =pDimStyle->dimtxsty () ;
	fromAcDbTextStyle (txtStyle, id) ;
	if ( !dimStyleId.isNull () ) {
		//- AutoCAD dimensions ignores this, so do the same
		txtStyle.setUpsideDown (Adesk::kFalse) ;
		txtStyle.setBackward (Adesk::kFalse) ;
	}
	AcDbTextStyleTableRecordPointer pTxtStyle (id, AcDb::kForRead) ;
	if ( pTxtStyle.openStatus () != Acad::eOk )
		return ;
	if ( !dimStyleId.isNull () && pTxtStyle->textSize () == 0.0 )
		txtStyle.setTextSize (pDimStyle->dimtxt ()) ;
}

//-----------------------------------------------------------------------------
/*static*/
void DrawUtils::exchangeColor (AcCmEntityColor entColor, AcCmColor color) {
	
	entColor.setRGBM (color.getRGBM()) ;
}

//-----------------------------------------------------------------------------
/*static*/
void DrawUtils::exchangeColor (AcCmColor color, AcCmEntityColor entColor) {
	//color.setColorMethod (entColor.colorMethod ()) ;
	//switch ( color.colorMethod () ) {
	//	case AcCmEntityColor::ColorMethod::kByACI:
	//		break ;
	//		case AcCmEntityColor::ColorMethod::
	//}
	//color.setRGB (entColor.red (), entColor.green (), entColor.blue ()) ;
	color.setRGBM (entColor.getRGBM ()) ;
}
