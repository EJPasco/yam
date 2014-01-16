cmake_minimum_required (VERSION 2.6)

project(yeditor)

set(CODE_PATH_YEDITOR ${CODE_PATH}/yeditor)

set(DEPEND_PROJ_LIST
    yam
    supereasyjson
    )

set(INCLUDE_PATH_LIST
    $ENV{QT_MSVC2012_X32}/include
    ${CODE_PATH}/yam/inc
    ${CODE_PATH}/t3rd/supereasyjson
    ${CODE_PATH_YEDITOR}/inc
    )

set(LINK_PATH_LIST
    $ENV{QT_MSVC2012_X32}/lib
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.a
    supereasyjson.a
    )
else(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.lib
    supereasyjson.lib
    qtmaind.lib
    Qt5Cored.lib
    Qt5Guid.lib
    Qt5Widgetsd.lib
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CODE_FILE_LIST_EDITOR
    ${CODE_PATH_YEDITOR}/inc/yeditor.h
    ${CODE_PATH_YEDITOR}/src/yeditor.cpp
    ${CODE_PATH_YEDITOR}/inc/quiarea.h
    ${CODE_PATH_YEDITOR}/src/quiarea.cpp
    ${CODE_PATH_YEDITOR}/inc/quiitem.h
    ${CODE_PATH_YEDITOR}/src/quiitem.cpp
    ${CODE_PATH_YEDITOR}/inc/ydragdroparea.h
    ${CODE_PATH_YEDITOR}/src/ydragdroparea.cpp
    )

set(CODE_FILE_LIST_RES
    ${CODE_PATH_YEDITOR}/res/main.ui
    )

set(CODE_FILE_LIST_QT
    ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h
    ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp
    ${CODE_PATH_YEDITOR}/src/ydragdroparea.moc.cpp
    )

set(CODE_FILE_LIST_EXPORT
    ${CODE_PATH_YEDITOR}/inc/yexport.h
    ${CODE_PATH_YEDITOR}/src/yexport.cpp
    )

source_group("editor" FILES ${CODE_FILE_LIST_EDITOR})
source_group("res" FILES ${CODE_FILE_LIST_RES})
source_group("qt" FILES ${CODE_FILE_LIST_QT})
source_group("export" FILES ${CODE_FILE_LIST_EXPORT})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
link_libraries(${LIBRARY_FILE_LIST})

#add_definitions("-DC4G_EXPORTS_API")

add_executable(yeditor ${CODE_FILE_LIST_EDITOR}
                       ${CODE_FILE_LIST_RES}
                       ${CODE_FILE_LIST_QT}
                       ${CODE_FILE_LIST_EXPORT}
                       )

add_custom_command(OUTPUT quiarea.moc.cpp
                   COMMAND $ENV{QT_MSVC2012_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quiarea.h -o ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC2012_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC2012_X32}/include/QtCore -I$ENV{QT_MSVC2012_X32}/include/QtGui -I$ENV{QT_MSVC2012_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiarea.h
                   )

add_custom_target(quiarea_moc_cpp
                  DEPENDS quiarea.moc.cpp)

add_custom_command(OUTPUT quiitem.moc.cpp
                   COMMAND $ENV{QT_MSVC2012_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quiitem.h -o ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC2012_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC2012_X32}/include/QtCore -I$ENV{QT_MSVC2012_X32}/include/QtGui -I$ENV{QT_MSVC2012_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiitem.h
                   )

add_custom_target(quiitem_moc_cpp
                  DEPENDS quiitem.moc.cpp)

add_custom_command(OUTPUT ydragdroparea.moc.cpp
                   COMMAND $ENV{QT_MSVC2012_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/ydragdroparea.h -o ${CODE_PATH_YEDITOR}/src/ydragdroparea.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC2012_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC2012_X32}/include/QtCore -I$ENV{QT_MSVC2012_X32}/include/QtGui -I$ENV{QT_MSVC2012_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/ydragdroparea.h
                   )

add_custom_target(ydragdroparea_moc_cpp
                  DEPENDS ydragdroparea.moc.cpp)

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
                         quiarea_moc_cpp
                         quiitem_moc_cpp
                         ydragdroparea_moc_cpp
                         yeditor_moc_cpp
                         yeditor_main_ui_h)
