cmake_minimum_required(VERSION 3.2.0)

set(TARGET_NAME qtcontrollayer)
project(${TARGET_NAME})
message(STATUS "Processing ${TARGET_NAME}...")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(SOURCES ${HEADER_FILES} ${SOURCE_FILES})

add_library(${TARGET_NAME} STATIC ${SOURCES})
target_link_libraries(${TARGET_NAME} Qt5::Core)

message(STATUS "Processing ${TARGET_NAME} - DONE")


