// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ConsoleApplication1.h"
#include <windows.h>

using namespace std;

extern "C"
{
    __declspec(dllimport) int Sum(int a, int b); //каждый раз копировать dll
};

extern "C"
{
    __declspec(dllimport) int Sub(int a, int b);
};

extern "C"
{
    __declspec(dllimport) int Mult(int a, int b); 
};

struct Complex;

struct Complex {
	int img;
	int real;
};


int main()
{
    std::cout << Sum(1, 2) << " \n";
    std::cout << Sub(1, 2) << " \n";
    std::cout << Mult(1, 2) << " \n";

    Complex(*C_Sum)(Complex c1, Complex c2);
    Complex(*C_Sub)(Complex c1, Complex c2);
    Complex(*C_Mult)(Complex c1, Complex c2);

    HMODULE hModule;
    hModule = LoadLibrary(TEXT("c_numbers.dll"));
    C_Sum = reinterpret_cast<Complex(*)(Complex, Complex)>
        (GetProcAddress(hModule, "C_Sum"));
    C_Sub = reinterpret_cast<Complex(*)(Complex, Complex)>
        (GetProcAddress(hModule, "C_Sub"));
    C_Mult = reinterpret_cast<Complex(*)(Complex, Complex)>
        (GetProcAddress(hModule, "C_Mult"));
    Complex c1{ 1,2 };
    Complex c2{ 2,2 };
    Complex res = C_Sum(c1, c2);
    cout << res.real << " " << res.img << endl;
    Complex res1 = C_Sub(c1, c2);
    cout << res1.real << " " << res1.img << endl;
    Complex res2 = C_Mult(c1, c2);
    cout << res2.real << " " << res2.img << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.