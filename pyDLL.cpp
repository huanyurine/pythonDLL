#include <stdio.h>
#include <iostream>
#include "pyDLL.h"

int add(int x, int y) {
    int z = x + y;
    return z;
}
float minus(float x, float y) {
    return x - y;
}
const char* TestReturnChar() {
    return "TestReturnChar String";
}
const wchar_t* TestReturnWChar() {
    return L"TestReturnWChar String";
}
int* TestPointer(float* f1) {
    static int re = 1001;
    *f1 = 99.9f;
    printf("In C++ TestPointer re = %d\n", re);
    return &re;
}
void TestArray(int* arr, int size) {
    printf("=========In C++ ===============\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void TestStruct1(Pos pos) {
    printf("\nIn c++ TestStruct \n");
    printf("pos x = %d,y = %d\n", pos.x, pos.y);
}
void TestStruct2(Pos pos1, Pos* pos2) {
    printf("\nIn c++ TestStruct \n");
    printf("pos1 x = %d,y = %d\n", pos1.x, pos1.y);
    printf("pos2 x = %d,y = %d\n", pos2->x, pos2->y);
}
void TestStruct3(Pos pos1, Pos* pos2, Pos* pos3, int size) {
    printf("\nIn c++ TestStruct \n");
    printf("pos1 x = %d,y = %d\n", pos1.x, pos1.y);
    printf("pos2 x = %d,y = %d\n", pos2->x, pos2->y);
    printf("pos3 =");
    for (int i = 0; i < size; i++)
    {
        printf("(%d,%d)", pos3[i].x, pos3[i].y);
    }
}
Pos GetPos() {
    Pos pos;
    pos.x = 101;
    pos.y = 102;
    return pos;
}
Pos* TestStruct(Pos pos1, Pos* pos2, Pos* pos3, int size) {
    printf("\nIn c++ TestStruct \n");
    printf("pos1 x = %d,y = %d\n", pos1.x, pos1.y);
    printf("pos2 x = %d,y = %d\n", pos2->x, pos2->y);
    printf("pos3 =");
    for (int i = 0; i < size; i++)
    {
        printf("(%d,%d)", pos3[i].x, pos3[i].y);
    }
    printf("\n");
    static Pos re;
    re.x = 88;
    re.y = 99;
    //不返回局部变量
    return &re;
}