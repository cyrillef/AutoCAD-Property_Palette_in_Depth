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


/*
class ATL_NO_VTABLE IAcadBaseObjectImpl : 
	public IAcadBaseObject,
	public IConnectionPointContainerImpl<T>,
	public CProxy_AcadObjectEvents<T>,
	public CProxy_PropertyNotifySink<T>
		protected:
			AcDbObjectId m_objId;

class ATL_NO_VTABLE IAcadBaseObject2Impl :
	public IAcadBaseObject2,
	public IAcadBaseObjectImpl<T, pclsid>
		protected:
			AcAxObjectRef m_objRef;


class ATL_NO_VTABLE IAcadObjectDispatchImpl : 
	public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>,
	public IAcadBaseObject2Impl<C, pclsid>,
	public IRetrieveApplicationImpl

class ATL_NO_VTABLE IAcadEntityDispatchImpl : 
	public IAcadObjectDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>

*/

//-----------------------------------------------------------------------------
//----- IAcadCircleImpl.h : Declaration of the IAcadCircleImpl
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#include "resource.h"
#include "DeepPropInspector.h"
#include "COM Defines.h"

//-----------------------------------------------------------------------------
#define ACAD_DISPID_RESERVED 100

//-----------------------------------------------------------------------------
template <
	class T, class rxClass, class interfaceClass, class inheritedInterface,
	const CLSID *pclsid, const CLSID *pinheritedClsid, const IID *piid =&__uuidof (interfaceClass),
	const GUID *plibid =&CAtlModule::m_libid
