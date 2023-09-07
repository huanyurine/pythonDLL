from ctypes import *


class Pos(Structure):
    _fields_ = [("x", c_int), ("y", c_int)]


lib = cdll.LoadLibrary("x64/Release/pyDLL.dll")

lib.minus.restype = c_float
lib.minus.argtypes = [c_float, c_float]
re_minus = lib.minus(10.2, 2.1)
print(type(re_minus), "minus = ", re_minus)

lib.TestPointer.restype = POINTER(c_int)
lib.TestPointer.argtypes = (POINTER(c_float),)
f1 = c_float(88.8)
print("begin f1 = ", f1)
re = lib.TestPointer(byref(f1))
print("end f1 = ", f1, "\nreturn = ", re, "\nreturn type = ", type(re))
re.contents.value = 666  # re.contents 就是指针指向的内容
print("In Python TestPointer re =", re.contents.value)
lib.TestPointer(byref(f1))  # 在C语言中再调用一次

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
TenArrType = c_int*len(arr)
carr = TenArrType(*arr)  # *把list中每个元素当作位置参数等同于 TenArrType(1,2,3,4,5,...)
lib.TestArray.argtypes = (TenArrType,)
lib.TestArray(carr, len(arr))

pos1 = Pos(11, 22)
pos2 = Pos(33, 44)
pos3 = [Pos(1, 1), Pos(2, 2), Pos(3, 3)]
lib.TestStruct1.argtypes = (Pos,)
lib.TestStruct1(pos1)

lib.TestStruct2.argtypes = (Pos, POINTER(Pos))
lib.TestStruct2(pos1, byref(pos2))

PosType = Pos*len(pos3)
lib.TestStruct3(pos1, byref(pos2), PosType(*pos3), len(pos3))

lib.TestStruct.restype = POINTER(Pos)
repos = lib.TestStruct(pos1, byref(pos2), PosType(*pos3), len(pos3))
print(repos)
print(type(repos))
print(repos.contents.x, repos.contents.y)

lib.GetPos.restype = Pos
repos2 = lib.GetPos()
print("GetPos = ", repos2.x, repos2.y)
