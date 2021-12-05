#pragma once
#include <winerror.h>

/*
* 组件查询类的接口
*/
typedef HRESULT (__stdcall* PFN_ADDREF)(PVOID, size_t*);
typedef HRESULT (__stdcall* PFN_DECREF)(PVOID, size_t*);
typedef HRESULT (__stdcall* PFN_QUERYINTERFACE)(PVOID, GUID, PVOID*);

/*
* Crc32接口
*/
typedef HRESULT(__stdcall* PFN_CRCR32)(PVOID, PBYTE, size_t, PDWORD);

/*
* Md5接口
*/
typedef HRESULT(__stdcall* PDN_MD5)(PVOID, PBYTE, size_t, PBYTE);


// {6BC27478-A935-46F2-98D2-9A518EF4A60F}
static const GUID s_iidInterFace =
{ 0x6bc27478, 0xa935, 0x46f2, { 0x98, 0xd2, 0x9a, 0x51, 0x8e, 0xf4, 0xa6, 0xf } };

// {888E709B-0B03-4A3C-9613-F9EE894DC6E6}
static const GUID s_iidMd5 =
{ 0x888e709b, 0xb03, 0x4a3c, { 0x96, 0x13, 0xf9, 0xee, 0x89, 0x4d, 0xc6, 0xe6 } };

// {3C342390-F541-435D-B497-7E2CC1909ED4}
static const GUID s_iidCrc32 =
{ 0x3c342390, 0xf541, 0x435d, { 0xb4, 0x97, 0x7e, 0x2c, 0xc1, 0x90, 0x9e, 0xd4 } };

