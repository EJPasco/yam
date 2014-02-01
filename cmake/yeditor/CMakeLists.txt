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
    )

SET (CODE_FILE_LIST_QT
    ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h
    ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreehelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreereshelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeuihelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemsizehelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.moc.cpp
    ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.moc.cpp
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
SOURCE_GROUP ("res" FILES ${CODE_FILE_LIST_RES})
SOURCE_GROUP ("qt" FILES ${CODE_FILE_LIST_QT})
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
                       ${CODE_FILE_LIST_RES}
                       ${CODE_FILE_LIST_QT}
                       ${CODE_FILE_LIST_EXPORT}
                       )

IF (YENV_SYSTEM_IS_WINDOWS AND YENV_COMPILER_IS_GNUC)
    SET_TARGET_PROPERTIES (yeditor PROPERTIES LINK_FLAGS "-mwindows")
ENDIF ()

ADD_CUSTOM_COMMAND (OUTPUT quiarea.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quiarea.h -o ${CODE_PATH_YEDITOR}/src/quiarea.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiarea.h
                   )

ADD_CUSTOM_TARGET (quiarea_moc_cpp
                  DEPENDS quiarea.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quiitem.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quiitem.h -o ${CODE_PATH_YEDITOR}/src/quiitem.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quiitem.h
                   )

ADD_CUSTOM_TARGET (quiitem_moc_cpp
                  DEPENDS quiitem.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreehelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreehelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreehelper.h
                   )

ADD_CUSTOM_TARGET (quitreehelper_moc_cpp
                  DEPENDS quitreehelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreereshelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h -o ${CODE_PATH_YEDITOR}/src/quitreereshelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreereshelper.h
                   )

ADD_CUSTOM_TARGET (quitreereshelper_moc_cpp
                  DEPENDS quitreereshelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeuihelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeuihelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeuihelper.h
                   )

ADD_CUSTOM_TARGET (quitreeuihelper_moc_cpp
                  DEPENDS quitreeuihelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemsizehelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemsizehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemsizehelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemsizehelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemsizehelper_moc_cpp
                  DEPENDS quitreeitemsizehelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemboundhelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemboundhelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemboundhelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemboundhelper_moc_cpp
                  DEPENDS quitreeitemboundhelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemlayerweighthelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemlayerweighthelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemlayerweighthelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemlayerweighthelper_moc_cpp
                  DEPENDS quitreeitemlayerweighthelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT quitreeitemimagehelper.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h -o ${CODE_PATH_YEDITOR}/src/quitreeitemimagehelper.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/quitreeitemimagehelper.h
                   )

ADD_CUSTOM_TARGET (quitreeitemimagehelper_moc_cpp
                  DEPENDS quitreeitemimagehelper.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT yeditor.moc.cpp
                   COMMAND ${QT_SDK_PATH}/bin/moc ${CODE_PATH_YEDITOR}/inc/yeditor.h -o ${CODE_PATH_YEDITOR}/src/yeditor.moc.cpp -DQT_CORE_LIB -DQT_DLL -DQT_GUI_LIB -DQT_WIDGETS_LIB -DUNICODE -DWIN32 -DWIN64 -I${CODE_PATH_YEDITOR}/inc -I. -I${QT_SDK_INC_PATH} -I${CODE_PATH_YEDITOR}/inc -I${QT_SDK_INC_PATH}/QtCore -I${QT_SDK_INC_PATH}/QtGui -I${QT_SDK_INC_PATH}/QtWidgets
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/inc/yeditor.h
                   )

ADD_CUSTOM_TARGET (yeditor_moc_cpp
                  DEPENDS yeditor.moc.cpp)

ADD_CUSTOM_COMMAND (OUTPUT yeditor.main.ui.h
                   COMMAND ${QT_SDK_PATH}/bin/uic -o ${CODE_PATH_YEDITOR}/inc/yeditor.main.ui.h ${CODE_PATH_YEDITOR}/res/main.ui
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_YEDITOR}/res/main.ui
                   )

ADD_CUSTOM_TARGET (yeditor_main_ui_h
                  DEPENDS yeditor.main.ui.h)

ADD_DEPENDENCIES (yeditor ${DEPEND_PROJ_LIST}
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
                         yeditor_main_ui_h)
