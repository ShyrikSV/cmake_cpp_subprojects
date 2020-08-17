cmake_minimum_required(VERSION 3.1)

project(libA)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIB)

add_library(libA STATIC ${SRC_LIB})
target_include_directories(libA PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_include_directories(libA PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)