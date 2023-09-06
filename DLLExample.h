#ifndef DLLHEADER_H
#define DLLHEADER_H

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" DLL_API int add(int a, int b);

#endif  // !DLLHEADER_H
