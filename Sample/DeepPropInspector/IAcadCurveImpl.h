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
//----- IAcadCurveImpl.h : Declaration of the IAcadCurveImpl
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#include "resource.h"
#include "DeepPropInspector.h"
#include "IBaseObjectImpl.h"

//-----------------------------------------------------------------------------
template <
	class T, class rxClass, class interfaceClass,
		const IID *pclsid, const IID *piid =&__uuidof (interfaceClass),
		const GUID *plibid =&CAtlModule::m_libid
>
class ATL_NO_VTABLE IAcadCurveImpl : 
	//	public IOPMPropertyExtensionImpl2<T>,
	//	public IAcPiCategorizePropertiesImpl<T>,
	//	public IOPMPropertyExpander,
	public IAcadEntityBaseDispatchImpl<T, rxClass, interfaceClass, pclsid, piid, plibid>
{
public:
	//- IAcadCurve
} ;
