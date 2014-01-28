cmake_minimum_required (VERSION 2.8.12)

project(yam)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_C_FLAGS "-DGNUC ${CMAKE_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "-DGNUC ${CMAKE_CXX_FLAGS}")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(CMAKE_C_FLAGS "/DMSVC ${CMAKE_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "/DMSVC ${CMAKE_CXX_FLAGS}")
else()
    message(FATAL_ERROR "sorry, can't find the compiler type - CMAKE_CXX_COMPILER_ID:${CMAKE_CXX_COMPILER_ID}")
endif()

set(ROOT_PATH "${yam_SOURCE_DIR}/..")
set(CODE_PATH "${ROOT_PATH}/code")
set(OUT_PATH "${ROOT_PATH}/out")

set(QT_SDK_PATH "${QT_SDK_PATH}" CACHE STRING "Add the qt sdk path" FORCE)
# can't compile the photoshop plugin for gnuc
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
set(PHOTOSHOP_SDK_PATH "${PHOTOSHOP_SDK_PATH}" CACHE STRING "Add the qt sdk path" FORCE)
endif()

add_subdirectory(yam)
add_subdirectory(yeditor)
# can't compile the photoshop plugin for gnuc
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
add_subdirectory(pstoyam)
endif()

add_subdirectory(t3rd)

add_subdirectory(test)
