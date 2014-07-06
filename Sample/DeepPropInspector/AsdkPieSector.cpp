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
//----- AsdkPieSector.cpp : Implementation of AsdkPieSector
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "AsdkPieSector.h"
#include "AsdkPie.h"

//-----------------------------------------------------------------------------
Adesk::UInt32 AsdkPieSector::kCurrentVersionNumber =1 ;


//-----------------------------------------------------------------------------
AsdkPieSector::AsdkPieSector () {
	assert( 0 ) ;
}

AsdkPieSector::AsdkPieSector (AsdkPie *pParent) :
	mTitleTextSize(0.0), mTitlePosition(AcGePoint2d::kOrigin),
	mNumber(0), mNumberType(kPercentage),
	mbExploded(false), mbVisible(true),
	mPatternType(AcDbHatch::kPreDefined), mPatternName(_T("Solid")), mScale(1.0), mAngle(0.0),
	mpParent(pParent)
{
	assert( mpParent != NULL ) ;
}

AsdkPieSector::~AsdkPieSector () {
}

//-----------------------------------------------------------------------------
void AsdkPieSector::assertReadEnabled () const {
	assert( mpParent != NULL ) ;
	mpParent->assertReadEnabled () ;
}

void AsdkPieSector::assertWriteEnabled (Adesk::Boolean autoUndo, Adesk::Boolean recordModified) {
	assert( mpParent != NULL ) ;
	mpParent->assertWriteEnabled (autoUndo, recordModified) ;
}
//-----------------------------------------------------------------------------
//- Dwg Filing protocol
Acad::ErrorStatus AsdkPieSector::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Object version number needs to be saved first
	eOkReturn( pFiler->writeUInt32 (AsdkPieSector::kCurrentVersionNumber) ) ;

	pFiler->writeString ((LPCTSTR)mTitle) ;
	pFiler->writeHardPointerId (mTitleTextStyleId) ;
	pFiler->writeDouble (mTitleTextSize) ;
	pFiler->writePoint2d (mTitlePosition) ;
	pFiler->writeDouble (mNumber) ;
	pFiler->writeInt32 ((Adesk::Int32)mNumberType) ;
	pFiler->writeBool (mbExploded) ;
	pFiler->writeBool (mbVisible) ;
	pFiler->writeInt32 (mPatternType) ;
	pFiler->writeString ((LPCTSTR)mPatternName) ;
	pFiler->writeDouble (mScale) ;
	pFiler->writeDouble (mAngle) ;
	pFiler->writeUInt32 (mColor.color ()) ;

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus AsdkPieSector::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =0 ;
	eOkReturn( pFiler->readUInt32 (&version)) ;
	if ( version > AsdkPieSector::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < AsdkMyArc::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;

	char *pSt =NULL ; pFiler->readString (&pSt) ; mTitle =pSt ; delete [] pSt ; //acdbFree (pSt) ;
	pFiler->readHardPointerId (&mTitleTextStyleId) ;
	pFiler->readDouble (&mTitleTextSize) ;
	pFiler->readPoint2d (&mTitlePosition) ;
	pFiler->readDouble (&mNumber) ;
	pFiler->readInt32 ((Adesk::Int32 *)&mNumberType) ;
	pFiler->readBool (&mbExploded) ;
	pFiler->readBool (&mbVisible) ;
	pFiler->readInt32 ((Adesk::Int32 *)&mPatternType) ;
	pSt =NULL ; pFiler->readString (&pSt) ; mPatternName =pSt ; delete [] pSt ; //acdbFree (pSt) ;
	pFiler->readDouble (&mScale) ;
	pFiler->readDouble (&mAngle) ;
	Adesk::UInt32 color ; pFiler->readUInt32 (&color) ; mColor.setColor (color) ;

	return (pFiler->filerStatus ()) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
void AsdkPieSector::evaluateSectorData (
	CString &text, AcGePoint3d &textPosition, AcGiTextStyle &textStyle,
	AcGePoint2dArray &sectorLoop, AcGeDoubleArray &bulges,
	AcGePoint2dArray &textLoop
) {
	//- Evaluate text and text style
	if ( isPercentage () )
		text.Format (mTitle.IsEmpty () ? _T("%.2lf %%") : mTitle, mValue) ;
	else
		text.Format (mTitle.IsEmpty () ? _T("%.2lf %% (%.2lf)") : mTitle, mValue, mNumber) ;
	AcDbObjectId id =mTitleTextStyleId ;
	if ( id.isNull () )
		id =mpParent->get_TitleTextStyleId () ;
	DrawUtils::buildTextStyle (textStyle, id, AcDbObjectId::kNull) ;
	if ( mTitleTextSize != 0 )
		textStyle.setTextSize (mTitleTextSize) ;
	else if ( mpParent->get_TitleTextSize () != 0 )
		textStyle.setTextSize (mTitleTextSize) ;
	//- Make ECS
	AcGeVector3d xAxis =mpParent->normal ().perpVector () ;
	//- Calculate sector loop
	AcGeVector3d sAxis =xAxis ;
	sAxis.rotateBy (mStartAngle, mpParent->normal ()) ;
	sectorLoop.append (MAKE2D(mCenter)) ;
	sectorLoop.append (MAKE2D(mCenter + mpParent->radius () * sAxis)) ;
	AcGeVector3d eAxis =sAxis ;
	eAxis.rotateBy (mSeepAngle, mpParent->normal ()) ;
	sectorLoop.append (MAKE2D(mCenter + mpParent->radius () * eAxis)) ;
	sectorLoop.append (MAKE2D(mCenter)) ;
	bulges.append (0.0) ;
	bulges.append (fabs (tan (.25 * mSeepAngle))) ;
	bulges.append (0.0) ;
	bulges.append (0.0) ;
	//- Calculate text position and extents
	AcGePlane plan (mpParent->center (), xAxis, xAxis.perpVector ()) ;
	textPosition =plan.evalPoint (mTitlePosition) ;
	if ( mTitlePosition == AcGePoint2d::kOrigin ) {
		AcGeVector3d midAxis =sAxis ;
		midAxis.rotateBy (mSeepAngle / 2, mpParent->normal ()) ;
		textPosition =mCenter + 0.5 * mpParent->radius () * midAxis ;
	}
	AcGePoint2d extTextExtents ;
	AcGiTextEngine *pTextEngine =AcGiTextEngine::create () ;
	pTextEngine->getExtents (textStyle, (LPCTSTR)text, text.GetLength (), false, true, extTextExtents) ;
	delete pTextEngine ;
	AcGeVector3d xOff =0.7 * extTextExtents.x * xAxis ;
	AcGeVector3d yOff =extTextExtents.y * xAxis.perpVector () ;
	AcGePoint3d textCenter =textPosition ;
	textPosition -=0.5 * extTextExtents.x * xAxis ;
	textPosition -=0.5 * extTextExtents.y * xAxis.perpVector () ;
	//- Calculate text loop
	textLoop.append (MAKE2D(textCenter - xOff - yOff)) ;
	textLoop.append (MAKE2D(textCenter + xOff - yOff)) ;
	textLoop.append (MAKE2D(textCenter + xOff + yOff)) ;
	textLoop.append (MAKE2D(textCenter - xOff + yOff)) ;
	textLoop.append (MAKE2D(textCenter - xOff - yOff)) ;
}

void AsdkPieSector::drawSectorHatch (AcGiWorldDraw *mode, AcGePoint2dArray &sectorLoop, AcGeDoubleArray &bulges) {
	SubEntityTraitsSaveContext saveContext (mode) ;

	AcDbHatch hatch ;
	hatch.setDatabaseDefaults (mpParent->database ()) ;
	hatch.setNormal (mpParent->normal ()) ;
	hatch.setPatternAngle (mAngle) ;
	hatch.setPatternScale (mScale) ;
	hatch.setAssociative (Adesk::kFalse) ;
	hatch.setPattern (mPatternType, (LPCTSTR)mPatternName) ;
	hatch.appendLoop (AcDbHatch::kDefault, sectorLoop, bulges) ;
	hatch.setHatchStyle (AcDbHatch::kNormal) ;
	AcCmColor cm ;
	if ( mColor.colorMethod () != AcCmEntityColor::kNone )
		cm.setColor (mColor.trueColor ()) ;
	else
		cm.setColor (mode->subEntityTraits ().trueColor ().trueColor ()) ;
	hatch.setColor (cm, true) ;
	hatch.evaluateHatch (false) ;
	hatch.worldDraw (mode) ;
}

void AsdkPieSector::drawTitleHatch (AcGiWorldDraw *mode, AcGePoint2dArray &textLoop) {
	SubEntityTraitsSaveContext saveContext (mode) ;

	AcDbHatch hatch ;
	hatch.setDatabaseDefaults (mpParent->database ()) ;
	hatch.setNormal (mpParent->normal ()) ;
	hatch.setAssociative (Adesk::kFalse) ;
	hatch.setPattern (AcDbHatch::kPreDefined, _T("Solid")) ;
	AcGeDoubleArray bulges ;
	hatch.appendLoop (AcDbHatch::kDefault, textLoop, bulges) ;
	hatch.setHatchStyle (AcDbHatch::kNormal) ;
	AcCmColor cm ;
	cm.setRGB (0, 0, 0) ;
	hatch.setColor (cm, true) ;
	hatch.evaluateHatch (false) ;
	hatch.worldDraw (mode) ;
}

Adesk::Boolean AsdkPieSector::worldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;
	if ( mbVisible == true ) {
		SubEntityTraitsSaveContext saveContext (mode) ;

		if ( mColor.colorMethod () != AcCmEntityColor::kNone )
			mode->subEntityTraits ().setTrueColor (mColor) ;
		//- Draw border
		AcGeVector3d xAxis =mpParent->normal ().perpVector () ;
		AcGeVector3d sAxis =xAxis ;
		sAxis.rotateBy (mStartAngle, mpParent->normal ()) ;
		mode->geometry ().circularArc (mCenter, mpParent->radius (), mpParent->normal (), sAxis, mSeepAngle, kAcGiArcSector) ;

        CString text ;
		AcGePoint3d textPosition ;
		AcGiTextStyle textStyle ;
		AcGePoint2dArray sectorLoop, textLoop ;
		AcGeDoubleArray bulges ;
		evaluateSectorData (text, textPosition, textStyle, sectorLoop, bulges, textLoop) ;
		drawSectorHatch (mode, sectorLoop, bulges) ;
		drawTitleHatch (mode, textLoop) ;
		mode->geometry ().text (
			textPosition, mpParent->normal (), xAxis,
			(LPCTSTR)text, text.GetLength (),
			Adesk::kFalse, textStyle
		) ;
	}
	return (Adesk::kTrue) ;
}

