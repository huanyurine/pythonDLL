#ifndef PYDLL_H
#define PYDLL_H

#ifdef __cplusplus	//如果是C++
#define XEXT extern "C"
#else
#define XEXT
#endif

#ifdef PYDLL_H	//
#define XLIB XEXT __declspec(dllexport)	//被修饰的变量、函数、类等从此文件导出
#else
#define XLIB XEXT __declspec(dllimport)	//被修饰的变量、函数、类等导入此文件
#endif

XLIB int add(int x, int y);

XLIB float minus(float x, float y);

XLIB const char* TestReturnChar();

XLIB const wchar_t* TestReturnWChar();

XLIB int* TestPointer(float* f1);

XLIB void TestArray(int* arr, int size);

XLIB struct Pos{
    int x;
    int y;
};
XLIB void TestStruct1(Pos pos);

XLIB void TestStruct2(Pos pos1, Pos* pos2);

XLIB void TestStruct3(Pos pos1, Pos* pos2, Pos* pos3, int size);

XLIB Pos GetPos();

XLIB Pos* TestStruct(Pos pos1, Pos* pos2, Pos* pos3, int size);

#endif  // !PYDLL_H
