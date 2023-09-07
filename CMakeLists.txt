cmake_minimum_required(VERSION 3.20)

project(smrproxy_test)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -std=gnu17 -ggdb")
else ()
    message(FATAL_ERROR "unsupported system type")
endif ()

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}")

add_executable(smrtest smrtest.c smrtestconfig.c)
target_include_directories(smrtest PUBLIC
    .
    ${CMAKE_SOURCE_DIR}/../smrproxy/include
    ${CMAKE_SOURCE_DIR}/../arcproxy/include
    )
#target_link_libraries(smrtest ${CMAKE_CURRENT_SOURCE_DIR}/../lib/libsmrproxy.a)
target_link_libraries(smrtest 
    ${CMAKE_SOURCE_DIR}/../smrproxy/lib/libsmrproxy.a
    ${CMAKE_SOURCE_DIR}/../arcproxy/lib/libarcproxy.a
    )

add_executable(smrtest_mb smrtest.c smrtestconfig.c)
target_compile_definitions(smrtest_mb PUBLIC SMRPROXY_MB)
target_include_directories(smrtest_mb PUBLIC
    .
    ${CMAKE_SOURCE_DIR}/../smrproxy/include
    ${CMAKE_SOURCE_DIR}/../arcproxy/include
    )
target_link_libraries(smrtest_mb
    ${CMAKE_SOURCE_DIR}/../smrproxy/lib/libsmrproxy.a
    ${CMAKE_SOURCE_DIR}/../arcproxy/lib/libarcproxy.a
    )

