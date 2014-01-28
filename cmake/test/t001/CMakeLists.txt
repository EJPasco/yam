cmake_minimum_required (VERSION 2.8.12)

project(t001)

set(TEST_CODE_PATH_T001 ${TEST_CODE_PATH}/t001)

set(DEPEND_PROJ_LIST
    yam
    supereasyjson
    rectanglebinpack
    )

set(INCLUDE_PATH_LIST
    ${CODE_PATH}/yam/inc
    ${CODE_PATH}/t3rd/supereasyjson
    ${CODE_PATH}/t3rd/rectanglebinpack
    ${TEST_CODE_PATH_T001}
    )

set(LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.a
    supereasyjson.a
    rectanglebinpack.a
    )
else(CMAKE_COMPILER_IS_GNUCXX)
set(LIBRARY_FILE_LIST
    yam.lib
    supereasyjson.lib
    rectanglebinpack.lib
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CODE_FILE_LIST_T001
    ${TEST_CODE_PATH_T001}/t001.cpp
    )

source_group("t001" FILES ${CODE_FILE_LIST_T001})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
link_libraries(${LIBRARY_FILE_LIST})

#add_definitions("-DC4G_EXPORTS_API")

add_executable(t001 ${CODE_FILE_LIST_T001})

add_dependencies(t001 ${DEPEND_PROJ_LIST})
