cmake_minimum_required (VERSION 2.6)

project(yeditor)

set(CODE_PATH_YEDITOR ${CODE_PATH}/yeditor)

set(DEPEND_PROJ_LIST
    yam
    )

set(INCLUDE_PATH_LIST
    ${CODE_PATH}/yam/inc
    ${CODE_PATH_YEDITOR}/inc
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

set(CODE_FILE_LIST_YEDITOR
    ${CODE_PATH_YEDITOR}/inc/yeditor.h
    ${CODE_PATH_YEDITOR}/src/yeditor.cpp
    )

source_group("yeditor" FILES ${CODE_FILE_LIST_YEDITOR})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
link_libraries(${LIBRARY_FILE_LIST})

#add_definitions("-DC4G_EXPORTS_API")

add_executable(yeditor ${CODE_FILE_LIST_YEDITOR}
                       )

add_dependencies(yeditor ${DEPEND_PROJ_LIST})

