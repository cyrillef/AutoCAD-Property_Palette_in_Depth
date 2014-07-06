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
//----- AsdkPieSector.h : Declaration of the AsdkPieSector
//-----------------------------------------------------------------------------
#pragma once

#ifdef DEEPPROPINSPECTOR_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
class AsdkPie ;

class DLLIMPEXP AsdkPieSector {

public:
	typedef enum {
		kNumber,
		kPercentage
	} AsdkPieSectorNumberType ;

private:
	CString mTitle ;
	AcDbHardPointerId mTitleTextStyleId ;
	double mTitleTextSize ;
	AcGePoint2d mTitlePosition ;
	double mNumber ;
	AsdkPieSectorNumberType mNumberType ;
	bool mbExploded ;
	bool mbVisible ;
	AcDbHatch::HatchPatternType mPatternType ;
	CString mPatternName ;
	double mScale, mAngle ;
	AcCmEntityColor mColor ;

	//- Non filed data
	AcGePoint3d mCenter ;
	double mStartAngle, mSeepAngle ;
	double mValue ;
	AsdkPie *mpParent ;

protected:
	static Adesk::UInt32 kCurrentVersionNumber ;

protected:
	AsdkPieSector () ;
public:
	AsdkPieSector (AsdkPie *pParent) ;
	virtual ~AsdkPieSector () ;

	void assertReadEnabled () const ;
	void assertWriteEnabled (Adesk::Boolean autoUndo =true, Adesk::Boolean recordModified =true) ;

	//----- AcDbObject protocols
	//- Dwg Filing protocol
	virtual Acad::ErrorStatus dwgOutFields (AcDbDwgFiler *pFiler) const ;
	virtual Acad::ErrorStatus dwgInFields (AcDbDwgFiler *pFiler) ;

	//----- AcDbEntity protocols
	//- Graphics protocol
	void evaluateSectorData (
		CString &text, AcGePoint3d &textPosition, AcGiTextStyle &textStyle,
		AcGePoint2dArray &sectorLoop, AcGeDoubleArray &bulges,
		AcGePoint2dArray &textLoop
	) ;

	void drawSectorHatch (AcGiWorldDraw *mode, AcGePoint2dArray &sectorLoop, AcGeDoubleArray &bulges) ;
	void drawTitleHatch (AcGiWorldDraw *mode, AcGePoint2dArray &textLoop) ;

//	void drawTitleHatch (AcGiWorldDraw *mode) ;
//	void drawTitle (AcGiWorldDraw *mode) ;
	virtual Adesk::Boolean worldDraw (AcGiWorldDraw *mode) ;

public:
	//- Data access
	double get_Number () const ;
	void put_Number (double number) ;
	AsdkPieSectorNumberType get_NumberType () const  ;
	void put_NumberType (AsdkPieSectorNumberType numberType) ;
	bool isPercentage () const ;
	bool isExploded () const ;
	void put_Exploded (bool bExploded) ;
	bool isVisible () const ;
	void put_Visible (bool bVisible) ;
	AcCmEntityColor get_Color () const ;
	void put_Color (AcCmEntityColor color) ;
	AcDbHatch::HatchPatternType get_PatternType () const ;
	void put_Pattern (AcDbHatch::HatchPatternType patternType, LPCTSTR patternName, double angle =0.0, double scale =1.0) ;

	//- Non filed data access
	double get_Value () ;
	void put_Value (double newVal) ;
	double get_StartAngle () ;
	void put_StartAngle (double angle) ;
	double get_SeepAngle () ;
	void put_SeepAngle (double seepAngle) ;
	void put_Center (AcGePoint3d center) ;

} ;
