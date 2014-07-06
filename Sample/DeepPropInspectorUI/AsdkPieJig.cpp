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
//----- AsdkPieJig.cpp : Declaration of the AsdkPieJig
//-----------------------------------------------------------------------------
#include "StdAfx.h"

#include "resource.h"

#include "../DeepPropInspector/AsdkPie.h"
#include "AsdkPieJig.h"

#include "../DeepPropInspector/DeepPropInspector_i.c" //- MUST be after AsdkPieJig.h

//-----------------------------------------------------------------------------
HINSTANCE AsdkPieJig::GetResourceInstance () {
	return (_hdllInstance) ;
}

//-----------------------------------------------------------------------------
VARTYPE AsdkPieJig::propertyTypeCallback (int index, VARTYPE varType) {
	PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
	switch ( index ) {
		case 0: //- Center
			varType =VT_R8 | VT_ARRAY ;
			break ;
		default:
			break ;
	}
	return (varType) ;
}

//-----------------------------------------------------------------------------
int AsdkPieJig::promptCallback (int index) {
	PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
	switch ( index ) {
		case 3: { //- Sectors
			double dist =0 ;
			int retval =acedGetReal (BuildPromptString (index), &dist) ;
			if ( retval == RTNORM ) {
				m_dist =dist ;
				if ( dist != 0 ) {
					CComPtr<IAcadPieSectors> pSectors ;
					m_pWrapperObject->get_Sectors (&pSectors) ;
					CComPtr<IAcadPieSector> pSector ;
					pSectors->AddSimpleSector (dist, &pSector) ;
				} else {
					pPromptMap [index].m_bGotThisProperty =true ;
				}
			}
			return (retval) ;
		}
		default:
			break ;
	}
	return (RTINPUTTRUNCATED) ;
}

//-----------------------------------------------------------------------------
AcEdJig::DragStatus AsdkPieJig::samplerCallback (int index, bool &compareChange) {
	PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
	switch ( index ) {
//		case 3: { //- Sectors
//			double dist =0 ;
//			//AcEdJig::DragStatus stat =acquireDist (dist) ;
//			if ( retval == RTNORM ) {
//				m_dist =dist ;
//				if ( dist != 0 ) {
//					CComPtr<IAcadPieSectors> pSectors ;
//					m_pWrapperObject->get_Sectors (&pSectors) ;
//					CComPtr<IAcadPieSector> pSector ;
//					pSectors->AddSimpleSector (dist, &pSector) ;
//				} else {
//					pPromptMap [index].m_bGotThisProperty =true ;
//				}
//			}
//			return (retval) ;
////			return (stat) ;
//		}
		default:
			break ;
	}
	return (AcEdJig::kOther) ;
}

//-----------------------------------------------------------------------------
bool AsdkPieJig::updateCallback (int index) {
	PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
	switch ( index ) {
		default:
			break ;
	}
	return (false) ;
}

//-----------------------------------------------------------------------------
bool AsdkPieJig::keywordCallback (int index, TCHAR *kword, void *value) {
	PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
	switch ( index ) {
		default:
			break ;
	}
	return (false) ;
}

//-----------------------------------------------------------------------------
bool AsdkPieJig::defaultValueCallback (int index, LPTSTR szDefaultVal) {
	PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
	switch ( index ) {
		default:
			break ;
	}
	return (false) ;
}