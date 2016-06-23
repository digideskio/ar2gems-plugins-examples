cmake_minimum_required(VERSION 2.8)


set(PROJECT_NAME plugin-demo)

project(${PROJECT_NAME})


######################################################################
# Please set the variables with your preferences. The defaults should
# work out of the box.
######################################################################

set(USE_AR2GEMS_ALL         OFF CACHE BOOL "checkbox")

# core
set(USE_AR2GEMS_ACTIONS_CORE     OFF  CACHE BOOL "checkbox")
set(USE_AR2GEMS_APPLI_CORE       OFF CACHE BOOL "checkbox")
set(USE_AR2GEMS_FILTERS_CORE     OFF CACHE BOOL "checkbox")
set(USE_AR2GEMS_GEOSTAT_CORE     OFF  CACHE BOOL "checkbox")
set(USE_AR2GEMS_GRID_CORE        OFF CACHE BOOL "checkbox")
set(USE_AR2GEMS_MATH_CORE        OFF CACHE BOOL "checkbox")
set(USE_AR2GEMS_UTILS_CORE       OFF CACHE BOOL "checkbox")

# gui
set(USE_AR2GEMS_ACTIONS     ON  CACHE BOOL "checkbox")
set(USE_AR2GEMS_APPLI       ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_CHARTS      ON  CACHE BOOL "checkbox")
set(USE_AR2GEMS_AEXTRAGUI   ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_FILTERS     ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_GEOSTAT     ON  CACHE BOOL "checkbox")
set(USE_AR2GEMS_GRID        ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_GUI         ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_MATH        ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_QWT         ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_UTILS       ON CACHE BOOL "checkbox")
set(USE_AR2GEMS_WIDGETS     ON  CACHE BOOL "checkbox")

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Release CACHE STRING
       "Choose the type of build, options are: Debug Release"
       FORCE )
endif()

set(ALLOW_BUILD_PACKAGE OFF CACHE BOOL "checkbox")

if (APPLE)
     # ...
elseif (UNIX)
    #set(BOOST_ROOT "E:/workspace/ar2externals/Boost/win64/release-V1.49.0-VC2010" CACHE TYPE STRING)
    set(VTK_DIR "/home/diverlin/workspace/AlexSanto/vtk/VTK/VTK-6.1/VTK-6.1.0_build" CACHE TYPE STRING)
    set(AR2GEMS_SOURCE_PATH "/home/diverlin/workspace/AlexSanto/ar2gems/ar2gems" CACHE TYPE STRING)
    set(AR2GEMS_BUILD_PATH  "/home/diverlin/workspace/AlexSanto/ar2gems/build-ar2gems-Desktop-Default" CACHE TYPE STRING)
elseif (WIN32)
    set(BOOST_ROOT "d:/release-V1.49.0-VC2010" CACHE TYPE STRING)
    set(VTK_DIR "D:/workspace/VTK-master/build" CACHE TYPE STRING)
    #set(AR2GEMS_PATH "c:/SGeMS-ar2tech-x64" CACHE TYPE STRING) # if commented the searching happens by registry information
    set(AR2GEMS_SOURCE_PATH "d:/workspace/ar2gems" CACHE TYPE STRING)
    set(AR2GEMS_BUILD_PATH "d:/workspace/ar2gems_build" CACHE TYPE STRING)
endif (APPLE)


if (MSVC)
	  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${AR2GEMS_BUILD_PATH}/bin/Debug/plugins/Geostat )
	  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${AR2GEMS_BUILD_PATH}/bin/Release/plugins/Geostat )
	  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${AR2GEMS_BUILD_PATH}/bin/Debug/plugins/Geostat )
	  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${AR2GEMS_BUILD_PATH}/bin/Release/plugins/Geostat )	
endif (MSVC)


# SET RELEVANT VARS FOR PACKAGE
if (ALLOW_BUILD_PACKAGE)
	if (APPLE)
	elseif (UNIX)
	    SET(PACKAGE_TYPE "DEB")    # DEB or RPM
	endif (APPLE)
	
	SET(PACKAGE_MAINTAINER "Alex Santo <asanto@stereoofusion.com>")
	#SET(PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/about.txt")
	#SET(PACKAGE_LICENSE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE-ar2tech.txt")
	    
	SET(PACKAGE_VERSION_MAJOR "1")
	SET(PACKAGE_VERSION_MINOR "0")
	SET(PACKAGE_VERSION_PATCH "0")
	    
	SET(PACKAGE_SYSTEM_NAME "amd64")
endif (ALLOW_BUILD_PACKAGE)

if (APPLE)
     # ...
elseif (UNIX)
    set(INSTALL_LIB_DIR "/usr/bin/plugins/designer")
    SET(INSTALL_GEOSTAT_LIB_DIR "/usr/bin/plugins/Geostat")  
elseif (WIN32)
    SET(INSTALL_LIB_DIR         "../../../../plugins/designer") # don't set ABS path it will fail at stage of package creation (ABS path forbiden)
    SET(INSTALL_GEOSTAT_LIB_DIR "../../../../plugins/Geostat")  # don't set ABS path it will fail at stage of package creation (ABS path forbiden)
    
    SET(PACKAGE_DIR         "../../../plugins/") # don't set ABS path it will fail at stage of package creation (ABS path forbiden)
