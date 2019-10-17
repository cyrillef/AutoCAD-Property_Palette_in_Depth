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
//----- acrxEntryPoint.h
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "../DeepPropInspector/AsdkPie.h"
#include "AsdkPieJig.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST(_T("Asdk"))

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CDeepPropInspectorUIApp : public AcRxArxApp {

public:
	CDeepPropInspectorUIApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		if ( ::acrxAppIsLoaded (_T("DeepPropInspector.dbx")) == false ) 
			{
			if ( acrxLoadModule (_T("DeepPropInspector.dbx"), false, true) == false ) 
				{
				RXASSERT( 0 ) ;
				return (AcRx::kRetError) ;
			}
		}
		acrxLoadModule (_T("DeepPropInspector.dbx"), false, false) ;

		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		acrxUnloadModule (_T("DeepPropInspector.dbx"), false) ;

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
		//----- Self-register COM server upon loading.
#ifdef _DEBUG
		::DllUnregisterServer () ;
#endif
		if ( FAILED(::DllRegisterServer ()) )
			acutPrintf (_RXST("Failed to register COM server.\n")) ;
	}


	// ----- AsdkDeepPropInspectorUI._MyCommand1 command (do not rename)
	static void AsdkDeepPropInspectorUI_MyCommand1 (void) {
		AcDbObjectPointer<AsdkPie> pPie ;
		pPie.create () ;
		pPie->setDatabaseDefaults () ;
		pPie->setCenter (AcGePoint3d (10, 10, 0)) ;
		pPie->setNormal (AcGeVector3d (0, 0, 1)) ;
		pPie->setRadius (10) ;
		pPie->put_Title (_T("My Chart Title")) ;
		pPie->put_TitlePosition (AcGePoint2d (0, 10 + pPie->get_TitleTextSize ())) ;

		AsdkPieSector *pSector =pPie->AppendData (100, AsdkPieSector::kNumber, false, true) ;
		pSector =pPie->AppendData (25, AsdkPieSector::kPercentage, false, false) ;
		pSector->put_Color (AcCmEntityColor (255, 0, 0)) ;
		pSector =pPie->AppendData (125, AsdkPieSector::kNumber, true, true) ;
		pSector->put_Color (AcCmEntityColor (255, 128, 0)) ;
		pSector =pPie->AppendData (62, AsdkPieSector::kNumber) ;
		pSector->put_Color (AcCmEntityColor (255, 0, 128)) ;
		pSector->put_Pattern (AcDbHatch::kPreDefined, _T("BRICK"), 0.8, 1.0) ;

		AcDbBlockTableRecordPointer pMS (ACDB_MODEL_SPACE, curDoc ()->database (), AcDb::kForWrite, false) ;
		pMS->appendAcDbEntity (pPie.object ()) ;
	}

	// ----- AsdkDeepPropInspectorUI._MyCommand2 command (do not rename)
	static void AsdkDeepPropInspectorUI_MyCommand2 (void) {
		AfxSetResourceHandle (acedGetAcadResourceInstance ()) ;
		CComObject<AsdkPieJig> jigPie ;
		jigPie.promptLoop () ;
	}

} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CDeepPropInspectorUIApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CDeepPropInspectorUIApp, AsdkDeepPropInspectorUI, _MyCommand1, test, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CDeepPropInspectorUIApp, AsdkDeepPropInspectorUI, _MyCommand2, testjig, ACRX_CMD_TRANSPARENT | ACRX_CMD_INTERRUPTIBLE | ACRX_CMD_NOHISTORY, NULL)
