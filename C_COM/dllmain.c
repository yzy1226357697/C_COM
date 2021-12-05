﻿// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Interface.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct _AlgHash
{
	COMInterface base;
	ICrc32 Crc32;
	IMd5 MD5;

	size_t nRefCount;

}AlgHash;





HRESULT __stdcall AddRef(LPVOID pThis, size_t* pCount)
{
	size_t* pRefCount = &((AlgHash*)pThis)->nRefCount;
	++(*pRefCount);
	if (pCount)
	{
		*pCount = *pRefCount;
	}
	return ERROR_SUCCESS;
}
HRESULT __stdcall DecRef(LPVOID pThis, size_t* pCount)
{
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

HRESULT __stdcall Crc32(LPVOID pThis, PBYTE pRaw, size_t nLen, PDWORD pRes)
{
	if (pRaw == NULL || nLen < 0 || pRes == NULL)
	{
		return E_INVALIDARG;
	}
	printf("AlgHash::Crc32\r\n");

	return ERROR_SUCCESS;
}

HRESULT __stdcall Md5(LPVOID pThis, PBYTE pRaw, size_t nLen, PBYTE pRes)
{
	if (pRaw == NULL || nLen < 0 || pRes == NULL)
	{
		return E_INVALIDARG;
	}
	printf("AlgHash::Md5\r\n");

	return ERROR_SUCCESS;
}
HRESULT __stdcall QueryInterface(LPVOID pThis, GUID iid, LPVOID* pInterface)
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
	return ERROR_SUCCESS;
}


static const COMInterface_vfptr s_COMInterface_vfptr =
{
	&AddRef,
	& DecRef,
	& QueryInterface
};

static const ICrc32_vfptr s_ICrc32_vfptr =
{
	&Crc32
};

static const IMd5_vfptr s_IMd5_vfptr =
{
	&Md5
};

void InitAlgHashClass(LPVOID pThis)
{
	AlgHash* pHash = pThis;
	pHash->base.__vfptr = &s_COMInterface_vfptr;
	pHash->Crc32.__vfptr = &s_ICrc32_vfptr;
	pHash->MD5.__vfptr = &s_IMd5_vfptr;
	pHash->nRefCount = 0;

}

HRESULT __stdcall GetCOMObject(LPVOID* pObj)
{
	if (!pObj)
	{
		return E_INVALIDARG;
	}
	*pObj = malloc(sizeof(AlgHash));
	if (!*pObj)
	{
		return E_OUTOFMEMORY;
	}
	InitAlgHashClass(*pObj);

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
