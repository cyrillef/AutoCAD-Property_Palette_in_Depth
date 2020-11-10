

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 08:44:07 2038
 */
/* Compiler settings for DeepPropInspectorUI.idl:
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


#ifndef __DeepPropInspectorUI_h__
#define __DeepPropInspectorUI_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsdkSpinner_FWD_DEFINED__
#define __IAsdkSpinner_FWD_DEFINED__
typedef interface IAsdkSpinner IAsdkSpinner;

#endif 	/* __IAsdkSpinner_FWD_DEFINED__ */


#ifndef ___IAsdkSpinnerEvents_FWD_DEFINED__
#define ___IAsdkSpinnerEvents_FWD_DEFINED__
typedef interface _IAsdkSpinnerEvents _IAsdkSpinnerEvents;

#endif 	/* ___IAsdkSpinnerEvents_FWD_DEFINED__ */


#ifndef __AsdkSpinner_FWD_DEFINED__
#define __AsdkSpinner_FWD_DEFINED__

#ifdef __cplusplus
typedef class AsdkSpinner AsdkSpinner;
#else
typedef struct AsdkSpinner AsdkSpinner;
#endif /* __cplusplus */

#endif 	/* __AsdkSpinner_FWD_DEFINED__ */


#ifndef __IPieSectorsCount_FWD_DEFINED__
#define __IPieSectorsCount_FWD_DEFINED__
typedef interface IPieSectorsCount IPieSectorsCount;

#endif 	/* __IPieSectorsCount_FWD_DEFINED__ */


#ifndef __PieSectorsCount_FWD_DEFINED__
#define __PieSectorsCount_FWD_DEFINED__

#ifdef __cplusplus
typedef class PieSectorsCount PieSectorsCount;
#else
typedef struct PieSectorsCount PieSectorsCount;
#endif /* __cplusplus */

#endif 	/* __PieSectorsCount_FWD_DEFINED__ */


#ifndef __IPieSectorsSpin_FWD_DEFINED__
#define __IPieSectorsSpin_FWD_DEFINED__
typedef interface IPieSectorsSpin IPieSectorsSpin;

#endif 	/* __IPieSectorsSpin_FWD_DEFINED__ */


#ifndef __PieSectorsSpin_FWD_DEFINED__
#define __PieSectorsSpin_FWD_DEFINED__

#ifdef __cplusplus
typedef class PieSectorsSpin PieSectorsSpin;
#else
typedef struct PieSectorsSpin PieSectorsSpin;
#endif /* __cplusplus */

#endif 	/* __PieSectorsSpin_FWD_DEFINED__ */


#ifndef __IPieSectorExploded_FWD_DEFINED__
#define __IPieSectorExploded_FWD_DEFINED__
typedef interface IPieSectorExploded IPieSectorExploded;

#endif 	/* __IPieSectorExploded_FWD_DEFINED__ */


#ifndef __PieSectorExploded_FWD_DEFINED__
#define __PieSectorExploded_FWD_DEFINED__

#ifdef __cplusplus
typedef class PieSectorExploded PieSectorExploded;
#else
typedef struct PieSectorExploded PieSectorExploded;
#endif /* __cplusplus */

#endif 	/* __PieSectorExploded_FWD_DEFINED__ */


#ifndef __IPieSectorImage_FWD_DEFINED__
#define __IPieSectorImage_FWD_DEFINED__
typedef interface IPieSectorImage IPieSectorImage;

#endif 	/* __IPieSectorImage_FWD_DEFINED__ */


#ifndef __PieSectorImage_FWD_DEFINED__
#define __PieSectorImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class PieSectorImage PieSectorImage;
#else
typedef struct PieSectorImage PieSectorImage;
#endif /* __cplusplus */

#endif 	/* __PieSectorImage_FWD_DEFINED__ */


#ifndef __IPieSectorColor_FWD_DEFINED__
#define __IPieSectorColor_FWD_DEFINED__
typedef interface IPieSectorColor IPieSectorColor;

#endif 	/* __IPieSectorColor_FWD_DEFINED__ */


