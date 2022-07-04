// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "RegLibrary.h"


static unsigned index_;
LONG lreg;
HKEY hkey;
DWORD val = 999;
bool Cr_reg()
{
   
	lreg = RegCreateKeyEx(HKEY_LOCAL_MACHINE,
		L"Software\\I191777",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS | KEY_WOW64_64KEY,
		NULL,
		&hkey,
		NULL);

	if (lreg != ERROR_SUCCESS)
	{
		return 0;
	}
	return 1;
	RegCloseKey(hkey);
}
bool Reg_setV()
{

	lreg = RegSetValueEx(hkey,
		L"RegValue",
		NULL,
		REG_DWORD,
		(LPBYTE)&val,
		sizeof(val));

	if (lreg != ERROR_SUCCESS)
	{
		return 0;
	}
	return 1;
	RegCloseKey(hkey);
}
DWORD setter(DWORD data)
{

	lreg = RegSetValueEx(hkey,
		L"RegValue",
		NULL,
		REG_DWORD,
		(LPBYTE)&data,
		sizeof(data));

	if (lreg != ERROR_SUCCESS)
	{
		return 0;
	}
	return data;
	RegCloseKey(hkey);
}
bool setN(DWORD data)
{

	lreg = RegSetValueEx(hkey,
		L"RegValue",
		NULL,
		REG_DWORD,
		(LPBYTE)&data,
		sizeof(data));

	if (lreg != ERROR_SUCCESS)
	{
		return 0;
	}
	return 1;
	RegCloseKey(hkey);
}

DWORD getval()
{

	
	DWORD dtype = REG_DWORD;
	DWORD dSize = sizeof(val);
	LONG lErr = RegQueryValueEx(hkey,L"RegValue", NULL, &dtype, (LPBYTE)&val, &dSize);

	if (ERROR_SUCCESS != lErr)
	{
		return 0;
	}

	return val;

}
bool Reg_Del()
{

	lreg=RegDeleteKeyEx(HKEY_LOCAL_MACHINE,L"SOFTWARE\\I191777", KEY_WOW64_64KEY,0);
	
	if (lreg != ERROR_SUCCESS)
	{
		return 0;
	}
	return 1;
	RegCloseKey(hkey);
}
