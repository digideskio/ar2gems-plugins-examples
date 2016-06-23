// DEMO

#ifndef PLUGINS_DEMO_COMMON_H_
#define PLUGINS_DEMO_COMMON_H_

#if defined(_WIN32) || defined(WIN32)
  #ifdef LIB_STATIC
    #define WIDGET_DEMO_DECL
  #else
    #ifdef WIDGET_DEMO_EXPORT
#define WIDGET_DEMO_DECL __declspec(dllexport)
    #else
#define WIDGET_DEMO_DECL __declspec(dllimport)
    #endif
  #endif
#else
#define WIDGET_DEMO_DECL
#endif



#endif