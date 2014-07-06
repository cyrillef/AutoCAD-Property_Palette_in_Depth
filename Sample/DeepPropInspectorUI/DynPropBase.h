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
//----- DynPropBase.h : Declaration of the DynPropBaseImpl<>
//-----------------------------------------------------------------------------
#pragma once

#include "acPexCtl.h"

//-----------------------------------------------------------------------------
template<class T> class ATL_NO_VTABLE DynPropBaseImpl :
	public ICategorizeProperties, // Legacy interface replaced by IAcPiCategorizeProperties
	//public IAcPiCategorizeProperties,
	public IAcPiPropertyDisplayImpl<T>,
	public IDynamicProperty2
{

	//COM_INTERFACE_ENTRY(IAcPiCategorizeProperties)

public:

	//-----------------------------------------------------------------------------
	AcDbObjectId GetObjectId (IUnknown *pUnk) {
		CComQIPtr<IAcadEntity> pEnt (pUnk) ;
		long lid =0 ;
		pEnt->get_ObjectID (&lid) ;
		AcDbObjectId id ;
		id.setFromOldId (lid) ;
		return (id) ;
	}

	//-----------------------------------------------------------------------------
	//- IPerPropertyDisplay
	STDMETHOD(GetCustomPropertyCtrl) (VARIANT varId, LCID lcid, BSTR *pProgId) {
		return (IAcPiPropertyDisplayImpl<T>::GetCustomPropertyCtrl (varId, lcid, pProgId)) ;
	}

	virtual HINSTANCE GetResourceInstance () {
		return (_hdllInstance) ;
	}

	//-----------------------------------------------------------------------------
	//- ICategorizeProperties
	STDMETHOD(MapPropertyToCategory) (DISPID dispid, PROPCAT *pPropCat) {
		CHECKOUTPARAM( pPropCat ) ;
		*pPropCat =0 ;
		return (S_OK) ;
	}

	//-----------------------------------------------------------------------------
	STDMETHOD(GetCategoryName) (PROPCAT propcat, LCID lcid, BSTR *pBstrName) {
		if ( propcat != 0 )
			return (E_INVALIDARG) ;
		CHECKOUTPARAM( pBstrName ) ;
		*pBstrName =::SysAllocString (L"Pie Sector") ;
		return (S_OK) ;
	}

	//- IAcPiCategorizeProperties
	//STDMETHOD(MapPropertyToCategory) (DISPID dispID, int *pCatID) ;
	//STDMETHOD(GetCategoryName) (int CatID, LCID lCid, BSTR *pCategoryName) ;
	//STDMETHOD(GetCategoryDescription) (int CatID, LCID lCid, BSTR *pCategoryDescription) ;
	//STDMETHOD(GetCategoryWeight) (int CatID, long *pCategoryWeight) ;
	//STDMETHOD(GetParentCategory) (int CatID, int *pParentCatID) ;
	//STDMETHOD(GetUniqueID) (BSTR *pVal) ;
	//STDMETHOD(GetCommandButtons) (int CatID, VARIANT *pCatCmdBtns) ;

} ;
