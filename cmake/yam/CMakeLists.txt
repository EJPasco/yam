CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (yam)

SET (CODE_PATH_YAM ${CODE_PATH}/yam)

SET (DEPEND_PROJ_LIST
    )

SET (INCLUDE_PATH_LIST ${CODE_PATH_YAM}/inc)
SET (LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

SET (LIBRARY_FILE_LIST
    )

SET (CODE_FILE_LIST_COMMON
    ${CODE_PATH_YAM}/inc/define.h
    ${CODE_PATH_YAM}/inc/typedef.h
    ${CODE_PATH_YAM}/inc/enum.h
    ${CODE_PATH_YAM}/inc/struct.h
    ${CODE_PATH_YAM}/src/struct.cpp
    ${CODE_PATH_YAM}/inc/compiler.h
    ${CODE_PATH_YAM}/inc/common.h
    )

SET (CODE_FILE_LIST_BASE
    ${CODE_PATH_YAM}/inc/object.h
    ${CODE_PATH_YAM}/inc/tree.h
    ${CODE_PATH_YAM}/src/tree.cpp
    ${CODE_PATH_YAM}/inc/buffer.h
    ${CODE_PATH_YAM}/src/buffer.cpp
    ${CODE_PATH_YAM}/inc/panel.h
    ${CODE_PATH_YAM}/src/panel.cpp
    ${CODE_PATH_YAM}/inc/property.h
    ${CODE_PATH_YAM}/src/property.cpp
    ${CODE_PATH_YAM}/inc/widget.h
    ${CODE_PATH_YAM}/src/widget.cpp
    ${CODE_PATH_YAM}/inc/format.h
    ${CODE_PATH_YAM}/src/format.cpp
    ${CODE_PATH_YAM}/inc/new.h
    ${CODE_PATH_YAM}/src/new.cpp
    )

SET (CODE_FILE_LIST_UTIL
    ${CODE_PATH_YAM}/inc/merge.h
    ${CODE_PATH_YAM}/src/merge.cpp
    )

SET (CODE_FILE_LIST_STORAGE
    ${CODE_PATH_YAM}/inc/file.h
    ${CODE_PATH_YAM}/src/file.cpp
    )

SET (CODE_FILE_LIST_YAM
    ${CODE_PATH_YAM}/inc/yam.h
    ${CODE_PATH_YAM}/src/yam.cpp
    )

SOURCE_GROUP ("common" FILES ${CODE_FILE_LIST_COMMON})
SOURCE_GROUP ("base" FILES ${CODE_FILE_LIST_BASE})
SOURCE_GROUP ("util" FILES ${CODE_FILE_LIST_UTIL})
SOURCE_GROUP ("storage" FILES ${CODE_FILE_LIST_STORAGE})
SOURCE_GROUP ("yam" FILES ${CODE_FILE_LIST_YAM})

SET (LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
SET (EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

INCLUDE_DIRECTORIES (${INCLUDE_PATH_LIST})
LINK_DIRECTORIES (${LINK_PATH_LIST})
#LINK_LIBRARIES (${LIBRARY_FILE_LIST}

#ADD_DEFINITIONS ("-DC4G_EXPORTS_API")
#ADD_DEPENDENCIES (yam ${DEPEND_PROJ_LIST})

ADD_LIBRARY (yam STATIC ${CODE_FILE_LIST_COMMON}
                       ${CODE_FILE_LIST_BASE}
                       ${CODE_FILE_LIST_UTIL}
                       ${CODE_FILE_LIST_STORAGE}
                       ${CODE_FILE_LIST_YAM}
                       )
