// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef REGLIBRARY_EXPORTS
#define REGLIBRARY_API __declspec(dllexport)
#else
#define REGLIBRARY_API __declspec(dllimport)
#endif


extern "C" REGLIBRARY_API bool Cr_reg();
extern "C" REGLIBRARY_API bool Reg_setV();

extern "C" REGLIBRARY_API bool Reg_Del();

extern "C" REGLIBRARY_API DWORD getval();

extern "C" REGLIBRARY_API DWORD setter(DWORD data);

extern "C" REGLIBRARY_API bool setN(DWORD data);