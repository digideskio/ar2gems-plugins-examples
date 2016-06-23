cmake_minimum_required(VERSION 2.8)


set(PROJECT_NAME widget-demo)

project(${PROJECT_NAME})



# Process all headers with Q_OBJECT
QT5_WRAP_CPP(${PROJECT_NAME}_MOC
  location_widget.h
)

## File to compile
add_library(${PROJECT_NAME} SHARED
  location_widget.cpp
  location_widget.h
  location_widget_plugin.h
  location_widget_plugin.cpp
  common.h
  ${${PROJECT_NAME}_MOC}
#  ${${PROJECT_NAME}_FORMS}
)

target_link_libraries(${PROJECT_NAME}
    ${AR2GEMS_LIBRARIES}
    #${QT_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Xml_LIBRARIES}
    ${Qt5Svg_LIBRARIES}
    ${Qt5Designer_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5UiTools_LIBRARIES}
    ${VTK_LIBRARIES}
)

source_group(Qt FILES ${${PROJECT_NAME}_MOC} )

if (WIN32)
  add_definitions(-DWIDGET_DEMO_EXPORT)
endif()

