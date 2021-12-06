#pragma once
#include <winerror.h>
#include "COMDeclaration.h"

typedef  struct 
{
	PFN_ADDREF pfn_AddRef;
	PFN_DECREF pfn_DecRef;
	PFN_QUERYINTERFACE pfn_QueryInterface;
<<<<<<< HEAD
}COMInterface_vfptr;

typedef struct _COMInterface
{
	const COMInterface_vfptr* __vfptr;

}COMInterface;
=======
}IMyUnknown_vfptr;

typedef struct _IMyUnknown
{
	const IMyUnknown_vfptr* __vfptr;

}IMyUnknown;
>>>>>>> c6e920d (修改子类this指针)



typedef struct 
{
	PFN_ADDREF pfn_AddRef;
	PFN_DECREF pfn_DecRef;
	PFN_QUERYINTERFACE pfn_QueryInterface;
	PFN_GETINSTANCE pfn_GetInstance;
}IFACTORY_vfptr;
typedef struct _IFactory
{
	const IFACTORY_vfptr* __vfptr;
}IFactory;



typedef struct 
{
	PFN_ADDREF pfn_AddRef;
	PFN_DECREF pfn_DecRef;
	PFN_QUERYINTERFACE pfn_QueryInterface;
	PFN_CRCR32 pfn_Crc32;
}ICrc32_vfptr;
typedef struct _ICrc32
{

	const ICrc32_vfptr* __vfptr;
}ICrc32;


typedef struct 
{
	PFN_ADDREF pfn_AddRef;
	PFN_DECREF pfn_DecRef;
	PFN_QUERYINTERFACE pfn_QueryInterface;
	PDN_MD5 pfn_Md5;
}IMd5_vfptr;
typedef struct _IMd5
{
	const IMd5_vfptr* __vfptr;
}IMd5;

