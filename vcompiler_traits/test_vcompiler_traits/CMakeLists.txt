#========================================================================================
cmake_minimum_required(VERSION 2.8)

project( test_vcompiler_traits )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include( ../../cmake/vcompiler_traits.cmake )

add_executable( ${PROJECT_NAME} ${HEADERS} ${SOURCES} "main.cpp" )

target_link_libraries( ${PROJECT_NAME} ${LIBRARIES} )

#========================================================================================