//-----------------------------------------------------------------------------
//- Data access
double AsdkPieSector::get_Number () const {
	assertReadEnabled () ;
	return (mNumber) ;
}

void AsdkPieSector::put_Number (double number) {
	assertWriteEnabled () ;
	mNumber =number ;
}

AsdkPieSector::AsdkPieSectorNumberType AsdkPieSector::get_NumberType () const {
	assertReadEnabled () ;
	return (mNumberType) ;
}

void AsdkPieSector::put_NumberType (AsdkPieSectorNumberType numberType) {
	assertWriteEnabled () ;
	mNumberType =numberType ;
}

bool AsdkPieSector::isPercentage () const {
	assertReadEnabled () ;
	return (mNumberType == kPercentage) ;
}

bool AsdkPieSector::isExploded () const {
	assertReadEnabled () ;
	return (mbExploded) ;
}

void AsdkPieSector::put_Exploded (bool bExploded) {
	assertWriteEnabled () ;
	mbExploded =bExploded ;
}

bool AsdkPieSector::isVisible () const {
	assertReadEnabled () ;
	return (mbVisible) ;
}

void AsdkPieSector::put_Visible (bool bVisible) {
	mbVisible =bVisible ;
}

AcCmEntityColor AsdkPieSector::get_Color () const {
	assertReadEnabled () ;
	return (mColor) ;
}

