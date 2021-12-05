#pragma once
#include <winerror.h>
#include "COMDeclaration.h"

typedef  struct 
{
	PFN_ADDREF pfn_AddRef;
	PFN_DECREF pfn_DecRef;
	PFN_QUERYINTERFACE pfn_QueryInterface;
}COMInterface_vfptr;

typedef struct _COMInterface
{
	const COMInterface_vfptr* __vfptr;

}COMInterface;


typedef struct 
{
	PFN_CRCR32 pfn_Crc32;
}ICrc32_vfptr;
typedef struct _ICrc32
{
	const ICrc32_vfptr* __vfptr;
}ICrc32;


typedef struct 
{
	PDN_MD5 pfn_Md5;
}IMd5_vfptr;
typedef struct _IMd5
{
	const IMd5_vfptr* __vfptr;
}IMd5;

