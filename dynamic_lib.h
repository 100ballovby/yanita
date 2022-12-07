#include <iostream>
#define array_lib

#ifdef array_lib //or #if (defined(ABC_LIB) || !defined(WIN32))
#define array_lib_api
std::pair<int, int> min(int *array, int i, int j);
#else
#ifdef ARRAY_EXPORT
    #define array_lib_api __declspec(dllexport)
  #else
    #define array_lib_api __declspec(dllimport)
  #endif

#endif