>
class ATL_NO_VTABLE IAcadEntityBaseDispatchImpl :
	public IOPMPropertyExtensionImpl2<T>,
	public IAcPiCategorizePropertiesImpl<T>,
	public IOPMPropertyExpander,
	public IAcadEntityDispatchImpl<T, pclsid, interfaceClass, piid, plibid>
{

protected:
	inheritedInterface *mpInnerObject ;

public:
	IAcadEntityBaseDispatchImpl () : mpInnerObject(NULL) {
		InternalFinalConstruct () ;
	}

	virtual ~IAcadEntityBaseDispatchImpl () {
		InternalFinalRelease () ;
	}

	//- Error reporting
	static HRESULT WINAPI xError (LPCOLESTR lpszDesc, const IID &iid =GUID_NULL, HRESULT hRes =0) {
		return (AtlReportError (*pclsid, lpszDesc, *piid, hRes)) ;
	}

protected:
	virtual HRESULT InternalFinalConstruct () {
		HRESULT hr =S_OK ;
		if ( mpInnerObject == NULL )
			hr =::CoCreateInstance (*pinheritedClsid, NULL, CLSCTX_INPROC_SERVER, __uuidof (inheritedInterface), (void **)&mpInnerObject) ;
		return (hr) ;
	}

	virtual void InternalFinalRelease () {
		if ( mpInnerObject )
			mpInnerObject->Release () ;
		mpInnerObject =NULL ;
	}

public:
	//- IAcadBaseObjectImpl
	virtual HRESULT CreateNewObject (AcDbObjectId &objId, AcDbObjectId &ownerId, TCHAR *keyName) {
		try {
			THROWFAILED( CreateObject (ownerId, keyName) ) ;
			THROWFAILED( AddToDb (objId, ownerId, keyName)) ;
		} catch ( HRESULT hr ) {
			return (hr) ;
		}
		return (S_OK) ;
	}

	STDMETHOD(SetObjectId) (AcDbObjectId &objId, AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL) {
		HRESULT hr =IAcadBaseObjectImpl<T, pclsid>::SetObjectId (objId, ownerId, keyName) ;
		if ( SUCCEEDED( hr ) ) {
			CComQIPtr<IAcadBaseObject> pBase (mpInnerObject) ;
			pBase->SetObjectId (objId, ownerId, keyName) ;
		}
		return (hr) ;
	}

	STDMETHOD(NullObjectId) (void) {
		HRESULT hr =IAcadBaseObjectImpl<T, pclsid>::NullObjectId () ;
		if ( SUCCEEDED( hr ) ) {
			CComQIPtr<IAcadBaseObject> pBase (mpInnerObject) ;
			pBase->NullObjectId () ;
		}
		return (hr) ;
	}

	//- IAcadBaseObject2Impl
	STDMETHOD(ForceDbResident) (VARIANT_BOOL *forceDbResident) {
		CHECKOUTPARAM( forceDbResident ) ;
		//- Return ACAX_VARIANT_TRUE if the object must be database resident to be functional
		*forceDbResident =ACAX_VARIANT_FALSE ;
		return (S_OK) ;
	}

	STDMETHOD(CreateObject) (AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL) {
		try {
			AcDbObjectPointer<rxClass> pEnt ;
			pEnt.create () ;
			eOkObjectPointerThrow( pEnt ) ;
			pEnt->setDatabaseDefaults (ownerId.database ()) ;
			rxClass *pTmp =NULL ;
			pEnt.release (pTmp) ;
			rxClass *pTmp2 =pTmp ;
			SetObject ((AcDbObject *&)pTmp) ;

			CComQIPtr<IAcadBaseObject2> pBase (mpInnerObject) ;
			pBase->SetObject ((AcDbObject *&)pTmp2) ;

		} catch ( const Acad::ErrorStatus ) {
			return (xError (L"Failed to create entity", *piid, E_FAIL)) ;
		}
		return (S_OK) ;
	}

	STDMETHOD(AddToDb) (AcDbObjectId &objId, AcDbObjectId ownerId =AcDbObjectId::kNull, TCHAR *keyName =NULL) {
		try {
			AcAxDocLock docLock (ownerId) ;
			AcAxObjectRefPtr<AcDbEntity> pEnt (&m_objRef, AcDb::kForRead) ;
			//- Entities can be owned by block table records only
			AcDbBlockTableRecordPointer pBlockTableRecord (ownerId, AcDb::kForWrite, true) ;
			eOkObjectPointerThrow( pBlockTableRecord ) ;
			eOkThrow( pBlockTableRecord->appendAcDbEntity (objId, pEnt.object ()) ) ;
		} catch( const Acad::ErrorStatus ) {
			return (xError (L"Failed to add entity to database", *piid, E_FAIL)) ;
		}

		CComQIPtr<IAcadBaseObject> pBase (mpInnerObject) ;
		pBase->SetObjectId (objId) ;
		return (SetObjectId (objId)) ;
	}

	//- IOPMPropertyExtensionImpl2
	//- IPerPropertyBrowsing
	STDMETHOD(GetDisplayString) (DISPID dispID, BSTR *pBstr) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IPerPropertyBrowsing> pPerPropertyBrowsing (mpInnerObject) ;
			if ( pPerPropertyBrowsing )
				return (pPerPropertyBrowsing->GetDisplayString (dispID, pBstr)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::GetDisplayString (dispID, pBstr)) ;
	}

	STDMETHOD(MapPropertyToPage) (DISPID dispID, CLSID *pClsid) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IPerPropertyBrowsing> pPerPropertyBrowsing (mpInnerObject) ;
			if ( pPerPropertyBrowsing )
				return (pPerPropertyBrowsing->MapPropertyToPage (dispID, pClsid)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::MapPropertyToPage (dispID, pClsid)) ;
	}

	STDMETHOD(GetPredefinedStrings) (DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IPerPropertyBrowsing> pPerPropertyBrowsing (mpInnerObject) ;
			if ( pPerPropertyBrowsing )
				return (pPerPropertyBrowsing->GetPredefinedStrings (dispID, pCaStringsOut, pCaCookiesOut)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::GetPredefinedStrings (dispID, pCaStringsOut, pCaCookiesOut)) ;
	}

	STDMETHOD(GetPredefinedValue) (DISPID dispID, DWORD dwCookie, VARIANT *pVarOut) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IPerPropertyBrowsing> pPerPropertyBrowsing (mpInnerObject) ;
			if ( pPerPropertyBrowsing )
				return (pPerPropertyBrowsing->GetPredefinedValue (dispID, dwCookie, pVarOut)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::GetPredefinedValue (dispID, dwCookie, pVarOut)) ;
	}

	//- IOPMPropertyExtension
	STDMETHOD(GetDisplayName) (DISPID dispID, BSTR *pBstr) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExtension> pOPMPropertyExtension (mpInnerObject) ;
			if ( pOPMPropertyExtension )
				return (pOPMPropertyExtension->GetDisplayName (dispID, pBstr)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::GetDisplayName (dispID, pBstr)) ;
	}

	STDMETHOD(Editable) (DISPID dispID, BOOL *bEditable) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExtension> pOPMPropertyExtension (mpInnerObject) ;
			if ( pOPMPropertyExtension )
				return (pOPMPropertyExtension->Editable (dispID, bEditable)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::Editable (dispID, bEditable)) ;
	}

	STDMETHOD(ShowProperty) (DISPID dispID, BOOL *pShow) {
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExtension> pOPMPropertyExtension (mpInnerObject) ;
			if ( pOPMPropertyExtension )
				return (pOPMPropertyExtension->ShowProperty (dispID, pShow)) ;
		}
		return (IOPMPropertyExtensionImpl2<T>::ShowProperty (dispID, pShow)) ;
	}

	//- IAcPiCategorizeProperties
	//- See IAcPiCategorizePropertiesImpl
	STDMETHOD(GetUniqueID) (BSTR *pVal) {
		CHECKOUTPARAM( pVal ) ;
		*pVal =_bstr_t (rxClass::desc ()->name ()) ;
		return (S_OK) ;
	}

	//- Ok we need to support both ICategorizeProperties / IAcPiCategorizeProperties
	STDMETHOD(MapPropertyToCategory) (DISPID dispid, PROPCAT *ppropcat) {
		if ( dispid < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IAcPiCategorizeProperties> pAcPiCategorizeProperties (mpInnerObject) ;
			if ( pAcPiCategorizeProperties )
				return (pAcPiCategorizeProperties->MapPropertyToCategory (dispid, ppropcat)) ;
			CComQIPtr<ICategorizeProperties> pCategorizeProperties (mpInnerObject) ;
			if ( pCategorizeProperties )
				return (pCategorizeProperties->MapPropertyToCategory (dispid, ppropcat)) ;
		}
		return (IAcPiCategorizePropertiesImpl<T>::MapPropertyToCategory (dispid, ppropcat)) ;
	}

	STDMETHOD(GetCategoryName) (PROPCAT propcat, LCID lcid, BSTR *pbstrName) {
		CHECKOUTPARAM( pbstrName ) ;
		*pbstrName =NULL ;
		CComQIPtr<IAcPiCategorizeProperties> pAcPiCategorizeProperties (mpInnerObject) ;
		if ( pAcPiCategorizeProperties ) {
			HRESULT hr =pAcPiCategorizeProperties->GetCategoryName (propcat, lcid, pbstrName) ;
			if ( !FAILED( hr ) && *pbstrName != NULL )
				return (hr) ;
		}
		CComQIPtr<ICategorizeProperties> pCategorizeProperties (mpInnerObject) ;
		if ( pCategorizeProperties ) {
			HRESULT hr =pCategorizeProperties->GetCategoryName (propcat, lcid, pbstrName) ;
			if ( !FAILED( hr ) && *pbstrName != NULL )
				return (hr) ;
		}
		return (IAcPiCategorizePropertiesImpl<T>::GetCategoryName (propcat, lcid, pbstrName)) ;
	}

	//- IOPMPropertyExpander
	STDMETHOD(GetElementValue) (DISPID dispID, DWORD dwCookie, VARIANT *pVarOut) {
		CHECKOUTPARAM( pVarOut ) ;
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExpander> pPropExp (mpInnerObject) ;
			if ( pPropExp )
				return (pPropExp->GetElementValue (dispID, dwCookie, pVarOut)) ;
		}
		return (E_NOTIMPL) ;
	}

	STDMETHOD(SetElementValue) (DISPID dispID, DWORD dwCookie, VARIANT VarIn) {       
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExpander> pPropExp (mpInnerObject) ;
			if ( pPropExp )
				return (pPropExp->SetElementValue (dispID, dwCookie, VarIn)) ;
		}
		return (E_NOTIMPL) ;
	}

	STDMETHOD(GetElementStrings) (DISPID dispID, OPMLPOLESTR *pCaStringsOut, OPMDWORD *pCaCookiesOut) {
		CHECKOUTPARAM( pCaStringsOut ) ;
		CHECKOUTPARAM( pCaCookiesOut ) ;
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExpander> pPropExp (mpInnerObject) ;
			if ( pPropExp )
				return (pPropExp->GetElementStrings (dispID, pCaStringsOut, pCaCookiesOut)) ;
		}
		return (E_NOTIMPL) ;
	}

	STDMETHOD(GetElementGrouping) (DISPID dispID, short *groupingNumber) {
		CHECKOUTPARAM( groupingNumber ) ;
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExpander> pPropExp (mpInnerObject) ;
			if ( pPropExp )
				return (pPropExp->GetElementGrouping (dispID, groupingNumber)) ;
		}
		return (E_NOTIMPL) ;
	}

	STDMETHOD(GetGroupCount) (DISPID dispID, long *nGroupCnt) {
		CHECKOUTPARAM( nGroupCnt ) ;
		if ( dispID < ACAD_DISPID_RESERVED ) {
			CComQIPtr<IOPMPropertyExpander> pPropExp (mpInnerObject) ;
			if ( pPropExp )
				return (pPropExp->GetGroupCount (dispID, nGroupCnt)) ;
		}
		return (E_NOTIMPL) ;
	}

} ;