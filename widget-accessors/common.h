// DEMO

#ifndef WIDGET_ACCESSOR_DEMO_COMMON_H_
#define WIDGET_ACCESSOR_DEMO_COMMON_H_

#if defined(_WIN32) || defined(WIN32)
  #ifdef LIB_STATIC
    #define WIDGET_ACCESSOR_DEMO_DECL
  #else
    #ifdef WIDGET_ACCESSOR_DEMO_EXPORT
#define WIDGET_ACCESSOR_DEMO_DECL __declspec(dllexport)
    #else
#define WIDGET_ACCESSOR_DEMO_DECL __declspec(dllimport)
    #endif
  #endif
#else
#define WIDGET_ACCESSOR_DEMO_DECL
#endif



#endif