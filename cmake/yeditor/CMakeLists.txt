cmake_minimum_required (VERSION 2.6)

project(yeditor)

set(CODE_PATH_YEDITOR ${CODE_PATH}/yeditor)

set(DEPEND_PROJ_LIST
    yam
    supereasyjson
    rectanglebinpack
    )

set(INCLUDE_PATH_LIST
    $ENV{QT_MSVC_X32}/include
    ${CODE_PATH}/yam/inc
    ${CODE_PATH}/t3rd/supereasyjson
    ${CODE_PATH}/t3rd/rectanglebinpack
    ${CODE_PATH_YEDITOR}/inc
    )

set(LINK_PATH_LIST
    $ENV{QT_MSVC_X32}/lib
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.a
    supereasyjson.a
    rectanglebinpack.a
    # todo: more for qt
    )
else(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.lib
    supereasyjson.lib
    rectanglebinpack.lib
    qtmain.lib
    Qt5Core.lib
    Qt5Gui.lib
    Qt5Widgets.lib
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CODE_FILE_LIST_EDITOR
    ${CODE_PATH_YEDITOR}/inc/yeditorcommon.h
    ${CODE_PATH_YEDITOR}/inc/yeditor.h
    ${CODE_PATH_YEDITOR}/src/yeditor.cpp
    ${CODE_PATH_YEDITOR}/inc/quiarea.h
    ${CODE_PATH_YEDITOR}/src/quiarea.cpp
    ${CODE_PATH_YEDITOR}/inc/quiitem.h
    ${CODE_PATH_YEDITOR}/src/quiitem.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreehelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreewidgethelper.h
    ${CODE_PATH_YEDITOR}/src/quitreewidgethelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.cpp
    )

set(CODE_FILE_LIST_RES
    ${CODE_PATH_YEDITOR}/res/main.ui
    )

set(CODE_FILE_LIST_QT
    ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h
    ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreehelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreewidgethelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.moc.cpp
    )

set(CODE_FILE_LIST_EXPORT
    ${CODE_PATH_YEDITOR}/inc/yconverter.h
    ${CODE_PATH_YEDITOR}/src/yconverter.cpp
    ${CODE_PATH_YEDITOR}/inc/yexport.h
    ${CODE_PATH_YEDITOR}/src/yexport.cpp
    ${CODE_PATH_YEDITOR}/inc/yrectpacker.h
    ${CODE_PATH_YEDITOR}/src/yrectpacker.cpp
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
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quiarea.h -o ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiarea.h
                   )

add_custom_target(quiarea_moc_cpp
                  DEPENDS quiarea.moc.cpp)

add_custom_command(OUTPUT quiitem.moc.cpp
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quiitem.h -o ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiitem.h
                   )

add_custom_target(quiitem_moc_cpp
                  DEPENDS quiitem.moc.cpp)

add_custom_command(OUTPUT quitreehelper.moc.cpp
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreehelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
                   )

add_custom_target(quitreehelper_moc_cpp
                  DEPENDS quitreehelper.moc.cpp)

add_custom_command(OUTPUT quitreewidgethelper.moc.cpp
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreewidgethelper.h -o ${CODE_PATH_YEDITOR}/src/quitreewidgethelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreewidgethelper.h
                   )

add_custom_target(quitreewidgethelper_moc_cpp
                  DEPENDS quitreewidgethelper.moc.cpp)

add_custom_command(OUTPUT quitreeitemboundhelper.moc.cpp
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
                   )

add_custom_target(quitreeitemboundhelper_moc_cpp
                  DEPENDS quitreeitemboundhelper.moc.cpp)

add_custom_command(OUTPUT quitreeitemlayerweighthelper.moc.cpp
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
                   )

add_custom_target(quitreeitemlayerweighthelper_moc_cpp
                  DEPENDS quitreeitemlayerweighthelper.moc.cpp)

add_custom_command(OUTPUT yeditor.moc.cpp
                   COMMAND $ENV{QT_MSVC_X32}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/yeditor.h -o ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I$ENV{QT_MSVC_X32}/include -I${CODE_PATH_YEDITOR}/inc -I$ENV{QT_MSVC_X32}/include/QtCore -I$ENV{QT_MSVC_X32}/include/QtGui -I$ENV{QT_MSVC_X32}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/yeditor.h
                   )

add_custom_target(yeditor_moc_cpp
                  DEPENDS yeditor.moc.cpp)

add_custom_command(OUTPUT yeditor.main.ui.h
                   COMMAND $ENV{QT_MSVC_X32}/bin/uic.exe -o ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h ${CODE_PATH_YEDITOR}/res/main.ui
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/res/main.ui
                   )

add_custom_target(yeditor_main_ui_h
                  DEPENDS yeditor.main.ui.h)

add_dependencies(yeditor ${DEPEND_PROJ_LIST}
                         quiarea_moc_cpp
                         quiitem_moc_cpp
                         quitreehelper_moc_cpp
                         quitreewidgethelper_moc_cpp
                         quitreeitemboundhelper_moc_cpp
                         quitreeitemlayerweighthelper_moc_cpp
                         yeditor_moc_cpp
                         yeditor_main_ui_h)
