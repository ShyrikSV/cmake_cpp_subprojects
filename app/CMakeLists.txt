cmake_minimum_required(VERSION 3.1)

project(CMAKE_VOODO)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_APP)
add_executable(CMAKE_VOODO ${SRC_APP})

target_include_directories(CMAKE_VOODO PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(CMAKE_VOODO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../libs)
add_dependencies(CMAKE_VOODO libA libB)
target_link_libraries(CMAKE_VOODO libA libB)