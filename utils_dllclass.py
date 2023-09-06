import ctypes


class DllClass:
    def __init__(self, func, res_type, arg_types):
        self.func = func
        self.func.restype = res_type
        self.func.argtypes = arg_types

    @classmethod
    def dll_link(cls, dll_path):
        cls.print_func_linked(dll_path)
        cls.dll = ctypes.cdll.LoadLibrary(dll_path)

    @staticmethod
    def print_func_linked(dll_path):
        print('%s has linked' % dll_path)
