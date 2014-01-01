cmake_minimum_required (VERSION 2.6)

project (yam)

set(CODE_DIR_YAM ${CODE_DIR}/yam)

set(PATH_LIST ${CODE_DIR_YAM}/inc)

set(CODE_LIST
    ${CODE_DIR_YAM}/inc/yam.h
    ${CODE_DIR_YAM}/src/yam.cpp
    )

source_group("common" FILES ${CODE_LIST})

include_directories(${PATH_LIST})

add_library(yam STATIC ${CODE_LIST})