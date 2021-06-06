cmake_minimum_required(VERSION 3.5)

project( dev_traits LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

include( ../../cmake/vcompiler_traits.cmake )

add_executable( dev_traits main.cpp ${SOURCES} ${HEADERS} )
target_link_libraries( ${PROJECT_NAME} ${LIBRARIES} )

unset( CMAKE_C_COMPILER    )
unset( QT_QMAKE_EXECUTABLE )
