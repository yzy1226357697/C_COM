// template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "..\C_COM\COMDeclaration.h"
#include "..\C_COM\Interface.h"



int main()
{
	typedef HRESULT(__stdcall* PFN_COMFACTORY)(LPVOID*);

	HMODULE hModule = NULL;
	COMInterface* pCom = NULL;
	COMInterface* pCom1 = NULL;
	IFactory* ComFactory;
	PFN_COMFACTORY pfn_Factory = NULL;
	ICrc32* pCrc32 = NULL;
	IMd5* pMd5 = NULL;
	BYTE RawData[MAXBYTE];
	BYTE ResData[MAXBYTE];
	DWORD dwResCrc = 0;


	hModule = LoadLibrary("C_COM.dll");

	if (!hModule)
	{
		printf("加载com库失败!\r\n");
		return 0;
	}
	
	
	pfn_Factory = (PFN_COMFACTORY)GetProcAddress(hModule, "GetCOMFactory");

	
	pfn_Factory((LPVOID*)&ComFactory);
	ComFactory->__vfptr->pfn_GetInstance((LPVOID*)&pCom);

	
	pCom->__vfptr->pfn_QueryInterface(pCom, s_iidCrc32, (PVOID*)&pCrc32);



	pCrc32->__vfptr->pfn_Crc32(pCrc32, RawData, sizeof(RawData), &dwResCrc);

	pCrc32->__vfptr->pfn_DecRef(pCrc32, s_iidCrc32, NULL);

	pCom->__vfptr->pfn_DecRef(pCom,s_iidInterFace, NULL);

	ComFactory->__vfptr->pfn_GetInstance((LPVOID*)&pCom1);
	pCom1->__vfptr->pfn_QueryInterface(pCom1,s_iidMd5,(LPVOID*)&pMd5);
	pMd5->__vfptr->pfn_Md5(pCrc32, RawData, sizeof(RawData), ResData);
	pMd5->__vfptr->pfn_DecRef(pMd5,s_iidMd5, NULL);
	pCom1->__vfptr->pfn_DecRef(pCom1, s_iidInterFace, NULL);

	ComFactory->__vfptr->pfn_DecRef(ComFactory, s_iidFactory, NULL);


	system("pause");
	return 0;
}
