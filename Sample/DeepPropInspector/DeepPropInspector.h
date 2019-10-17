

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 08:44:07 2038
 */
/* Compiler settings for DeepPropInspector.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __DeepPropInspector_h__
#define __DeepPropInspector_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAcadPieSector_FWD_DEFINED__
#define __IAcadPieSector_FWD_DEFINED__
typedef interface IAcadPieSector IAcadPieSector;

#endif 	/* __IAcadPieSector_FWD_DEFINED__ */


#ifndef __AcadPieSector_FWD_DEFINED__
#define __AcadPieSector_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPieSector AcadPieSector;
#else
typedef struct AcadPieSector AcadPieSector;
#endif /* __cplusplus */

#endif 	/* __AcadPieSector_FWD_DEFINED__ */


#ifndef __IAcadPieSectors_FWD_DEFINED__
#define __IAcadPieSectors_FWD_DEFINED__
typedef interface IAcadPieSectors IAcadPieSectors;

#endif 	/* __IAcadPieSectors_FWD_DEFINED__ */


#ifndef __AcadPieSectors_FWD_DEFINED__
#define __AcadPieSectors_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPieSectors AcadPieSectors;
#else
typedef struct AcadPieSectors AcadPieSectors;
#endif /* __cplusplus */

#endif 	/* __AcadPieSectors_FWD_DEFINED__ */


#ifndef __AcadPieSectorsEnum_FWD_DEFINED__
#define __AcadPieSectorsEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPieSectorsEnum AcadPieSectorsEnum;
#else
typedef struct AcadPieSectorsEnum AcadPieSectorsEnum;
#endif /* __cplusplus */

#endif 	/* __AcadPieSectorsEnum_FWD_DEFINED__ */


#ifndef __IAcadPie_FWD_DEFINED__
#define __IAcadPie_FWD_DEFINED__
typedef interface IAcadPie IAcadPie;

#endif 	/* __IAcadPie_FWD_DEFINED__ */


#ifndef __AcadPie_FWD_DEFINED__
#define __AcadPie_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadPie AcadPie;
#else
typedef struct AcadPie AcadPie;
#endif /* __cplusplus */

#endif 	/* __AcadPie_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AsdkDeepPropInspectorLib_LIBRARY_DEFINED__
#define __AsdkDeepPropInspectorLib_LIBRARY_DEFINED__

/* library AsdkDeepPropInspectorLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AsdkDeepPropInspectorLib;

#ifndef __IAcadPieSector_INTERFACE_DEFINED__
#define __IAcadPieSector_INTERFACE_DEFINED__

/* interface IAcadPieSector */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcadPieSector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("601F7769-86D4-42FB-962F-042329B702CA")
    IAcadPieSector : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Exploded( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Exploded( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TrueColor( 
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **ppColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TrueColor( 
            /* [in] */ /* external definition not present */ IAcadAcCmColor *pColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ /* external definition not present */ ACAD_COLOR *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Color( 
            /* [in] */ /* external definition not present */ ACAD_COLOR cColor) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPieSectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPieSector * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPieSector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPieSector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPieSector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPieSector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPieSector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPieSector * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Exploded )( 
            IAcadPieSector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Exploded )( 
            IAcadPieSector * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IAcadPieSector * This,
            /* [retval][out] */ /* external definition not present */ IAcadAcCmColor **ppColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IAcadPieSector * This,
            /* [in] */ /* external definition not present */ IAcadAcCmColor *pColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IAcadPieSector * This,
            /* [retval][out] */ /* external definition not present */ ACAD_COLOR *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IAcadPieSector * This,
            /* [in] */ /* external definition not present */ ACAD_COLOR cColor);
        
        END_INTERFACE
    } IAcadPieSectorVtbl;

    interface IAcadPieSector
    {
        CONST_VTBL struct IAcadPieSectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPieSector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPieSector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPieSector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPieSector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPieSector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPieSector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPieSector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPieSector_get_Exploded(This,pVal)	\
    ( (This)->lpVtbl -> get_Exploded(This,pVal) ) 

#define IAcadPieSector_put_Exploded(This,newVal)	\
    ( (This)->lpVtbl -> put_Exploded(This,newVal) ) 

#define IAcadPieSector_get_TrueColor(This,ppColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,ppColor) ) 

#define IAcadPieSector_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IAcadPieSector_get_Color(This,pColor)	\
    ( (This)->lpVtbl -> get_Color(This,pColor) ) 

#define IAcadPieSector_put_Color(This,cColor)	\
    ( (This)->lpVtbl -> put_Color(This,cColor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPieSector_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcadPieSector;

#ifdef __cplusplus

class DECLSPEC_UUID("FABA78D8-3083-4AC8-9BB2-BCDEDB95A0E6")
AcadPieSector;
#endif

#ifndef __IAcadPieSectors_INTERFACE_DEFINED__
#define __IAcadPieSectors_INTERFACE_DEFINED__

/* interface IAcadPieSectors */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcadPieSectors;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("907EAF23-8D93-46A2-8AD5-73E227A86803")
    IAcadPieSectors : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSimpleSector( 
            /* [in] */ DOUBLE val,
            /* [out] */ IAcadPieSector **ppSector) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPieSectorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPieSectors * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPieSectors * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcadPieSectors * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPieSectors * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPieSectors * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPieSectors * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPieSectors * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAcadPieSectors * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAcadPieSectors * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAcadPieSectors * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSimpleSector )( 
            IAcadPieSectors * This,
            /* [in] */ DOUBLE val,
            /* [out] */ IAcadPieSector **ppSector);
        
        END_INTERFACE
    } IAcadPieSectorsVtbl;

    interface IAcadPieSectors
    {
        CONST_VTBL struct IAcadPieSectorsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPieSectors_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcadPieSectors_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcadPieSectors_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcadPieSectors_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcadPieSectors_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcadPieSectors_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcadPieSectors_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcadPieSectors_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IAcadPieSectors_get_Item(This,vIndex,ppUnk)	\
    ( (This)->lpVtbl -> get_Item(This,vIndex,ppUnk) ) 

#define IAcadPieSectors_get__NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppUnk) ) 

#define IAcadPieSectors_AddSimpleSector(This,val,ppSector)	\
    ( (This)->lpVtbl -> AddSimpleSector(This,val,ppSector) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPieSectors_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcadPieSectors;

#ifdef __cplusplus

class DECLSPEC_UUID("B07FA972-C43A-4FE8-83F8-8B4C557B42A8")
AcadPieSectors;
#endif

EXTERN_C const CLSID CLSID_AcadPieSectorsEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("106CF43F-48F2-405b-9BF0-303DFF8A004F")
AcadPieSectorsEnum;
#endif

#ifndef __IAcadPie_INTERFACE_DEFINED__
#define __IAcadPie_INTERFACE_DEFINED__

/* interface IAcadPie */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcadPie;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A4D3EFDD-DD8A-435F-B665-63B0942F9D5E")
    IAcadPie : public IAcadCircle
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllExploded( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllExploded( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Clockwise( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Clockwise( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sectors( 
            /* [retval][out] */ IAcadPieSectors **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcadPieVtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcadPie * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            IAcadPie * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            IAcadPie * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcadPie * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcadPie * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcadPie * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcadPie * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BSTR AppName,
            /* [out][idldescattr] */ VARIANT *XDataType,
            /* [out][idldescattr] */ VARIANT *XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT XDataType,
            /* [in][idldescattr] */ VARIANT XDataValue,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IAcadPie * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IAcadPie * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IAcadPie * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IAcadPie * This,
            /* [retval][out] */ IAcadDatabase **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IAcadPie * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IAcadPie * This,
            /* [retval][out] */ IAcadDictionary **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IAcadPie * This,
            /* [retval][out] */ LONG_PTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IAcadPie * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IAcadPie * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IAcadPie * This,
            /* [retval][out] */ IAcadAcCmColor **retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IAcadPie * This,
            /* [in][idldescattr] */ IAcadAcCmColor *noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IAcadPie * This,
            /* [retval][out] */ ACAD_NOUNITS *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IAcadPie * This,
            /* [in][idldescattr] */ ACAD_NOUNITS noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IAcadPie * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IAcadPie * This,
            /* [in][idldescattr] */ signed INT NumberOfObjects,
            /* [in][idldescattr] */ double AngleToFill,
            /* [in][idldescattr] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IAcadPie * This,
            /* [in][idldescattr] */ signed INT NumberOfRows,
            /* [in][idldescattr] */ signed INT NumberOfColumns,
            /* [in][idldescattr] */ signed INT NumberOfLevels,
            /* [in][idldescattr] */ double DistBetweenRows,
            /* [in][idldescattr] */ double DistBetweenCols,
            /* [in][idldescattr] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BOOLEAN HighlightFlag,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IAcadPie * This,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT FromPoint,
            /* [in][idldescattr] */ VARIANT ToPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ double RotationAngle,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT Point1,
            /* [in][idldescattr] */ VARIANT Point2,
            /* [in][idldescattr] */ VARIANT point3,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT BasePoint,
            /* [in][idldescattr] */ double ScaleFactor,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT TransformationMatrix,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IAcadPie * This,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IAcadPie * This,
            /* [out][idldescattr] */ VARIANT *MinPoint,
            /* [out][idldescattr] */ VARIANT *MaxPoint,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IAcadPie * This,
            /* [in][idldescattr] */ IDispatch *IntersectObject,
            /* [in][idldescattr] */ enum AcExtendOption option,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IAcadPie * This,
            /* [retval][out] */ ACAD_LWEIGHT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IAcadPie * This,
            /* [in][idldescattr] */ ACAD_LWEIGHT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IAcadPie * This,
            /* [retval][out] */ IAcadHyperlinks **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IAcadPie * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IAcadPie * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IAcadPie * This,
            /* [retval][out] */ ACAD_COLOR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IAcadPie * This,
            /* [in][idldescattr] */ ACAD_COLOR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Center )( 
            IAcadPie * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Center )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Radius )( 
            IAcadPie * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Radius )( 
            IAcadPie * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Diameter )( 
            IAcadPie * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Diameter )( 
            IAcadPie * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Circumference )( 
            IAcadPie * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Circumference )( 
            IAcadPie * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Area )( 
            IAcadPie * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Area )( 
            IAcadPie * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Normal )( 
            IAcadPie * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Normal )( 
            IAcadPie * This,
            /* [in][idldescattr] */ VARIANT noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Thickness )( 
            IAcadPie * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Thickness )( 
            IAcadPie * This,
            /* [in][idldescattr] */ double noname,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Offset )( 
            IAcadPie * This,
            /* [in][idldescattr] */ double Distance,
            /* [retval][out] */ VARIANT *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IAcadPie * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IAcadPie * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllExploded )( 
            IAcadPie * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllExploded )( 
            IAcadPie * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Clockwise )( 
            IAcadPie * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Clockwise )( 
            IAcadPie * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sectors )( 
            IAcadPie * This,
            /* [retval][out] */ IAcadPieSectors **ppVal);
        
        END_INTERFACE
    } IAcadPieVtbl;

    interface IAcadPie
    {
        CONST_VTBL struct IAcadPieVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcadPie_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define IAcadPie_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define IAcadPie_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define IAcadPie_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define IAcadPie_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define IAcadPie_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define IAcadPie_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define IAcadPie_get_Handle(This,retval)	\
    ( (This)->lpVtbl -> get_Handle(This,retval) ) 

#define IAcadPie_get_ObjectName(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectName(This,retval) ) 

#define IAcadPie_GetXData(This,AppName,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue,retval) ) 

#define IAcadPie_SetXData(This,XDataType,XDataValue,retval)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue,retval) ) 

#define IAcadPie_Delete(This,retval)	\
    ( (This)->lpVtbl -> Delete(This,retval) ) 

#define IAcadPie_get_ObjectID(This,retval)	\
    ( (This)->lpVtbl -> get_ObjectID(This,retval) ) 

#define IAcadPie_get_Application(This,retval)	\
    ( (This)->lpVtbl -> get_Application(This,retval) ) 

#define IAcadPie_get_Database(This,retval)	\
    ( (This)->lpVtbl -> get_Database(This,retval) ) 

#define IAcadPie_get_HasExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,retval) ) 

#define IAcadPie_GetExtensionDictionary(This,retval)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,retval) ) 

#define IAcadPie_get_OwnerID(This,retval)	\
    ( (This)->lpVtbl -> get_OwnerID(This,retval) ) 

#define IAcadPie_get_Document(This,retval)	\
    ( (This)->lpVtbl -> get_Document(This,retval) ) 

#define IAcadPie_Erase(This,retval)	\
    ( (This)->lpVtbl -> Erase(This,retval) ) 

#define IAcadPie_get_TrueColor(This,retval)	\
    ( (This)->lpVtbl -> get_TrueColor(This,retval) ) 

#define IAcadPie_put_TrueColor(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TrueColor(This,noname,retval) ) 

#define IAcadPie_get_Layer(This,retval)	\
    ( (This)->lpVtbl -> get_Layer(This,retval) ) 

#define IAcadPie_put_Layer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Layer(This,noname,retval) ) 

#define IAcadPie_get_Linetype(This,retval)	\
    ( (This)->lpVtbl -> get_Linetype(This,retval) ) 

#define IAcadPie_put_Linetype(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Linetype(This,noname,retval) ) 

#define IAcadPie_get_LinetypeScale(This,retval)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,retval) ) 

#define IAcadPie_put_LinetypeScale(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,noname,retval) ) 

#define IAcadPie_get_Visible(This,retval)	\
    ( (This)->lpVtbl -> get_Visible(This,retval) ) 

#define IAcadPie_put_Visible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Visible(This,noname,retval) ) 

#define IAcadPie_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,retval) ) 

#define IAcadPie_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,retval) ) 

#define IAcadPie_Highlight(This,HighlightFlag,retval)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag,retval) ) 

#define IAcadPie_Copy(This,retval)	\
    ( (This)->lpVtbl -> Copy(This,retval) ) 

#define IAcadPie_Move(This,FromPoint,ToPoint,retval)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint,retval) ) 

#define IAcadPie_Rotate(This,BasePoint,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle,retval) ) 

#define IAcadPie_Rotate3D(This,Point1,Point2,RotationAngle,retval)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle,retval) ) 

#define IAcadPie_Mirror(This,Point1,Point2,retval)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,retval) ) 

#define IAcadPie_Mirror3D(This,Point1,Point2,point3,retval)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,retval) ) 

#define IAcadPie_ScaleEntity(This,BasePoint,ScaleFactor,retval)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor,retval) ) 

#define IAcadPie_TransformBy(This,TransformationMatrix,retval)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix,retval) ) 

#define IAcadPie_Update(This,retval)	\
    ( (This)->lpVtbl -> Update(This,retval) ) 

#define IAcadPie_GetBoundingBox(This,MinPoint,MaxPoint,retval)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint,retval) ) 

#define IAcadPie_IntersectWith(This,IntersectObject,option,retval)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,retval) ) 

#define IAcadPie_get_PlotStyleName(This,retval)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,retval) ) 

#define IAcadPie_put_PlotStyleName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,noname,retval) ) 

#define IAcadPie_get_Lineweight(This,retval)	\
    ( (This)->lpVtbl -> get_Lineweight(This,retval) ) 

#define IAcadPie_put_Lineweight(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Lineweight(This,noname,retval) ) 

#define IAcadPie_get_EntityTransparency(This,retval)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,retval) ) 

#define IAcadPie_put_EntityTransparency(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,noname,retval) ) 

#define IAcadPie_get_Hyperlinks(This,retval)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,retval) ) 

#define IAcadPie_get_Material(This,retval)	\
    ( (This)->lpVtbl -> get_Material(This,retval) ) 

#define IAcadPie_put_Material(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Material(This,noname,retval) ) 

#define IAcadPie_get_EntityName(This,retval)	\
    ( (This)->lpVtbl -> get_EntityName(This,retval) ) 

#define IAcadPie_get_EntityType(This,retval)	\
    ( (This)->lpVtbl -> get_EntityType(This,retval) ) 

#define IAcadPie_get_color(This,retval)	\
    ( (This)->lpVtbl -> get_color(This,retval) ) 

#define IAcadPie_put_color(This,noname,retval)	\
    ( (This)->lpVtbl -> put_color(This,noname,retval) ) 

#define IAcadPie_get_Center(This,retval)	\
    ( (This)->lpVtbl -> get_Center(This,retval) ) 

#define IAcadPie_put_Center(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Center(This,noname,retval) ) 

#define IAcadPie_get_Radius(This,retval)	\
    ( (This)->lpVtbl -> get_Radius(This,retval) ) 

#define IAcadPie_put_Radius(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Radius(This,noname,retval) ) 

#define IAcadPie_get_Diameter(This,retval)	\
    ( (This)->lpVtbl -> get_Diameter(This,retval) ) 

#define IAcadPie_put_Diameter(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Diameter(This,noname,retval) ) 

#define IAcadPie_get_Circumference(This,retval)	\
    ( (This)->lpVtbl -> get_Circumference(This,retval) ) 

#define IAcadPie_put_Circumference(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Circumference(This,noname,retval) ) 

#define IAcadPie_get_Area(This,retval)	\
    ( (This)->lpVtbl -> get_Area(This,retval) ) 

#define IAcadPie_put_Area(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Area(This,noname,retval) ) 

#define IAcadPie_get_Normal(This,retval)	\
    ( (This)->lpVtbl -> get_Normal(This,retval) ) 

#define IAcadPie_put_Normal(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Normal(This,noname,retval) ) 

#define IAcadPie_get_Thickness(This,retval)	\
    ( (This)->lpVtbl -> get_Thickness(This,retval) ) 

#define IAcadPie_put_Thickness(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Thickness(This,noname,retval) ) 

#define IAcadPie_Offset(This,Distance,retval)	\
    ( (This)->lpVtbl -> Offset(This,Distance,retval) ) 


#define IAcadPie_get_Title(This,pVal)	\
    ( (This)->lpVtbl -> get_Title(This,pVal) ) 

#define IAcadPie_put_Title(This,newVal)	\
    ( (This)->lpVtbl -> put_Title(This,newVal) ) 

#define IAcadPie_get_AllExploded(This,pVal)	\
    ( (This)->lpVtbl -> get_AllExploded(This,pVal) ) 

#define IAcadPie_put_AllExploded(This,newVal)	\
    ( (This)->lpVtbl -> put_AllExploded(This,newVal) ) 

#define IAcadPie_get_Clockwise(This,pVal)	\
    ( (This)->lpVtbl -> get_Clockwise(This,pVal) ) 

#define IAcadPie_put_Clockwise(This,newVal)	\
    ( (This)->lpVtbl -> put_Clockwise(This,newVal) ) 

#define IAcadPie_get_Sectors(This,ppVal)	\
    ( (This)->lpVtbl -> get_Sectors(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcadPie_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcadPie;

#ifdef __cplusplus

class DECLSPEC_UUID("BD5E4DAA-12BF-4D52-9E45-25C67C973720")
AcadPie;
#endif
#endif /* __AsdkDeepPropInspectorLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


