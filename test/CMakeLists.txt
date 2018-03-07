
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_LIST_DIR}/../3Party)

file(GLOB_RECURSE SRC_LIST  ./*.cpp ./*.h)

add_definitions(/DWINVER=0x601)

set(PKG_GTEST gtest)

get_filename_component(PKG_GTEST_DIR "${CMAKE_CURRENT_LIST_DIR}/../3rdparty/${PKG_GTEST}" ABSOLUTE CACHE)
get_filename_component(PKG_GTEST_INCLUDE_DIR "${PKG_GTEST_DIR}/include" ABSOLUTE CACHE)

add_subdirectory(${PKG_GTEST_DIR} ${CMAKE_CURRENT_BINARY_DIR}/${PKG_GTEST})

set(DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
foreach(f ${SRC_LIST})
    file(RELATIVE_PATH SRCGR ${DIRECTORY} ${f})
    set(SRCGR "${SRCGR}")
    string(REGEX REPLACE "(.*)(/[^/]*)$" "\\1" SRCGR ${SRCGR})
    string(REPLACE / \\ SRCGR ${SRCGR})
    source_group("${SRCGR}" FILES ${f})
endforeach()

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include
                    ${CMAKE_CURRENT_LIST_DIR}/fixture
                    ${CMAKE_CURRENT_LIST_DIR}/case
                    ${PKG_GTEST_INCLUDE_DIR})

add_executable(test_${PROJECT_NAME} ${SRC_LIST})
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../target/)

target_link_libraries(test_${PROJECT_NAME} ${PROJECT_NAME} gtest gtest_main)

