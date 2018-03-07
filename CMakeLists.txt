cmake_minimum_required(VERSION 2.8)

PROJECT(StringCompare)

SET(_BASE_PATH ${CMAKE_CURRENT_LIST_DIR})

if (MSVC)
    add_definitions(/MTd)
endif()

ADD_SUBDIRECTORY(${_BASE_PATH}/src)
ADD_SUBDIRECTORY(${_BASE_PATH}/test)

