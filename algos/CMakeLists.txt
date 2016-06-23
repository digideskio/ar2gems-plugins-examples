cmake_minimum_required(VERSION 2.8)


set(PROJECT_NAME algos-demo)

project(${PROJECT_NAME})


## File to compile
add_library(${PROJECT_NAME} SHARED
  add_property_action.cpp
  add_property_action.h
  local_high_values_algo.cpp
  local_high_values_algo.h
  distance_from_point.cpp
  distance_from_point.h
  library_init.cpp
  common.h
)

target_link_libraries(${PROJECT_NAME}
    ${AR2GEMS_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Xml_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${VTK_LIBRARIES}
)

source_group(Qt FILES ${${PROJECT_NAME}_MOC} )

if (WIN32)
  add_definitions(-DPLUGINS_DEMO_EXPORT)
endif()

