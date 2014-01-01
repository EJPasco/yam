cmake_minimum_required (VERSION 2.6)

project(yam)

set(ROOT_PATH "${yam_SOURCE_DIR}/..")
set(CODE_PATH "${ROOT_PATH}/code")
set(OUT_PATH "${ROOT_PATH}/out")

add_subdirectory(yam)
add_subdirectory(yeditor)
add_subdirectory(pstoyam)
