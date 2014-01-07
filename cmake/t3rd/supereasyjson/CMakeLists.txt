cmake_minimum_required (VERSION 2.6)

project (supereasyjson)

set(T3RD_CODE_PATH_SUPEREASYJSON ${T3RD_CODE_PATH}/supereasyjson)

set(DEPEND_PROJ_LIST
    )

set(INCLUDE_PATH_LIST ${T3RD_CODE_PATH_SUPEREASYJSON})
set(LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

set(LIBRARY_FILE_LIST
    )

set(CODE_FILE_LIST_JSON
    ${T3RD_CODE_PATH_SUPEREASYJSON}/json.h
    ${T3RD_CODE_PATH_SUPEREASYJSON}/json.cpp
    )

set(CODE_FILE_LIST_RES
    ${T3RD_CODE_PATH_SUPEREASYJSON}/LICENSE
    ${T3RD_CODE_PATH_SUPEREASYJSON}/README.txt
    )

source_group("json" FILES ${CODE_FILE_LIST_JSON})
source_group("res" FILES ${CODE_FILE_LIST_RES})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
#link_libraries(${LIBRARY_FILE_LIST}

#add_definitions("-DC4G_EXPORTS_API")
#add_dependencies(supereasyjson ${DEPEND_PROJ_LIST})

add_library(supereasyjson STATIC ${CODE_FILE_LIST_JSON}
		                 ${CODE_FILE_LIST_RES}
                                 )
