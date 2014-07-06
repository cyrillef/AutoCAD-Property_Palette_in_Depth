

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Aug 17 09:59:20 2004
 */
/* Compiler settings for .\DeepPropInspector.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


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
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_AsdkDeepPropInspectorLib,0xA31FE251,0x1A57,0x437B,0x97,0xB3,0xBE,0x37,0xB1,0x4C,0x64,0xA2);


MIDL_DEFINE_GUID(IID, IID_IAcadPieSector,0x601F7769,0x86D4,0x42FB,0x96,0x2F,0x04,0x23,0x29,0xB7,0x02,0xCA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPieSector,0xFABA78D8,0x3083,0x4AC8,0x9B,0xB2,0xBC,0xDE,0xDB,0x95,0xA0,0xE6);


MIDL_DEFINE_GUID(IID, IID_IAcadPieSectors,0x907EAF23,0x8D93,0x46A2,0x8A,0xD5,0x73,0xE2,0x27,0xA8,0x68,0x03);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPieSectors,0xB07FA972,0xC43A,0x4FE8,0x83,0xF8,0x8B,0x4C,0x55,0x7B,0x42,0xA8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPieSectorsEnum,0x106CF43F,0x48F2,0x405b,0x9B,0xF0,0x30,0x3D,0xFF,0x8A,0x00,0x4F);


MIDL_DEFINE_GUID(IID, IID_IAcadPie,0xA4D3EFDD,0xDD8A,0x435F,0xB6,0x65,0x63,0xB0,0x94,0x2F,0x9D,0x5E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPie,0xBD5E4DAA,0x12BF,0x4D52,0x9E,0x45,0x25,0xC6,0x7C,0x97,0x37,0x20);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

