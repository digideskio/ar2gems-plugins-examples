cmake_minimum_required(VERSION 2.8)


set(PROJECT_NAME widget-accessors-demo)

project(${PROJECT_NAME})

include_directories("../widgets")

## File to compile
add_library(${PROJECT_NAME} SHARED
  location_widget_accessor.cpp
  location_widget_accessor.h
  demo_widget_library_init.cpp
  common.h
)

target_link_libraries(${PROJECT_NAME}
    widget-demo
    ${AR2GEMS_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Xml_LIBRARIES}
)


if (WIN32)
  add_definitions(-DWIDGET_ACCESSOR_DEMO_EXPORT)
endif()

