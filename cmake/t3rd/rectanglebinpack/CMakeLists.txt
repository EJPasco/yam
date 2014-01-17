cmake_minimum_required (VERSION 2.6)

project (rectanglebinpack)

set(T3RD_CODE_PATH_RECTANGLEBINPACK ${T3RD_CODE_PATH}/rectanglebinpack)

set(DEPEND_PROJ_LIST
    )

set(INCLUDE_PATH_LIST ${T3RD_CODE_PATH_RECTANGLEBINPACK})
set(LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

set(LIBRARY_FILE_LIST
    )

set(CODE_FILE_LIST_RECTANGLEBINPACK
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/Rect.h
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/Rect.cpp
    ${T3RD_CODE_PATH_RECTANGLEBINPACK}/GuillotineBinPack.h
    ${T3RD_CODE_PATH_RECTANGLEBINPACK}/GuillotineBinPack.cpp
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/MaxRectsBinPack.h
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/MaxRectsBinPack.cpp
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/ShelfBinPack.h
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/ShelfBinPack.cpp
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/ShelfNextFitBinPack.h
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/ShelfNextFitBinPack.cpp
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/SkylineBinPack.h
	${T3RD_CODE_PATH_RECTANGLEBINPACK}/SkylineBinPack.cpp
    )

set(CODE_FILE_LIST_RES
    ${T3RD_CODE_PATH_RECTANGLEBINPACK}/RectangleBinPack.pdf
    ${T3RD_CODE_PATH_RECTANGLEBINPACK}/Readme.txt
    )

source_group("rectanglebinpack" FILES ${CODE_FILE_LIST_RECTANGLEBINPACK})
source_group("res" FILES ${CODE_FILE_LIST_RES})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
#link_libraries(${LIBRARY_FILE_LIST}

#add_definitions("-DC4G_EXPORTS_API")
#add_dependencies(rectanglebinpack ${DEPEND_PROJ_LIST})

add_library(rectanglebinpack STATIC ${CODE_FILE_LIST_RECTANGLEBINPACK}
                                    ${CODE_FILE_LIST_RES}
                                    )
