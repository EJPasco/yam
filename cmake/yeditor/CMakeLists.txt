CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (yeditor)

SET (CODE_PATH_YEDITOR ${CODE_PATH}/yeditor)

SET (DEPEND_PROJ_LIST
    yam
    supereasyjson
    rectanglebinpack
    )

SET (INCLUDE_PATH_LIST
    ${QT_SDK_INC_PATH}
    ${CODE_PATH}/yam/inc
    ${CODE_PATH}/t3rd/supereasyjson
    ${CODE_PATH}/t3rd/rectanglebinpack
    ${CODE_PATH_YEDITOR}/inc
    )

IF (YENV_SYSTEM_IS_LINUX)
SET (LINK_PATH_LIST
    ${QT_SDK_PATH}/lib/x86_64-linux-gnu
    ${OUT_PATH}/lib
    )
ELSEIF (YENV_SYSTEM_IS_WINDOWS)
SET (LINK_PATH_LIST
    ${QT_SDK_PATH}/lib
    ${OUT_PATH}/lib
    )
ENDIF ()

if(CMAKE_COMPILER_IS_GNUCXX)
SET (LIBRARY_FILE_LIST
    yam
    supereasyjson
    rectanglebinpack
    Qt5Core
    Qt5Gui
    Qt5Widgets
    )
ELSE ()
SET (LIBRARY_FILE_LIST
    yam.lib
    supereasyjson.lib
    rectanglebinpack.lib
    qtmain.lib
    Qt5Core.lib
    Qt5Gui.lib
    Qt5Widgets.lib
    )
ENDIF ()

SET (CODE_FILE_LIST_EDITOR
    ${CODE_PATH_YEDITOR}/inc/yeditorcommon.h
    ${CODE_PATH_YEDITOR}/inc/yeditor.h
    ${CODE_PATH_YEDITOR}/src/yeditor.cpp
    )

SET (CODE_FILE_LIST_QT_WIDGET
    ${CODE_PATH_YEDITOR}/inc/qdlgcreatewidget.h
    ${CODE_PATH_YEDITOR}/src/qdlgcreatewidget.cpp
    ${CODE_PATH_YEDITOR}/inc/qdlgexport.h
    ${CODE_PATH_YEDITOR}/src/qdlgexport.cpp
    ${CODE_PATH_YEDITOR}/inc/quiarea.h
    ${CODE_PATH_YEDITOR}/src/quiarea.cpp
    ${CODE_PATH_YEDITOR}/inc/quiitem.h
    ${CODE_PATH_YEDITOR}/src/quiitem.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitem.h
    ${CODE_PATH_YEDITOR}/src/quitreeitem.cpp
    )

SET (CODE_FILE_LIST_QT_HELPER
    ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreehelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h
    ${CODE_PATH_YEDITOR}/src/quitreereshelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeuihelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemsizehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemsizehelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemsizefhelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemsizefhelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemboundfhelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundfhelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemimagetypehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagetypehelper.cpp
    )

SET (CODE_FILE_LIST_RES
    ${CODE_PATH_YEDITOR}/res/main.ui
    ${CODE_PATH_YEDITOR}/res/createwidget.ui
    ${CODE_PATH_YEDITOR}/res/export.ui
    )

SET (CODE_FILE_LIST_QT_GENERATE
    ${CODE_PATH_YEDITOR}/inc/yeditor_main_ui.h
    ${CODE_PATH_YEDITOR}/inc/yeditor_createwidget_ui.h
    ${CODE_PATH_YEDITOR}/inc/yeditor_export_ui.h
    ${CODE_PATH_YEDITOR}/src/yeditor_moc.cpp
    ${CODE_PATH_YEDITOR}/src/qdlgcreatewidget_moc.cpp
    ${CODE_PATH_YEDITOR}/src/qdlgexport_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiarea_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiitem_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreehelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreereshelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeuihelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemsizehelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemsizefhelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundfhelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagetypehelper_moc.cpp
    )

SET (CODE_FILE_LIST_EXPORT
    ${CODE_PATH_YEDITOR}/inc/yconverter.h
    ${CODE_PATH_YEDITOR}/src/yconverter.cpp
    ${CODE_PATH_YEDITOR}/inc/yexport.h
    ${CODE_PATH_YEDITOR}/src/yexport.cpp
    ${CODE_PATH_YEDITOR}/inc/yexportyam.h
    ${CODE_PATH_YEDITOR}/src/yexportyam.cpp
    ${CODE_PATH_YEDITOR}/inc/yqt2yam.h
    ${CODE_PATH_YEDITOR}/src/yqt2yam.cpp
    ${CODE_PATH_YEDITOR}/inc/yrectpacker.h
    ${CODE_PATH_YEDITOR}/src/yrectpacker.cpp
    )

