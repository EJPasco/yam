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
    ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.cpp
    ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.cpp
    )

SET (CODE_FILE_LIST_RES
    ${CODE_PATH_YEDITOR}/res/main.ui
    ${CODE_PATH_YEDITOR}/res/createwidget.ui
    )

SET (CODE_FILE_LIST_QT_GENERATE
    ${CODE_PATH_YEDITOR}/inc/yeditor_main_ui.h
    ${CODE_PATH_YEDITOR}/inc/yeditor_createwidget_ui.h
    ${CODE_PATH_YEDITOR}/src/yeditor_moc.cpp
    ${CODE_PATH_YEDITOR}/src/qdlgcreatewidget_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiarea_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiitem_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreehelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreereshelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeuihelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemsizehelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper_moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper_moc.cpp
    )

SET (CODE_FILE_LIST_EXPORT
    ${CODE_PATH_YEDITOR}/inc/yconverter.h
    ${CODE_PATH_YEDITOR}/src/yconverter.cpp
    ${CODE_PATH_YEDITOR}/inc/yexport.h
    ${CODE_PATH_YEDITOR}/src/yexport.cpp
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

ADD_CUSTOM_COMMAND (OUTPUT qdlgcreatewidget_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/qdlgcreatewidget.h -o ${CODE_PATH_YEDITOR}/src/qdlgcreatewidget_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/qdlgcreatewidget.h
                   )

ADD_CUSTOM_TARGET (qdlgcreatewidget_moc_cpp
                  DEPENDS qdlgcreatewidget_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quiarea_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quiarea.h -o ${CODE_PATH_YEDITOR}/src/quiarea_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiarea.h
                   )

ADD_CUSTOM_TARGET (quiarea_moc_cpp
                  DEPENDS quiarea_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quiitem_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quiitem.h -o ${CODE_PATH_YEDITOR}/src/quiitem_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiitem.h
                   )

ADD_CUSTOM_TARGET (quiitem_moc_cpp
                  DEPENDS quiitem_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreehelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreehelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
                   )

ADD_CUSTOM_TARGET (quitreehelper_moc_cpp
                  DEPENDS quitreehelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreereshelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h -o ${CODE_PATH_YEDITOR}/src/quitreereshelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h
                   )

ADD_CUSTOM_TARGET (quitreereshelper_moc_cpp
                  DEPENDS quitreereshelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeuihelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeuihelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h
                   )

ADD_CUSTOM_TARGET (quitreeuihelper_moc_cpp
                  DEPENDS quitreeuihelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemsizehelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemsizehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemsizehelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemsizehelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemsizehelper_moc_cpp
                  DEPENDS quitreeitemsizehelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemboundhelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemboundhelper_moc_cpp
                  DEPENDS quitreeitemboundhelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemlayerweighthelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemlayerweighthelper_moc_cpp
                  DEPENDS quitreeitemlayerweighthelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemimagehelper_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemimagehelper_moc_cpp
                  DEPENDS quitreeitemimagehelper_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT yeditor_moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/yeditor.h -o ${CODE_PATH_YEDITOR}/src/yeditor_moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/yeditor.h
                   )

ADD_CUSTOM_TARGET (yeditor_moc_cpp
                  DEPENDS yeditor_moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT yeditor_main_ui.h
                   COMMAND ${QT_SDK_PATH}/bin/uic -o ${CODE_PATH_YEDITOR}/inc/yeditor_main_ui.h ${CODE_PATH_YEDITOR}/res/main.ui
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/res/main.ui
                   )

ADD_CUSTOM_TARGET (yeditor_main_ui_h
                  DEPENDS yeditor_main_ui.h)

ADD_CUSTOM_COMMAND (OUTPUT yeditor_createwidget_ui.h
                   COMMAND ${QT_SDK_PATH}/bin/uic -o ${CODE_PATH_YEDITOR}/inc/yeditor_createwidget_ui.h ${CODE_PATH_YEDITOR}/res/createwidget.ui
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/res/createwidget.ui
                   )

ADD_CUSTOM_TARGET (yeditor_createwidget_ui_h
                  DEPENDS yeditor_createwidget_ui.h)

ADD_DEPENDENCIES (yeditor ${DEPEND_PROJ_LIST}
                         qdlgcreatewidget_moc_cpp
                         quiarea_moc_cpp
                         quiitem_moc_cpp
                         quitreehelper_moc_cpp
                         quitreeuihelper_moc_cpp
                         quitreereshelper_moc_cpp
                         quitreeitemsizehelper_moc_cpp
                         quitreeitemboundhelper_moc_cpp
                         quitreeitemlayerweighthelper_moc_cpp
                         quitreeitemimagehelper_moc_cpp
                         yeditor_moc_cpp
                         yeditor_main_ui_h
                         yeditor_createwidget_ui_h)
