// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

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

struct Complex
{
    int img;
    int real;
};

extern "C"
{
    //__declspec(dllexport) заставляет линкер добавить функцию в секцию экспорта
    __declspec(dllexport) Complex C_Sum(Complex a, Complex b);//Объявление функции
};

extern "C"
{
    //__declspec(dllexport) заставляет линкер добавить функцию в секцию экспорта
    __declspec(dllexport) Complex C_Sub(Complex a, Complex b);//Объявление функции
};
extern "C"
{
    //__declspec(dllexport) заставляет линкер добавить функцию в секцию экспорта
    __declspec(dllexport) Complex C_Mult(Complex a, Complex b);//Объявление функции
};


struct Complex C_Sum(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    return result;
}

struct Complex C_Sub(Complex a, Complex b)
{
    Complex result;
    result.real = a.real - b.real;
    result.img = a.img - b.img;
    return result;
}

struct Complex C_Mult(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.img * b.img;
    result.img = a.img * a.real + b.img * b.real;
    return result;
}
