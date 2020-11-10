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
//----- AsdkPie.cpp : Implementation of AsdkPie
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "AsdkPie.h"

//-----------------------------------------------------------------------------
Adesk::UInt32 AsdkPie::kCurrentVersionNumber =1 ;
const double kPi =4 * atan (1) ;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS (
	AsdkPie, AcDbCircle,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, ASDKPIE,
	"ASDKDEEPPROPINSPECTORAPP"
	"|Product Desc:     A description for your object"
	"|Company:          Your company name"
	"|WEB Address:      Your company WEB site address"
)

//-----------------------------------------------------------------------------
AsdkPie::AsdkPie () : AcDbCircle (),
	mbClockwise(false), mStartAngle(0.0),
	mbAllExploded(false), mExplodedOffset(10.0),
	mTitleTextSize(0.0), mTitlePosition(AcGePoint2d::kOrigin)
{
}

AsdkPie::~AsdkPie () {
	while ( mpSectors.logicalLength () ) {
		AsdkPieSector *p =mpSectors.last () ;
		mpSectors.removeLast () ;
		delete p ;
	}
}

//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus AsdkPie::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbCircle::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (AsdkPie::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;

	pFiler->writeString ((LPCTSTR)mTitle) ;
	pFiler->writeHardPointerId (mTitleTextStyleId) ;
	pFiler->writeDouble (mTitleTextSize) ;
	pFiler->writePoint2d (mTitlePosition) ;
	pFiler->writeBool (mbClockwise) ;
	pFiler->writeDouble (mStartAngle) ;
	pFiler->writeBool (mbAllExploded) ;
	pFiler->writeDouble (mExplodedOffset) ;
	pFiler->writeInt32 (mpSectors.logicalLength ()) ;
	for ( int i =0 ; i < mpSectors.logicalLength () ; i++ )
		mpSectors.at (i)->dwgOutFields (pFiler) ;

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus AsdkPie::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbCircle::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =0 ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > AsdkPie::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < AsdkPie::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;

	ACHAR*pSt =NULL ; pFiler->readString (&pSt) ; mTitle =pSt ; delete [] pSt ; //acdbFree (pSt) ;
	pFiler->readHardPointerId (&mTitleTextStyleId) ;
	pFiler->readDouble (&mTitleTextSize) ;
	pFiler->readPoint2d (&mTitlePosition) ;
	pFiler->readBool (&mbClockwise) ;
	pFiler->readDouble (&mStartAngle) ;
	pFiler->readBool (&mbAllExploded) ;
	pFiler->readDouble (&mExplodedOffset) ;
	Adesk::Int32 nb =0 ;
	pFiler->readInt32 (&nb) ;
	for ( int i =0 ; i < nb ; i++ ) {
		AsdkPieSector *pSector =new AsdkPieSector (this) ;
		pSector->dwgInFields (pFiler) ;
		mpSectors.append (pSector) ;
	}

	return (pFiler->filerStatus ()) ;
}

//- SubXXX() methods (self notification)
Acad::ErrorStatus AsdkPie::subOpen (AcDb::OpenMode mode) {
	return (AcDbCircle::subOpen (mode)) ;
}

Acad::ErrorStatus AsdkPie::subErase (Adesk::Boolean erasing) {
	return (AcDbCircle::subErase (erasing)) ;
}

Acad::ErrorStatus AsdkPie::subCancel () {
	return (AcDbCircle::subCancel ()) ;
}

Acad::ErrorStatus AsdkPie::subClose () {
	return (AcDbCircle::subClose ()) ;
}

void AsdkPie::subSetDatabaseDefaults (AcDbDatabase *pDb) {
	AcDbCircle::subSetDatabaseDefaults (pDb) ;
	mTitleTextStyleId =pDb->textstyle () ;
	mTitleTextSize =pDb->textsize () ;
}

//----- deepClone
Acad::ErrorStatus AsdkPie::subDeepClone (AcDbObject *pOwnerObject, AcDbObject *&pClonedObject, AcDbIdMapping &idMap, Adesk::Boolean isPrimary) const {
	assertReadEnabled () ;
	return (AcDbCircle::deepClone (pOwnerObject, pClonedObject, idMap, isPrimary)) ;
}

//----- wblockClone
Acad::ErrorStatus AsdkPie::subWblockClone (AcRxObject *pOwnerObject, AcDbObject *&pClonedObject, AcDbIdMapping &idMap, Adesk::Boolean isPrimary) const {
	assertReadEnabled () ;
	return (AcDbCircle::wblockClone (pOwnerObject, pClonedObject, idMap, isPrimary)) ;
}

