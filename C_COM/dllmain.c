// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Interface.h"
#include <stdlib.h>
#include <stdio.h>

<<<<<<< HEAD

=======
static const ICrc32_vfptr s_ICrc32_vfptr;
static const IMd5_vfptr s_IMd5_vfptr;
>>>>>>> c6e920d (修改子类this指针)

typedef struct _AlgHash
{
	//COMInterface base;
	ICrc32 Crc32;
	IMd5 MD5;

	size_t nRefCount;

}AlgHash;


<<<<<<< HEAD
HRESULT __stdcall AddRef(LPVOID pThis,GUID iidType, size_t* pCount)
{
	if (!memcmp(&iidType, &s_iidCrc32, sizeof(iidType)))
	{
		pThis = (LPVOID)((char*)pThis -(char*)((&((AlgHash*)NULL)->Crc32)));
	}
	else if (!memcmp(&iidType, &s_iidMd5, sizeof(iidType)))
=======
HRESULT __stdcall AddRef(LPVOID pThis, size_t* pCount)
{
	if ((*(DWORD*)pThis) == ((DWORD)&s_ICrc32_vfptr))
	{
		pThis = (LPVOID)((char*)pThis - (char*)((&((AlgHash*)NULL)->Crc32)));
	}
	else if ((*(DWORD*)pThis) == ((DWORD)&s_IMd5_vfptr))
>>>>>>> c6e920d (修改子类this指针)
	{
		pThis = (LPVOID)((char*)pThis - (char*)((&((AlgHash*)NULL)->MD5)));
	}

<<<<<<< HEAD
=======

>>>>>>> c6e920d (修改子类this指针)
	size_t* pRefCount = &((AlgHash*)pThis)->nRefCount;
	++(*pRefCount);
	if (pCount)
	{
		*pCount = *pRefCount;
	}
	return ERROR_SUCCESS;
}
<<<<<<< HEAD
HRESULT __stdcall DecRef(LPVOID pThis, GUID iidType, size_t* pCount)
{
	if (!memcmp(&iidType, &s_iidCrc32, sizeof(iidType)))
	{
		pThis = (LPVOID)((char*)pThis - (char*)((&((AlgHash*)NULL)->Crc32)));
	}
	else if (!memcmp(&iidType, &s_iidMd5, sizeof(iidType)))
=======
HRESULT __stdcall DecRef(LPVOID pThis, size_t* pCount)
{
	if ((*(DWORD*)pThis) == ((DWORD)&s_ICrc32_vfptr))
	{
		pThis = (LPVOID)((char*)pThis - (char*)((&((AlgHash*)NULL)->Crc32)));
	}
	else if ((*(DWORD*)pThis) == ((DWORD)&s_IMd5_vfptr))
>>>>>>> c6e920d (修改子类this指针)
	{
		pThis = (LPVOID)((char*)pThis - (char*)((&((AlgHash*)NULL)->MD5)));
	}


	size_t* pRefCount = &((AlgHash*)pThis)->nRefCount;
	--(*pRefCount);
	if (!(*pRefCount))
	{
		free(pThis);
	}
	if (pCount)
	{
		*pCount = *pRefCount;
	}
	return ERROR_SUCCESS;
}

HRESULT __stdcall Hash_Crc32(LPVOID pThis, PBYTE pRaw, size_t nLen, PDWORD pRes)
{
	if (pRaw == NULL || nLen < 0 || pRes == NULL)
	{
		return E_INVALIDARG;
	}
	printf("AlgHash::Crc32\r\n");

	return ERROR_SUCCESS;
}

HRESULT __stdcall Hash_Md5(LPVOID pThis, PBYTE pRaw, size_t nLen, PBYTE pRes)
{
	if (pRaw == NULL || nLen < 0 || pRes == NULL)
	{
		return E_INVALIDARG;
	}
	printf("AlgHash::Md5\r\n");

	return ERROR_SUCCESS;
}
HRESULT __stdcall Hash_QueryInterface(LPVOID pThis, GUID iid, LPVOID* pInterface)
{
	AlgHash* pHash = pThis;
	if (!memcmp(&iid, &s_iidInterFace, sizeof(iid)))
	{
		*pInterface = pThis;
	}

	else if (!memcmp(&iid, &s_iidCrc32, sizeof(iid)))
	{
		*pInterface = &pHash->Crc32;
	}
	else if (!memcmp(&iid, &s_iidMd5, sizeof(iid)))
	{
		*pInterface = &pHash->MD5;
	}
	else
	{
		return E_NOTIMPL;
	}
	//引用计数+1
<<<<<<< HEAD
	pHash->Crc32.__vfptr->pfn_AddRef(pHash,s_iidCrc32, NULL);
=======
	pHash->Crc32.__vfptr->pfn_AddRef(pHash, NULL);
>>>>>>> c6e920d (修改子类this指针)

	return ERROR_SUCCESS;
}


<<<<<<< HEAD
static const COMInterface_vfptr s_COMInterface_Hash_vfptr =
=======
static const IMyUnknown_vfptr s_COMInterface_Hash_vfptr =
>>>>>>> c6e920d (修改子类this指针)
{
	&AddRef,
	& DecRef,
	& Hash_QueryInterface
};

static const ICrc32_vfptr s_ICrc32_vfptr =
{
	&AddRef,
	& DecRef,
	& Hash_QueryInterface,
	&Hash_Crc32
};

static const IMd5_vfptr s_IMd5_vfptr =
{
	&AddRef,
	& DecRef,
	& Hash_QueryInterface,
	& Hash_Md5
};

void InitAlgHashClass(LPVOID pThis)
{
	AlgHash* pHash = pThis;
	//pHash->base.__vfptr = &s_COMInterface_Hash_vfptr;
	pHash->Crc32.__vfptr = &s_ICrc32_vfptr;
	pHash->MD5.__vfptr = &s_IMd5_vfptr;
	pHash->nRefCount = 0;

}




typedef struct _CHashFactory
{
	IFactory factory;
	size_t nRefCount;
}CHashFactory;

<<<<<<< HEAD
HRESULT __stdcall HashFactory_AddRef(LPVOID pThis,GUID iidType, size_t* pCount)
=======
HRESULT __stdcall HashFactory_AddRef(LPVOID pThis, size_t* pCount)
>>>>>>> c6e920d (修改子类this指针)
{
	size_t* pRefCount = &((CHashFactory*)pThis)->nRefCount;

	++(*pRefCount);
	if (pCount)
	{
		*pCount = *pRefCount;
	}
	return ERROR_SUCCESS;
}
<<<<<<< HEAD
HRESULT __stdcall HashFactory_DecRef(LPVOID pThis, GUID iidType, size_t* pCount)
=======
HRESULT __stdcall HashFactory_DecRef(LPVOID pThis, size_t* pCount)
>>>>>>> c6e920d (修改子类this指针)
{
	size_t* pRefCount = &((CHashFactory*)pThis)->nRefCount;
	--(*pRefCount);
	if (!(*pRefCount))
	{
		free(pThis);
	}
	if (pCount)
	{
		*pCount = *pRefCount;
	}
	return ERROR_SUCCESS;
}
HRESULT __stdcall GetHashInstance(LPVOID* pInstance)
{
	if (!pInstance)
	{
		return E_INVALIDARG;
	}
	*pInstance = malloc(sizeof(AlgHash));
	if (!*pInstance)
	{
		return E_OUTOFMEMORY;
	}
	InitAlgHashClass(*pInstance);
<<<<<<< HEAD
	((AlgHash*)*pInstance)->Crc32.__vfptr->pfn_AddRef(*pInstance, s_iidCrc32, NULL);
=======
	((AlgHash*)*pInstance)->Crc32.__vfptr->pfn_AddRef(*pInstance, NULL);
>>>>>>> c6e920d (修改子类this指针)
	
	return ERROR_SUCCESS;
}
HRESULT __stdcall Factory_QueryInterface(LPVOID pThis, GUID iid, LPVOID* pInterface)
{
	CHashFactory* pFactory = pThis;
	if (!memcmp(&iid, &s_iidInterFace, sizeof(iid)))
	{
		*pInterface = pThis;
	}

	else if (!memcmp(&iid, &s_iidFactory, sizeof(iid)))
	{
		*pInterface = pFactory;
	}
	else
	{
		return E_NOTIMPL;
	}
	//引用计数+1
<<<<<<< HEAD
	pFactory->factory.__vfptr->pfn_AddRef(pFactory,s_iidFactory,NULL);
=======
	pFactory->factory.__vfptr->pfn_AddRef(pFactory,NULL);
>>>>>>> c6e920d (修改子类this指针)
	return ERROR_SUCCESS;
}

static const IFACTORY_vfptr s_HashFactory_vfptr = {
	& HashFactory_AddRef,
	& HashFactory_DecRef,
	& Hash_QueryInterface,
	& GetHashInstance
};



void InitHashFactoryCalss(LPVOID pThis)
{
	CHashFactory* pHash = (CHashFactory*)pThis;
	pHash->factory.__vfptr = &s_HashFactory_vfptr;
	pHash->nRefCount = 0;
}



HRESULT __stdcall GetCOMFactory(LPVOID* pObj)
{
	if (!pObj)
	{
		return E_INVALIDARG;
	}
	*pObj = malloc(sizeof(CHashFactory));
	if (!*pObj)
	{
		return E_OUTOFMEMORY;
	}
	InitHashFactoryCalss(*pObj);
<<<<<<< HEAD
	((CHashFactory*)*pObj)->factory.__vfptr->pfn_AddRef(*pObj,s_iidFactory, NULL);
=======
	((CHashFactory*)*pObj)->factory.__vfptr->pfn_AddRef(*pObj, NULL);
>>>>>>> c6e920d (修改子类this指针)

	return ERROR_SUCCESS;
}








BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