SOURCE_GROUP ("editor" FILES ${CODE_FILE_LIST_EDITOR})
SOURCE_GROUP ("qt\\widget" FILES ${CODE_FILE_LIST_QT_WIDGET})
SOURCE_GROUP ("qt\\helper" FILES ${CODE_FILE_LIST_QT_HELPER})
SOURCE_GROUP ("qt\\generate" FILES ${CODE_FILE_LIST_QT_GENERATE})
SOURCE_GROUP ("res" FILES ${CODE_FILE_LIST_RES})
SOURCE_GROUP ("export" FILES ${CODE_FILE_LIST_EXPORT})

SET (LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
SET (EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

INCLUDE_DIRECTORIES (${INCLUDE_PATH_LIST})
LINK_DIRECTORIES (${LINK_PATH_LIST})
LINK_LIBRARIES (${LIBRARY_FILE_LIST})

#ADD_DEFINITIONS ("-DC4G_EXPORTS_API")
IF (YENV_SYSTEM_IS_LINUX)
    SET (CMAKE_CXX_FLAGS "-fPIC")
ENDIF ()

ADD_EXECUTABLE (yeditor ${CODE_FILE_LIST_EDITOR}
                        ${CODE_FILE_LIST_QT_WIDGET}
                        ${CODE_FILE_LIST_QT_HELPER}
                        ${CODE_FILE_LIST_QT_GENERATE}
                        ${CODE_FILE_LIST_RES}
                        ${CODE_FILE_LIST_EXPORT}
                        )

IF (YENV_SYSTEM_IS_WINDOWS AND YENV_COMPILER_IS_GNUC)
    SET_TARGET_PROPERTIES (yeditor PROPERTIES LINK_FLAGS "-mwindows")
ENDIF ()

MACRO(QT_GENERATE_MOC directory filename)
ADD_CUSTOM_COMMAND (OUTPUT ${directory}/src/${filename}_moc.cpp
                    DEPENDS ${directory}/inc/${filename}.h
                    COMMAND ${QT_SDK_PATH}/bin/moc ${directory}/inc/${filename}.h -o ${directory}/src/${filename}_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                    COMMENT "Generating C++ source file ${directory}/src/${filename}_moc.cpp by ${directory}/inc/${filename}.h"
                    VERBATIM
                    )
ADD_CUSTOM_TARGET (${filename}_moc_cpp
                   DEPENDS ${directory}/src/${filename}_moc.cpp
                   SOURCES ${directory}/inc/${filename}.h
                   VERBATIM
                   )
ENDMACRO(QT_GENERATE_MOC)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} qdlgcreatewidget)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} qdlgexport)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quiarea)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quiitem)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreehelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreereshelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeuihelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemsizehelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemsizefhelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemboundhelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemboundfhelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemlayerweighthelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemimagehelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} quitreeitemimagetypehelper)

QT_GENERATE_MOC(${CODE_PATH_YEDITOR} yeditor)

MACRO(QT_GENERATE_UIC directory resname filename)
ADD_CUSTOM_COMMAND (OUTPUT ${directory}/inc/${filename}_ui.h
                    DEPENDS ${directory}/res/${resname}.ui
                    COMMAND ${QT_SDK_PATH}/bin/uic ${directory}/res/${resname}.ui -o ${directory}/inc/${filename}_ui.h
                    COMMENT "Generating C++ header file ${directory}/inc/${filename}_ui.h by ${directory}/res/${resname}.ui"
                    VERBATIM)
ADD_CUSTOM_TARGET (${filename}_ui_h
                   DEPENDS ${directory}/inc/${filename}_ui.h
                   SOURCE ${directory}/res/${resname}.ui
                   VERBATIM)
ENDMACRO(QT_GENERATE_UIC)

QT_GENERATE_UIC(${CODE_PATH_YEDITOR} main yeditor_main)

QT_GENERATE_UIC(${CODE_PATH_YEDITOR} createwidget yeditor_createwidget)

QT_GENERATE_UIC(${CODE_PATH_YEDITOR} export yeditor_export)


ADD_DEPENDENCIES (yeditor ${DEPEND_PROJ_LIST}
                         qdlgcreatewidget_moc_cpp
                         qdlgexport_moc_cpp
                         quiarea_moc_cpp
                         quiitem_moc_cpp
                         quitreehelper_moc_cpp
                         quitreeuihelper_moc_cpp
                         quitreereshelper_moc_cpp
                         quitreeitemsizehelper_moc_cpp
                         quitreeitemsizefhelper_moc_cpp
                         quitreeitemboundhelper_moc_cpp
                         quitreeitemlayerweighthelper_moc_cpp
                         quitreeitemimagehelper_moc_cpp
                         quitreeitemimagetypehelper_moc_cpp
                         yeditor_moc_cpp
                         yeditor_main_ui_h
                         yeditor_createwidget_ui_h
                         yeditor_export_ui_h)