endif (APPLE)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# core
if (USE_AR2GEMS_ACTIONS_CORE OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS actions_core)
endif()
if (USE_AR2GEMS_APPLI_CORE OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS appli_core)
endif()
if (USE_AR2GEMS_FILTERS_CORE OR USE_AR2GEMS_ALL)   
    list(APPEND AR2GEMS_COMPONENTS filters_core)
endif() 
if (USE_AR2GEMS_GEOSTAT_CORE OR USE_AR2GEMS_ALL)   
    list(APPEND AR2GEMS_COMPONENTS geostat_core) 
endif()
if (USE_AR2GEMS_GRID_CORE OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS grid_core)
endif() 
if (USE_AR2GEMS_GUI_CORE OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS gui_core) 
endif()
if (USE_AR2GEMS_MATH_CORE OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS math_core)
endif()
if (USE_AR2GEMS_UTILS_CORE OR USE_AR2GEMS_ALL) 
    list(APPEND AR2GEMS_COMPONENTS utils_core) 
endif()

# gui
if (USE_AR2GEMS_ACTIONS OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS actions)
endif()
if (USE_AR2GEMS_APPLI OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS appli)
endif()
if (USE_AR2GEMS_CHARTS OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS charts)
endif()
if (USE_AR2GEMS_AEXTRAGUI OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS extragui) 
endif()
if (USE_AR2GEMS_FILTERS OR USE_AR2GEMS_ALL)   
    list(APPEND AR2GEMS_COMPONENTS filters)
endif() 
if (USE_AR2GEMS_GEOSTAT OR USE_AR2GEMS_ALL)   
    list(APPEND AR2GEMS_COMPONENTS geostat) 
endif()
if (USE_AR2GEMS_GRID OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS grid)
endif() 
if (USE_AR2GEMS_GUI OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS gui) 
endif()
if (USE_AR2GEMS_MATH OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS math)
endif()
if (USE_AR2GEMS_QWT OR USE_AR2GEMS_ALL) 
    list(APPEND AR2GEMS_COMPONENTS qwt)
endif()
if (USE_AR2GEMS_UTILS OR USE_AR2GEMS_ALL) 
    list(APPEND AR2GEMS_COMPONENTS utils) 
endif()
if (USE_AR2GEMS_WIDGETS OR USE_AR2GEMS_ALL)
    list(APPEND AR2GEMS_COMPONENTS widgets)
endif()

find_package(AR2GEMS REQUIRED)
FindAR2GEMS("${AR2GEMS_COMPONENTS}")
if (AR2GEMS_FOUND)
	include_directories(${AR2GEMS_INCLUDE_DIRS}/ar2gems)
	include_directories(${AR2GEMS_INCLUDE_DIRS}/ar2GsTL)
    include_directories(${AR2GEMS_INCLUDE_DIRS})
endif ()

if (AR2GEMS_BUILD_PATH)
    #include automatic generated ui_*.h headers
	include_directories(${AR2GEMS_BUILD_PATH}/ar2gems)
endif ()

include_directories()
     


### Enabling Boost ###################################################
if(WIN32)
    set(Boost_NO_SYSTEM_PATHS TRUE)
endif()

FIND_PACKAGE( Boost REQUIRED )
if(Boost_FOUND)
  message(STATUS "Boost found in ${BOOST_ROOT}")
  include_directories(${Boost_INCLUDE_DIRS})
endif()


######################################################################
############### DON'T NEED CHANGE ANYTHING HERE ######################
######################################################################

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -O3 -march=native")
  set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -ggdb -march=native")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "/MP4")
  # customize flags for Visual Studio
endif()



### Enabling Qt5 #####################################################
find_package(Qt5Core REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
find_package(Qt5Gui REQUIRED)
include_directories(${Qt5Gui_INCLUDE_DIRS})
find_package(Qt5Xml REQUIRED)
include_directories(${Qt5Xml_INCLUDE_DIRS})
find_package(Qt5Svg REQUIRED)
include_directories(${Qt5Svg_INCLUDE_DIRS})
find_package(Qt5Designer REQUIRED)
include_directories(${Qt5Designer_INCLUDE_DIRS})
find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
find_package(Qt5PrintSupport REQUIRED)
include_directories(${Qt5PrintSupport_INCLUDE_DIRS})
find_package(Qt5Multimedia REQUIRED)
include_directories(${Qt5Multimedia_INCLUDE_DIRS})
find_package(Qt5UiTools REQUIRED)
include_directories(${Qt5UiTools_INCLUDE_DIRS})


### Enabling VTK #####################################################
#find_package(VTK REQUIRED)
find_package(VTK COMPONENTS REQUIRED
  vtkCommonCore
  vtkFiltersSources
  vtkRenderingCore
  vtkRenderingOpenGL
  vtkInteractionStyle
  vtkChartsCore
  vtkIOXML  
  vtkRenderingQt
  vtkGUISupportQt
  vtkViewsQt
  vtkViewsContext2D
  vtkInteractionWidgets
)
  
if(VTK_FOUND)
  message(STATUS "VTK found in ${VTK_DIR}")
  include(${VTK_USE_FILE})
endif()

### Enabling Python ##################################################
find_package(PythonLibs 2.7 REQUIRED)
if(PYTHONLIBS_FOUND)
  message(STATUS "Python found in ${PYTHON_INCLUDE_DIR}")
  include_directories(${PYTHON_INCLUDE_DIR})
endif()


add_subdirectory(algos)
add_subdirectory(widgets)
add_subdirectory(widget-accessors)
add_subdirectory(eda)

  
