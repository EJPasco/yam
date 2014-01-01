cmake_minimum_required (VERSION 2.6)

project(pstoyam)

set(CODE_PATH_PSTOYAM ${CODE_PATH}/pstoyam)

set(DEPEND_PROJ_LIST
    yam
    )

set(INCLUDE_PATH_LIST
    ${CODE_PATH_PSTOYAM}/inc
    )

set(LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.a
    )
else(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.lib
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CODE_FILE_LIST_PSTOYAM
    ${CODE_PATH_PSTOYAM}/inc/pstoyam.h
    ${CODE_PATH_PSTOYAM}/src/pstoyam.cpp
    )

source_group("pstoyam" FILES ${CODE_FILE_LIST_PSTOYAM})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
link_libraries(${LIBRARY_FILE_LIST})

add_definitions("-DC4G_EXPORTS_API")

add_library(pstoyam SHARED ${CODE_FILE_LIST_PSTOYAM})

add_dependencies(pstoyam ${DEPEND_PROJ_LIST})

