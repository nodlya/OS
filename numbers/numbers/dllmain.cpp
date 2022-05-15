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

extern "C"
{
    //__declspec(dllexport) заставляет линкер добавить функцию в секцию экспорта
    __declspec(dllexport) int Sum(int a, int b);//Объявление функции
};

extern "C"
{
    //__declspec(dllexport) заставляет линкер добавить функцию в секцию экспорта
    __declspec(dllexport) int Sub(int a, int b);//Объявление функции
};

extern "C"
{
    //__declspec(dllexport) заставляет линкер добавить функцию в секцию экспорта
    __declspec(dllexport) int Mult(int a, int b);//Объявление функции
};

int Sum(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

int Mult(int a, int b)
{
    return a * b;
}