//- Automation support
Acad::ErrorStatus AsdkPie::subGetClassID (CLSID *pClsid) const {
	assertReadEnabled () ;
	if ( SUCCEEDED( ::CLSIDFromProgID (L"DeepPropInspector.AcadPie.1", pClsid) ) )
		return (Acad::eOk) ;
	return (AcDbCircle::getClassID (pClsid)) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
void AsdkPie::CalculateSectorsPoints () {
	//- First init Number or Percentage
	double totalNum =0 ;
	double totalPercentage =0 ;
	bool bAllNumber =true ;
	bool bAllPercentage =true ;
	for ( int i =0 ; i < mpSectors.logicalLength () ; i++ ) {
		AsdkPieSector *pSector =mpSectors.at (i) ;
		if ( pSector->isPercentage () == true ) {
			totalPercentage +=pSector->get_Number () ;
			bAllNumber =false ;
		} else {
			totalNum +=pSector->get_Number () ;
			bAllPercentage =false ;
		}
	}
	//- Determine exact values (in percentage)
	RXASSERT( totalPercentage <= 100 && totalPercentage >= 0 ) ;
	RXASSERT( totalNum >=0 ) ;
	double onePercent =totalNum > 0 ? (100 - totalPercentage) / totalNum : 0.0 ;
	double angle =mStartAngle ;
	for ( int i =0 ; i < mpSectors.logicalLength () ; i++ ) {
		AsdkPieSector *pSector =mpSectors.at (i) ;
		if ( pSector->isPercentage () == true )
			pSector->put_Value (pSector->get_Number ()) ;
		else
			pSector->put_Value (pSector->get_Number () * onePercent) ;
		//pSector->put_Normal (this->normal ()) ;
		//pSector->put_Radius (this->radius ()) ;
		double sweepAngle =2 * kPi * (360 * pSector->get_Value () / 100) / 360 ;
		pSector->put_StartAngle (angle - (mbClockwise == true ? sweepAngle : 0)) ;
		pSector->put_SeepAngle (sweepAngle) ;
		pSector->put_Center (this->center ()) ;
		if ( mbAllExploded == true || pSector->isExploded () == true ) {
			AcGeVector3d xAxis =this->normal ().perpVector () ;
			xAxis.rotateBy (pSector->get_StartAngle (), this->normal ()) ;
			xAxis.rotateBy (sweepAngle / 2, this->normal ()) ;
			xAxis.normalize () ;
			pSector->put_Center (this->center () + (this->radius () * mExplodedOffset / 100) * xAxis) ;
		}
		angle +=sweepAngle * (mbClockwise == true ? -1 : 1) ;
		//pSector->put_ParentColor (this->entityColor ()) ;
	}
}

Adesk::Boolean AsdkPie::subWorldDraw (AcGiWorldDraw *mode) {
	assertReadEnabled () ;
	//- In case there is no sectors. It means 100%
	if ( mpSectors.logicalLength () == 0 ) {
		mode->geometry ().circle (this->center (), this->radius (), this->normal ()) ;
		return (Adesk::kTrue) ;
	}
	//- Draw sectors
	CalculateSectorsPoints () ;
	for ( int i =0 ; i < mpSectors.logicalLength () ; i++ ) {
		AsdkPieSector *pSector =mpSectors.at (i) ;
		pSector->worldDraw (mode) ;
	}
	//- Draw title
	if ( !mTitle.IsEmpty () ) {
		AcGeVector3d xAxis =normal ().perpVector () ;
		AcGePlane plan (center (), xAxis, xAxis.perpVector ()) ;
		AcGePoint3d pt =plan.evalPoint (mTitlePosition) ;
		AcGiTextStyle textStyle ;
		DrawUtils::buildTextStyle (textStyle, mTitleTextStyleId, AcDbObjectId::kNull) ;
		if ( mTitleTextSize != 0 )
			textStyle.setTextSize (mTitleTextSize) ;
		mode->geometry().text (pt, normal (), xAxis, (LPCTSTR)mTitle, mTitle.GetLength (), Adesk::kFalse, textStyle) ;
	}

	return (Adesk::kTrue) ;
	//return (AcDbCircle::worldDraw (mode)) ;
}

//void AsdkPie::viewportDraw (AcGiViewportDraw *mode) {
//	assertReadEnabled () ;
//	AcDbCircle::viewportDraw (mode) ;
//}

//- Osnap points protocol
//Acad::ErrorStatus AsdkPie::subGetOsnapPoints (
//	AcDb::OsnapMode osnapMode,
//	int gsSelectionMark,
//	const AcGePoint3d &pickPoint,
//	const AcGePoint3d &lastPoint,
//	const AcGeMatrix3d &viewXform,
//	AcGePoint3dArray &snapPoints,
//	AcDbIntArray &geomIds) const
//{
//	assertReadEnabled () ;
//	return (AcDbCircle::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds)) ;
//}

Acad::ErrorStatus AsdkPie::subGetOsnapPoints(
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
	return (AcDbCircle::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds)) ;
}

//Acad::ErrorStatus AsdkPie::subGetOsnapPoints (
//	AcDb::OsnapMode osnapMode,
//	int gsSelectionMark,
//	const AcGePoint3d &pickPoint,
//	const AcGePoint3d &lastPoint,
//	const AcGeMatrix3d &viewXform,
//	AcGePoint3dArray &snapPoints,
//	AcDbIntArray &geomIds,
//	const AcGeMatrix3d &insertionMat) const
//{
//	assertReadEnabled () ;
//	return (AcDbCircle::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat)) ;
//}

