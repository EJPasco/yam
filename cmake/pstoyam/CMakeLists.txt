cmake_minimum_required (VERSION 2.6)

project(pstoyam)

set(CODE_PATH_PSTOYAM ${CODE_PATH}/pstoyam)

set(DEPEND_PROJ_LIST
    yam
    )

set(INCLUDE_PATH_LIST
    ${CODE_PATH}/yam/inc
    ${CODE_PATH_PSTOYAM}/inc
    $ENV{PS_PLUGIN_SDK}/photoshopapi/adm
    $ENV{PS_PLUGIN_SDK}/photoshopapi/c++wrapperclasses
    $ENV{PS_PLUGIN_SDK}/photoshopapi/photoshop
    $ENV{PS_PLUGIN_SDK}/photoshopapi/pica_sp
    $ENV{PS_PLUGIN_SDK}/photoshopapi/resources
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

set(CODE_FILE_LIST_PS
    ${CODE_PATH_PSTOYAM}/ps/pstoyam.r
    ${CODE_PATH_PSTOYAM}/ps/pstoyam.pipl
    )

set(CODE_FILE_LIST_PSTOYAM
    ${CODE_PATH_PSTOYAM}/inc/pstoyamcommon.h
    ${CODE_PATH_PSTOYAM}/inc/pstoyam.h
    ${CODE_PATH_PSTOYAM}/src/pstoyam.cpp
    )

set(CODE_FILE_LIST_RES
    ${CODE_PATH_PSTOYAM}/inc/resource.h
    ${CODE_PATH_PSTOYAM}/res/pstoyam.rc
	)

source_group("ps" FILES ${CODE_FILE_LIST_PS})
source_group("pstoyam" FILES ${CODE_FILE_LIST_PSTOYAM})
source_group("res" FILES ${CODE_FILE_LIST_RES})

set(LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
set(EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

include_directories(${INCLUDE_PATH_LIST})
link_directories(${LINK_PATH_LIST})
link_libraries(${LIBRARY_FILE_LIST})

add_definitions("-DC4G_EXPORTS_API")

add_library(pstoyam SHARED ${CODE_FILE_LIST_PS}
                           ${CODE_FILE_LIST_PSTOYAM}
                           ${CODE_FILE_LIST_RES}
            )

set_target_properties(pstoyam PROPERTIES SUFFIX ".8bi")

add_custom_command(OUTPUT pstoyam.pipl
                   COMMAND cl /I$ENV{PS_PLUGIN_SDK}/photoshopapi/PICA_SP /I$ENV{PS_PLUGIN_SDK}/photoshopapi/Photoshop /I$ENV{PS_PLUGIN_SDK}/photoshopapi/Resources /I${CODE_PATH_PSTOYAM}/inc /EP /DMSWindows=1 /Tc"${CODE_PATH_PSTOYAM}/ps/pstoyam.r" > "${OUT_PATH}/pstoyam.rr"
                   COMMAND $ENV{PS_PLUGIN_SDK}/samplecode/resources/cnvtpipl "${OUT_PATH}/pstoyam.rr" "${CODE_PATH_PSTOYAM}/ps/pstoyam.pipl"
                   #COMMAND del "${OUT_PATH}/pstoyam.rr"
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_PSTOYAM}/ps/pstoyam.r
                   )

add_custom_target(pstoyam_pipl DEPENDS pstoyam.pipl)
add_dependencies(pstoyam ${DEPEND_PROJ_LIST}
                         pstoyam_pipl)

