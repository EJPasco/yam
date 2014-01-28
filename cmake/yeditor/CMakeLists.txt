cmake_minimum_required (VERSION 2.8.12)

project(yeditor)

set(CODE_PATH_YEDITOR ${CODE_PATH}/yeditor)

set(DEPEND_PROJ_LIST
    yam
    supereasyjson
    rectanglebinpack
    )

set(INCLUDE_PATH_LIST
    ${QT_SDK_PATH}/include
    ${CODE_PATH}/yam/inc
    ${CODE_PATH}/t3rd/supereasyjson
    ${CODE_PATH}/t3rd/rectanglebinpack
    ${CODE_PATH_YEDITOR}/inc
    )

set(LINK_PATH_LIST
    ${QT_SDK_PATH}/lib
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.a
    supereasyjson.a
    rectanglebinpack.a
    Qt5Core.a
    Qt5Gui.a
	Qt5Widgets.a
    )
else()
set(LIBRARY_FILE_LIST
    yam.lib
    supereasyjson.lib
    rectanglebinpack.lib
    qtmain.lib
    Qt5Core.lib
    Qt5Gui.lib
    Qt5Widgets.lib
    )
endif()

set(CODE_FILE_LIST_EDITOR
    ${CODE_PATH_YEDITOR}/inc/yeditorcommon.h
    ${CODE_PATH_YEDITOR}/inc/yeditor.h
    ${CODE_PATH_YEDITOR}/src/yeditor.cpp
    ${CODE_PATH_YEDITOR}/inc/quiarea.h
    ${CODE_PATH_YEDITOR}/src/quiarea.cpp
    ${CODE_PATH_YEDITOR}/inc/quiitem.h
    ${CODE_PATH_YEDITOR}/src/quiitem.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitem.h
    ${CODE_PATH_YEDITOR}/src/quitreeitem.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreehelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h
    ${CODE_PATH_YEDITOR}/src/quitreereshelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeuihelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.cpp
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
    ${CODE_PATH_YEDITOR}/src/quitreereshelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeuihelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.moc.cpp
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

set_target_properties(yeditor PROPERTIES LINK_FLAGS "-mwindows")

add_custom_command(OUTPUT quiarea.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quiarea.h -o ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiarea.h
                   )

add_custom_target(quiarea_moc_cpp
                  DEPENDS quiarea.moc.cpp)

add_custom_command(OUTPUT quiitem.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quiitem.h -o ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiitem.h
                   )

add_custom_target(quiitem_moc_cpp
                  DEPENDS quiitem.moc.cpp)

add_custom_command(OUTPUT quitreehelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreehelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
                   )

add_custom_target(quitreehelper_moc_cpp
                  DEPENDS quitreehelper.moc.cpp)

add_custom_command(OUTPUT quitreereshelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h -o ${CODE_PATH_YEDITOR}/src/quitreereshelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h
                   )

add_custom_target(quitreereshelper_moc_cpp
                  DEPENDS quitreereshelper.moc.cpp)

add_custom_command(OUTPUT quitreeuihelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeuihelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h
                   )

add_custom_target(quitreeuihelper_moc_cpp
                  DEPENDS quitreeuihelper.moc.cpp)

add_custom_command(OUTPUT quitreeitemboundhelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
                   )

add_custom_target(quitreeitemboundhelper_moc_cpp
                  DEPENDS quitreeitemboundhelper.moc.cpp)

add_custom_command(OUTPUT quitreeitemlayerweighthelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
                   )

add_custom_target(quitreeitemlayerweighthelper_moc_cpp
                  DEPENDS quitreeitemlayerweighthelper.moc.cpp)

add_custom_command(OUTPUT quitreeitemimagehelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h
                   )

add_custom_target(quitreeitemimagehelper_moc_cpp
                  DEPENDS quitreeitemimagehelper.moc.cpp)

add_custom_command(OUTPUT yeditor.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc.exe ${CODE_PATH_YEDITOR}/inc/yeditor.h -o ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_PATH}/include -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_PATH}/include/QtCore -I${QT_SDK_PATH}/include/QtGui -I${QT_SDK_PATH}/include/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/yeditor.h
                   )

add_custom_target(yeditor_moc_cpp
                  DEPENDS yeditor.moc.cpp)

add_custom_command(OUTPUT yeditor.main.ui.h
                   COMMAND ${QT_SDK_PATH}/bin/uic.exe -o ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h ${CODE_PATH_YEDITOR}/res/main.ui
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/res/main.ui
                   )

add_custom_target(yeditor_main_ui_h
                  DEPENDS yeditor.main.ui.h)

add_dependencies(yeditor ${DEPEND_PROJ_LIST}
                         quiarea_moc_cpp
                         quiitem_moc_cpp
                         quitreehelper_moc_cpp
                         quitreeuihelper_moc_cpp
                         quitreereshelper_moc_cpp
                         quitreeitemboundhelper_moc_cpp
                         quitreeitemlayerweighthelper_moc_cpp
                         quitreeitemimagehelper_moc_cpp
                         yeditor_moc_cpp
                         yeditor_main_ui_h)
