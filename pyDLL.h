#ifndef PYDLL_H
#define PYDLL_H

#ifdef __cplusplus	//�����C++
#define XEXT extern "C"
#else
#define XEXT
#endif

#ifdef PYDLL_H	//
#define XLIB XEXT __declspec(dllexport)	//�����εı�������������ȴӴ��ļ�����
#else
#define XLIB XEXT __declspec(dllimport)	//�����εı�������������ȵ�����ļ�
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
