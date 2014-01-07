cmake_minimum_required (VERSION 2.6)

project(yeditor)

set(CODE_PATH_YEDITOR ${CODE_PATH}/yeditor)

set(DEPEND_PROJ_LIST
    yam
    )

set(INCLUDE_PATH_LIST
    $ENV{QT_MSVC2012_X32}/include
    ${CODE_PATH}/yam/inc
    ${CODE_PATH_YEDITOR}/inc
    )

set(LINK_PATH_LIST
    $ENV{QT_MSVC2012_X32}/lib
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.a
    )
else(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.lib
    qtmaind.lib
    Qt5Cored.lib
    Qt5Guid.lib
    Qt5Widgetsd.lib
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CODE_FILE_LIST_YEDITOR
    ${CODE_PATH_YEDITOR}/inc/yeditor.h
    ${CODE_PATH_YEDITOR}/src/yeditor.cpp
    )

set(CODE_FILE_LIST_RES
    ${CODE_PATH_YEDITOR}/res/main.ui
    )

set(CODE_FILE_LIST_QT
    ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h
    ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp
    )

source_group("yeditor" FILES ${CODE_FILE_LIST_YEDITOR})
source_group("res" FILES ${CODE_FILE_LIST_RES})
source_group("qt" FILES ${CODE_FILE_LIST_QT})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
link_libraries(${LIBRARY_FILE_LIST})

#add_definitions("-DC4G_EXPORTS_API")

add_executable(yeditor ${CODE_FILE_LIST_YEDITOR}
                       ${CODE_FILE_LIST_RES}
                       ${CODE_FILE_LIST_QT}
                       )


add_custom_command(OUTPUT yeditor.moc.cpp
                   COMMAND $ENV{QT_MSVC2012_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/yeditor.h -o ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC2012_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC2012_X32}/include/QtCore -I$ENV{QT_MSVC2012_X32}/include/QtGui -I$ENV{QT_MSVC2012_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/yeditor.h
                   )

add_custom_target(yeditor_moc_cpp
                  DEPENDS yeditor.moc.cpp)

add_custom_command(OUTPUT yeditor.main.ui.h
                   COMMAND $ENV{QT_MSVC2012_X32}/bin/uic.exe -o ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h ${CODE_PATH_YEDITOR}/res/main.ui
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/res/main.ui
                   )

add_custom_target(yeditor_main_ui_h
                  DEPENDS yeditor.main.ui.h)

add_dependencies(yeditor ${DEPEND_PROJ_LIST}
                         yeditor_moc_cpp
                         yeditor_main_ui_h)
