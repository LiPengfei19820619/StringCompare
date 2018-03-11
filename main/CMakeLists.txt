cmake_minimum_required(VERSION 2.8)

PROJECT(StringCompare)

SET(_BASE_PATH ${CMAKE_CURRENT_LIST_DIR}/..)

file(GLOB_RECURSE SRC_LIST  ./*.cpp ./*.h)

get_filename_component(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/../src" ABSOLUTE CACHE)

if (MSVC)
    add_definitions(/MTd /W3 /WX-)
endif()

ADD_SUBDIRECTORY(${SRC_DIR}  ${CMAKE_CURRENT_BINARY_DIR}/src)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)                    

add_executable(main_${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(main_${PROJECT_NAME} ${PROJECT_NAME})