#ifndef __PieSectorColor_FWD_DEFINED__
#define __PieSectorColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class PieSectorColor PieSectorColor;
#else
typedef struct PieSectorColor PieSectorColor;
#endif /* __cplusplus */

#endif 	/* __PieSectorColor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AsdkDeepPropInspectorUILib_LIBRARY_DEFINED__
#define __AsdkDeepPropInspectorUILib_LIBRARY_DEFINED__

/* library AsdkDeepPropInspectorUILib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AsdkDeepPropInspectorUILib;

#ifndef __IAsdkSpinner_INTERFACE_DEFINED__
#define __IAsdkSpinner_INTERFACE_DEFINED__

/* interface IAsdkSpinner */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAsdkSpinner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E6302B9-4EE3-443f-8183-DE2C57722325")
    IAsdkSpinner : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *pHWND) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsdkSpinnerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsdkSpinner * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsdkSpinner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsdkSpinner * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAsdkSpinner * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAsdkSpinner * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAsdkSpinner * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAsdkSpinner * This,
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
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IAsdkSpinner * This,
            /* [retval][out] */ LONG_PTR *pHWND);
        
        END_INTERFACE
    } IAsdkSpinnerVtbl;

    interface IAsdkSpinner
    {
        CONST_VTBL struct IAsdkSpinnerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsdkSpinner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsdkSpinner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsdkSpinner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsdkSpinner_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAsdkSpinner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAsdkSpinner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAsdkSpinner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAsdkSpinner_get_HWND(This,pHWND)	\
    ( (This)->lpVtbl -> get_HWND(This,pHWND) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsdkSpinner_INTERFACE_DEFINED__ */


#ifndef ___IAsdkSpinnerEvents_DISPINTERFACE_DEFINED__
#define ___IAsdkSpinnerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAsdkSpinnerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IAsdkSpinnerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6FFEEA70-E9E3-4ab7-849D-1B5911EC7E72")
    _IAsdkSpinnerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IAsdkSpinnerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IAsdkSpinnerEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IAsdkSpinnerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IAsdkSpinnerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IAsdkSpinnerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IAsdkSpinnerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IAsdkSpinnerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IAsdkSpinnerEvents * This,
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
        
        END_INTERFACE
    } _IAsdkSpinnerEventsVtbl;

    interface _IAsdkSpinnerEvents
    {
        CONST_VTBL struct _IAsdkSpinnerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IAsdkSpinnerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IAsdkSpinnerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IAsdkSpinnerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IAsdkSpinnerEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IAsdkSpinnerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IAsdkSpinnerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IAsdkSpinnerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IAsdkSpinnerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AsdkSpinner;

#ifdef __cplusplus

class DECLSPEC_UUID("79A97213-610C-4e91-9F53-AF428492CA43")
AsdkSpinner;
#endif

#ifndef __IPieSectorsCount_INTERFACE_DEFINED__
#define __IPieSectorsCount_INTERFACE_DEFINED__

/* interface IPieSectorsCount */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPieSectorsCount;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1BF306F9-F5E0-4e03-90F1-40E85A0BF8E1")
    IPieSectorsCount : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IPieSectorsCountVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPieSectorsCount * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPieSectorsCount * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPieSectorsCount * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPieSectorsCount * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPieSectorsCount * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPieSectorsCount * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPieSectorsCount * This,
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
        
        END_INTERFACE
    } IPieSectorsCountVtbl;

    interface IPieSectorsCount
    {
        CONST_VTBL struct IPieSectorsCountVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPieSectorsCount_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPieSectorsCount_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPieSectorsCount_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPieSectorsCount_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPieSectorsCount_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPieSectorsCount_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPieSectorsCount_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPieSectorsCount_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PieSectorsCount;

#ifdef __cplusplus

class DECLSPEC_UUID("B8594FEC-D059-4bc2-9967-D86EB9FBB7DA")
PieSectorsCount;
#endif

#ifndef __IPieSectorsSpin_INTERFACE_DEFINED__
#define __IPieSectorsSpin_INTERFACE_DEFINED__

/* interface IPieSectorsSpin */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPieSectorsSpin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("295EF768-EF00-4e7c-935E-858772E2D0BF")
    IPieSectorsSpin : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Counter( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPieSectorsSpinVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPieSectorsSpin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPieSectorsSpin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPieSectorsSpin * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPieSectorsSpin * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPieSectorsSpin * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPieSectorsSpin * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPieSectorsSpin * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Counter )( 
            IPieSectorsSpin * This,
            /* [retval][out] */ ULONG *pVal);
        
        END_INTERFACE
    } IPieSectorsSpinVtbl;

    interface IPieSectorsSpin
    {
        CONST_VTBL struct IPieSectorsSpinVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPieSectorsSpin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPieSectorsSpin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPieSectorsSpin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPieSectorsSpin_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPieSectorsSpin_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPieSectorsSpin_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPieSectorsSpin_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPieSectorsSpin_get_Counter(This,pVal)	\
    ( (This)->lpVtbl -> get_Counter(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPieSectorsSpin_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PieSectorsSpin;

#ifdef __cplusplus

class DECLSPEC_UUID("C254C627-905A-41df-B821-FE569B1ECA73")
PieSectorsSpin;
#endif

#ifndef __IPieSectorExploded_INTERFACE_DEFINED__
#define __IPieSectorExploded_INTERFACE_DEFINED__

/* interface IPieSectorExploded */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPieSectorExploded;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17105299-5894-427f-A6B6-ACC1A5CEB89A")
    IPieSectorExploded : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IPieSectorExplodedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPieSectorExploded * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPieSectorExploded * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPieSectorExploded * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPieSectorExploded * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPieSectorExploded * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPieSectorExploded * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPieSectorExploded * This,
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
        
        END_INTERFACE
    } IPieSectorExplodedVtbl;

    interface IPieSectorExploded
    {
        CONST_VTBL struct IPieSectorExplodedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPieSectorExploded_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPieSectorExploded_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPieSectorExploded_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPieSectorExploded_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPieSectorExploded_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPieSectorExploded_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPieSectorExploded_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPieSectorExploded_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PieSectorExploded;

#ifdef __cplusplus

class DECLSPEC_UUID("31DF0413-9691-4c45-9EAB-E7D397F19362")
PieSectorExploded;
#endif

#ifndef __IPieSectorImage_INTERFACE_DEFINED__
#define __IPieSectorImage_INTERFACE_DEFINED__

/* interface IPieSectorImage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPieSectorImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("80ACF585-655E-4619-8287-184500636D48")
    IPieSectorImage : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IPieSectorImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPieSectorImage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPieSectorImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPieSectorImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPieSectorImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPieSectorImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPieSectorImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPieSectorImage * This,
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
        
        END_INTERFACE
    } IPieSectorImageVtbl;

    interface IPieSectorImage
    {
        CONST_VTBL struct IPieSectorImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPieSectorImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPieSectorImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPieSectorImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPieSectorImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPieSectorImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPieSectorImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPieSectorImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPieSectorImage_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PieSectorImage;

#ifdef __cplusplus

class DECLSPEC_UUID("14A844BA-9FE4-47ED-9CDC-69270A77E172")
PieSectorImage;
#endif

#ifndef __IPieSectorColor_INTERFACE_DEFINED__
#define __IPieSectorColor_INTERFACE_DEFINED__

/* interface IPieSectorColor */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPieSectorColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F676F52-452D-4f13-9124-3E2BF21AC66A")
    IPieSectorColor : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IPieSectorColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPieSectorColor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPieSectorColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPieSectorColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPieSectorColor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPieSectorColor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPieSectorColor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPieSectorColor * This,
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
        
        END_INTERFACE
    } IPieSectorColorVtbl;

    interface IPieSectorColor
    {
        CONST_VTBL struct IPieSectorColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPieSectorColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPieSectorColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPieSectorColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPieSectorColor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPieSectorColor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPieSectorColor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPieSectorColor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPieSectorColor_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PieSectorColor;

#ifdef __cplusplus

class DECLSPEC_UUID("3F931CE4-524D-4857-A261-F9392943EBF8")
PieSectorColor;
#endif
#endif /* __AsdkDeepPropInspectorUILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