Acad::ErrorStatus AsdkPie::subGetOsnapPoints (
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d & pickPoint,
	const AcGePoint3d & lastPoint,
	const AcGeMatrix3d & viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds,
	const AcGeMatrix3d &insertionMat) const
{
	assertReadEnabled () ;
	return (AcDbCircle::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat)) ;
}

//- Grip points protocol
Acad::ErrorStatus AsdkPie::subGetGripPoints (
	AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds
) const {
	assertReadEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new getGripPoints() method below (which is the default implementation)

	return (AcDbCircle::getGripPoints (gripPoints, osnapModes, geomIds)) ;
}

Acad::ErrorStatus AsdkPie::subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) {
	assertWriteEnabled () ;
	//----- This method is never called unless you return eNotImplemented 
	//----- from the new moveGripPointsAt() method below (which is the default implementation)

	return (AcDbCircle::moveGripPointsAt (indices, offset)) ;
}

Acad::ErrorStatus AsdkPie::subGetGripPoints (
	AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const AcGeVector3d &curViewDir, const int bitflags
) const {
	assertReadEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	return (AcDbCircle::subGetGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}

Acad::ErrorStatus AsdkPie::subMoveGripPointsAt (
	const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset,
	const int bitflags
) {
	assertWriteEnabled () ;

	//----- If you return eNotImplemented here, that will force AutoCAD to call
	//----- the older getGripPoints() implementation. The call below may return
	//----- eNotImplemented depending of your base class.
	return (AcDbCircle::subMoveGripPointsAt (gripAppData, offset, bitflags)) ;
}

//- Data access
AsdkPieSector *AsdkPie::AppendData (double value, AsdkPieSector::AsdkPieSectorNumberType numberType, bool bExploded, bool bVisible) {
	assertWriteEnabled () ;
	AsdkPieSector *pSector =new AsdkPieSector (this) ;
	pSector->put_Number (value) ;
	pSector->put_NumberType (numberType) ;
	pSector->put_Exploded (bExploded) ;
	pSector->put_Visible (bVisible) ;
	pSector->put_Color (AcCmEntityColor::None()) ;
	mpSectors.append (pSector) ;
	return (pSector) ;
}

LPCTSTR AsdkPie::get_Title () const  {
	assertReadEnabled () ;
	return ((LPCTSTR)mTitle) ;
}

void AsdkPie::put_Title (LPCTSTR title) {
	assertWriteEnabled () ;
	mTitle =title ;
}

AcDbObjectId AsdkPie::get_TitleTextStyleId () const {
	assertReadEnabled () ;
	return (mTitleTextStyleId) ;
}

void AsdkPie::put_TitleTextStyleId (AcDbObjectId id) {
	assertWriteEnabled () ;
	mTitleTextStyleId =id ;
}

double AsdkPie::get_TitleTextSize () const {
	assertReadEnabled () ;
	return (mTitleTextSize) ;
}

void AsdkPie::put_TitleTextSize (double titleTextSize) {
	assertWriteEnabled () ;
	mTitleTextSize =titleTextSize ;
}

AcGePoint2d AsdkPie::get_TitlePosition () const {
	assertReadEnabled () ;
	return (mTitlePosition) ;
}

void AsdkPie::put_TitlePosition (AcGePoint2d position) {
	assertWriteEnabled () ;
	mTitlePosition =position ;
}

double AsdkPie::get_StartAngle () const {
	assertReadEnabled () ;
	return (mStartAngle) ;
}

void AsdkPie::put_StartAngle (double startAngle) {
	assertWriteEnabled () ;
	mStartAngle =startAngle ;
}

bool AsdkPie::isClockwise () const {
	assertReadEnabled () ;
	return (mbClockwise) ;
}

void AsdkPie::put_Clockwise (bool bClockwise) {
	assertWriteEnabled () ;
	mbClockwise =bClockwise ;
}

bool AsdkPie::isAllExploded () const {
	assertReadEnabled () ;
	return (mbAllExploded) ;
}

void AsdkPie::put_AllExploded (bool bExploded) {
	assertWriteEnabled () ;
	mbAllExploded =bExploded ;
}

double AsdkPie::get_ExplodedOffset () const {
	assertReadEnabled () ;
	return (mExplodedOffset) ;
}

void AsdkPie::put_ExplodedOffset (double explodedOffset) {
	assertWriteEnabled () ;
	mExplodedOffset =explodedOffset ;
}

int AsdkPie::get_SectorCount () const {
	assertReadEnabled () ;
	return (mpSectors.logicalLength ()) ;
}

AsdkPieSector *AsdkPie::get_Sector (int index) {
	assertReadEnabled () ;
	RXASSERT( index >= 0 && index < mpSectors.logicalLength () ) ;
	if ( index < 0 || index >= mpSectors.logicalLength () )
		return (NULL) ;
	return (mpSectors.at (index)) ;
}