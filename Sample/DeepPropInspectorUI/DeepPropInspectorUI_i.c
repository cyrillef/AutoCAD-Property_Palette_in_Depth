

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_AsdkDeepPropInspectorUILib,0x9AAD2845,0x4D4B,0x43F6,0xA3,0x35,0xAE,0x32,0x63,0x31,0x08,0xAE);


MIDL_DEFINE_GUID(IID, IID_IAsdkSpinner,0x6E6302B9,0x4EE3,0x443f,0x81,0x83,0xDE,0x2C,0x57,0x72,0x23,0x25);


MIDL_DEFINE_GUID(IID, DIID__IAsdkSpinnerEvents,0x6FFEEA70,0xE9E3,0x4ab7,0x84,0x9D,0x1B,0x59,0x11,0xEC,0x7E,0x72);


MIDL_DEFINE_GUID(CLSID, CLSID_AsdkSpinner,0x79A97213,0x610C,0x4e91,0x9F,0x53,0xAF,0x42,0x84,0x92,0xCA,0x43);


MIDL_DEFINE_GUID(IID, IID_IPieSectorsCount,0x1BF306F9,0xF5E0,0x4e03,0x90,0xF1,0x40,0xE8,0x5A,0x0B,0xF8,0xE1);


MIDL_DEFINE_GUID(CLSID, CLSID_PieSectorsCount,0xB8594FEC,0xD059,0x4bc2,0x99,0x67,0xD8,0x6E,0xB9,0xFB,0xB7,0xDA);


MIDL_DEFINE_GUID(IID, IID_IPieSectorsSpin,0x295EF768,0xEF00,0x4e7c,0x93,0x5E,0x85,0x87,0x72,0xE2,0xD0,0xBF);


MIDL_DEFINE_GUID(CLSID, CLSID_PieSectorsSpin,0xC254C627,0x905A,0x41df,0xB8,0x21,0xFE,0x56,0x9B,0x1E,0xCA,0x73);


MIDL_DEFINE_GUID(IID, IID_IPieSectorExploded,0x17105299,0x5894,0x427f,0xA6,0xB6,0xAC,0xC1,0xA5,0xCE,0xB8,0x9A);


MIDL_DEFINE_GUID(CLSID, CLSID_PieSectorExploded,0x31DF0413,0x9691,0x4c45,0x9E,0xAB,0xE7,0xD3,0x97,0xF1,0x93,0x62);


MIDL_DEFINE_GUID(IID, IID_IPieSectorImage,0x80ACF585,0x655E,0x4619,0x82,0x87,0x18,0x45,0x00,0x63,0x6D,0x48);


MIDL_DEFINE_GUID(CLSID, CLSID_PieSectorImage,0x14A844BA,0x9FE4,0x47ED,0x9C,0xDC,0x69,0x27,0x0A,0x77,0xE1,0x72);


MIDL_DEFINE_GUID(IID, IID_IPieSectorColor,0x8F676F52,0x452D,0x4f13,0x91,0x24,0x3E,0x2B,0xF2,0x1A,0xC6,0x6A);


MIDL_DEFINE_GUID(CLSID, CLSID_PieSectorColor,0x3F931CE4,0x524D,0x4857,0xA2,0x61,0xF9,0x39,0x29,0x43,0xEB,0xF8);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



