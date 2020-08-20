cmake_minimum_required(VERSION 3.1)

project(libB)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIB)

add_library(libB STATIC ${SRC_LIB})

target_include_directories(libB 
    PUBLIC 
        $<INSTALL_INTERFACE:include>                                # in case we will install our lib 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>      # when we use lib - where to look up public headers
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src                             # private headers - only for build lib
)