import ctypes
from utils_dllclass import DllClass

DllClass.dll_link("DLLExample.dll")
# DllClass.dll.add, add is an int(int, int) function name in C++
dll_obj = DllClass(func=DllClass.dll.add, res_type=ctypes.c_int, arg_types=[ctypes.c_int, ctypes.c_int])
obj = dll_obj.func(1, 2)
print(obj)
