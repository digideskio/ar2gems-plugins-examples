// DEMO

#ifndef EDA_DEMO_COMMON_H_
#define EDA_DEMO_COMMON_H_

#if defined(_WIN32) || defined(WIN32)
  #ifdef LIB_STATIC
    #define EDA_DEMO_DECL
  #else
    #ifdef EDA_DEMO_EXPORT
      #define EDA_DEMO_DECL __declspec(dllexport)
    #else
      #define EDA_DEMO_DECL __declspec(dllimport)
    #endif
  #endif
#else
    #define EDA_DEMO_DECL
#endif



#endif