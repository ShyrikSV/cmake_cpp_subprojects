cmake_minimum_required(VERSION 3.1)

project(libA)

# we need all source files...
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIB)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/PrivClass SRC_LIB)

add_library(libA STATIC ${SRC_LIB})
target_include_directories(libA 
    PUBLIC 
        $<INSTALL_INTERFACE:include>                                # in case we will install our lib 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>      # when we use lib - where to look up public headers
        
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src                             # private headers - only for build lib
        ${CMAKE_CURRENT_SOURCE_DIR}/src/PrivClass
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
)

add_dependencies(libA libB)
target_link_libraries(libA PRIVATE libB)