void AsdkPieSector::put_Color (AcCmEntityColor color) {
	assertWriteEnabled () ;
	mColor =color ;
}

AcDbHatch::HatchPatternType AsdkPieSector::get_PatternType () const {
	assertReadEnabled () ;
	return (mPatternType) ;
}

void AsdkPieSector::put_Pattern (AcDbHatch::HatchPatternType patternType, LPCTSTR patternName, double angle, double scale) {
	assertWriteEnabled () ;
	mPatternType =patternType ;
	mPatternName =patternName ;
	mScale =scale ;
	mAngle =angle ;
}

//-----------------------------------------------------------------------------
//- Non filed data access
double AsdkPieSector::get_Value () {
	//assertReadEnabled () ;
	return (mValue) ;
}

void AsdkPieSector::put_Value (double newVal) {
	//assertWriteEnabled () ;
	mValue =newVal ;
}

double AsdkPieSector::get_StartAngle () {
	//assertReadEnabled () ;
	return (mStartAngle) ;
}

void AsdkPieSector::put_StartAngle (double angle) {
	//assertWriteEnabled () ;
	mStartAngle =angle ;
}

double AsdkPieSector::get_SeepAngle () {
	//assertReadEnabled () ;
	return (mSeepAngle) ;
}

void AsdkPieSector::put_SeepAngle (double seepAngle) {
	//assertWriteEnabled () ;
	mSeepAngle =seepAngle ;
}

void AsdkPieSector::put_Center (AcGePoint3d center) {
	//assertReadEnabled () ;
	mCenter =center ;
}
