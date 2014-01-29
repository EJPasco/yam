CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (pstoyam)

SET (CODE_PATH_PSTOYAM ${CODE_PATH}/pstoyam)

SET (DEPEND_PROJ_LIST
    yam
    )

SET (INCLUDE_PATH_LIST
    ${CODE_PATH}/yam/inc
    ${CODE_PATH_PSTOYAM}/inc
    ${PHOTOSHOP_SDK_PATH}/photoshopapi/adm
    ${PHOTOSHOP_SDK_PATH}/photoshopapi/c++wrapperclasses
    ${PHOTOSHOP_SDK_PATH}/photoshopapi/photoshop
    ${PHOTOSHOP_SDK_PATH}/photoshopapi/pica_sp
    ${PHOTOSHOP_SDK_PATH}/photoshopapi/resources
    )

SET (LINK_PATH_LIST
    ${OUT_PATH}/lib
    )

if(CMAKE_COMPILER_IS_GNUCXX)
SET (LIBRARY_FILE_LIST
    yam.a
    )
ELSE (CMAKE_COMPILER_IS_GNUCXX)
SET (LIBRARY_FILE_LIST
    yam.lib
    )
ENDIF ()

SET (CODE_FILE_LIST_PS
    ${CODE_PATH_PSTOYAM}/ps/pstoyam.r
    ${CODE_PATH_PSTOYAM}/ps/pstoyam.pipl
    )

SET (CODE_FILE_LIST_PSTOYAM
    ${CODE_PATH_PSTOYAM}/inc/pstoyamr.h
    ${CODE_PATH_PSTOYAM}/inc/pstoyamcommon.h
    ${CODE_PATH_PSTOYAM}/inc/pstoyam.h
    ${CODE_PATH_PSTOYAM}/src/pstoyam.cpp
    ${CODE_PATH_PSTOYAM}/inc/psformat.h
    ${CODE_PATH_PSTOYAM}/src/psformat.cpp
    ${CODE_PATH_PSTOYAM}/inc/psformatwriter.h
    ${CODE_PATH_PSTOYAM}/src/psformatwriter.cpp
    ${CODE_PATH_PSTOYAM}/inc/psformatreader.h
    ${CODE_PATH_PSTOYAM}/src/psformatreader.cpp
    ${CODE_PATH_PSTOYAM}/inc/pschannel.h
    ${CODE_PATH_PSTOYAM}/src/pschannel.cpp
    )

SET (CODE_FILE_LIST_RES
    ${CODE_PATH_PSTOYAM}/inc/resource.h
    ${CODE_PATH_PSTOYAM}/res/pstoyam.rc
	)

SOURCE_GROUP ("ps" FILES ${CODE_FILE_LIST_PS})
SOURCE_GROUP ("pstoyam" FILES ${CODE_FILE_LIST_PSTOYAM})
SOURCE_GROUP ("res" FILES ${CODE_FILE_LIST_RES})

SET (LIBRARY_OUTPUT_PATH ${OUT_PATH}/lib)
SET (EXECUTABLE_OUTPUT_PATH ${OUT_PATH}/bin)

INCLUDE_DIRECTORIES (${INCLUDE_PATH_LIST})
LINK_DIRECTORIES (${LINK_PATH_LIST})
LINK_LIBRARIES (${LIBRARY_FILE_LIST})

ADD_DEFINITIONS ("-DC4G_EXPORTS_API")

ADD_LIBRARY (pstoyam SHARED ${CODE_FILE_LIST_PS}
                           ${CODE_FILE_LIST_PSTOYAM}
                           ${CODE_FILE_LIST_RES}
            )

set_target_properties(pstoyam PROPERTIES SUFFIX ".8bi")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
ADD_CUSTOM_COMMAND (OUTPUT pstoyam.pipl
                   COMMAND ${CMAKE_CXX_COMPILER} -I${PHOTOSHOP_SDK_PATH}/photoshopapi/PICA_SP -I${PHOTOSHOP_SDK_PATH}/photoshopapi/Photoshop -I${PHOTOSHOP_SDK_PATH}/photoshopapi/Resources -I${CODE_PATH_PSTOYAM}/inc -DMSWindows=1 -c"${CODE_PATH_PSTOYAM}/ps/pstoyam.r" -o"${OUT_PATH}/pstoyam.rr"
                   COMMAND ${PHOTOSHOP_SDK_PATH}/samplecode/resources/cnvtpipl "${OUT_PATH}/pstoyam.rr" "${CODE_PATH_PSTOYAM}/ps/pstoyam.pipl"
                   #COMMAND del "${OUT_PATH}/pstoyam.rr"
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_PSTOYAM}/ps/pstoyam.r
                   )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
ADD_CUSTOM_COMMAND (OUTPUT pstoyam.pipl
                   COMMAND ${CMAKE_CXX_COMPILER} /I${PHOTOSHOP_SDK_PATH}/photoshopapi/PICA_SP /I${PHOTOSHOP_SDK_PATH}/photoshopapi/Photoshop /I${PHOTOSHOP_SDK_PATH}/photoshopapi/Resources /I${CODE_PATH_PSTOYAM}/inc /EP /DMSWindows=1 /Tc"${CODE_PATH_PSTOYAM}/ps/pstoyam.r" > "${OUT_PATH}/pstoyam.rr"
                   COMMAND ${PHOTOSHOP_SDK_PATH}/samplecode/resources/cnvtpipl "${OUT_PATH}/pstoyam.rr" "${CODE_PATH_PSTOYAM}/ps/pstoyam.pipl"
                   #COMMAND del "${OUT_PATH}/pstoyam.rr"
                   COMMAND echo "ok"
                   DEPENDS ${CODE_PATH_PSTOYAM}/ps/pstoyam.r
                   )
ENDIF ()

ADD_CUSTOM_TARGET (pstoyam_pipl DEPENDS pstoyam.pipl)
ADD_DEPENDENCIES (pstoyam ${DEPEND_PROJ_LIST}
                         pstoyam_pipl)

