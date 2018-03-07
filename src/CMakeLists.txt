
file(GLOB_RECURSE SRC_LIST
     ${_BASE_PATH}/include/*.h
     ./*.cpp
     ./*.h)

set(CUR_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
get_filename_component(CUR_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/" ABSOLUTE CACHE)
get_filename_component(PUB_INC_DIR "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE CACHE)

foreach(f ${SRC_LIST})
    file(RELATIVE_PATH SRCGR ${_BASE_PATH} ${f})
    set(SRCGR "${SRCGR}")
    string(REGEX REPLACE "(.*)(/[^/]*)$" "\\1" SRCGR ${SRCGR})
    string(REPLACE / \\ SRCGR ${SRCGR})
    source_group("${SRCGR}" FILES ${f})
endforeach()

include_directories(${PUB_INC_DIR}
                    ${CUR_DIRECTORY}
                    )


add_library(${PROJECT_NAME} STATIC ${SRC_LIST})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../target/lib/)


