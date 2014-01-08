cmake_minimum_required (VERSION 2.6)

project (yam)

set(CODE_PATH_YAM ${CODE_PATH}/yam)

set(DEPEND_PROJ_LIST
    )

set(INCLUDE_PATH_LIST ${CODE_PATH_YAM}/inc)
set(LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

set(LIBRARY_FILE_LIST
    )

set(CODE_FILE_LIST_COMMON
    ${CODE_PATH_YAM}/inc/define.h
    ${CODE_PATH_YAM}/inc/typedef.h
	${CODE_PATH_YAM}/inc/struct.h
    ${CODE_PATH_YAM}/inc/common.h
    )

set(CODE_FILE_LIST_BASE
    ${CODE_PATH_YAM}/inc/tree.h
    ${CODE_PATH_YAM}/inc/panel.h
    ${CODE_PATH_YAM}/src/panel.cpp
    ${CODE_PATH_YAM}/inc/widget.h
    ${CODE_PATH_YAM}/src/widget.cpp
    ${CODE_PATH_YAM}/inc/format.h
    ${CODE_PATH_YAM}/src/format.cpp
    )

set(CODE_FILE_LIST_FILE
    ${CODE_PATH_YAM}/inc/file.h
    ${CODE_PATH_YAM}/src/file.cpp
    )

set(CODE_FILE_LIST_YAM
    ${CODE_PATH_YAM}/inc/yam.h
    ${CODE_PATH_YAM}/src/yam.cpp
    )

source_group("common" FILES ${CODE_FILE_LIST_COMMON})
source_group("base" FILES ${CODE_FILE_LIST_BASE})
source_group("file" FILES ${CODE_FILE_LIST_FILE})
source_group("yam" FILES ${CODE_FILE_LIST_YAM})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
#link_libraries(${LIBRARY_FILE_LIST}

#add_definitions("-DC4G_EXPORTS_API")
#add_dependencies(yam ${DEPEND_PROJ_LIST})

add_library(yam STATIC ${CODE_FILE_LIST_COMMON}
                       ${CODE_FILE_LIST_BASE}
                       ${CODE_FILE_LIST_FILE}
                       ${CODE_FILE_LIST_YAM}
                       )
