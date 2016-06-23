cmake_minimum_required(VERSION 2.8)


set(PROJECT_NAME eda-demo)

project(${PROJECT_NAME})



# Process all headers with Q_OBJECT
QT5_WRAP_CPP(${PROJECT_NAME}_MOC
  pie_chart_creator.h
  pie_chart.h
)

## File to compile
add_library(${PROJECT_NAME} SHARED
  pie_chart_creator.cpp
  pie_chart_creator.h
  pie_chart.cpp
  pie_chart.h
  library_init.cpp
  common.h
  ${${PROJECT_NAME}_MOC}
)

target_link_libraries(${PROJECT_NAME}
    ${AR2GEMS_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Xml_LIBRARIES}
    ${Qt5Designer_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5UiTools_LIBRARIES}
    ${VTK_LIBRARIES}
)

source_group(Qt FILES ${${PROJECT_NAME}_MOC} )

if (WIN32)
  add_definitions(-DEDA_DEMO_EXPORT)
endif()

