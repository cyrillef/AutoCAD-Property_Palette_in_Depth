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
//----- AsdkPieJig.h : Declaration of the AsdkPieJig
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"

#include "../DeepPropInspector/DeepPropInspector.h"
#include "DeepPropInspectorUI.h"
#include "AsdkPromptBase.h"

//-----------------------------------------------------------------------------
class AsdkPieJig : public AsdkPromptBase<IAcadPie, &CLSID_AcadPie> {

	BEGIN_PROMPT_MAP(AsdkPieJig)
		PROMPT_ENTRY(_T("Center"), 1, RT3DPOINT, 0, IDS_PROMPT_CENTER, true)
		PROMPT_ENTRY(_T("Radius"), 2, RTREAL, 0, IDS_PROMPT_RADIUS, true)
		PROMPT_ENTRY(_T("Title"), 100, RTSTR, 0, IDS_PROMPT_TITLE, false)
		PROMPT_ENTRY(_T("Sector"), 0, RTREAL, 0, IDS_PROMPT_SECTOR, true)
	END_PROMPT_MAP

	DEFINE_SAMPLER(AcEdJig::kCrosshair, (AcEdJig::UserInputControls)(kAcceptOtherInputString | kAccept3dCoordinates)) ;

protected:
	virtual VARTYPE propertyTypeCallback (int index, VARTYPE varType) ;

	virtual bool defaultValueCallback (int index, LPTSTR szDefaultVal) ;
	virtual bool keywordCallback (int index, TCHAR *kword, void *value) ;

	virtual int promptCallback (int index) ;
	virtual AcEdJig::DragStatus samplerCallback (int index, bool &compareChange) ;
	virtual bool updateCallback (int index) ;

public:
	virtual HINSTANCE GetResourceInstance () ;
} ;
