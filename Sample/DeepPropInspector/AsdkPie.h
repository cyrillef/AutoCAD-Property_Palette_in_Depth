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
//----- AsdkPie.h : Declaration of the AsdkPie
//-----------------------------------------------------------------------------
#pragma once

#ifdef DEEPPROPINSPECTOR_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
#include "AsdkPieSector.h"

//-----------------------------------------------------------------------------
class DLLIMPEXP AsdkPie : public AcDbCircle {

private:
	CString mTitle ;
	AcDbHardPointerId mTitleTextStyleId ;
	double mTitleTextSize ;
	AcGePoint2d mTitlePosition ;
	bool mbClockwise ;
	double mStartAngle ;
	bool mbAllExploded ;
	double mExplodedOffset ;
	AcArray<AsdkPieSector *> mpSectors ;

public:
	ACRX_DECLARE_MEMBERS(AsdkPie) ;

protected:
	static Adesk::UInt32 kCurrentVersionNumber ;

public:
	AsdkPie () ;
	virtual ~AsdkPie () ;

	//----- AcDbObject protocols
	//- Dwg Filing protocol
	virtual Acad::ErrorStatus dwgOutFields (AcDbDwgFiler *pFiler) const ;
	virtual Acad::ErrorStatus dwgInFields (AcDbDwgFiler *pFiler) ;

	//- SubXXX() methods (self notification)
	virtual Acad::ErrorStatus subOpen (AcDb::OpenMode mode) ;
	virtual Acad::ErrorStatus subErase (Adesk::Boolean erasing) ;
	virtual Acad::ErrorStatus subCancel () ;
	virtual Acad::ErrorStatus subClose () ;
	virtual void subSetDatabaseDefaults (AcDbDatabase *pDb) ;

	//----- deepClone / wblockClone
	virtual Acad::ErrorStatus subDeepClone (AcDbObject *pOwnerObject, AcDbObject *&pClonedObject, AcDbIdMapping &idMap, Adesk::Boolean isPrimary =true) const ;
	virtual Acad::ErrorStatus subWblockClone (AcRxObject *pOwnerObject, AcDbObject *&pClonedObject, AcDbIdMapping &idMap, Adesk::Boolean isPrimary =true) const ;

	//- Automation support
	virtual Acad::ErrorStatus subGetClassID (CLSID *pClsid) const ;

	//----- AcDbEntity protocols
	//- Graphics protocol
	void CalculateSectorsPoints () ;
	//virtual void viewportDraw (AcGiViewportDraw *mode) ;
	virtual Adesk::Boolean subWorldDraw (AcGiWorldDraw *mode) ;

	//- Osnap points protocol
	//virtual Acad::ErrorStatus subGetOsnapPoints (
	//	AcDb::OsnapMode osnapMode,
	//	int gsSelectionMark,
	//	const AcGePoint3d &pickPoint,
	//	const AcGePoint3d &lastPoint,
	//	const AcGeMatrix3d &viewXform,
	//	AcGePoint3dArray &snapPoints,
	//	AcDbIntArray &geomIds) const ;
	virtual Acad::ErrorStatus subGetOsnapPoints (
		AcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds) const ;
	//virtual Acad::ErrorStatus subGetOsnapPoints (
	//	AcDb::OsnapMode osnapMode,
	//	int gsSelectionMark,
	//	const AcGePoint3d &pickPoint,
	//	const AcGePoint3d &lastPoint,
	//	const AcGeMatrix3d &viewXform,
	//	AcGePoint3dArray &snapPoints,
	//	AcDbIntArray &geomIds,
	//	const AcGeMatrix3d &insertionMat) const ;
	virtual Acad::ErrorStatus subGetOsnapPoints (
		AcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds,
		const AcGeMatrix3d &insertionMat) const ;

	//- Grip points protocol
	virtual Acad::ErrorStatus subGetGripPoints (AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const ;
	virtual Acad::ErrorStatus subMoveGripPointsAt (const AcDbIntArray &indices, const AcGeVector3d &offset) ;
	virtual Acad::ErrorStatus subGetGripPoints (
		AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
		const AcGeVector3d &curViewDir, const int bitflags) const ;
	virtual Acad::ErrorStatus subMoveGripPointsAt (const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset, const int bitflags) ;

	//- Data access
	AsdkPieSector *AppendData (
		double value,
		AsdkPieSector::AsdkPieSectorNumberType numberType =AsdkPieSector::kPercentage,
		bool bExploded =false, bool bVisible =true
	) ;

	LPCTSTR get_Title () const ;
	void put_Title (LPCTSTR title) ;
	AcDbObjectId get_TitleTextStyleId () const ;
	void put_TitleTextStyleId (AcDbObjectId id) ;
	double get_TitleTextSize () const ;
	void put_TitleTextSize (double titleTextSize) ;
	AcGePoint2d get_TitlePosition () const ;
	void put_TitlePosition (AcGePoint2d position) ;
	double get_StartAngle () const ;
	void put_StartAngle (double startAngle) ;
	bool isClockwise () const ;
	void put_Clockwise (bool bClockwise) ;
	bool isAllExploded () const ;
	void put_AllExploded (bool bExploded) ;
	double get_ExplodedOffset () const ;
	void put_ExplodedOffset (double explodedOffset) ;
	int get_SectorCount () const ;
	AsdkPieSector *get_Sector (int index) ;

} ;

//-----------------------------------------------------------------------------
#ifdef DEEPPROPINSPECTOR_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(AsdkPie)
#endif
